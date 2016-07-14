#include "Button.h"

Button::Button(int x, int y, int width, int height, bool visible, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state), const std::string& _text) :
	GraphicsRectItem(x, y, width, height, visible, clicked, callbackClickedFunc), text(_text)
{

}

Button::~Button()
{

}

void Button::draw()
{
	if(visible)
	{
		GraphicsRectItem::draw();
		int space = 15;
		for(int i = 0; i < text.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(x + width / 2 - text.size()*space / 2.15 + i*space, y + height / 1.65);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
		}
	}
}

void Button::setText(std::string& aText)
{
	text = aText;
}

const std::string& Button::getText() const
{
	return text;
}