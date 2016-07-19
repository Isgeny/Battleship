#include "Button.h"

Button::Button() : text(nullptr), GraphicsItem()
{

}

Button::Button(const std::string& _text, const Rect& rect, CallbackClicked callbackClicked, bool visible, double r, double g, double b, double a) :
	GraphicsItem(rect, callbackClicked, visible, r, g, b, a)
{
	text = new Label(_text, GLUT_BITMAP_HELVETICA_18, 16, Rect(rect.x() + rect.width()/2 - _text.size()*15/2, rect.y() + rect.height()/2 + 6, 0, 0), nullptr, visible);
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

void Button::setVisible(bool visible)
{
	GraphicsItem::setVisible(visible);
	text->setVisible(visible);
}

void Button::setText(Label* _text)
{
	text = _text;
}

void Button::setText(const std::string& _text)
{
	text->setText(_text);
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