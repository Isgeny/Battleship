#pragma once
#include <string>
#include "GraphicsRectItem.h"

class Button : public GraphicsRectItem
{
protected:
	std::string text;

public:
	Button(int x, int y , int width, int height, bool visible, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state), const std::string& text);
	~Button();
	void draw();
	void setText(std::string& text);
	const std::string& getText() const;

};