#pragma once

#include "../Control/Control.h"
#include "../Butten/Button.h"
#include "../Butten/ButtonItem.h"
#include <vector>

using namespace std;

class Panel : public Control
{
	vector<Control*> controls;
	int height;
public:
	Panel(int height, int width);
	void addControl(Control& control, int, int);
	bool validSpace(short x, short y);
	vector<Control*> getAllControllers();

	void draw(Graphics graphics, int, int, size_t);
	void keydown(WORD, CHAR);
	void mousePress(short, short, DWORD);

	~Panel();
};

