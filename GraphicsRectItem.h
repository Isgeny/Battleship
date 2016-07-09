#pragma once
#include "freeglut.h"
#include "enums.h"

class GraphicsRectItem
{
protected:
	int x, y, width, height;
	bool visiable, pressed;
	void (*callbackFunc)();

public:
	GraphicsRectItem();
	GraphicsRectItem(int x, int y, int width, int height, bool visiable, bool pressed, void (*callbackFunc)());
	virtual ~GraphicsRectItem();
	virtual void draw();
	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);
	void setVisiable(bool visiable);
	void setPressed(bool pressed);
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	bool isVisiable() const;
	bool isPressed() const;
	bool mouseOnItem(int mX, int mY);

};