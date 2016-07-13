#pragma once
#include "GraphicsRectItem.h"
#include <string>
class TextEdit : public GraphicsRectItem
{
private:
	std::string text;
	bool focus;

public:
	TextEdit();
	TextEdit(int x, int y, int width, int height, bool visiable, bool clicked, void(*callbackClickedFunc)(GraphicsRectItem*, int button, int state), const std::string& text, bool focus);
	~TextEdit();
	void draw();
	void setText(const std::string& text);
	void setFocus(bool focus);
	const std::string& getText() const;
	bool hasFocus() const;

};