#pragma once

class Shape;

class Setting
{
public:
	Setting();

	Shape **shape;

	int count;

	int selected_type;
	int selected_thickness;
	int selected_color;


	void AddShape(CPoint pt1, CPoint pt2);
};

