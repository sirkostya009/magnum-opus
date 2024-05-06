#pragma once

#include "frmAbout.h"
#include <iostream>
#include <map>
#include <windows.h>
#include <winnetwk.h>
#include <msclr/marshal.h>

#pragma comment(lib, "mpr.lib")

std::map<std::wstring, std::wstring> ListValidDrives() {
	auto map = std::map<std::wstring, std::wstring>();
	auto drives = GetLogicalDrives();

	for (int i = 0; i < 26; i++) {
		if (!(drives >> i & 1)) continue;

		auto label = std::wstring(1, 'A' + i) + L":\\";
		if (!(GetDriveTypeW(label.c_str()) & DRIVE_REMOTE))
			continue;

		auto buf = new wchar_t[MAX_PATH] {};
		auto size = (DWORD)MAX_PATH;
		if (WNetGetUniversalName(label.c_str(), UNIVERSAL_NAME_INFO_LEVEL, buf, &size) != NO_ERROR)
			continue;

		auto name = std::wstring(((UNIVERSAL_NAME_INFOW*)buf)->lpUniversalName);
		delete[] buf;

		map.emplace(label.substr(0, 2), name);
	}

	return map;
}


namespace OSmetod {

	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		frmMain(void)
		{
			InitializeComponent();
			frmabout = gcnew frmAbout();
		}
	protected:
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ topMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ topMenuFileItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tmFileConnect;


	private: System::Windows::Forms::ToolStripMenuItem^ tmFileDisconnect;

	protected:





	protected:

	protected:




	private: System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ tmFileExit;









	private: System::Windows::Forms::ToolStripMenuItem^ tmsiInfo;
	private: System::Windows::Forms::ToolStripMenuItem^ tmInfoHelp;
	private: System::Windows::Forms::ToolStripMenuItem^ tmInfoAbout;










	private: System::Windows::Forms::ToolStrip^ tsMain;
	private: System::Windows::Forms::ToolStripButton^ tsbNew;
	private: System::Windows::Forms::ToolStripButton^ tsbOpen;
	private: System::Windows::Forms::ToolStripButton^ tsbSave;




	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^ executeButton;





	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripButton^ tsbAbout;

