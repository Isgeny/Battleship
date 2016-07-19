#pragma once
#include "GraphicsItem.h"
#include "Label.h"
#include "enums.h"

class Table : public GraphicsItem
{
protected:
	int rows, columns;
	int cellWidth, cellHeight;
	std::vector<Label*> cells;

public:
	Table(int rows, int columns, const Rect& rect, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	~Table();
	void draw();
	void setVisible(bool visible);
	void addData(int row, int column, const std::string& text);
	void deleteData();

};