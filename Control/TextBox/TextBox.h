#pragma once

#include "../Control/Control.h"

class TextBox : public Control
{
	string value;
public:
	TextBox(int width);
	void setValue(string value);
	string getValue();
	void draw(Graphics graphics, int, int, size_t);
	void keydown(WORD, CHAR);
	void mousePress(short, short, DWORD);
	~TextBox();
};

