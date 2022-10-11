// Aaron Grycner, agrycner@cnm.edu, GrycnerP4.cpp

#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
//Use a Single Threading model


[STAThread]
void Main()//program entry point
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project1::MyForm form;

	Application::Run(% form);
} 
