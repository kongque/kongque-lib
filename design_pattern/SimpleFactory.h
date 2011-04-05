//
// simple factory
// author : kongque
// date   : 04/05/2011
//

#ifndef Q_SIMPLE_FACTORY__H__
#define Q_SIMPLE_FACTORY__H__

class IShape
{
public:
	virtual void draw() = 0;
	virtual ~IShape();
};

class CSquare : public IShape
{
public:
	CSquare();
	~CSquare();
	virtual void draw();
};

class CTriangle : public IShape
{
public:
	CTriangle();
	~CTriangle();
	virtual void draw();
};

class CCircle : public IShape
{
public:
	CCircle();
	~CCircle();
	virtual void draw();
};

enum EShapeType
{
	EST_CTriangle,
	EST_CSquare,
	EST_CCircle
};

class CSimpleFactory
{
public:
	IShape* createShape(EShapeType type);
};

#endif


