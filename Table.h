#pragma once
#include <vector>
#include "GraphicsItem.h"
#include "Label.h"

class Table : public GraphicsItem
{
private:
	int rows, columns;
	int cellWidth, cellHeight;
	std::vector<Label*> cells;

public:
	Table(int rows, int columns, const Rect& rect, double r = 1.0, double g = 1.0, double b = 1.0, double a = 1.0, bool visible = false, CallbackClicked callbackClicked = NULL);
	~Table();
	void draw();
	void addData(int row, int column, const std::string& text);

};