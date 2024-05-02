#include <AppCore/AppCore.h>
#include <iostream>
#include <functional>
#include <string>
#include <windows.h>
#include <winnetwk.h>
#include <map>

#pragma comment(lib, "mpr.lib")

namespace ul = ultralight;

class About : public ul::WindowListener, public ul::LoadListener, public ul::ViewListener {
    ul::RefPtr<ul::Window> window;
    ul::RefPtr<ul::Overlay> overlay;
    std::function<void()> closeCallback;

public:
    About(const ul::RefPtr<ul::App>& app, std::function<void()> onClose)
    : closeCallback{std::move(onClose)}
    , window{ ul::Window::Create(app->main_monitor(), 560, 600, false, ul::kWindowFlags_Resizable) }
    , overlay{ ul::Overlay::Create(window, 1, 1, 0, 0) }
    {
        window->set_listener(this);
        overlay->view()->set_load_listener(this);
        overlay->view()->set_view_listener(this);

        window->MoveToCenter();
        overlay->Resize(window->width(), window->height());
        overlay->view()->LoadURL("file:///about.html");
        overlay->Focus();
    }

    void OnClose(ul::Window*) override {
        window->Close();
        closeCallback();
    }

    void OnResize(ul::Window*, uint32_t width, uint32_t height) override {
        overlay->Resize(width, height);
    }

    void OnChangeTitle(ul::View *caller, const ul::String &title) override {
        window->SetTitle(title.utf8().data());
    }

    bool OnKeyEvent(const ul::KeyEvent &evt) override {
        constexpr auto Escape = 27;

        switch (evt.virtual_key_code) {
        case Escape:
            OnClose(window.get());
        }
        return true;
    }
};

class App : public ul::AppListener, public ul::WindowListener, public ul::LoadListener, public ul::ViewListener {
    ul::RefPtr<ul::App> app;
    ul::RefPtr<ul::Window> window;
    ul::RefPtr<ul::Overlay> overlay;

    About* pAbout = nullptr;
    bool closeAbout = false;
public:
    App()
    : app{ ul::App::Create() }
    , window{ ul::Window::Create(app->main_monitor(), 720, 640, false, ul::kWindowFlags_Resizable | ul::kWindowFlags_Maximizable) }
    , overlay{ ul::Overlay::Create(window, 1, 1, 0, 0) }
    {
        app->set_listener(this);
        window->set_listener(this);
        overlay->view()->set_load_listener(this);
        overlay->view()->set_view_listener(this);

        window->MoveToCenter();
        overlay->Resize(window->width(), window->height());
        overlay->view()->LoadURL("file:///app.html");
        overlay->Focus();
    }

    inline void run() {
        app->Run();
    }

    void OnUpdate() override {
        if (closeAbout) {
            delete pAbout;
            pAbout = nullptr;
            closeAbout = false;
            ul::SetJSContext(overlay->view()->LockJSContext()->ctx());
        }
    }

    void OnClose(ul::Window*) override {
        std::exit(0);
    }

    void OnResize(ul::Window*, uint32_t width, uint32_t height) override {
        overlay->Resize(width, height);
        overlay->view()->Resize(width, height);
    }

    void OnDOMReady(ul::View *caller, uint64_t frame_id, bool is_main_frame, const ul::String &url) override {
        using ul::JSCallback, ul::JSCallbackWithRetval;
        ul::SetJSContext(caller->LockJSContext()->ctx());
        auto global = ul::JSGlobalObject();

        global["nuke"] = BindJSCallback(&App::Nuke);
        global["openInfo"] = BindJSCallback(&App::OpenInfo);
        global["connectDisk"] = BindJSCallbackWithRetval(&App::ConnectDisk);
        global["disconnectDisk"] = BindJSCallbackWithRetval(&App::DisconnectDisk);
        global["getDiskCount"] = JSCallbackWithRetval([this](const ul::JSObject&, const ul::JSArgs&) -> ul::JSValue {
            return { ListValidDrives().size() };
        });
        global["openDisk"] = BindJSCallback(&App::OpenDisk);

        auto drives = ListValidDrives();
        ul::JSEval(("diskCount.innerText = 'Кількість дисків: "+std::to_string(drives.size())+'\'').c_str());

        auto addDisk = global["addDisk"].ToFunction();
        for (auto& [label, name] : drives) {
            addDisk({name.c_str(), label.c_str()});
        }
    }

    void OnChangeCursor(ul::View *caller, ul::Cursor cursor) override {
        window->SetCursor(cursor);
    }

    void OnChangeTitle(ul::View *caller, const ul::String &title) override {
        window->SetTitle(title.utf8().data());
    }

    void OnAddConsoleMessage(ul::View*, ul::MessageSource, ul::MessageLevel lvl, const ul::String &message,
                             uint32_t line, uint32_t col, const ul::String &) override {
        (lvl == ul::kMessageLevel_Error ? std::cerr : std::cout)
                << "Console: " << message.utf8().data() << " at line: " << line << ", column: " << col << std::endl;
    }

