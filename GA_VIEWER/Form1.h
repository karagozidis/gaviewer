#pragma once

#include "OpenGl.h"
#include "GeneticAlgorithm.h"
#include "StartValues.h"
#include "Parser.h"

namespace GA_VIEWER {

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
	private:
		OpenGL^ openGL_ ;
	private: Ascend::Windows::Forms::NavigationPanePage^  navigationPanePage3;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: Ascend::Windows::Forms::NavigationPanePage^  navigationPanePage4;
	private: Ascend::Windows::Forms::GradientPanel^  gradientPanel2;
	private: Ascend::Windows::Forms::GradientPanel^  gradientPanel1;
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::RichTextBox^  stepInfoRichTextBox;
	private: 

	private: Ascend::Windows::Forms::GradientPanel^  gradientPanel4;
	public: System::Windows::Forms::RichTextBox^  generationInfoRichTextBox;
	private: 
	public: 

	private: 
	private: Ascend::Windows::Forms::GradientPanel^  gradientPanel3;
	public: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::Label^  GenerationLabel;
	private: System::Windows::Forms::Label^  ChosenAtomLabel;












	private: 

	public:
		bool isGAPlayerPaused_ ; 

	public:
		Form1(void)
		{
			InitializeComponent();
	
			this->SellectionMethodComboBox->SelectedIndex=0;
			openGL_ = gcnew OpenGL(this, this->Width-377 , this->Height-88 );
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
	private: System::Windows::Forms::Timer^  openglRenderTimer;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: Ascend::Windows::Forms::NavigationPane^  navigationPane1;
	private: Ascend::Windows::Forms::NavigationPanePage^  navigationPanePage2;


	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::ComboBox^  SellectionMethodComboBox;







	private: System::Windows::Forms::Button^  stopGAButton;
	private: System::Windows::Forms::Button^  pauseGAButton;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  startGAButton;
	private: System::Windows::Forms::NumericUpDown^  stepMSecUpDown;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::NumericUpDown^  MutationProbUpDown;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  CrossoverProbUpDown;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::NumericUpDown^  CrossoverPosUpDown;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::NumericUpDown^  TotalGenUpDown;
	private: System::Windows::Forms::NumericUpDown^  BitsUpDown;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::NumericUpDown^  TotalPopUpDown;
	private: Ascend::Windows::Forms::NavigationPanePage^  navigationPanePage1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  FxTextBox;

	private: Ascend::Windows::Forms::GradientLine^  gradientLine4;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Button^  ZoomOutButton;
	private: System::Windows::Forms::Button^  UpButton;
	private: System::Windows::Forms::Button^  ZoomInButton;
	private: System::Windows::Forms::Button^  DownButton;
	private: System::Windows::Forms::Button^  LeftButton;
	private: System::Windows::Forms::Button^  RightButton;

	private: System::Windows::Forms::TextBox^  XToTextBox;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Button^  PaintGraphButton;
	private: System::Windows::Forms::TextBox^  YFromTextBox;

	private: System::Windows::Forms::TextBox^  XFromTextBox;
	private: System::Windows::Forms::TextBox^  YToTextBox;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;

	private: Ascend::Windows::Forms::GradientLine^  gradientLine1;
	private: System::Windows::Forms::Timer^  GaStepTimer;

























































	protected: 
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
			this->openglRenderTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->navigationPane1 = (gcnew Ascend::Windows::Forms::NavigationPane());
			this->navigationPanePage1 = (gcnew Ascend::Windows::Forms::NavigationPanePage());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->FxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->gradientLine4 = (gcnew Ascend::Windows::Forms::GradientLine());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->ZoomOutButton = (gcnew System::Windows::Forms::Button());
			this->UpButton = (gcnew System::Windows::Forms::Button());
			this->ZoomInButton = (gcnew System::Windows::Forms::Button());
			this->DownButton = (gcnew System::Windows::Forms::Button());
			this->LeftButton = (gcnew System::Windows::Forms::Button());
			this->RightButton = (gcnew System::Windows::Forms::Button());
			this->XToTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->PaintGraphButton = (gcnew System::Windows::Forms::Button());
			this->YFromTextBox = (gcnew System::Windows::Forms::TextBox());
			this->XFromTextBox = (gcnew System::Windows::Forms::TextBox());
			this->YToTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->navigationPanePage3 = (gcnew Ascend::Windows::Forms::NavigationPanePage());
			this->gradientPanel2 = (gcnew Ascend::Windows::Forms::GradientPanel());
			this->stepInfoRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->gradientPanel1 = (gcnew Ascend::Windows::Forms::GradientPanel());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->navigationPanePage4 = (gcnew Ascend::Windows::Forms::NavigationPanePage());
			this->gradientPanel4 = (gcnew Ascend::Windows::Forms::GradientPanel());
			this->generationInfoRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->gradientPanel3 = (gcnew Ascend::Windows::Forms::GradientPanel());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->navigationPanePage2 = (gcnew Ascend::Windows::Forms::NavigationPanePage());
			this->gradientLine1 = (gcnew Ascend::Windows::Forms::GradientLine());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->SellectionMethodComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->stopGAButton = (gcnew System::Windows::Forms::Button());
			this->pauseGAButton = (gcnew System::Windows::Forms::Button());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->startGAButton = (gcnew System::Windows::Forms::Button());
			this->stepMSecUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->MutationProbUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->CrossoverProbUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->CrossoverPosUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->TotalGenUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->BitsUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->TotalPopUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->GaStepTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->GenerationLabel = (gcnew System::Windows::Forms::Label());
			this->ChosenAtomLabel = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->navigationPane1->SuspendLayout();
			this->navigationPanePage1->SuspendLayout();
			this->navigationPanePage3->SuspendLayout();
			this->gradientPanel2->SuspendLayout();
			this->gradientPanel1->SuspendLayout();
			this->navigationPanePage4->SuspendLayout();
			this->gradientPanel4->SuspendLayout();
			this->gradientPanel3->SuspendLayout();
			this->navigationPanePage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stepMSecUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MutationProbUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CrossoverProbUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CrossoverPosUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TotalGenUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BitsUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TotalPopUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// openglRenderTimer
			// 
			this->openglRenderTimer->Enabled = true;
			this->openglRenderTimer->Interval = 10;
			this->openglRenderTimer->Tick += gcnew System::EventHandler(this, &Form1::openglRenderTimer_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1043, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->closeToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1043, 64);
			this->panel1->TabIndex = 3;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 658);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1043, 22);
			this->statusStrip1->TabIndex = 5;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// navigationPane1
			// 
			this->navigationPane1->ButtonActiveGradientHighColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->navigationPane1->ButtonActiveGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPane1->ButtonBorderColor = System::Drawing::SystemColors::MenuHighlight;
			this->navigationPane1->ButtonFont = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold));
			this->navigationPane1->ButtonForeColor = System::Drawing::SystemColors::ControlText;
			this->navigationPane1->ButtonGradientHighColor = System::Drawing::SystemColors::ButtonHighlight;
			this->navigationPane1->ButtonGradientLowColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->navigationPane1->ButtonHighlightGradientHighColor = System::Drawing::Color::White;
			this->navigationPane1->ButtonHighlightGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPane1->CaptionBorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->navigationPane1->CaptionFont = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold));
			this->navigationPane1->CaptionForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->navigationPane1->CaptionGradientHighColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->navigationPane1->CaptionGradientLowColor = System::Drawing::SystemColors::ActiveCaption;
			this->navigationPane1->Controls->Add(this->navigationPanePage3);
			this->navigationPane1->Controls->Add(this->navigationPanePage1);
			this->navigationPane1->Controls->Add(this->navigationPanePage4);
			this->navigationPane1->Controls->Add(this->navigationPanePage2);
			this->navigationPane1->Cursor = System::Windows::Forms::Cursors::Default;
			this->navigationPane1->Dock = System::Windows::Forms::DockStyle::Left;
			this->navigationPane1->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->navigationPane1->FooterGradientHighColor = System::Drawing::SystemColors::ButtonHighlight;
			this->navigationPane1->FooterGradientLowColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->navigationPane1->FooterHeight = 30;
			this->navigationPane1->FooterHighlightGradientHighColor = System::Drawing::Color::White;
			this->navigationPane1->FooterHighlightGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPane1->Location = System::Drawing::Point(0, 88);
			this->navigationPane1->Name = L"navigationPane1";
			this->navigationPane1->NavigationPages->AddRange(gcnew cli::array< Ascend::Windows::Forms::NavigationPanePage^  >(4) {this->navigationPanePage1, 
				this->navigationPanePage2, this->navigationPanePage3, this->navigationPanePage4});
			this->navigationPane1->RenderMode = Ascend::Windows::Forms::RenderMode::Glass;
			this->navigationPane1->Size = System::Drawing::Size(377, 570);
			this->navigationPane1->TabIndex = 6;
			this->navigationPane1->VisibleButtonCount = 4;
			// 
			// navigationPanePage1
			// 
			this->navigationPanePage1->ActiveGradientHighColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->navigationPanePage1->ActiveGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPanePage1->AutoScroll = true;
			this->navigationPanePage1->ButtonFont = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold));
			this->navigationPanePage1->ButtonForeColor = System::Drawing::SystemColors::ControlText;
			this->navigationPanePage1->Controls->Add(this->checkBox1);
			this->navigationPanePage1->Controls->Add(this->checkBox2);
			this->navigationPanePage1->Controls->Add(this->checkBox3);
			this->navigationPanePage1->Controls->Add(this->label12);
			this->navigationPanePage1->Controls->Add(this->FxTextBox);
			this->navigationPanePage1->Controls->Add(this->gradientLine4);
			this->navigationPanePage1->Controls->Add(this->label9);
			this->navigationPanePage1->Controls->Add(this->label11);
			this->navigationPanePage1->Controls->Add(this->ZoomOutButton);
			this->navigationPanePage1->Controls->Add(this->UpButton);
			this->navigationPanePage1->Controls->Add(this->ZoomInButton);
			this->navigationPanePage1->Controls->Add(this->DownButton);
			this->navigationPanePage1->Controls->Add(this->LeftButton);
			this->navigationPanePage1->Controls->Add(this->RightButton);
			this->navigationPanePage1->Controls->Add(this->XToTextBox);
			this->navigationPanePage1->Controls->Add(this->label13);
			this->navigationPanePage1->Controls->Add(this->PaintGraphButton);
			this->navigationPanePage1->Controls->Add(this->YFromTextBox);
			this->navigationPanePage1->Controls->Add(this->XFromTextBox);
			this->navigationPanePage1->Controls->Add(this->YToTextBox);
			this->navigationPanePage1->Controls->Add(this->label14);
			this->navigationPanePage1->Controls->Add(this->label15);
			this->navigationPanePage1->Controls->Add(this->label16);
			this->navigationPanePage1->Controls->Add(this->label17);
			this->navigationPanePage1->Controls->Add(this->label18);
			this->navigationPanePage1->GradientHighColor = System::Drawing::SystemColors::ButtonHighlight;
			this->navigationPanePage1->GradientLowColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->navigationPanePage1->HighlightGradientHighColor = System::Drawing::Color::White;
			this->navigationPanePage1->HighlightGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPanePage1->Image = nullptr;
			this->navigationPanePage1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->navigationPanePage1->ImageFooter = nullptr;
			this->navigationPanePage1->ImageIndex = -1;
			this->navigationPanePage1->ImageIndexFooter = -1;
			this->navigationPanePage1->ImageKey = L"";
			this->navigationPanePage1->ImageKeyFooter = L"";
			this->navigationPanePage1->ImageList = nullptr;
			this->navigationPanePage1->ImageListFooter = nullptr;
			this->navigationPanePage1->Key = L"navigationPanePage1";
			this->navigationPanePage1->Location = System::Drawing::Point(1, 27);
			this->navigationPanePage1->Name = L"navigationPanePage1";
			this->navigationPanePage1->Size = System::Drawing::Size(375, 377);
			this->navigationPanePage1->TabIndex = 0;
			this->navigationPanePage1->Text = L"Graph options";
			this->navigationPanePage1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->navigationPanePage1->ToolTipText = nullptr;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->checkBox1->Location = System::Drawing::Point(261, 274);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 128;
			this->checkBox1->Text = L"Gray graph";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->checkBox2->Location = System::Drawing::Point(261, 253);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(82, 17);
			this->checkBox2->TabIndex = 127;
			this->checkBox2->Text = L"Grain graph";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->checkBox3->Location = System::Drawing::Point(261, 232);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(92, 17);
			this->checkBox3->TabIndex = 126;
			this->checkBox3->Text = L"Lines in graph";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox3_CheckedChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label12->Location = System::Drawing::Point(66, 27);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(23, 13);
			this->label12->TabIndex = 83;
			this->label12->Text = L"Fx:";
			// 
			// FxTextBox
			// 
			this->FxTextBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->FxTextBox->Location = System::Drawing::Point(98, 27);
			this->FxTextBox->Name = L"FxTextBox";
			this->FxTextBox->Size = System::Drawing::Size(230, 21);
			this->FxTextBox->TabIndex = 82;
			// 
			// gradientLine4
			// 
			this->gradientLine4->Location = System::Drawing::Point(0, 198);
			this->gradientLine4->Name = L"gradientLine4";
			this->gradientLine4->Size = System::Drawing::Size(371, 10);
			this->gradientLine4->TabIndex = 80;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label9->Location = System::Drawing::Point(13, 330);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(213, 13);
			this->label9->TabIndex = 79;
			this->label9->Text = L"Press Ctrl+z , Ctrl+x to zoom in , zoom out";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label11->Location = System::Drawing::Point(13, 317);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(197, 13);
			this->label11->TabIndex = 78;
			this->label11->Text = L"Press Ctrl + Arrows to rotate the graph";
			// 
			// ZoomOutButton
			// 
			this->ZoomOutButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ZoomOutButton.BackgroundImage")));
			this->ZoomOutButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ZoomOutButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ZoomOutButton->Location = System::Drawing::Point(192, 262);
			this->ZoomOutButton->Name = L"ZoomOutButton";
			this->ZoomOutButton->Size = System::Drawing::Size(30, 34);
			this->ZoomOutButton->TabIndex = 77;
			this->ZoomOutButton->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->ZoomOutButton->UseVisualStyleBackColor = true;
			this->ZoomOutButton->Click += gcnew System::EventHandler(this, &Form1::ZoomOutButton_Click);
			// 
			// UpButton
			// 
			this->UpButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"UpButton.BackgroundImage")));
			this->UpButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UpButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->UpButton->Location = System::Drawing::Point(83, 228);
			this->UpButton->Name = L"UpButton";
			this->UpButton->Size = System::Drawing::Size(49, 32);
			this->UpButton->TabIndex = 73;
			this->UpButton->UseVisualStyleBackColor = true;
			this->UpButton->Click += gcnew System::EventHandler(this, &Form1::UpButton_Click);
			// 
			// ZoomInButton
			// 
			this->ZoomInButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ZoomInButton.BackgroundImage")));
			this->ZoomInButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ZoomInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ZoomInButton->ForeColor = System::Drawing::Color::DarkBlue;
			this->ZoomInButton->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->ZoomInButton->Location = System::Drawing::Point(192, 227);
			this->ZoomInButton->Name = L"ZoomInButton";
			this->ZoomInButton->Size = System::Drawing::Size(30, 33);
			this->ZoomInButton->TabIndex = 76;
			this->ZoomInButton->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->ZoomInButton->UseVisualStyleBackColor = true;
			this->ZoomInButton->Click += gcnew System::EventHandler(this, &Form1::ZoomInButton_Click);
			// 
			// DownButton
			// 
			this->DownButton->BackColor = System::Drawing::SystemColors::Window;
			this->DownButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"DownButton.BackgroundImage")));
			this->DownButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DownButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->DownButton->Location = System::Drawing::Point(83, 265);
			this->DownButton->Name = L"DownButton";
			this->DownButton->Size = System::Drawing::Size(49, 32);
			this->DownButton->TabIndex = 72;
			this->DownButton->UseVisualStyleBackColor = false;
			this->DownButton->Click += gcnew System::EventHandler(this, &Form1::DownButton_Click);
			// 
			// LeftButton
			// 
			this->LeftButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"LeftButton.BackgroundImage")));
			this->LeftButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->LeftButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->LeftButton->Location = System::Drawing::Point(43, 237);
			this->LeftButton->Name = L"LeftButton";
			this->LeftButton->Size = System::Drawing::Size(34, 48);
			this->LeftButton->TabIndex = 75;
			this->LeftButton->UseVisualStyleBackColor = true;
			this->LeftButton->Click += gcnew System::EventHandler(this, &Form1::LeftButton_Click);
			// 
			// RightButton
			// 
			this->RightButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"RightButton.BackgroundImage")));
			this->RightButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->RightButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->RightButton->Location = System::Drawing::Point(138, 237);
			this->RightButton->Name = L"RightButton";
			this->RightButton->Size = System::Drawing::Size(34, 48);
			this->RightButton->TabIndex = 74;
			this->RightButton->UseVisualStyleBackColor = true;
			this->RightButton->Click += gcnew System::EventHandler(this, &Form1::RightButton_Click);
			// 
			// XToTextBox
			// 
			this->XToTextBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->XToTextBox->Location = System::Drawing::Point(251, 65);
			this->XToTextBox->Name = L"XToTextBox";
			this->XToTextBox->Size = System::Drawing::Size(77, 21);
			this->XToTextBox->TabIndex = 61;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label13->Location = System::Drawing::Point(219, 111);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(23, 13);
			this->label13->TabIndex = 71;
			this->label13->Text = L"To:";
			// 
			// PaintGraphButton
			// 
			this->PaintGraphButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->PaintGraphButton->Location = System::Drawing::Point(251, 146);
			this->PaintGraphButton->Name = L"PaintGraphButton";
			this->PaintGraphButton->Size = System::Drawing::Size(75, 32);
			this->PaintGraphButton->TabIndex = 68;
			this->PaintGraphButton->Text = L"Paint";
			this->PaintGraphButton->UseVisualStyleBackColor = true;
			this->PaintGraphButton->Click += gcnew System::EventHandler(this, &Form1::PaintGraphButton_Click);
			// 
			// YFromTextBox
			// 
			this->YFromTextBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->YFromTextBox->Location = System::Drawing::Point(110, 105);
			this->YFromTextBox->Name = L"YFromTextBox";
			this->YFromTextBox->Size = System::Drawing::Size(77, 21);
			this->YFromTextBox->TabIndex = 62;
			// 
			// XFromTextBox
			// 
			this->XFromTextBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->XFromTextBox->Location = System::Drawing::Point(110, 66);
			this->XFromTextBox->Name = L"XFromTextBox";
			this->XFromTextBox->Size = System::Drawing::Size(77, 21);
			this->XFromTextBox->TabIndex = 60;
			// 
			// YToTextBox
			// 
			this->YToTextBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->YToTextBox->Location = System::Drawing::Point(251, 107);
			this->YToTextBox->Name = L"YToTextBox";
			this->YToTextBox->Size = System::Drawing::Size(77, 21);
			this->YToTextBox->TabIndex = 63;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label14->Location = System::Drawing::Point(70, 111);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(35, 13);
			this->label14->TabIndex = 70;
			this->label14->Text = L"From:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label15->Location = System::Drawing::Point(49, 95);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(14, 13);
			this->label15->TabIndex = 65;
			this->label15->Text = L"Y";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label16->Location = System::Drawing::Point(49, 61);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(17, 13);
			this->label16->TabIndex = 66;
			this->label16->Text = L"X ";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label17->Location = System::Drawing::Point(219, 71);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(23, 13);
			this->label17->TabIndex = 69;
			this->label17->Text = L"To:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label18->Location = System::Drawing::Point(70, 71);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(35, 13);
			this->label18->TabIndex = 67;
			this->label18->Text = L"From:";
			// 
			// navigationPanePage3
			// 
			this->navigationPanePage3->ActiveGradientHighColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->navigationPanePage3->ActiveGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPanePage3->AutoScroll = true;
			this->navigationPanePage3->ButtonFont = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold));
			this->navigationPanePage3->ButtonForeColor = System::Drawing::SystemColors::ControlText;
			this->navigationPanePage3->Controls->Add(this->gradientPanel2);
			this->navigationPanePage3->Controls->Add(this->gradientPanel1);
			this->navigationPanePage3->GradientHighColor = System::Drawing::SystemColors::ButtonHighlight;
			this->navigationPanePage3->GradientLowColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->navigationPanePage3->HighlightGradientHighColor = System::Drawing::Color::White;
			this->navigationPanePage3->HighlightGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPanePage3->Image = nullptr;
			this->navigationPanePage3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->navigationPanePage3->ImageFooter = nullptr;
			this->navigationPanePage3->ImageIndex = -1;
			this->navigationPanePage3->ImageIndexFooter = -1;
			this->navigationPanePage3->ImageKey = L"";
			this->navigationPanePage3->ImageKeyFooter = L"";
			this->navigationPanePage3->ImageList = nullptr;
			this->navigationPanePage3->ImageListFooter = nullptr;
			this->navigationPanePage3->Key = L"navigationPanePage3";
			this->navigationPanePage3->Location = System::Drawing::Point(1, 27);
			this->navigationPanePage3->Name = L"navigationPanePage3";
			this->navigationPanePage3->Size = System::Drawing::Size(375, 377);
			this->navigationPanePage3->TabIndex = 2;
			this->navigationPanePage3->Text = L"Genetic algorithm execution info";
			this->navigationPanePage3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->navigationPanePage3->ToolTipText = nullptr;
			// 
			// gradientPanel2
			// 
			this->gradientPanel2->Controls->Add(this->stepInfoRichTextBox);
			this->gradientPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gradientPanel2->Location = System::Drawing::Point(0, 0);
			this->gradientPanel2->Name = L"gradientPanel2";
			this->gradientPanel2->Size = System::Drawing::Size(375, 346);
			this->gradientPanel2->TabIndex = 1;
			// 
			// stepInfoRichTextBox
			// 
			this->stepInfoRichTextBox->AccessibleRole = System::Windows::Forms::AccessibleRole::Text;
			this->stepInfoRichTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->stepInfoRichTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->stepInfoRichTextBox->Location = System::Drawing::Point(0, 0);
			this->stepInfoRichTextBox->Name = L"stepInfoRichTextBox";
			this->stepInfoRichTextBox->ReadOnly = true;
			this->stepInfoRichTextBox->Size = System::Drawing::Size(375, 346);
			this->stepInfoRichTextBox->TabIndex = 4;
			this->stepInfoRichTextBox->TabStop = false;
			this->stepInfoRichTextBox->Text = L"";
			this->stepInfoRichTextBox->WordWrap = false;
			// 
			// gradientPanel1
			// 
			this->gradientPanel1->Controls->Add(this->checkBox4);
			this->gradientPanel1->Controls->Add(this->button1);
			this->gradientPanel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->gradientPanel1->Location = System::Drawing::Point(0, 346);
			this->gradientPanel1->Name = L"gradientPanel1";
			this->gradientPanel1->Size = System::Drawing::Size(375, 31);
			this->gradientPanel1->TabIndex = 0;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(46, 11);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(60, 17);
			this->checkBox4->TabIndex = 6;
			this->checkBox4->Text = L"Display";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox4_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(3, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(26, 29);
			this->button1->TabIndex = 5;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// navigationPanePage4
			// 
			this->navigationPanePage4->ActiveGradientHighColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->navigationPanePage4->ActiveGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPanePage4->AutoScroll = true;
			this->navigationPanePage4->ButtonFont = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold));
			this->navigationPanePage4->ButtonForeColor = System::Drawing::SystemColors::ControlText;
			this->navigationPanePage4->Controls->Add(this->gradientPanel4);
			this->navigationPanePage4->Controls->Add(this->gradientPanel3);
			this->navigationPanePage4->GradientHighColor = System::Drawing::SystemColors::ButtonHighlight;
			this->navigationPanePage4->GradientLowColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->navigationPanePage4->HighlightGradientHighColor = System::Drawing::Color::White;
			this->navigationPanePage4->HighlightGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPanePage4->Image = nullptr;
			this->navigationPanePage4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->navigationPanePage4->ImageFooter = nullptr;
			this->navigationPanePage4->ImageIndex = -1;
			this->navigationPanePage4->ImageIndexFooter = -1;
			this->navigationPanePage4->ImageKey = L"";
			this->navigationPanePage4->ImageKeyFooter = L"";
			this->navigationPanePage4->ImageList = nullptr;
			this->navigationPanePage4->ImageListFooter = nullptr;
			this->navigationPanePage4->Key = L"navigationPanePage4";
			this->navigationPanePage4->Location = System::Drawing::Point(1, 27);
			this->navigationPanePage4->Name = L"navigationPanePage4";
			this->navigationPanePage4->Size = System::Drawing::Size(375, 377);
			this->navigationPanePage4->TabIndex = 3;
			this->navigationPanePage4->Text = L"Genetic algorithm population report";
			this->navigationPanePage4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->navigationPanePage4->ToolTipText = nullptr;
			// 
			// gradientPanel4
			// 
			this->gradientPanel4->Controls->Add(this->generationInfoRichTextBox);
			this->gradientPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gradientPanel4->Location = System::Drawing::Point(0, 0);
			this->gradientPanel4->Name = L"gradientPanel4";
			this->gradientPanel4->Size = System::Drawing::Size(375, 346);
			this->gradientPanel4->TabIndex = 2;
			// 
			// generationInfoRichTextBox
			// 
			this->generationInfoRichTextBox->AccessibleRole = System::Windows::Forms::AccessibleRole::Text;
			this->generationInfoRichTextBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->generationInfoRichTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->generationInfoRichTextBox->Location = System::Drawing::Point(0, 0);
			this->generationInfoRichTextBox->Name = L"generationInfoRichTextBox";
			this->generationInfoRichTextBox->ReadOnly = true;
			this->generationInfoRichTextBox->Size = System::Drawing::Size(375, 346);
			this->generationInfoRichTextBox->TabIndex = 5;
			this->generationInfoRichTextBox->TabStop = false;
			this->generationInfoRichTextBox->Text = L"";
			this->generationInfoRichTextBox->WordWrap = false;
			// 
			// gradientPanel3
			// 
			this->gradientPanel3->Controls->Add(this->checkBox5);
			this->gradientPanel3->Controls->Add(this->button2);
			this->gradientPanel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->gradientPanel3->Location = System::Drawing::Point(0, 346);
			this->gradientPanel3->Name = L"gradientPanel3";
			this->gradientPanel3->Size = System::Drawing::Size(375, 31);
			this->gradientPanel3->TabIndex = 1;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Checked = true;
			this->checkBox5->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox5->Location = System::Drawing::Point(46, 11);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(60, 17);
			this->checkBox5->TabIndex = 7;
			this->checkBox5->Text = L"Display";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox5_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(3, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(26, 29);
			this->button2->TabIndex = 5;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// navigationPanePage2
			// 
			this->navigationPanePage2->ActiveGradientHighColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->navigationPanePage2->ActiveGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPanePage2->AutoScroll = true;
			this->navigationPanePage2->ButtonFont = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold));
			this->navigationPanePage2->ButtonForeColor = System::Drawing::SystemColors::ControlText;
			this->navigationPanePage2->Controls->Add(this->gradientLine1);
			this->navigationPanePage2->Controls->Add(this->label24);
			this->navigationPanePage2->Controls->Add(this->SellectionMethodComboBox);
			this->navigationPanePage2->Controls->Add(this->stopGAButton);
			this->navigationPanePage2->Controls->Add(this->pauseGAButton);
			this->navigationPanePage2->Controls->Add(this->label20);
			this->navigationPanePage2->Controls->Add(this->label1);
			this->navigationPanePage2->Controls->Add(this->startGAButton);
			this->navigationPanePage2->Controls->Add(this->stepMSecUpDown);
			this->navigationPanePage2->Controls->Add(this->label2);
			this->navigationPanePage2->Controls->Add(this->label19);
			this->navigationPanePage2->Controls->Add(this->label25);
			this->navigationPanePage2->Controls->Add(this->MutationProbUpDown);
			this->navigationPanePage2->Controls->Add(this->label3);
			this->navigationPanePage2->Controls->Add(this->label4);
			this->navigationPanePage2->Controls->Add(this->CrossoverProbUpDown);
			this->navigationPanePage2->Controls->Add(this->label6);
			this->navigationPanePage2->Controls->Add(this->label7);
			this->navigationPanePage2->Controls->Add(this->CrossoverPosUpDown);
			this->navigationPanePage2->Controls->Add(this->label8);
			this->navigationPanePage2->Controls->Add(this->label21);
			this->navigationPanePage2->Controls->Add(this->TotalGenUpDown);
			this->navigationPanePage2->Controls->Add(this->BitsUpDown);
			this->navigationPanePage2->Controls->Add(this->label22);
			this->navigationPanePage2->Controls->Add(this->label23);
			this->navigationPanePage2->Controls->Add(this->TotalPopUpDown);
			this->navigationPanePage2->GradientHighColor = System::Drawing::SystemColors::ButtonHighlight;
			this->navigationPanePage2->GradientLowColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->navigationPanePage2->HighlightGradientHighColor = System::Drawing::Color::White;
			this->navigationPanePage2->HighlightGradientLowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->navigationPanePage2->Image = nullptr;
			this->navigationPanePage2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->navigationPanePage2->ImageFooter = nullptr;
			this->navigationPanePage2->ImageIndex = -1;
			this->navigationPanePage2->ImageIndexFooter = -1;
			this->navigationPanePage2->ImageKey = L"";
			this->navigationPanePage2->ImageKeyFooter = L"";
			this->navigationPanePage2->ImageList = nullptr;
			this->navigationPanePage2->ImageListFooter = nullptr;
			this->navigationPanePage2->Key = L"navigationPanePage2";
			this->navigationPanePage2->Location = System::Drawing::Point(1, 27);
			this->navigationPanePage2->Name = L"navigationPanePage2";
			this->navigationPanePage2->Size = System::Drawing::Size(375, 377);
			this->navigationPanePage2->TabIndex = 1;
			this->navigationPanePage2->Text = L"Genetic algorithm options";
			this->navigationPanePage2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->navigationPanePage2->ToolTipText = nullptr;
			// 
			// gradientLine1
			// 
			this->gradientLine1->Location = System::Drawing::Point(0, 219);
			this->gradientLine1->Name = L"gradientLine1";
			this->gradientLine1->Size = System::Drawing::Size(373, 10);
			this->gradientLine1->TabIndex = 130;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label24->Location = System::Drawing::Point(212, 40);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(89, 13);
			this->label24->TabIndex = 127;
			this->label24->Text = L"Selection method";
			// 
			// SellectionMethodComboBox
			// 
			this->SellectionMethodComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->SellectionMethodComboBox->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->SellectionMethodComboBox->FormattingEnabled = true;
			this->SellectionMethodComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Roulette sellection", L"Tournament sellection", 
				L"Rank sellection"});
			this->SellectionMethodComboBox->Location = System::Drawing::Point(242, 65);
			this->SellectionMethodComboBox->Name = L"SellectionMethodComboBox";
			this->SellectionMethodComboBox->Size = System::Drawing::Size(121, 21);
			this->SellectionMethodComboBox->TabIndex = 126;
			// 
			// stopGAButton
			// 
			this->stopGAButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"stopGAButton.BackgroundImage")));
			this->stopGAButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->stopGAButton->Enabled = false;
			this->stopGAButton->Location = System::Drawing::Point(192, 257);
			this->stopGAButton->Name = L"stopGAButton";
			this->stopGAButton->Size = System::Drawing::Size(57, 48);
			this->stopGAButton->TabIndex = 104;
			this->stopGAButton->UseVisualStyleBackColor = true;
			this->stopGAButton->Click += gcnew System::EventHandler(this, &Form1::stopGAButton_Click);
			// 
			// pauseGAButton
			// 
			this->pauseGAButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pauseGAButton.BackgroundImage")));
			this->pauseGAButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pauseGAButton->Enabled = false;
			this->pauseGAButton->Location = System::Drawing::Point(129, 257);
			this->pauseGAButton->Name = L"pauseGAButton";
			this->pauseGAButton->Size = System::Drawing::Size(57, 48);
			this->pauseGAButton->TabIndex = 103;
			this->pauseGAButton->UseVisualStyleBackColor = true;
			this->pauseGAButton->Click += gcnew System::EventHandler(this, &Form1::pauseGAButton_Click);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label20->Location = System::Drawing::Point(12, 17);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(123, 14);
			this->label20->TabIndex = 119;
			this->label20->Text = L"Genetic Algorithms";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label1->Location = System::Drawing::Point(12, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 13);
			this->label1->TabIndex = 109;
			this->label1->Text = L"Total";
			// 
			// startGAButton
			// 
			this->startGAButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"startGAButton.BackgroundImage")));
			this->startGAButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->startGAButton->Location = System::Drawing::Point(69, 257);
			this->startGAButton->Name = L"startGAButton";
			this->startGAButton->Size = System::Drawing::Size(54, 48);
			this->startGAButton->TabIndex = 102;
			this->startGAButton->UseVisualStyleBackColor = true;
			this->startGAButton->Click += gcnew System::EventHandler(this, &Form1::startGAButton_Click);
			// 
			// stepMSecUpDown
			// 
			this->stepMSecUpDown->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->stepMSecUpDown->Location = System::Drawing::Point(104, 317);
			this->stepMSecUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			this->stepMSecUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->stepMSecUpDown->Name = L"stepMSecUpDown";
			this->stepMSecUpDown->Size = System::Drawing::Size(41, 21);
			this->stepMSecUpDown->TabIndex = 105;
			this->stepMSecUpDown->Tag = L"";
			this->stepMSecUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label2->Location = System::Drawing::Point(13, 127);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 13);
			this->label2->TabIndex = 108;
			this->label2->Text = L"Bits";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label19->Location = System::Drawing::Point(214, 117);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(57, 13);
			this->label19->TabIndex = 118;
			this->label19->Text = L"Probability";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label25->Location = System::Drawing::Point(67, 325);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(36, 13);
			this->label25->TabIndex = 122;
			this->label25->Text = L"mSec:";
			// 
			// MutationProbUpDown
			// 
			this->MutationProbUpDown->DecimalPlaces = 4;
			this->MutationProbUpDown->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->MutationProbUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 262144});
			this->MutationProbUpDown->Location = System::Drawing::Point(300, 111);
			this->MutationProbUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->MutationProbUpDown->Name = L"MutationProbUpDown";
			this->MutationProbUpDown->Size = System::Drawing::Size(63, 21);
			this->MutationProbUpDown->TabIndex = 100;
			this->MutationProbUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label3->Location = System::Drawing::Point(13, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 110;
			this->label3->Text = L"Total";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label4->Location = System::Drawing::Point(214, 173);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 117;
			this->label4->Text = L"Probability";
			// 
			// CrossoverProbUpDown
			// 
			this->CrossoverProbUpDown->DecimalPlaces = 2;
			this->CrossoverProbUpDown->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->CrossoverProbUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->CrossoverProbUpDown->Location = System::Drawing::Point(302, 167);
			this->CrossoverProbUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->CrossoverProbUpDown->Name = L"CrossoverProbUpDown";
			this->CrossoverProbUpDown->Size = System::Drawing::Size(61, 21);
			this->CrossoverProbUpDown->TabIndex = 101;
			this->CrossoverProbUpDown->Tag = L"";
			this->CrossoverProbUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 131072});
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label6->Location = System::Drawing::Point(13, 161);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 13);
			this->label6->TabIndex = 111;
			this->label6->Text = L"Crossover";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label7->Location = System::Drawing::Point(13, 174);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 13);
			this->label7->TabIndex = 116;
			this->label7->Text = L"Positions";
			// 
			// CrossoverPosUpDown
			// 
			this->CrossoverPosUpDown->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->CrossoverPosUpDown->Location = System::Drawing::Point(101, 168);
			this->CrossoverPosUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			this->CrossoverPosUpDown->Name = L"CrossoverPosUpDown";
			this->CrossoverPosUpDown->Size = System::Drawing::Size(61, 21);
			this->CrossoverPosUpDown->TabIndex = 99;
			this->CrossoverPosUpDown->Tag = L"";
			this->CrossoverPosUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label8->Location = System::Drawing::Point(214, 159);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 13);
			this->label8->TabIndex = 112;
			this->label8->Text = L"Crossover ";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label21->Location = System::Drawing::Point(13, 91);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(57, 13);
			this->label21->TabIndex = 115;
			this->label21->Text = L"Population";
			// 
			// TotalGenUpDown
			// 
			this->TotalGenUpDown->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->TotalGenUpDown->Location = System::Drawing::Point(101, 48);
			this->TotalGenUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {-727379968, 232, 0, 0});
			this->TotalGenUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->TotalGenUpDown->Name = L"TotalGenUpDown";
			this->TotalGenUpDown->Size = System::Drawing::Size(61, 21);
			this->TotalGenUpDown->TabIndex = 96;
			this->TotalGenUpDown->Tag = L"";
			this->TotalGenUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			// 
			// BitsUpDown
			// 
			this->BitsUpDown->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->BitsUpDown->Location = System::Drawing::Point(101, 125);
			this->BitsUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->BitsUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->BitsUpDown->Name = L"BitsUpDown";
			this->BitsUpDown->Size = System::Drawing::Size(61, 21);
			this->BitsUpDown->TabIndex = 98;
			this->BitsUpDown->Tag = L"";
			this->BitsUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {8, 0, 0, 0});
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label22->Location = System::Drawing::Point(214, 103);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(49, 13);
			this->label22->TabIndex = 113;
			this->label22->Text = L"Mutation";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label23->Location = System::Drawing::Point(12, 54);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(65, 13);
			this->label23->TabIndex = 114;
			this->label23->Text = L"Generations";
			// 
			// TotalPopUpDown
			// 
			this->TotalPopUpDown->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->TotalPopUpDown->Location = System::Drawing::Point(101, 85);
			this->TotalPopUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			this->TotalPopUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->TotalPopUpDown->Name = L"TotalPopUpDown";
			this->TotalPopUpDown->Size = System::Drawing::Size(61, 21);
			this->TotalPopUpDown->TabIndex = 97;
			this->TotalPopUpDown->Tag = L"";
			this->TotalPopUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			// 
			// GaStepTimer
			// 
			this->GaStepTimer->Tick += gcnew System::EventHandler(this, &Form1::GaStepTimer_Tick);
			// 
			// GenerationLabel
			// 
			this->GenerationLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->GenerationLabel->AutoSize = true;
			this->GenerationLabel->BackColor = System::Drawing::SystemColors::Control;
			this->GenerationLabel->Font = (gcnew System::Drawing::Font(L"Garamond", 11));
			this->GenerationLabel->ForeColor = System::Drawing::Color::Black;
			this->GenerationLabel->Location = System::Drawing::Point(8, 661);
			this->GenerationLabel->Name = L"GenerationLabel";
			this->GenerationLabel->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->GenerationLabel->Size = System::Drawing::Size(36, 17);
			this->GenerationLabel->TabIndex = 9;
			this->GenerationLabel->Text = L"Gen:";
			this->GenerationLabel->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// ChosenAtomLabel
			// 
			this->ChosenAtomLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->ChosenAtomLabel->AutoSize = true;
			this->ChosenAtomLabel->BackColor = System::Drawing::SystemColors::Control;
			this->ChosenAtomLabel->Font = (gcnew System::Drawing::Font(L"Garamond", 10));
			this->ChosenAtomLabel->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ChosenAtomLabel->Location = System::Drawing::Point(81, 661);
			this->ChosenAtomLabel->Name = L"ChosenAtomLabel";
			this->ChosenAtomLabel->Size = System::Drawing::Size(88, 16);
			this->ChosenAtomLabel->TabIndex = 10;
			this->ChosenAtomLabel->Text = L"Selected atom:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1043, 680);
			this->Controls->Add(this->ChosenAtomLabel);
			this->Controls->Add(this->GenerationLabel);
			this->Controls->Add(this->navigationPane1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"GA VIEWER";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->navigationPane1->ResumeLayout(false);
			this->navigationPanePage1->ResumeLayout(false);
			this->navigationPanePage1->PerformLayout();
			this->navigationPanePage3->ResumeLayout(false);
			this->gradientPanel2->ResumeLayout(false);
			this->gradientPanel1->ResumeLayout(false);
			this->gradientPanel1->PerformLayout();
			this->navigationPanePage4->ResumeLayout(false);
			this->gradientPanel4->ResumeLayout(false);
			this->gradientPanel3->ResumeLayout(false);
			this->gradientPanel3->PerformLayout();
			this->navigationPanePage2->ResumeLayout(false);
			this->navigationPanePage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stepMSecUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MutationProbUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CrossoverProbUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->CrossoverPosUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TotalGenUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BitsUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TotalPopUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }

	private: System::Void openglRenderTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 UNREFERENCED_PARAMETER(sender);
			 UNREFERENCED_PARAMETER(e);
			 openGL_->Render();
			 openGL_->SwapOpenGLBuffers();
			 }

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {
		 this->openGL_->reSizeGLScene(this , this->Width-377 , this->Height-88);
		 }
