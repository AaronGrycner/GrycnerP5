#pragma once
#include "SimpleCalc.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	SimpleCalc calc;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	private: void Calculate(char operation) {
		double tmp1, tmp2;
		try {
			
			tmp1 = Convert::ToDouble(txtNum1->Text);
			tmp2 = Convert::ToDouble(txtNum2->Text);
			calc.SetOperation(operation, tmp1, tmp2);
			this->txtResults->Text = gcnew String(calc.GetResults().c_str());
			this->lblOps->Text = (Convert::ToChar(operation)).ToString();

		}
		
		catch (FormatException^ e) {
			if (txtNum1->Text == "" || txtNum2->Text == "")
				txtResults->Text = "Error! Empty arg";
			else
				txtResults->Text = "Type Error!";
		}
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}



























	protected:

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
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PaleTurquoise;
			this->ClientSize = System::Drawing::Size(674, 461);
			this->Name = L"MyForm";
			this->Text = L"Aaron Grycner P4 simplecalc";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void op1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	double n1, n2;

	Calculate('+');
}
private: System::Void btnSubtract_Click(System::Object^ sender, System::EventArgs^ e) {
	Calculate('-');
}
private: System::Void btnDivide_Click(System::Object^ sender, System::EventArgs^ e) {
	Calculate('/');
}
private: System::Void btnMultiply_Click(System::Object^ sender, System::EventArgs^ e) {
	Calculate('*');
}
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
	txtNum1->Clear();
	txtNum2->Clear();
	txtResults->Clear();
	lblOps->Text = "?";
}
};
}
