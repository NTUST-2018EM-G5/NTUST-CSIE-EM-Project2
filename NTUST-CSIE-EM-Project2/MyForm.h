#include "EditFuncForm.h"
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
			//
			//TODO:  在此加入建構函式程式碼
			//
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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->cbxMethod = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listFunction = (gcnew System::Windows::Forms::ListBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->toolStripTop->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
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
			// 
			// btnClear
			// 
			this->btnClear->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClear.Image")));
			this->btnClear->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(65, 27);
			this->btnClear->Text = L"Clear";
			// 
			// btnHint
			// 
			this->btnHint->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnHint.Image")));
			this->btnHint->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnHint->Name = L"btnHint";
			this->btnHint->Size = System::Drawing::Size(59, 27);
			this->btnHint->Text = L"Hint";
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
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(488, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Output";
			// 
			// txtOutput
			// 
			this->txtOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtOutput->Location = System::Drawing::Point(3, 23);
			this->txtOutput->Multiline = true;
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->Size = System::Drawing::Size(488, 561);
			this->txtOutput->TabIndex = 1;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel3->Controls->Add(this->label3, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel5, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->listFunction, 0, 1);
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
			this->tableLayoutPanel3->Size = System::Drawing::Size(394, 587);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Silver;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(3, 407);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(388, 20);
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
			// 
			// cbxMethod
			// 
			this->cbxMethod->Dock = System::Windows::Forms::DockStyle::Bottom;
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
			this->cbxMethod->Location = System::Drawing::Point(3, 8);
			this->cbxMethod->Margin = System::Windows::Forms::Padding(3, 7, 3, 7);
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
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(388, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Function and Method";
			// 
			// listFunction
			// 
			this->listFunction->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listFunction->FormattingEnabled = true;
			this->listFunction->ItemHeight = 16;
			this->listFunction->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"x^2+x-2*x^0.5", L"7+x^2-3*x*y+3.25*y^2-4*y",
					L"0.001*x^3-0.07*x^2+0.06*x+0.0002*y^3-0.004*y^2+0.02*y"
			});
			this->listFunction->Location = System::Drawing::Point(3, 23);
			this->listFunction->Margin = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->listFunction->Name = L"listFunction";
			this->listFunction->Size = System::Drawing::Size(388, 344);
			this->listFunction->TabIndex = 2;
			this->listFunction->DoubleClick += gcnew System::EventHandler(this, &MyForm::listFunction_DoubleClick);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"FileName";
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
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->toolStripTop->ResumeLayout(false);
			this->toolStripTop->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		
	private: System::Void listFunction_DoubleClick(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listFunction->SelectedIndex >= 0)
		{
			EditFuncForm ^ eform = gcnew EditFuncForm;
			eform->setText(listFunction->Text);
			eform->ShowDialog();
			if (eform->pressEnter)listFunction->Items[listFunction->SelectedIndex] = eform->getText();
		}
	}
	private: System::Void btnLoad_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		
	}
};
}
