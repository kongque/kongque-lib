// 模式应该融入设计与编码，而不是要为了模式而模式
//
#include "Factory.h"

#include <iostream>
using namespace std;

CButton::CButton()
{
	cout << "Create CButton instance" << endl;
}

CCheckbox::CCheckbox()
{
	cout << "Create CCheckbox instance" << endl;
}

CDialog::CDialog()
{
	cout << "Create CDialog instance" << endl;
}

IWindow* 
CButtonFactory::create()
{
	return new CButton;
}

IWindow*
CCheckboxFactory::create()
{
	return new CCheckbox;
}

IWindow* 
CDialogFactory::create()
{
	return new CDialog;
}
