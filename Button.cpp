#include "Button.h"
Button::Button() : text(NULL), GraphicsItem()
{

}

Button::Button(const std::string& _text, const Rect& rect, double r, double g, double b, double a, bool visible, CallbackClicked callbackClicked) :
	GraphicsItem(rect, r, g, b, a, visible, callbackClicked)
{
	text = new Label(_text, GLUT_BITMAP_HELVETICA_18, 16, Rect(rect.x() + rect.width()/2 - _text.size()*15/2, rect.y() + rect.height()/2 + 6, 0, 0), r, g, b, a, true);
}

Button::~Button()
{
	delete text;
}

void Button::draw()
{
	if(visible)
	{
		text->draw();
		drawRect();
	}
}

void Button::mousePressed(int button, int state, int mouseX, int mouseY)
{
	GraphicsItem::mousePressed(button, state, mouseX, mouseY);
}

void Button::setText(Label* _text)
{
	text = _text;
}

void Button::setAlpha(double alpha)
{
	a = alpha;
	text->setAlpha(alpha);
}

Label* Button::getText() const
{
	return text;
}