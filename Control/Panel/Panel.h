#pragma once

#include "../Control/Control.h"
#include "../Label/Label.h"
#include <vector>

using namespace std;

class Panel : public Control
{
	vector<Control *> controls;
public:
	Panel(int height, int width);
	bool addControl(Control *control, short, short);
	bool validSpace(Control c); //checks if the contrller is in the panel limits
	bool validSpaceWithControllers(Control c);

	void getAllControls(vector<Control *> &controls);
	void draw(Graphics graphics, int, int, size_t);
	void mousePressed(short, short, DWORD);

	~Panel();
};

