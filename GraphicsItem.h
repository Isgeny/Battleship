#pragma once
#include "Rect.h"
#include "enums.h"

class GraphicsItem;
typedef void(*CallbackClicked)(GraphicsItem*, int button, int state, int x, int y);

class GraphicsItem
{
protected:
	Rect rect;
	CallbackClicked callbackClicked;
	bool visible;
	double r, g, b, a;

public:
	GraphicsItem();
	GraphicsItem(const Rect& rect, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	virtual ~GraphicsItem();
	virtual void draw()=0;
	virtual void mousePressed(int button, int state, int mouseX, int mouseY);
	virtual void setRect(const Rect& rect);
	virtual void setRect(int x, int y, int width, int height);
	virtual void setRGBA(double r, double g, double b, double a);
	virtual void setR(double r);
	virtual void setG(double g);
	virtual void setB(double b);
	virtual void setAlpha(double alpha);
	virtual void setVisible(bool visible);
	virtual void setCallbackClicked(CallbackClicked callbackClicked);
	virtual Rect& getRect();
	virtual double getR() const;
	virtual double getG() const;
	virtual double getB() const;
	virtual double getA() const;
	virtual bool isVisible() const;
	virtual void drawRect();
	virtual bool contains(int x, int y);

};