    void OpenInfo(const ul::JSObject&, const ul::JSArgs&) {
        if (pAbout) {
            return;
        }

        pAbout = new About(app, [this] { closeAbout = true; });
    }

    void Nuke(const ul::JSObject&, const ul::JSArgs&) {
        std::exit(0);
    }

    ul::JSValue ConnectDisk(const ul::JSObject&, const ul::JSArgs& args) {
        auto label = ((ul::String) args[0]).utf8();
        auto path = ((ul::String) args[1]).utf8();
        auto user = ((ul::String) args[2]).utf8();
        auto password = ((ul::String) args[3]).utf8();
        auto flags = (uint64_t) args[4];

        auto nr = NETRESOURCE{
            .dwType = RESOURCETYPE_DISK,
            .lpLocalName = label.data(),
            .lpRemoteName = path.data(),
        };

        auto dwResult = WNetAddConnection2(
                &nr,
                password.empty() ? nullptr : password.data(),
                user.empty() ? nullptr : user.data(),
                flags
        );

        return {(uint64_t) dwResult};
    }

    ul::JSValue DisconnectDisk(const ul::JSObject&, const ul::JSArgs& args) {
        auto label = ((ul::String) args[0]).utf8();

        return {(uint64_t) WNetCancelConnection2(label.data(), CONNECT_UPDATE_PROFILE, true)};
    }

    std::map<std::string, std::string> ListValidDrives() {
        auto map = std::map<std::string, std::string>();
        auto drives = GetLogicalDrives();

        for (int i = 0; i < 26; i++) {
            if (!(drives >> i & 1)) continue;

            auto label = std::wstring(1, 'A' + i) + L":\\";
            if (!(GetDriveTypeW(label.c_str()) & DRIVE_REMOTE))
                continue;

            auto buf = new wchar_t[MAX_PATH]{};
            auto size = (DWORD) MAX_PATH;
            if (WNetGetUniversalNameW(label.c_str(), UNIVERSAL_NAME_INFO_LEVEL, buf, &size) != NO_ERROR)
                continue;

            auto name = std::wstring(((UNIVERSAL_NAME_INFOW*)buf)->lpUniversalName);
            delete[] buf;

#define as_utf8(str) std::move(std::string(ul::String16(str.data(), str.size()).utf8().data()))

            map.emplace(as_utf8(label.substr(0, 2)), as_utf8(name));
        }

        return map;
    }

    void OpenDisk(const ul::JSObject&, const ul::JSArgs& args) {
        auto nigger = (ul::String) args[0];

        system(("explorer " + nigger).utf8().data());
    }
};

int main(int argc, char** argv) {
    if (argc == 1) {
        CoInitialize(nullptr);
        App().run();
    } else {
        auto args = std::vector<std::string>();

        for (int i = 1; i < argc; ++i) {
            args.emplace_back(argv[i]);
        }

        if (args[0] == "connect") {
            if (args.size() == 1) {
                std::cerr << "Wrong usage.\n\n\tExample: connect <label> <url> <username:optional> <password:optional>" << std::endl;
            }
            auto label = args[1];
            auto disk = args[2];
            char* username{}, *password{};
            if  (args.size() >= 5) {
                username = args[3].data();
                password = args[4].data();
            }

            auto nr = NETRESOURCE{
                    .dwType = RESOURCETYPE_DISK,
                    .lpLocalName = label.data(),
                    .lpRemoteName = disk.data(),
            };

            return WNetAddConnection2(&nr, password, username, 0);
        } else if (args[0] == "disconnect") {
            if (args.size() == 1) {
                std::cerr << "Wrong usage.\n\n\tExample: disconnect <url>" << std::endl;
            }

            return WNetCancelConnection2(args[1].data(), CONNECT_UPDATE_PROFILE, false);
        } else if (args[0] == "list") {
            auto drives = GetLogicalDrives();
            for (int i = 0; i < 26; i++) {
                if (!(drives >> i & 1)) continue;

                auto label = std::string(1, 'A' + i) + ":\\";
                if (!(GetDriveType(label.c_str()) & DRIVE_REMOTE)) continue;

                auto buf = std::string(MAX_PATH, 0);
                if (!GetVolumeInformation(label.c_str(), buf.data(), MAX_PATH, nullptr, nullptr, nullptr, nullptr, 0)) continue;

                std::cout << label << " - " << buf << std::endl;
            }
        } else if (args[0] == "open") {
            if (args.size() == 1) {
                std::cerr << "Wrong usage.\n\n\tExample: open <path>" << std::endl;
            }

            system(("explorer " + args[1]).c_str());
        } else {
            std::cerr << "Unknown command." << std::endl;
        }
    }
}
