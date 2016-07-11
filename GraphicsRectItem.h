#pragma once
#include "freeglut.h"
#include "enums.h"

class GraphicsRectItem
{
protected:
	int x, y, width, height;
	bool visible, clicked;
	int button, state;
	void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state);

public:
	GraphicsRectItem();
	GraphicsRectItem(int x, int y, int width, int height, bool visible, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state));
	virtual ~GraphicsRectItem();
	virtual void draw();
	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);
	void setvisible(bool visible);
	void setClicked(bool clicked);
	void setButton(int button);
	void setState(int state);
	void setCallbackClickedFunc(void(*callbackClickedFunc)(GraphicsRectItem*, int button, int state));
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	bool isvisible() const;
	bool isclicked() const;
	int getButton() const;
	int getState() const;
	bool mouseOnItem(int mX, int mY);

};