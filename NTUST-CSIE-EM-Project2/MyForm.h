#include "EditFuncForm.h"
#include "HintForm.h"
#include "DataManager.h"
#include "DotNetUitilities.h"
#pragma once

namespace NTUSTCSIEEMProject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//建構函式程式碼
			dataManager = new DataManager();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	protected:

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStrip^  toolStripTop;




	private: System::Windows::Forms::ToolStripButton^  btnLoad;
	private: System::Windows::Forms::ToolStripButton^  btnReset;
	private: System::Windows::Forms::ToolStripButton^  btnHint;


	private: System::Windows::Forms::ToolStripButton^  btnClear;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TextBox^  txtOutput;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  listFunction;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::ComboBox^  cbxMethod;
	private: System::Windows::Forms::Button^  btnRun;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;







	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		DataManager* dataManager;








	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::TextBox^  txtVar2_init;






	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txtVar2_name;

	private: System::Windows::Forms::CheckBox^  cbxVar2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtVar2_interval_end;

	private: System::Windows::Forms::TextBox^  txtVar2_interval_begin;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtVar1_name;
	private: System::Windows::Forms::TextBox^  txtVar1_init;






	private: System::Windows::Forms::CheckBox^  cbxVar1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::TextBox^  txtVar1_interval_end;

