#include "Label.h"


Label::Label(int width, string value)
{
	Control(width);
	setValue(value);
}


Label::~Label()
{
}

void Label::setValue(string value) {
	value = value;
}