#pragma once

#include "../Control/Control.h"
#include <string>

using namespace std;

struct MouseListener{
	MouseListener() {}
	virtual void mousePressed(Control& b, short x, short y, bool isLeft) = 0;
};

struct MouseListener{
	MouseListener() {}
	virtual void mousePressed(Control& b, short x, short y, bool isLeft) = 0;
};

class Button : public Control
{
protected:
	string text;
	bool clickable;
	MouseListener& listener;
public:
	Button(int width, string text);

	void draw(Graphics graphics, int x, int y, size_t w);
	zzvoid mousePressed(short, short, bool);
	void setValue(string value);
	string getValue();
	void addListener(MouseListener&);

	~Button();
};