private: System::Windows::Forms::TextBox^  txtVar1_interval_begin;














			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->toolStripTop = (gcnew System::Windows::Forms::ToolStrip());
			this->btnLoad = (gcnew System::Windows::Forms::ToolStripButton());
			this->btnReset = (gcnew System::Windows::Forms::ToolStripButton());
			this->btnClear = (gcnew System::Windows::Forms::ToolStripButton());
			this->btnHint = (gcnew System::Windows::Forms::ToolStripButton());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtOutput = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtVar2_interval_end = (gcnew System::Windows::Forms::TextBox());
			this->txtVar2_interval_begin = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtVar2_name = (gcnew System::Windows::Forms::TextBox());
			this->cbxVar2 = (gcnew System::Windows::Forms::CheckBox());
			this->txtVar2_init = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->cbxMethod = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listFunction = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtVar1_name = (gcnew System::Windows::Forms::TextBox());
			this->txtVar1_init = (gcnew System::Windows::Forms::TextBox());
			this->cbxVar1 = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtVar1_interval_end = (gcnew System::Windows::Forms::TextBox());
			this->txtVar1_interval_begin = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->toolStripTop->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->toolStripTop, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 23)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(906, 633);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// toolStripTop
			// 
			this->toolStripTop->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->toolStripTop->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStripTop->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->btnLoad, this->btnReset,
					this->btnClear, this->btnHint
			});
			this->toolStripTop->Location = System::Drawing::Point(0, 0);
			this->toolStripTop->Name = L"toolStripTop";
			this->toolStripTop->Size = System::Drawing::Size(906, 30);
			this->toolStripTop->TabIndex = 3;
			this->toolStripTop->Text = L"toolStripTop";
			// 
			// btnLoad
			// 
			this->btnLoad->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLoad.Image")));
			this->btnLoad->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(65, 27);
			this->btnLoad->Text = L"Load";
			this->btnLoad->Click += gcnew System::EventHandler(this, &MyForm::btnLoad_Click);
			// 
			// btnReset
			// 
			this->btnReset->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnReset.Image")));
			this->btnReset->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(67, 27);
			this->btnReset->Text = L"Reset";
			this->btnReset->Click += gcnew System::EventHandler(this, &MyForm::btnReset_Click);
			// 
			// btnClear
			// 
			this->btnClear->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClear.Image")));
			this->btnClear->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(65, 27);
			this->btnClear->Text = L"Clear";
			this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::btnClear_Click);
			// 
			// btnHint
			// 
			this->btnHint->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnHint.Image")));
			this->btnHint->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnHint->Name = L"btnHint";
			this->btnHint->Size = System::Drawing::Size(59, 27);
			this->btnHint->Text = L"Hint";
			this->btnHint->Click += gcnew System::EventHandler(this, &MyForm::btnHint_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				400)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				500)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 34);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(900, 595);
			this->tableLayoutPanel2->TabIndex = 4;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->txtOutput, 0, 1);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(403, 4);
			this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(494, 587);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Silver;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(494, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Output";
			// 
			// txtOutput
			// 
			this->txtOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtOutput->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtOutput->Location = System::Drawing::Point(3, 23);
			this->txtOutput->Multiline = true;
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->ReadOnly = true;
			this->txtOutput->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtOutput->Size = System::Drawing::Size(488, 561);
			this->txtOutput->TabIndex = 1;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel6, 0, 7);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel8, 0, 6);
			this->tableLayoutPanel3->Controls->Add(this->label3, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel5, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->listFunction, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel7, 0, 4);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel9, 0, 5);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 4);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 8;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(394, 587);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 5;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				26)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				67)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				67)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				121)));
			this->tableLayoutPanel6->Controls->Add(this->label4, 2, 0);
			this->tableLayoutPanel6->Controls->Add(this->txtVar2_interval_end, 4, 0);
			this->tableLayoutPanel6->Controls->Add(this->txtVar2_interval_begin, 3, 0);
			this->tableLayoutPanel6->Location = System::Drawing::Point(0, 547);
			this->tableLayoutPanel6->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(394, 40);
			this->tableLayoutPanel6->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(143, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Interval :";
			// 
			// txtVar2_interval_end
			// 
			this->txtVar2_interval_end->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->txtVar2_interval_end->Enabled = false;
			this->txtVar2_interval_end->Location = System::Drawing::Point(276, 8);
			this->txtVar2_interval_end->Name = L"txtVar2_interval_end";
			this->txtVar2_interval_end->Size = System::Drawing::Size(60, 23);
			this->txtVar2_interval_end->TabIndex = 9;
			this->txtVar2_interval_end->Text = L"0";
			// 
			// txtVar2_interval_begin
			// 
			this->txtVar2_interval_begin->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->txtVar2_interval_begin->Enabled = false;
			this->txtVar2_interval_begin->Location = System::Drawing::Point(209, 8);
			this->txtVar2_interval_begin->Name = L"txtVar2_interval_begin";
			this->txtVar2_interval_begin->Size = System::Drawing::Size(60, 23);
			this->txtVar2_interval_begin->TabIndex = 8;
			this->txtVar2_interval_begin->Text = L"0";
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 5;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				26)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				67)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				67)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				121)));
			this->tableLayoutPanel8->Controls->Add(this->label6, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->txtVar2_name, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->cbxVar2, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->txtVar2_init, 3, 0);
			this->tableLayoutPanel8->Location = System::Drawing::Point(0, 507);
			this->tableLayoutPanel8->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(394, 40);
			this->tableLayoutPanel8->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(149, 12);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 16);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Init val :";
			// 
			// txtVar2_name
			// 
			this->txtVar2_name->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->txtVar2_name->Enabled = false;
			this->txtVar2_name->Location = System::Drawing::Point(116, 8);
			this->txtVar2_name->Name = L"txtVar2_name";
			this->txtVar2_name->Size = System::Drawing::Size(20, 23);
			this->txtVar2_name->TabIndex = 3;
			this->txtVar2_name->Text = L"y";
			// 
			// cbxVar2
			// 
			this->cbxVar2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->cbxVar2->AutoSize = true;
			this->cbxVar2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cbxVar2->Location = System::Drawing::Point(3, 10);
			this->cbxVar2->Name = L"cbxVar2";
			this->cbxVar2->Size = System::Drawing::Size(107, 20);
			this->cbxVar2->TabIndex = 1;
			this->cbxVar2->Text = L"Var 2   Name :";
			this->cbxVar2->UseVisualStyleBackColor = true;
			this->cbxVar2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::cbxVar2_CheckedChanged);
			// 
			// txtVar2_init
			// 
			this->txtVar2_init->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->txtVar2_init->Enabled = false;
			this->txtVar2_init->Location = System::Drawing::Point(209, 8);
			this->txtVar2_init->Name = L"txtVar2_init";
			this->txtVar2_init->Size = System::Drawing::Size(60, 23);
			this->txtVar2_init->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Silver;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(0, 407);
			this->label3->Margin = System::Windows::Forms::Padding(0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(394, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Option";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				60)));
			this->tableLayoutPanel5->Controls->Add(this->btnRun, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->cbxMethod, 0, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 367);
			this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(388, 37);
			this->tableLayoutPanel5->TabIndex = 4;
			// 
			// btnRun
			// 
			this->btnRun->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnRun->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnRun->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btnRun->ForeColor = System::Drawing::Color::Black;
			this->btnRun->Location = System::Drawing::Point(331, 3);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(54, 31);
			this->btnRun->TabIndex = 1;
			this->btnRun->Text = L"Run";
			this->btnRun->UseVisualStyleBackColor = false;
			this->btnRun->Click += gcnew System::EventHandler(this, &MyForm::btnRun_Click);
			// 
			// cbxMethod
			// 
			this->cbxMethod->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cbxMethod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxMethod->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbxMethod->FormattingEnabled = true;
			this->cbxMethod->IntegralHeight = false;
			this->cbxMethod->ItemHeight = 14;
			this->cbxMethod->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Powell’s Method", L"Newton Method", L"Steep Descent Algorithm",
					L"Quasi-Newton Method", L"Conjugate Gradient Methods"
			});
			this->cbxMethod->Location = System::Drawing::Point(3, 7);
			this->cbxMethod->Margin = System::Windows::Forms::Padding(0);
			this->cbxMethod->Name = L"cbxMethod";
			this->cbxMethod->Size = System::Drawing::Size(322, 22);
			this->cbxMethod->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Silver;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(0, 0);
			this->label2->Margin = System::Windows::Forms::Padding(0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(394, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Equations and Methods";
			// 
			// listFunction
			// 
			this->listFunction->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listFunction->FormattingEnabled = true;
			this->listFunction->ItemHeight = 16;
			this->listFunction->Location = System::Drawing::Point(3, 23);
			this->listFunction->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->listFunction->Name = L"listFunction";
			this->listFunction->Size = System::Drawing::Size(388, 344);
			this->listFunction->TabIndex = 2;
			this->listFunction->DoubleClick += gcnew System::EventHandler(this, &MyForm::listFunction_DoubleClick);
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 5;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				26)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				67)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				67)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				121)));
			this->tableLayoutPanel7->Controls->Add(this->label5, 2, 0);
			this->tableLayoutPanel7->Controls->Add(this->txtVar1_name, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->txtVar1_init, 3, 0);
			this->tableLayoutPanel7->Controls->Add(this->cbxVar1, 0, 0);
			this->tableLayoutPanel7->Location = System::Drawing::Point(0, 427);
			this->tableLayoutPanel7->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 1;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(394, 40);
			this->tableLayoutPanel7->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(149, 12);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Init val :";
			// 
			// txtVar1_name
			// 
			this->txtVar1_name->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->txtVar1_name->Location = System::Drawing::Point(116, 8);
			this->txtVar1_name->Name = L"txtVar1_name";
			this->txtVar1_name->Size = System::Drawing::Size(20, 23);
			this->txtVar1_name->TabIndex = 2;
			this->txtVar1_name->Text = L"x";
			// 
			// txtVar1_init
			// 
			this->txtVar1_init->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->txtVar1_init->Location = System::Drawing::Point(209, 8);
			this->txtVar1_init->Name = L"txtVar1_init";
			this->txtVar1_init->Size = System::Drawing::Size(60, 23);
			this->txtVar1_init->TabIndex = 4;
			// 
			// cbxVar1
			// 
			this->cbxVar1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->cbxVar1->AutoSize = true;
			this->cbxVar1->Checked = true;
			this->cbxVar1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxVar1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->cbxVar1->Location = System::Drawing::Point(3, 10);
			this->cbxVar1->Name = L"cbxVar1";
			this->cbxVar1->Size = System::Drawing::Size(107, 20);
			this->cbxVar1->TabIndex = 0;
			this->cbxVar1->Text = L"Var 1   Name :";
			this->cbxVar1->UseVisualStyleBackColor = true;
			this->cbxVar1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::cbxVar1_CheckedChanged);
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 5;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				26)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				67)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				67)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				121)));
			this->tableLayoutPanel9->Controls->Add(this->label7, 2, 0);
			this->tableLayoutPanel9->Controls->Add(this->txtVar1_interval_end, 4, 0);
			this->tableLayoutPanel9->Controls->Add(this->txtVar1_interval_begin, 3, 0);
			this->tableLayoutPanel9->Location = System::Drawing::Point(0, 467);
			this->tableLayoutPanel9->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 1;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(394, 40);
			this->tableLayoutPanel9->TabIndex = 7;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(143, 12);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(60, 16);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Interval :";
			// 
			// txtVar1_interval_end
			// 
			this->txtVar1_interval_end->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->txtVar1_interval_end->Location = System::Drawing::Point(276, 8);
			this->txtVar1_interval_end->Name = L"txtVar1_interval_end";
			this->txtVar1_interval_end->Size = System::Drawing::Size(60, 23);
			this->txtVar1_interval_end->TabIndex = 6;
			this->txtVar1_interval_end->Text = L"0";
			// 
			// txtVar1_interval_begin
			// 
			this->txtVar1_interval_begin->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->txtVar1_interval_begin->Location = System::Drawing::Point(209, 8);
			this->txtVar1_interval_begin->Name = L"txtVar1_interval_begin";
			this->txtVar1_interval_begin->Size = System::Drawing::Size(60, 23);
			this->txtVar1_interval_begin->TabIndex = 5;
			this->txtVar1_interval_begin->Text = L"0";
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"FileName";
			this->openFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(906, 633);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"P2_G05_V1";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->toolStripTop->ResumeLayout(false);
			this->toolStripTop->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		txtOutput->Text += "-Hello world!-" + Environment::NewLine;
	}
		
	private: System::Void listFunction_DoubleClick(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listFunction->SelectedIndex >= 0)
		{
			EditFuncForm ^ eform = gcnew EditFuncForm;
			eform->setText(listFunction->Text);
			eform->ShowDialog();
			if (eform->pressEnter)
			{
				dataManager->EditEquations(listFunction->SelectedIndex, ConvertToString(eform->getText()));
				listFunction->Items[listFunction->SelectedIndex] = eform->getText();
			}
		}
	}
	private: System::Void btnLoad_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		openFileDialog->ShowDialog();
	}

	private: System::Void btnRun_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listFunction->SelectedIndex < 0)
		{
			MessageBox::Show("Please select a Equation.");
			return;
		}
		if (cbxMethod->SelectedIndex < 0)
		{
			MessageBox::Show("Please select a Method.");
			return;
		}
		//把參數存進Variable裡面
		vector<Variable> var;
		try
		{
			Variable temp;
			if (cbxVar1->Checked)
			{
				temp.name = ConvertToString(txtVar1_name->Text);
				temp.init = stod(ConvertToString(txtVar1_init->Text));
				temp.begin = stod(ConvertToString(txtVar1_interval_begin->Text));
				temp.end = stod(ConvertToString(txtVar1_interval_end->Text));
				var.push_back(temp);
			}
			if (cbxVar2->Checked)
			{
				temp.name = ConvertToString(txtVar2_name->Text);
				temp.init = stod(ConvertToString(txtVar2_init->Text));
				temp.begin = stod(ConvertToString(txtVar2_interval_begin->Text));
				temp.end = stod(ConvertToString(txtVar2_interval_end->Text));
				var.push_back(temp);
			}
		}
		catch (...)
		{
			MessageBox::Show("Please Fill the value.\r\nIf not in use, fill the \"0\"");
			return;
		}
		
		
		//依據不同的Method，求出計算過程
		System::String^ result;
		int equIndex = listFunction->SelectedIndex;
		try
		{
			switch (cbxMethod->SelectedIndex)
			{
			case 0: //Powell’s Method
				result = dataManager->Powells_Method(equIndex, var);
				break;
			case 1: //Newton Method
				result = dataManager->Newton_Method(equIndex, var);
				break;
			case 2: //Steep Descent Algorithm
				result = dataManager->Steep_Descent_Algorithm(equIndex, var);
				break;
			case 3: //Quasi-Newton Method 
				result = dataManager->Quasi_Newton_Method(equIndex, var);
				break;
			case 4: //Conjugate Gradient Methods 
				result = dataManager->Conjugate_Gradient_Methods(equIndex, var);
				break;
			}
		}
		catch (string whyError)
		{
			result = ConvertToString(whyError + "\r\n");
		}
		
		//將結果輸出在Output
		txtOutput->Text += result;
		//自動捲到最下方
		txtOutput->SelectionStart = txtOutput->Text->Length;
		txtOutput->ScrollToCaret();
	}

	private: System::Void openFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
	{
		//取得檔名
		std::string fileName = ConvertToString(openFileDialog->FileName);
		dataManager->SetFileName(fileName);
		
		//讀取檔案，讀取成功就會true
		if (dataManager->LoadEquationData())
		{
			//重整list的equation
			listFunction->Items->Clear();
			for each(std::string equation in dataManager->GetEquations())
			{
				listFunction->Items->Add(ConvertToString(equation));
			}
		}
		else //NO FILE
		{
			txtOutput->Text += "-The data is wrong-" + Environment::NewLine;
		}
	}
	private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//清空方程式
		dataManager->Clear();
		listFunction->Items->Clear();

		//清空介面
		txtOutput->Clear();
		cbxMethod->SelectedIndex = -1;
	}
	private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//清空輸出
		txtOutput->Clear();
	}
	private: System::Void cbxVar1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		cbxVar1->Checked = true;
	}
	private: System::Void cbxVar2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (cbxVar2->Checked)
		{
			txtVar2_name->Enabled = true;
			txtVar2_init->Enabled = true;
			txtVar2_interval_begin->Enabled = true;
			txtVar2_interval_end->Enabled = true;
		}
		else
		{
			txtVar2_name->Enabled = false;
			txtVar2_init->Enabled = false;
			txtVar2_interval_begin->Enabled = false;
			txtVar2_interval_end->Enabled = false;
		}
	}


	private: System::Void btnHint_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		HintForm ^ hform = gcnew HintForm;
		hform->ShowDialog();
	}
};
}
