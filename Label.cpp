#include "Label.h"

Label::Label() : text(""), font(nullptr), space(0), GraphicsItem()
{

}

Label::Label(const std::string& _text, void* _font, int _space, const Rect& rect, CallbackClicked callbackClicked, bool visible, double r, double g, double b, double a) :
	text(_text), font(_font), space(_space), GraphicsItem(rect, callbackClicked, visible, r, g, b, a)
{

}

Label::~Label()
{

}

void Label::draw()
{
	if(visible)
	{
		//��������� ������
		for(int i = 0; i < text.size(); i++)
		{
			glColor4d(r, g, b, a);
			glRasterPos2d(rect.x() + space*i, rect.y());
			glutBitmapCharacter(font, text[i]);
		}
	}
}

void Label::setText(const std::string& _text)
{
	text = _text;
}

void Label::setFont(void* _font)
{
	font = _font;
}

void Label::setSpace(int _space)
{
	space = _space;
}

const std::string& Label::getText() const
{
	return text;
}

void* Label::getFont() const
{
	return font;
}

int Label::getSpace() const
{
	return space;
}