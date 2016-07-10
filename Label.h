#pragma once
#include "freeglut.h"
#include <string>

class Label
{
private:
	std::string text;
	int x, y;
	double r, g, b;
	int charSpace;
	void* font;

public:
	Label();
	Label(const std::string& text, int x, int y, double r, double g, double b, int charSpace, void *font);
	~Label();
	void draw();
	void setText(const std::string& text);
	void setRGB(double r, double g, double b);
	void setCharSpace(int charSpace);
	void setFont(void* font);
	const std::string& getText() const;
	int getX() const;
	int getY() const;
	int getCharSpace() const;
	void* getFont() const;

};