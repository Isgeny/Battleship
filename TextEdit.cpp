#include "TextEdit.h"

TextEdit::TextEdit() : GraphicsRectItem(0,0,0,0,false, false, NULL), text(""), focus(false)
{

}

TextEdit::TextEdit(int x, int y, int width, int height, bool visiable, bool clicked, void(*callbackClickedFunc)(GraphicsRectItem *, int button, int state), const std::string& _text, bool _focus) :
	GraphicsRectItem(x, y, width, height, visiable, clicked, callbackClickedFunc), text(_text), focus(_focus)
{

}

TextEdit::~TextEdit()
{

}

void TextEdit::draw()
{
	if(visible)
	{
		GraphicsRectItem::draw();
		std::string name = "Your name:";
		for(int i = 0; i < name.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(x - 145 + i*15, y + 20);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name[i]);
		}
		for(int i = 0; i < text.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(x + 5 + i*15, y + 20);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
		}
		if(focus)
		{
			glLineWidth(1.5);
			glColor3d(0.0, 0.0, 1.0);
			glBegin(GL_LINES);
			glVertex2d(x + 5 + text.size()*15, y + 5);
			glVertex2d(x + 5 + text.size()*15, y + height - 5);
			glEnd();
		}
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

const std::string & TextEdit::getText() const
{
	return text;
}

bool TextEdit::hasFocus() const
{
	return focus;
}
