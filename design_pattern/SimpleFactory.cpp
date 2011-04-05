#include "SimpleFactory.h"

#include <iostream>
using namespace std;

IShape::~IShape()
{
	cout << "IShape destructor." << endl;
}

// CSquare
CSquare::CSquare()
{
	cout << "create a new CSquare object." << endl;
}

CSquare::~CSquare()
{
	cout << "CSquare destructor." << endl;
}

void 
CSquare::draw()
{
	cout << "draw CSquare" << endl;
}

// CTriangle
CTriangle::CTriangle()
{
	cout << "create a new CTriangle object." << endl;
}

CTriangle::~CTriangle()
{
	cout << "CTriangle destructor." << endl;
}

void 
CTriangle::draw()
{
	cout << "draw CTriangle" << endl;
}

// CCircle
CCircle::CCircle()
{
	cout << "create a new CCircle object." << endl;
}

CCircle::~CCircle()
{
	cout << "CCircle destructor" << endl;
}

void 
CCircle::draw()
{
	cout << "draw CCircle" << endl;
}

IShape*
CSimpleFactory::createShape(EShapeType type)
{
	IShape* shape = 0;

	switch (type)
	{
		case EST_CTriangle:
			shape = new CTriangle;
			break;

		case EST_CSquare:
			shape = new CSquare;
			break;

		case EST_CCircle:
			shape = new CCircle;
			break;
	}

	return shape;
}