private: System::Void PaintGraphButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 
 bool result = false ; 
 float xStart = 0 , xEnd = 0, yStart = 0, yEnd = 0 ;
 int readyFunctionIndex = 0   , res = 0 ; 
 ExprParser::Parser^ parser = gcnew ExprParser::Parser();

	try
   {
	  xStart = float::Parse( XFromTextBox->Text );
	  xEnd = float::Parse( XToTextBox->Text );
	  yStart = float::Parse( YFromTextBox->Text );
	  yEnd = float::Parse( YToTextBox->Text );
   }
   catch ( FormatException^ ) 
   {
       MessageBox::Show(  "Start Values Error","Error",
            MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
	   return;
   }
   catch ( Exception^  ) 
   {
       MessageBox::Show( "Name Entry Error2","Error",
            MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
	   return;
   }


   result = parser->validateExpression(this->FxTextBox->Text);


	if (result == false)
		{
		MessageBox::Show(  "Fx mathematical expression error","Error",
		MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
		return;
		}

	StartValues^ startValues = gcnew StartValues(xStart, xEnd , yStart , yEnd , this->FxTextBox->Text);

	this->openGL_->graphController_->createNewGraph(startValues);


}


private: System::Void RightButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->openGL_->yAngleSpeed_ > -4)
			this->openGL_->yAngleSpeed_-=0.25;
		 }
