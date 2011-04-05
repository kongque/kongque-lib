// this file used to test all the design pattern that I write in c++ language
// author : kongque
// date   : 04/05/2011
//

#include "SimpleFactory.h"

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

int main(int argc, char* argv[])
{
	// Test simple factory :
	testSimpleFactory();
}
