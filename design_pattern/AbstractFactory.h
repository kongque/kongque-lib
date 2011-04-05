//
// Abstract factory
// author : kongque
// date   : 04/05/2011
//

#ifndef Q_ABSTRACT_FACTORY__H__
#define Q_ABSTRACT_FACTORY__H__

class IButton
{
};

class ICheckbox
{
};

class IDialogbox
{
};

class IWindowAbstractFactory
{
public:
	virtual IButton* createButton() = 0;
	virtual ICheckbox* createCheckbox() = 0;
	virtual IDialogbox* createDialogbox() = 0;
};

// Irrlicht style GUI
class CIrrlichtButton : public IButton
{
public:
	CIrrlichtButton();
};

class CIrrlichtCheckbox : public ICheckbox
{
public:
	CIrrlichtCheckbox();
};

class CIrrlichtDialogbox : public IDialogbox
{
public:
	CIrrlichtDialogbox();
};


class CIrrlichtFactory : public IWindowAbstractFactory 
{
public:
	virtual IButton* createButton();
	virtual ICheckbox* createCheckbox();
	virtual IDialogbox* createDialogbox();
};

// OGRE style GUI
class COGREButton : public IButton
{
public:
	COGREButton();
};

class COGRECheckbox : public ICheckbox
{
public:
	COGRECheckbox();
};

class COGREDialogbox : public IDialogbox
{
public:
	COGREDialogbox();
};


class COGREFactory : public IWindowAbstractFactory 
{
public:
	virtual IButton* createButton();
	virtual ICheckbox* createCheckbox();
	virtual IDialogbox* createDialogbox();
};

enum EGUIStyle
{
	EGS_Irrlicht,
	EGS_OGRE
};
//
IWindowAbstractFactory* createGUI(EGUIStyle style);

#endif