private: System::Void LeftButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 if(this->openGL_->yAngleSpeed_ < 4)
			this->openGL_->yAngleSpeed_+=0.25;
		 }
private: System::Void UpButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if(this->openGL_->xAngleSpeed_ < 4)
			this->openGL_->xAngleSpeed_+=0.25;
		 }
private: System::Void DownButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if(this->openGL_->xAngleSpeed_ > -4)	 
			this->openGL_->xAngleSpeed_-=0.25;
		 }
private: System::Void ZoomInButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->openGL_->ZBeginingPos_ > 0.5)
			 this->openGL_->ZBeginingPos_ -= 0.5 ;
		 }
private: System::Void ZoomOutButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->openGL_->ZBeginingPos_ < 60)
			 this->openGL_->ZBeginingPos_ += 0.5 ;
		 }


private: System::Void startGAButton_Click(System::Object^  sender, System::EventArgs^  e) {
			  int  res  = 0 , i = 0 ;
			  bool result = false ; 


			  if (this->isGAPlayerPaused_ == false)
				{
				result = this->initGAValues(); 
					if (result == false) return ;


				this->pauseGAButton ->Enabled = true;
				this->stopGAButton ->Enabled = true ; 
				}

			  else  if (this->isGAPlayerPaused_ == true)
				{
				this->pauseGAButton ->Enabled = true;
				this->stopGAButton ->Enabled = true; 
				isGAPlayerPaused_ =false;
				}

				
				this->GaStepTimer->Interval = Single::Parse(stepMSecUpDown->Text) ; 
				this->GaStepTimer->Start();
				this->startGAButton ->Enabled = false;

		 }


		 //Gets values from visual components and inits the algorhtim 
