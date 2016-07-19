#pragma once
#include "GraphicsItem.h"
#include "enums.h"

class Label : public GraphicsItem
{
private:
	std::string text;
	void* font;
	int space;

public:
	Label();
	Label(const std::string& text, void* font, int space, const Rect& rect, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	~Label();
	void draw();
	void setText(const std::string& text);
	void setFont(void* font);
	void setSpace(int space);
	const std::string& getText() const;
	void* getFont() const;
	int getSpace() const;

};