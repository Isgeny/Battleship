#include "TextEdit.h"

TextEdit::TextEdit() : text(""), yourName(NULL), GraphicsItem()
{

}

TextEdit::TextEdit(const std::string& _text, const Rect& rect, double r, double g, double b, double a, bool visible, CallbackClicked callbackClicked, bool _focus) :
	text(_text), focus(_focus), GraphicsItem(rect, r, g, b, a, visible, callbackClicked)
{
	yourName = new Label("Your name:", GLUT_BITMAP_HELVETICA_18, 15, Rect(rect.x() - 142, rect.y() + 20, 0, 0), r, g, b, a, true);
}

TextEdit::~TextEdit()
{
	delete yourName;
}

void TextEdit::draw()
{
	if(visible)
	{
		yourName->draw();
		//Рисование прямоугольника
		glLineWidth(3.0);
		glBegin(GL_LINE_LOOP);
		glColor4d(r, g, b, a);
		glVertex2d(rect.x() + rect.width(), rect.y() + rect.height());
		glVertex2d(rect.x() + rect.width(), rect.y());
		glVertex2d(rect.x(), rect.y());
		glVertex2d(rect.x(), rect.y() + rect.height());
		glEnd();
		for(int i = 0; i < text.size(); i++)
		{
			glColor4d(r, g, b, a);
			glRasterPos2d(rect.x() + 5 + i*15, rect.y() + 20);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
		}
		if(focus)
		{
			glLineWidth(1.5);
			glColor4d(r, g, b, a);
			glBegin(GL_LINES);
			glVertex2d(rect.x() + 5 + text.size()*15, rect.y() + 5);
			glVertex2d(rect.x() + 5 + text.size()*15, rect.y() + rect.height() - 5);
			glEnd();
		}
	}
}

void TextEdit::mousePressed(int button, int state, int mouseX, int mouseY)
{
	if(contains(mouseX, mouseY))
	{
		GraphicsItem::mousePressed(button, state, mouseX, mouseY);
		focus = true;
	}
	else
	{
		focus = false;
	}
}

void TextEdit::setText(const std::string& _text)
{
	text = _text;
}

void TextEdit::setFocus(bool _focus)
{
	focus = _focus;
}

const std::string& TextEdit::getText() const
{
	return text;
}

bool TextEdit::hasFocus() const
{
	return focus;
}