bool initGAValues()
		{	 
		float xFrom = 0 , xTo = 0, yFrom = 0, yTo = 0 ;
		int bits , totalGenerations , totalPopulation , crossoverPositions ; 
		double crossoverProbability , mutationProbability ;
		int  res  = 0 , i = 0 ;
		int selectionIndex = 0 ; 
		bool result = false;
		ExprParser::Parser^ parser = gcnew ExprParser::Parser();
		

		try
			{
				//xFrom = Single::Parse( XFromTextBox->Text );  //Palios tropos
			xFrom = float::Parse( XFromTextBox->Text );
			xTo =   float::Parse( XToTextBox->Text );
			yFrom = float::Parse( YFromTextBox->Text );
			yTo =   float::Parse( YToTextBox->Text );

			
	  
			bits = Single::Parse(BitsUpDown->Text);
			totalGenerations = Single::Parse(TotalGenUpDown->Text);
			totalPopulation = Single::Parse(TotalPopUpDown->Text);
			crossoverPositions = Single::Parse(CrossoverPosUpDown->Text);

			crossoverProbability = Single::Parse(CrossoverProbUpDown->Text);
			mutationProbability = Single::Parse(MutationProbUpDown->Text);
			selectionIndex = this->SellectionMethodComboBox->SelectedIndex;

			}
		catch ( FormatException^ ) 
			{
			MessageBox::Show(  "Start Values Error","Error",
					MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
			
			return false;
			}
		catch ( Exception^  ) 
			{
			MessageBox::Show( "Name Entry Error2","Error",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
			return false;
			}
	

		result = parser->validateExpression(this->FxTextBox->Text);

		if (result == false)
			{
			MessageBox::Show(  "Fx mathematical expression error","Error",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
			return false;
			}
				

		StartValues^ startValues = gcnew StartValues( xFrom , xTo , yFrom , yTo ,  this->FxTextBox->Text );
		
		startValues->setGeneticStartValues(bits  ,  totalGenerations  , totalPopulation 
				, crossoverPositions , crossoverProbability , mutationProbability , selectionIndex ); 


		startValues->setRichTextBoxes( this->stepInfoRichTextBox, this->generationInfoRichTextBox );
		startValues->setGenerationLabel(this->GenerationLabel);
		startValues->setChosenAtomLabel(this->ChosenAtomLabel);


		this->openGL_->graphController_->createNewGraph(startValues);
		this->openGL_->geneticAlgorithm_ = gcnew GA::GeneticAlgorithm(startValues) ;

	 
		if (this->checkBox4->Checked == true)this->openGL_->geneticAlgorithm_->infoMessageGenerationEnabled = true ; 
			 else this->openGL_->geneticAlgorithm_->infoMessageGenerationEnabled = false ;

		if (this->checkBox5->Checked == true)this->openGL_->geneticAlgorithm_->genMessageGenerationEnabled = true ; 
			 else this->openGL_->geneticAlgorithm_->genMessageGenerationEnabled = false ; 


		return true;
		}



private: System::Void pauseGAButton_Click(System::Object^  sender, System::EventArgs^  e) {
			this->GaStepTimer->Stop();
			this->isGAPlayerPaused_ =true;
			this->pauseGAButton->Enabled = false ; 
			this->startGAButton->Enabled = true ; 
		 }
private: System::Void stopGAButton_Click(System::Object^  sender, System::EventArgs^  e) {

			isGAPlayerPaused_ = false;
			this->pauseGAButton ->Enabled = true;
			this->stopGAButton ->Enabled = true ; 
			this->startGAButton->Enabled = true ; 
			this->GaStepTimer->Stop();
			delete this->openGL_->geneticAlgorithm_ ;
			this->openGL_->geneticAlgorithm_ = nullptr;

		 }
private: System::Void GaStepTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
		int res = 0 , i = 0 ; 
		int prevTextLength = -1; 


		for( i = 0 ; i < 10 ; i++ )
			this->openGL_->geneticAlgorithm_->RunStep();

		res = this->openGL_->geneticAlgorithm_->RunStep();




		if (res == -1)
			{
			isGAPlayerPaused_ = false;
			this->pauseGAButton ->Enabled = true;
			this->stopGAButton ->Enabled = true ; 
			this->startGAButton->Enabled = true ; 
			this->GaStepTimer->Stop();

				MessageBox::Show(  "Execution finished","Execution finished",
					MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
			}
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 if (this->checkBox5->Checked == true)this->openGL_->geneticAlgorithm_->genMessageGenerationEnabled = true ; 
			 else this->openGL_->geneticAlgorithm_->genMessageGenerationEnabled = false ; 

		 }
private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			  if (this->checkBox4->Checked == true)this->openGL_->geneticAlgorithm_->infoMessageGenerationEnabled = true ; 
			 else this->openGL_->geneticAlgorithm_->infoMessageGenerationEnabled = false ; 

		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->stepInfoRichTextBox->Text = "" ;
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->generationInfoRichTextBox->Text = "" ; 
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (this->checkBox2->Checked == true)
				this->openGL_->graphController_->paintGrainGraph_ = true ; 
			else if (this->checkBox2->Checked == false)
				this->openGL_->graphController_->paintGrainGraph_ = false ;
		 }
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (this->checkBox3->Checked == true)
				this->openGL_->graphController_->paintLineGraph_ = true ; 
			else if (this->checkBox3->Checked == false)
				this->openGL_->graphController_->paintLineGraph_ = false ;
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (this->checkBox1->Checked == true)
				this->openGL_->graphController_->paintGrayGraph_ = true ; 
			else if (this->checkBox1->Checked == false)
				this->openGL_->graphController_->paintGrayGraph_ = false ;
		 }
};
}

