#include "AbstractFactory.h"

#include <iostream>
using namespace std;

// Irrlicht style
CIrrlichtButton::CIrrlichtButton()
{
	cout << "create new CIrrlichtButton instance" << endl;
}

CIrrlichtCheckbox::CIrrlichtCheckbox()
{
	cout << "create new CIrrlichtCheckbox instance" << endl;
}

CIrrlichtDialogbox::CIrrlichtDialogbox()
{
	cout << "create new CIrrlichtDialogbox instance" << endl;
}

IButton*
CIrrlichtFactory::createButton()
{
	return new CIrrlichtButton;
}

ICheckbox*
CIrrlichtFactory::createCheckbox()
{
	return new CIrrlichtCheckbox;
}

IDialogbox*
CIrrlichtFactory::createDialogbox()
{
	return new CIrrlichtDialogbox;
}

// OGRE style
COGREButton::COGREButton()
{
	cout << "create new COGREButton instance" << endl;
}

COGRECheckbox::COGRECheckbox()
{
	cout << "create new COGRECheckbox instance" << endl;
}

COGREDialogbox::COGREDialogbox()
{
	cout << "create new COGREDialogbox instance" << endl;
}

IButton*
COGREFactory::createButton()
{
	return new COGREButton;
}

ICheckbox*
COGREFactory::createCheckbox()
{
	return new COGRECheckbox;
}

IDialogbox*
COGREFactory::createDialogbox()
{
	return new COGREDialogbox;
}

IWindowAbstractFactory* 
createGUI(EGUIStyle style)
{
	IWindowAbstractFactory* win_factory = 0;

	switch (style)
	{
		case EGS_Irrlicht:
			win_factory = new CIrrlichtFactory;
			break;

		case EGS_OGRE:
			win_factory = new COGREFactory;
			break;
	}

	return win_factory;
}





