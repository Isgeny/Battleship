#pragma once
class Rect
{
protected:
	int rX, rY, rWidth, rHeight;

public:
	Rect();
	Rect(int x, int y, int width, int height);
	~Rect();
	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);
	int x() const;
	int y() const;
	int width() const;
	int height() const;

};