	private: System::Windows::Forms::ImageList^ imageList1;




























	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;


	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip2;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip3;






























private: System::Windows::Forms::StatusStrip^ statusStrip;

private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
private: System::Windows::Forms::ToolStripProgressBar^ statusProgress;
private: System::Windows::Forms::ToolStripStatusLabel^ statusMainLabel;
private: System::Windows::Forms::Panel^ resultPanel;
private: System::Windows::Forms::ToolStrip^ toolStrip2;

private: System::Windows::Forms::Panel^ mainPanel;
private: System::Windows::Forms::ListView^ disksList;

private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::TextBox^ labelBox;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TextBox^ linkBox;

private: System::Windows::Forms::TextBox^ loginBox;

private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::TextBox^ passwordBox;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::CheckBox^ autoConnect;

private: System::Windows::Forms::CheckBox^ remember;
private: System::Windows::Forms::Button^ connectButton;
private: System::Windows::Forms::ColumnHeader^ мітка;
private: System::Windows::Forms::ColumnHeader^ назва;
private: System::Windows::Forms::ColumnHeader^ columnHeader1;







































	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			this->topMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->topMenuFileItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmFileConnect = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmFileDisconnect = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tmFileExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmsiInfo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmInfoHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmInfoAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsMain = (gcnew System::Windows::Forms::ToolStrip());
			this->tsbNew = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsbOpen = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsbSave = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->executeButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tsbAbout = (gcnew System::Windows::Forms::ToolStripButton());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuStrip2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuStrip3 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->statusProgress = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->statusMainLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->resultPanel = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->connectButton = (gcnew System::Windows::Forms::Button());
			this->autoConnect = (gcnew System::Windows::Forms::CheckBox());
			this->remember = (gcnew System::Windows::Forms::CheckBox());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->loginBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->linkBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelBox = (gcnew System::Windows::Forms::TextBox());
			this->disksList = (gcnew System::Windows::Forms::ListView());
			this->мітка = (gcnew System::Windows::Forms::ColumnHeader());
			this->назва = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->topMenu->SuspendLayout();
			this->tsMain->SuspendLayout();
			this->statusStrip->SuspendLayout();
			this->resultPanel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->mainPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// topMenu
			// 
			this->topMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->topMenuFileItem, this->tmsiInfo });
			this->topMenu->Location = System::Drawing::Point(0, 0);
			this->topMenu->Name = L"topMenu";
			this->topMenu->Size = System::Drawing::Size(570, 24);
			this->topMenu->TabIndex = 0;
			this->topMenu->Text = L"menuStrip1";
			// 
			// topMenuFileItem
			// 
			this->topMenuFileItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->tmFileConnect,
					this->tmFileDisconnect, this->toolStripMenuItem1, this->tmFileExit
			});
			this->topMenuFileItem->Name = L"topMenuFileItem";
			this->topMenuFileItem->Size = System::Drawing::Size(48, 20);
			this->topMenuFileItem->Text = L"Файл";
			// 
			// tmFileConnect
			// 
			this->tmFileConnect->Name = L"tmFileConnect";
			this->tmFileConnect->Size = System::Drawing::Size(180, 22);
			this->tmFileConnect->Text = L"Підключити диск";
			this->tmFileConnect->Click += gcnew System::EventHandler(this, &frmMain::tmFileConnect_Click);
			// 
			// tmFileDisconnect
			// 
			this->tmFileDisconnect->Name = L"tmFileDisconnect";
			this->tmFileDisconnect->Size = System::Drawing::Size(180, 22);
			this->tmFileDisconnect->Text = L"Відключити диск";
			this->tmFileDisconnect->Click += gcnew System::EventHandler(this, &frmMain::tmFileDisconnect_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(177, 6);
			// 
			// tmFileExit
			// 
			this->tmFileExit->Name = L"tmFileExit";
			this->tmFileExit->Size = System::Drawing::Size(180, 22);
			this->tmFileExit->Text = L"Закрити";
			this->tmFileExit->Click += gcnew System::EventHandler(this, &frmMain::tsbexit_Click);
			// 
			// tmsiInfo
			// 
			this->tmsiInfo->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tmInfoHelp,
					this->tmInfoAbout
			});
			this->tmsiInfo->Name = L"tmsiInfo";
			this->tmsiInfo->Size = System::Drawing::Size(42, 20);
			this->tmsiInfo->Text = L"Про";
			// 
			// tmInfoHelp
			// 
			this->tmInfoHelp->Name = L"tmInfoHelp";
			this->tmInfoHelp->Size = System::Drawing::Size(161, 22);
			this->tmInfoHelp->Text = L"Допомога";
			// 
			// tmInfoAbout
			// 
			this->tmInfoAbout->Name = L"tmInfoAbout";
			this->tmInfoAbout->Size = System::Drawing::Size(161, 22);
			this->tmInfoAbout->Text = L"Про застосунок";
			this->tmInfoAbout->Click += gcnew System::EventHandler(this, &frmMain::tmsiAbout_Click);
			// 
			// tsMain
			// 
			this->tsMain->ImageScalingSize = System::Drawing::Size(32, 32);
			this->tsMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->tsbNew, this->tsbOpen,
					this->tsbSave, this->toolStripSeparator1, this->executeButton, this->toolStripSeparator2, this->tsbAbout
			});
			this->tsMain->Location = System::Drawing::Point(0, 24);
			this->tsMain->Name = L"tsMain";
			this->tsMain->Size = System::Drawing::Size(570, 39);
			this->tsMain->TabIndex = 1;
			// 
			// tsbNew
			// 
			this->tsbNew->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsbNew->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbNew.Image")));
			this->tsbNew->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbNew->Name = L"tsbNew";
			this->tsbNew->Size = System::Drawing::Size(36, 36);
			this->tsbNew->Text = L"New";
			this->tsbNew->Click += gcnew System::EventHandler(this, &frmMain::tsbNew_Click);
			this->tsbNew->MouseEnter += gcnew System::EventHandler(this, &frmMain::tsbNew_MouseEnter);
			this->tsbNew->MouseLeave += gcnew System::EventHandler(this, &frmMain::tsbNew_MouseLeave);
			// 
			// tsbOpen
			// 
			this->tsbOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsbOpen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbOpen.Image")));
			this->tsbOpen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbOpen->Name = L"tsbOpen";
			this->tsbOpen->Size = System::Drawing::Size(36, 36);
			this->tsbOpen->Text = L"toolStripButton4";
			this->tsbOpen->Click += gcnew System::EventHandler(this, &frmMain::tsbOpen_Click);
			// 
			// tsbSave
			// 
			this->tsbSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsbSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbSave.Image")));
			this->tsbSave->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbSave->Name = L"tsbSave";
			this->tsbSave->Size = System::Drawing::Size(36, 36);
			this->tsbSave->Text = L"toolStripButton3";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 39);
			// 
			// executeButton
			// 
			this->executeButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->executeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"executeButton.Image")));
			this->executeButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->executeButton->Name = L"executeButton";
			this->executeButton->Size = System::Drawing::Size(36, 36);
			this->executeButton->Text = L"Execute";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 39);
			// 
			// tsbAbout
			// 
			this->tsbAbout->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsbAbout->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbAbout.Image")));
			this->tsbAbout->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->tsbAbout->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbAbout->Name = L"tsbAbout";
			this->tsbAbout->Size = System::Drawing::Size(36, 36);
			this->tsbAbout->Text = L"toolStripButton1";
			this->tsbAbout->Click += gcnew System::EventHandler(this, &frmMain::tmsiAbout_Click);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"document_empty.png");
			this->imageList1->Images->SetKeyName(1, L"folder.png");
			this->imageList1->Images->SetKeyName(2, L"disk.png");
			this->imageList1->Images->SetKeyName(3, L"control_play_blue.png");
			this->imageList1->Images->SetKeyName(4, L"control_stop_blue.png");
			this->imageList1->Images->SetKeyName(5, L"information.png");
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// contextMenuStrip2
			// 
			this->contextMenuStrip2->Name = L"contextMenuStrip2";
			this->contextMenuStrip2->Size = System::Drawing::Size(61, 4);
			// 
			// contextMenuStrip3
			// 
			this->contextMenuStrip3->Name = L"contextMenuStrip3";
			this->contextMenuStrip3->Size = System::Drawing::Size(61, 4);
			// 
			// statusStrip
			// 
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripStatusLabel1,
					this->statusProgress, this->statusMainLabel
			});
			this->statusStrip->Location = System::Drawing::Point(0, 478);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(570, 26);
			this->statusStrip->TabIndex = 5;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(52, 21);
			this->toolStripStatusLabel1->Text = L"Progress";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &frmMain::toolStripStatusLabel1_Click);
			// 
			// statusProgress
			// 
			this->statusProgress->Name = L"statusProgress";
			this->statusProgress->Overflow = System::Windows::Forms::ToolStripItemOverflow::Never;
			this->statusProgress->Size = System::Drawing::Size(250, 20);
			// 
			// statusMainLabel
			// 
			this->statusMainLabel->Name = L"statusMainLabel";
			this->statusMainLabel->Size = System::Drawing::Size(0, 21);
			// 
			// resultPanel
			// 
			this->resultPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->resultPanel->Controls->Add(this->panel1);
			this->resultPanel->Controls->Add(this->disksList);
			this->resultPanel->Controls->Add(this->toolStrip2);
			this->resultPanel->Location = System::Drawing::Point(-514, 0);
			this->resultPanel->Name = L"resultPanel";
			this->resultPanel->Size = System::Drawing::Size(1084, 441);
			this->resultPanel->TabIndex = 2;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->connectButton);
			this->panel1->Controls->Add(this->autoConnect);
			this->panel1->Controls->Add(this->remember);
			this->panel1->Controls->Add(this->passwordBox);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->loginBox);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->linkBox);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->labelBox);
			this->panel1->Location = System::Drawing::Point(519, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(250, 409);
			this->panel1->TabIndex = 3;
			// 
			// connectButton
			// 
			this->connectButton->Location = System::Drawing::Point(18, 311);
			this->connectButton->Name = L"connectButton";
			this->connectButton->Size = System::Drawing::Size(75, 23);
			this->connectButton->TabIndex = 10;
			this->connectButton->Text = L"Додати";
			this->connectButton->UseVisualStyleBackColor = true;
			this->connectButton->Click += gcnew System::EventHandler(this, &frmMain::connectButton_Click);
			// 
			// autoConnect
			// 
			this->autoConnect->AutoSize = true;
			this->autoConnect->Location = System::Drawing::Point(18, 271);
			this->autoConnect->Name = L"autoConnect";
			this->autoConnect->Size = System::Drawing::Size(152, 17);
			this->autoConnect->TabIndex = 9;
			this->autoConnect->Text = L"Підключати автоматично";
			this->autoConnect->UseVisualStyleBackColor = true;
			// 
			// remember
			// 
			this->remember->AutoSize = true;
			this->remember->Location = System::Drawing::Point(18, 233);
			this->remember->Name = L"remember";
			this->remember->Size = System::Drawing::Size(89, 17);
			this->remember->TabIndex = 8;
			this->remember->Text = L"Запам\'ятати";
			this->remember->UseVisualStyleBackColor = true;
			// 
			// passwordBox
			// 
			this->passwordBox->Location = System::Drawing::Point(66, 189);
			this->passwordBox->Name = L"passwordBox";
			this->passwordBox->Size = System::Drawing::Size(100, 20);
			this->passwordBox->TabIndex = 7;
			this->passwordBox->UseSystemPasswordChar = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 192);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Пароль";
			// 
			// loginBox
			// 
			this->loginBox->Location = System::Drawing::Point(56, 147);
			this->loginBox->Name = L"loginBox";
			this->loginBox->Size = System::Drawing::Size(100, 20);
			this->loginBox->TabIndex = 5;
			this->loginBox->TextChanged += gcnew System::EventHandler(this, &frmMain::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 150);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Логін";
			this->label3->Click += gcnew System::EventHandler(this, &frmMain::label3_Click);
			// 
			// linkBox
			// 
			this->linkBox->Location = System::Drawing::Point(87, 101);
			this->linkBox->Name = L"linkBox";
			this->linkBox->Size = System::Drawing::Size(100, 20);
			this->linkBox->TabIndex = 3;
			this->linkBox->TextChanged += gcnew System::EventHandler(this, &frmMain::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Посилання";
			this->label2->Click += gcnew System::EventHandler(this, &frmMain::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Мітка";
			this->label1->Click += gcnew System::EventHandler(this, &frmMain::label1_Click_2);
			// 
			// labelBox
			// 
			this->labelBox->Location = System::Drawing::Point(56, 55);
			this->labelBox->Name = L"labelBox";
			this->labelBox->Size = System::Drawing::Size(100, 20);
			this->labelBox->TabIndex = 0;
			// 
			// disksList
			// 
			this->disksList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->мітка, this->назва,
					this->columnHeader1
			});
			this->disksList->HideSelection = false;
			this->disksList->Location = System::Drawing::Point(775, 3);
			this->disksList->Name = L"disksList";
			this->disksList->Size = System::Drawing::Size(309, 412);
			this->disksList->TabIndex = 2;
			this->disksList->UseCompatibleStateImageBehavior = false;
			this->disksList->View = System::Windows::Forms::View::Details;
			this->disksList->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::disksList_SelectedIndexChanged);
			// 
			// мітка
			// 
			this->мітка->Text = L"мітка";
			// 
			// назва
			// 
			this->назва->Text = L"назва";
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"";
			// 
			// toolStrip2
			// 
			this->toolStrip2->Location = System::Drawing::Point(0, 0);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(1084, 25);
			this->toolStrip2->TabIndex = 1;
			this->toolStrip2->Text = L"toolStrip2";
			this->toolStrip2->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &frmMain::toolStrip2_ItemClicked);
			// 
			// mainPanel
			// 
			this->mainPanel->Controls->Add(this->resultPanel);
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->Location = System::Drawing::Point(0, 63);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(570, 441);
			this->mainPanel->TabIndex = 4;
			// 
			// frmMain
			// 
			this->ClientSize = System::Drawing::Size(570, 504);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->tsMain);
			this->Controls->Add(this->topMenu);
			this->MainMenuStrip = this->topMenu;
			this->Name = L"frmMain";
			this->Text = L"Magnum Opus";
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->topMenu->ResumeLayout(false);
			this->topMenu->PerformLayout();
			this->tsMain->ResumeLayout(false);
			this->tsMain->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->resultPanel->ResumeLayout(false);
			this->resultPanel->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->mainPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: frmAbout^ frmabout;

	private: System::Void tmsiAbout_Click(System::Object^ sender, System::EventArgs^ e) {
		frmabout->ShowDialog();
	}
