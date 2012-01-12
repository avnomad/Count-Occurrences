#pragma once


namespace CountOccurrences {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  findLabel;
	protected: 
	private: System::Windows::Forms::TextBox^  findText;
	private: System::Windows::Forms::Label^  fileLabel;
	private: System::Windows::Forms::TextBox^  fileText;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon;
	private: System::Windows::Forms::Label^  outputLabel;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->findLabel = (gcnew System::Windows::Forms::Label());
			this->findText = (gcnew System::Windows::Forms::TextBox());
			this->fileLabel = (gcnew System::Windows::Forms::Label());
			this->fileText = (gcnew System::Windows::Forms::TextBox());
			this->notifyIcon = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->outputLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// findLabel
			// 
			this->findLabel->AutoSize = true;
			this->findLabel->Location = System::Drawing::Point(12, 3);
			this->findLabel->Name = L"findLabel";
			this->findLabel->Size = System::Drawing::Size(59, 13);
			this->findLabel->TabIndex = 0;
			this->findLabel->Text = L"text to find:";
			this->findLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// findText
			// 
			this->findText->Location = System::Drawing::Point(12, 19);
			this->findText->Name = L"findText";
			this->findText->Size = System::Drawing::Size(288, 20);
			this->findText->TabIndex = 1;
			// 
			// fileLabel
			// 
			this->fileLabel->AutoSize = true;
			this->fileLabel->Location = System::Drawing::Point(12, 42);
			this->fileLabel->Name = L"fileLabel";
			this->fileLabel->Size = System::Drawing::Size(81, 13);
			this->fileLabel->TabIndex = 2;
			this->fileLabel->Text = L"file to search in:";
			this->fileLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// fileText
			// 
			this->fileText->Location = System::Drawing::Point(12, 58);
			this->fileText->Name = L"fileText";
			this->fileText->Size = System::Drawing::Size(288, 20);
			this->fileText->TabIndex = 3;
			// 
			// notifyIcon
			// 
			this->notifyIcon->BalloonTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			this->notifyIcon->BalloonTipText = L"This program counts the number of occurrences of a given string in a file.";
			this->notifyIcon->BalloonTipTitle = L"count occurrences";
			this->notifyIcon->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"notifyIcon.Icon")));
			this->notifyIcon->Text = L"Running";
			this->notifyIcon->Visible = true;
			this->notifyIcon->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::notifyIcon_MouseMove);
			// 
			// outputLabel
			// 
			this->outputLabel->AutoSize = true;
			this->outputLabel->Location = System::Drawing::Point(12, 91);
			this->outputLabel->Name = L"outputLabel";
			this->outputLabel->Size = System::Drawing::Size(171, 13);
			this->outputLabel->TabIndex = 4;
			this->outputLabel->Text = L"Press enter to commence search...";
			this->outputLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(312, 113);
			this->Controls->Add(this->outputLabel);
			this->Controls->Add(this->fileText);
			this->Controls->Add(this->fileLabel);
			this->Controls->Add(this->findText);
			this->Controls->Add(this->findLabel);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->MaximumSize = System::Drawing::Size(60000000, 140);
			this->MinimumSize = System::Drawing::Size(240, 140);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Count Occurrences";
			this->SizeChanged += gcnew System::EventHandler(this, &Form1::Form1_SizeChanged);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 if(e->KeyChar == '\033')
					 exit(0);
				 else if(e->KeyChar == '\r')
				 {
					 FILE *searchFile;
					 int c;
					 const char *p;
					 unsigned int count = 0;
					 const char  *searchFileName;
					 const char *searchString;
					
					 outputLabel->Text = "Counting occurrences of the string \"";
					 outputLabel->Text += findText->Text;
					 outputLabel->Text += "\" in the file \"";
					 outputLabel->Text += fileText->Text;
					 outputLabel->Text += "\"...";

					 searchString = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(findText->Text)).ToPointer();
					 searchFileName = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(fileText->Text)).ToPointer();

					 if(searchFile = fopen(searchFileName,"r"))
					 {
						 p = searchString;
						 while((c = fgetc(searchFile)) != EOF)
						 {
							 if(*p == c)
							 {
								 p++;
								 if(!*p)
								 {
									 p = searchString;
									 count++;
								 }
							 }
							 else
								 p = searchString;
						 }
						 outputLabel->Text = "";
						 outputLabel->Text += count;
						 outputLabel->Text += " occurrences of the string \"";
						 outputLabel->Text += findText->Text;
						 outputLabel->Text += "\" were found.";
						 //in the file \""<<argv[2]<<'\"'<<endl;
						 fclose(searchFile);
					 }
					 else
						 outputLabel->Text = "Error opening the file!";
					 Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)searchString));
					 Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)searchFileName));
					 
				 }
			 }
	private: System::Void Form1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
				 findText->Width = Form1::Width - 32;
				 fileText->Width = Form1::Width - 32;
			 }
private: System::Void notifyIcon_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 notifyIcon->ShowBalloonTip(2000);
		 }
};
}

