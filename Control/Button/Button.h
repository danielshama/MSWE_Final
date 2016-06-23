#pragma once

#include "../Control/Control.h"
#include <string>

using namespace std;

struct MouseListener{
	virtual void mousePressed(Button& b, short x, int y, short isLeft) = 0; //chk what is it 
};

class Button : public Control
{
	string text;
	MouseListener* listener;
	bool clickable;
public:
	Button(int width);

	void draw(Graphics graphics, int, int, size_t);
	void mousePressed(short, short, bool);
	void setValue(string value);
	string getValue();
	void addListener(MouseListener&);

	~Button();
};

