#pragma once

#include "../Control/Control.h"
#include <string>

using namespace std;

struct MouseListener{
	virtual void mousePressed(Button& b, int x, int y, bool isLeft) = 0;
};

class Button : public Control
{
	string text;
public:
	Button(int width);

	void draw(Graphics graphics, int, int, size_t);
	void mousePress(short, short, DWORD);
	void setValue(string value);
	void addListener(MouseListener &listener);

	~Button();
};

