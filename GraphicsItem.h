#pragma once
#include "freeglut.h"
#include "Rect.h"

class GraphicsItem;
typedef void(*CallbackClicked)(GraphicsItem*, int button, int state, int x, int y);

class GraphicsItem
{
protected:
	Rect rect;
	double r, g, b, a;
	bool visible;
	CallbackClicked callbackClicked;

public:
	GraphicsItem();
	GraphicsItem(const Rect& rect, double r = 1.0, double g = 1.0, double b = 1.0, double a = 1.0, bool visible = false, CallbackClicked callbackClicked = NULL);
	virtual ~GraphicsItem();
	virtual void draw()=0;
	void drawRect();
	virtual void mousePressed(int button, int state, int mouseX, int mouseY);
	void setRect(const Rect& rect);
	void setRect(int x, int y, int width, int height);
	void setRGBA(double r, double g, double b, double a);
	void setAlpha(double alpha);
	void setVisible(bool visible);
	void setCallbackClicked(CallbackClicked callbackClicked);
	Rect& getRect();
	double getR() const;
	double getG() const;
	double getB() const;
	double getA() const;
	bool isVisible() const;
	bool contains(int mouseX, int mouseY);

};