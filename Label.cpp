#include "Label.h"

Label::Label() : text(""), x(0), y(0), r(0), g(0), b(0), charSpace(0), font(NULL)
{

}

Label::Label(const std::string& _text, int _x, int _y, double _r, double _g, double _b, int _charSpace, void *_font) :
	text(_text), x(_x), y(_y), r(_r), g(_g), b(_b), charSpace(_charSpace), font(_font)
{

}

Label::~Label()
{

}

void Label::draw()
{
	for(int i = 0; i < text.size(); i++)
	{
		glColor3d(r, g, b);
		glRasterPos2d(x + i*charSpace, y);
		glutBitmapCharacter(font, text[i]);
	}
}

void Label::setText(const std::string & _text)
{
	text = _text;
}

void Label::setRGB(double _r, double _g, double _b)
{
	r = _r; g = _g; b = _b;
}

void Label::setCharSpace(int _charSpace)
{
	charSpace = _charSpace;
}

void Label::setFont(void* _font)
{
	font = _font;
}

const std::string & Label::getText() const
{
	return text;
}

int Label::getX() const
{
	return x;
}

int Label::getY() const
{
	return y;
}

int Label::getCharSpace() const
{
	return charSpace;
}

void* Label::getFont() const
{
	return font;
}