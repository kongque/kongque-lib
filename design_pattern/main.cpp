// this file used to test all the design pattern that I write in c++ language
// author : kongque
// date   : 04/05/2011
//

#include "SimpleFactory.h"
#include "Factory.h"
#include "AbstractFactory.h"

// test simple factory 
void testSimpleFactory()
{
	CSimpleFactory* factory = new CSimpleFactory;

	IShape* circle = factory->createShape(EST_CCircle);
	IShape* triangle = factory->createShape(EST_CTriangle);
	IShape* square = factory->createShape(EST_CSquare);

	delete circle; circle = 0;
	delete triangle; triangle = 0;
	delete square; square = 0;

	delete factory; factory = 0;
}

// test factory
void testFactory()
{
	// 使用工厂模式如下：
	CButtonFactory* button_factory = new CButtonFactory;
	IWindow* button1 = button_factory->create();

	delete button1; button1 = 0;
	delete button_factory; button_factory = 0;

	// 不使用任何模式，直接new
	CButton* btn2 = new CButton;
	delete btn2; btn2 = 0;

	// Thinking:
	// 1) 这里的简单的使用看不出工厂模式的任何优势，反而麻烦了。
	// 2) new和delete操作还暴露在外部，需要将其隐藏起来
}

// test abstract factory
void testAbstractFactory()
{
	IWindowAbstractFactory* win_factory = createGUI(EGS_Irrlicht);
	if (!win_factory)
		return;
	
	IButton* btn = win_factory->createButton();
	ICheckbox* checkbox = win_factory->createCheckbox();
	IDialogbox* dialogbox = win_factory->createDialogbox();
	
	delete btn; btn = 0;
	delete checkbox; checkbox = 0;
	delete dialogbox; dialogbox = 0;

	delete win_factory; win_factory = 0;
}

int main(int argc, char* argv[])
{
	// 1) Test simple factory :
	// testSimpleFactory();
	
	// 2) Test factory :
	//testFactory();
	
	// 3) Test abstract factory
	testAbstractFactory();
	
}
