#pragma once
#include "freeglut.h"
#include "enums.h"

class GraphicsItem
{
protected:
	int x, y, width, height;

public:
	GraphicsItem();
	GraphicsItem(int _x, int _y, int _width, int _height);
	virtual ~GraphicsItem();
	virtual void draw() =0;
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	void setX(int _x);
	void setY(int _y);
	void setWidth(int _width);
	void setHeight(int _height);

};