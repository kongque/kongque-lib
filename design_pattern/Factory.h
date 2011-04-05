// factory
// author : kongque
// date   : 04/05/2011
//

#ifndef Q_FACTORY__H__
#define Q_FACTORY__H__

class IWindow
{	
};

class IWindowFactory
{
public:
	virtual IWindow* create() = 0;
};

// concrete product
//
// button class
class CButton : public IWindow
{
public:
	CButton();
};

// checkbox class
class CCheckbox : public IWindow
{
public:
	CCheckbox();
};

// dialog class
class CDialog : public IWindow
{
public:
	CDialog();
};

// concrete factory
class CButtonFactory : public IWindowFactory
{
public:
	IWindow* create();
};

class CCheckboxFactory : public IWindowFactory
{
public:
	IWindow* create();
};

class CDialogFactory : public IWindowFactory
{
public:
	IWindow* create();
};


#endif
