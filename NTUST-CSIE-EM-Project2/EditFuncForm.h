#pragma once

namespace NTUSTCSIEEMProject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// EditFuncForm ���K�n
	/// </summary>
	public ref class EditFuncForm : public System::Windows::Forms::Form
	{
	public:
		bool pressEnter = false;
		EditFuncForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~EditFuncForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	protected:
	private: System::Windows::Forms::Button^  btnEnter;
	private: System::Windows::Forms::TextBox^  txtFunction;


	protected:







	protected:

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnEnter = (gcnew System::Windows::Forms::Button());
			this->txtFunction = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				80)));
			this->tableLayoutPanel2->Controls->Add(this->btnEnter, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->txtFunction, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(664, 42);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// btnEnter
			// 
			this->btnEnter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnEnter->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnEnter->Location = System::Drawing::Point(587, 3);
			this->btnEnter->Name = L"btnEnter";
			this->btnEnter->Size = System::Drawing::Size(74, 36);
			this->btnEnter->TabIndex = 0;
			this->btnEnter->Text = L"Enter";
			this->btnEnter->UseVisualStyleBackColor = false;
			this->btnEnter->Click += gcnew System::EventHandler(this, &EditFuncForm::btnEnter_Click);
			// 
			// txtFunction
			// 
			this->txtFunction->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtFunction->Location = System::Drawing::Point(3, 3);
			this->txtFunction->Multiline = true;
			this->txtFunction->Name = L"txtFunction";
			this->txtFunction->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->txtFunction->Size = System::Drawing::Size(578, 36);
			this->txtFunction->TabIndex = 1;
			// 
			// EditFuncForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(664, 42);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Font = (gcnew System::Drawing::Font(L"�L�n������", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"EditFuncForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Edit Function";
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}

		public:	String^ getText(void)
		{
			return txtFunction->Text;
		}

		public: void setText(String^s)
		{
			txtFunction->Text = s;
			return;
		}

#pragma endregion
	private: System::Void btnEnter_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		pressEnter = true;
		this->Close();
	}

};
}
