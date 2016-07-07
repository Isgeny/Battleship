#pragma once
#include <string>
#include "GraphicsRectItem.h"

class Button : public GraphicsRectItem
{
private:
	std::string text;

public:
	Button(int x, int y , int width, int height, const std::string& text);
	~Button();
	void draw();
	void setText(std::string& text);
	const std::string& getText() const;

};