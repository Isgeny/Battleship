#pragma once
#include "GraphicsItem.h"
#include "Label.h"
#include "enums.h"

class TextEdit : public GraphicsItem
{
private:
	std::string text;
	bool focus, carriage;
	Label* yourName;
	int carriageX;

public:
	TextEdit();
	TextEdit(const std::string& text, const Rect& rect, bool focus = false, bool carriage = false, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	~TextEdit();
	void draw();
	void mousePressed(int button, int state, int mouseX, int mouseY);
	void keyboardPressed(unsigned char key, int x, int y);
	void setVisible(bool visible);
	void setText(const std::string& text);
	void setFocus(bool focus);
	void setCarriage(bool carriage);
	void setcarriageX(int carriageX);
	const std::string& getText() const;
	bool hasFocus() const;
	bool hasCarriage() const;
	int getCarriageX() const;

};