#pragma once

#include "../Control/Control.h"

class TextBox : public Control
{
	string value;

	int curserPosition;
	void moveRight();
	void moveLeft();
	void deleteRight();
	void deleteLeft();
	void addCharecter(CHAR c);
public:
	TextBox(int width);
	void setValue(string value);
	string getValue();
	void draw(Graphics graphics, int, int, size_t);
	void keyDown(WORD, CHAR);
	void mousePress(short, short, DWORD);
	~TextBox();
};