private: void doprogress(float value) {
	if (statusProgress->Value != (int)value) statusProgress->Value = int(value);
	Application::DoEvents();
}
private: System::Void tsbNew_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tsbexit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void tsbInfo_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Information");
}
private: System::Void lvMain_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void frmMain_Load(System::Object^ sender, System::EventArgs^ e) {
	auto drives = ListValidDrives();
	for (auto& pair : drives) {
		auto label = pair.first;
		auto name = pair.second;
		auto item = gcnew ListViewItem();
		item->Text = gcnew System::String(label.c_str());
		item->SubItems->Add(gcnew System::String(name.c_str()));
		disksList->Items->Add(item);
	}
}
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tspMain_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void scView_Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void scView_Panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void tslInfo_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void toolStripComboBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void toolStripStatusLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void tsbNew_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		statusMainLabel->Text = "Create new file with initial data";
	}
	private: System::Void tsbNew_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		statusMainLabel->Text = "";
	}
private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void connectButton_Click(System::Object^ sender, System::EventArgs^ e) {
	auto label = labelBox->Text;
	auto path = linkBox->Text;
	auto user = loginBox->Text;
	auto password = passwordBox->Text;
	auto flags = 0;

	auto asd = Marshal::StringToHGlobalUni(label);
	auto ptr = (wchar_t*) asd.ToPointer();
	auto asd2 = Marshal::StringToHGlobalUni(path);
	auto ptr2 = (wchar_t*) asd2.ToPointer();

	if (autoConnect->Checked) flags |= 0x1;
	if (remember->Checked) flags |= 0x2;

	auto nr = NETRESOURCE{};
	nr.dwType = RESOURCETYPE_DISK;
	nr.lpLocalName = ptr;
	nr.lpRemoteName = ptr2;

	asd = Marshal::StringToHGlobalUni(user);
	ptr = (wchar_t*) asd.ToPointer();
	asd2 = Marshal::StringToHGlobalUni(password);
	ptr2 = (wchar_t*) asd2.ToPointer();

	auto dwResult = WNetAddConnection2(
		&nr,
		password->Empty ? nullptr : ptr,
		user->Empty ? nullptr : ptr2,
		flags
	);

	if (dwResult != NO_ERROR) {
		MessageBox::Show("Error: " + dwResult);
		return;
	}

	auto item = gcnew ListViewItem();
	item->Text = label;
	item->SubItems->Add(path);
	disksList->Items->Add(item);
}
private: System::Void toolStrip2_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void tmFileDisconnect_Click(System::Object^ sender, System::EventArgs^ e) {
	// get selected item
	auto item = disksList->SelectedItems[0];
	auto label = item->Text;
	auto ptr = Marshal::StringToHGlobalUni(label);

	auto hr = WNetCancelConnection2((wchar_t*) ptr.ToPointer(), CONNECT_UPDATE_PROFILE, true);

	if (hr != NO_ERROR) {
		MessageBox::Show("Error: " + hr);
		return;
	}

	disksList->Items->Remove(item);
}
private: System::Void disksList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tmFileConnect_Click(System::Object^ sender, System::EventArgs^ e) {
	auto label = labelBox->Text;
	auto path = linkBox->Text;
	auto user = loginBox->Text;
	auto password = passwordBox->Text;
	auto flags = 0;

	auto asd = Marshal::StringToHGlobalUni(label);
	auto ptr = (wchar_t*)asd.ToPointer();
	auto asd2 = Marshal::StringToHGlobalUni(path);
	auto ptr2 = (wchar_t*)asd2.ToPointer();

	if (autoConnect->Checked) flags |= 0x1;
	if (remember->Checked) flags |= 0x2;

	auto nr = NETRESOURCE{};
	nr.dwType = RESOURCETYPE_DISK;
	nr.lpLocalName = ptr;
	nr.lpRemoteName = ptr2;

	asd = Marshal::StringToHGlobalUni(user);
	ptr = (wchar_t*)asd.ToPointer();
	asd2 = Marshal::StringToHGlobalUni(password);
	ptr2 = (wchar_t*)asd2.ToPointer();

	auto dwResult = WNetAddConnection2(
		&nr,
		password->Empty ? nullptr : ptr,
		user->Empty ? nullptr : ptr2,
		flags
	);

	if (dwResult != NO_ERROR) {
		MessageBox::Show("Error: " + dwResult);
		return;
	}

	auto item = gcnew ListViewItem();
	item->Text = label;
	item->SubItems->Add(path);
	disksList->Items->Add(item);
}
private: System::Void tsbOpen_Click(System::Object^ sender, System::EventArgs^ e) {
	// open current selected disk in explorer
	auto item = disksList->SelectedItems[0];

	auto str2 = std::string((char*) Marshal::StringToHGlobalAnsi(item->Text).ToPointer());
	
	system(("explorer " + str2).c_str());
}
};
}
