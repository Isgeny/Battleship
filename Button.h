#pragma once
#include <string>
#include "GraphicsRectItem.h"

class Button : public GraphicsRectItem
{
protected:
	std::string text;

public:
	Button(int x, int y , int width, int height, bool visiable, bool pressed, void (*callbackFunc)(), const std::string& text);
	~Button();
	void draw();
	void setText(std::string& text);
	const std::string& getText() const;

};