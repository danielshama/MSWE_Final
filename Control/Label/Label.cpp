#include "Label.h"


Label::Label(int width, string value):Control(width)
{
	setValue(value);
}


Label::~Label()
{
}

void Label::setValue(string val) {
	value = val;
}

void Label::draw(Graphics graphics, int x , int y, size_t s) {
	Control::draw(graphics, x, y, s);
	graphics.setCursorVisibility(false);
	graphics.write(getBodyLeft(),getBodyTop(),makeStringInTheMiddle(getWidth(), value));
}

string Label::makeStringInTheMiddle(int width, string value) {
	int mid = (width / 2) - (value.size() / 2);
	string str;
	str.resize(width);
	str.insert(mid, value);
	return str;
}
