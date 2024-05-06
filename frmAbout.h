#pragma once

namespace OSmetod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmAbout
	/// </summary>
	public ref class frmAbout : public System::Windows::Forms::Form
	{
	public:
		frmAbout(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			lblVersion->Text = "Âåðñ³ÿ " + Application::ProductVersion;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmAbout()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnClose;
	protected:

	protected:
	private: System::Windows::Forms::PictureBox^ pbIcon;
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::Label^ lblVersion;
	private: System::Windows::Forms::Label^ lblAuthor;
	private: System::Windows::Forms::Label^ lblRights;
	private: System::Windows::Forms::GroupBox^ gbInfo;
	private: System::Windows::Forms::Label^ lblInfo;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmAbout::typeid));
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->pbIcon = (gcnew System::Windows::Forms::PictureBox());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->lblVersion = (gcnew System::Windows::Forms::Label());
			this->lblAuthor = (gcnew System::Windows::Forms::Label());
			this->lblRights = (gcnew System::Windows::Forms::Label());
			this->gbInfo = (gcnew System::Windows::Forms::GroupBox());
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbIcon))->BeginInit();
			this->gbInfo->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnClose->Location = System::Drawing::Point(153, 333);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"Закрити";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmAbout::btnClose_Click);
			// 
			// pbIcon
			// 
			this->pbIcon->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbIcon.ErrorImage")));
			this->pbIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbIcon.Image")));
			this->pbIcon->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbIcon.InitialImage")));
			this->pbIcon->Location = System::Drawing::Point(25, 28);
			this->pbIcon->Name = L"pbIcon";
			this->pbIcon->Size = System::Drawing::Size(128, 128);
			this->pbIcon->TabIndex = 1;
			this->pbIcon->TabStop = false;
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblName->Location = System::Drawing::Point(178, 28);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(72, 13);
			this->lblName->TabIndex = 2;
			this->lblName->Text = L"Магнум Опус";
			this->lblName->Click += gcnew System::EventHandler(this, &frmAbout::lblName_Click);
			// 
			// lblVersion
			// 
			this->lblVersion->AutoSize = true;
			this->lblVersion->Location = System::Drawing::Point(178, 57);
			this->lblVersion->Name = L"lblVersion";
			this->lblVersion->Size = System::Drawing::Size(91, 13);
			this->lblVersion->TabIndex = 3;
			this->lblVersion->Text = L"Версія: 1.0.0";
			// 
			// lblAuthor
			// 
			this->lblAuthor->AutoSize = true;
			this->lblAuthor->Location = System::Drawing::Point(178, 87);
			this->lblAuthor->Name = L"lblAuthor";
			this->lblAuthor->Size = System::Drawing::Size(261, 13);
			this->lblAuthor->TabIndex = 4;
			this->lblAuthor->Text = L"Розробник: ст. гр. ПІ-21б ПІБ";
			this->lblAuthor->Click += gcnew System::EventHandler(this, &frmAbout::label1_Click);
			// 
			// lblRights
			// 
			this->lblRights->AutoSize = true;
			this->lblRights->Location = System::Drawing::Point(178, 115);
			this->lblRights->Name = L"lblRights";
			this->lblRights->Size = System::Drawing::Size(104, 13);
			this->lblRights->TabIndex = 5;
			this->lblRights->Text = L"Всі права захищені";
			// 
			// gbInfo
			// 
			this->gbInfo->Controls->Add(this->lblInfo);
			this->gbInfo->Location = System::Drawing::Point(25, 162);
			this->gbInfo->Name = L"gbInfo";
			this->gbInfo->Size = System::Drawing::Size(411, 149);
			this->gbInfo->TabIndex = 7;
			this->gbInfo->TabStop = false;
			// 
			// lblInfo
			// 
			this->lblInfo->AutoSize = true;
			this->lblInfo->Location = System::Drawing::Point(11, 22);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(357, 104);
			this->lblInfo->TabIndex = 7;
			this->lblInfo->Text = resources->GetString(L"lblInfo.Text");
			// 
			// frmAbout
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(448, 368);
			this->Controls->Add(this->gbInfo);
			this->Controls->Add(this->lblRights);
			this->Controls->Add(this->lblAuthor);
			this->Controls->Add(this->lblVersion);
			this->Controls->Add(this->lblName);
			this->Controls->Add(this->pbIcon);
			this->Controls->Add(this->btnClose);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"frmAbout";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Ïðî çàñòîñóíîê";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmAbout::frmAbout_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbIcon))->EndInit();
			this->gbInfo->ResumeLayout(false);
			this->gbInfo->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void frmAbout_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	e->Cancel = true;
	Hide();
}
private: System::Void lblName_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
