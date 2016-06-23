#pragma once

#include "../Control/Control.h"
#include <string>

class Label : public Control
{
	string value;
public:
	Label(int width, string value);

	void setValue(string value);
	void draw(Graphics graphics, int, int, size_t);
	string makeStringInTheMiddle(int width, string value);
	~Label();
};

