#pragma once
#include "freeglut.h"
#include "enums.h"

class GraphicsRectItem
{
protected:
	int x, y, width, height;

public:
	GraphicsRectItem();
	GraphicsRectItem(int x, int y, int width, int height);
	virtual ~GraphicsRectItem();
	virtual void draw();
	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	bool mouseOnItem(int mX, int mY);

};