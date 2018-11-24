#include "stdafx.h"
#include "Setting.h"
#include "Shape.h"

Setting::Setting() {

	shape = new Shape*[50];

	count = 0;

	selected_type = 1;
	selected_color = RGB(0, 0, 0);
	selected_thickness = 1;

}

void Setting::AddShape(CPoint pt1, CPoint pt2) {

	shape[count++] = new Shape(pt1, pt2, selected_type, selected_thickness, selected_color, -1);
}

