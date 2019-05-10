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
	private: System::Windows::Forms::TextBox^  txtInput;
	private: System::Windows::Forms::TextBox^  txtOutput;
	protected:

	protected:

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::Label^  lblOutput;

	private: System::Windows::Forms::Label^  lblInput;
	private: System::Windows::Forms::ToolStripButton^  btnLoad;
	private: System::Windows::Forms::ToolStripButton^  btnReset;
	private: System::Windows::Forms::ToolStripButton^  btnHint;


	private: System::Windows::Forms::ToolStripButton^  btnClear;




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
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->txtOutput = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->btnLoad = (gcnew System::Windows::Forms::ToolStripButton());
			this->btnReset = (gcnew System::Windows::Forms::ToolStripButton());
			this->btnHint = (gcnew System::Windows::Forms::ToolStripButton());
			this->lblOutput = (gcnew System::Windows::Forms::Label());
			this->lblInput = (gcnew System::Windows::Forms::Label());
			this->btnClear = (gcnew System::Windows::Forms::ToolStripButton());
			this->tableLayoutPanel1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtInput
			// 
			this->txtInput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtInput->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->txtInput->Location = System::Drawing::Point(3, 74);
			this->txtInput->Multiline = true;
			this->txtInput->Name = L"txtInput";
			this->txtInput->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtInput->Size = System::Drawing::Size(996, 178);
			this->txtInput->TabIndex = 0;
			// 
			// txtOutput
			// 
			this->txtOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtOutput->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->txtOutput->Location = System::Drawing::Point(3, 284);
			this->txtOutput->Multiline = true;
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtOutput->Size = System::Drawing::Size(996, 425);
			this->txtOutput->TabIndex = 1;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->toolStrip1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->txtOutput, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->lblOutput, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->txtInput, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->lblInput, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 26)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 26)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 70)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1002, 712);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->btnLoad, this->btnReset,
					this->btnClear, this->btnHint
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1002, 31);
			this->toolStrip1->TabIndex = 3;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// btnLoad
			// 
			this->btnLoad->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLoad.Image")));
			this->btnLoad->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(79, 28);
			this->btnLoad->Text = L"Load";
			// 
			// btnReset
			// 
			this->btnReset->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnReset.Image")));
			this->btnReset->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(85, 28);
			this->btnReset->Text = L"Reset";
			// 
			// btnHint
			// 
			this->btnHint->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnHint.Image")));
			this->btnHint->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnHint->Name = L"btnHint";
			this->btnHint->Size = System::Drawing::Size(75, 28);
			this->btnHint->Text = L"Hint";
			// 
			// lblOutput
			// 
			this->lblOutput->AutoSize = true;
			this->lblOutput->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lblOutput->Location = System::Drawing::Point(3, 255);
			this->lblOutput->Name = L"lblOutput";
			this->lblOutput->Size = System::Drawing::Size(73, 23);
			this->lblOutput->TabIndex = 4;
			this->lblOutput->Text = L"Output";
			// 
			// lblInput
			// 
			this->lblInput->AutoSize = true;
			this->lblInput->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold));
			this->lblInput->Location = System::Drawing::Point(3, 45);
			this->lblInput->Name = L"lblInput";
			this->lblInput->Size = System::Drawing::Size(57, 23);
			this->lblInput->TabIndex = 3;
			this->lblInput->Text = L"Input";
			// 
			// btnClear
			// 
			this->btnClear->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClear.Image")));
			this->btnClear->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(82, 28);
			this->btnClear->Text = L"Clear";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1002, 712);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"P2_G05_V1";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
