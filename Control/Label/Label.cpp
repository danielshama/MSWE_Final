#include "Label.h"


Label::Label(int width, string value):Control(width)
{
	if (width - value.size() < 2) this->value = value;
	else {
		this->value = makeStringInTheMiddle(width, value);
		
	}
}


Label::~Label()
{
}

void Label::setValue(string val) {
	value = makeStringInTheMiddle(getWidth() - 2, val);
}

void Label::draw(Graphics graphics, int x , int y, size_t s) {
	Control::draw(graphics, x, y, s);
	graphics.setBackground(graphics.convertToColor(getBackGround()));
	graphics.setForeground(graphics.convertToColor(getForeground()));
	graphics.setCursorVisibility(false);
	graphics.write(getBodyLeft(),getBodyTop(), value);
	graphics.resetColors();
}

string Label::makeStringInTheMiddle(int width, string value) {
	
	int mid = (width / 2) - (value.length() / 2);
	string str;
	str.resize(width - value.length());
	str.insert(mid, value);
	return str;
}

string Label::getValue() {
	return value;
}