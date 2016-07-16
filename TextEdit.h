#pragma once
#include "GraphicsItem.h"
#include "Label.h"
#include <string>
class TextEdit : public GraphicsItem
{
private:
	std::string text;
	bool focus;
	Label* yourName;

public:
	TextEdit();
	TextEdit(const std::string& text, const Rect& rect, double r = 1.0, double g = 1.0, double b = 1.0, double a = 1.0, bool visible = false, CallbackClicked callbackClicked = NULL, bool focus = false);
	~TextEdit();
	void draw();
	void mousePressed(int button, int state, int mouseX, int mouseY);
	void setText(const std::string& text);
	void setFocus(bool focus);
	const std::string& getText() const;
	bool hasFocus() const;

};