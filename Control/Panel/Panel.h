#pragma once

#include "../Control/Control.h"
#include "../Button/Button.h"
#include "../Button/ButtonItem.h"
#include <vector>

using namespace std;

class Panel : public Control
{
	vector<Control*> controls;
public:
	Panel(int height, int width);
	void addControl(Control& control, int, int);
	bool validSpace(Control c); //checks if the contrller is in the panel limits
	bool validSpaceWithControllers(Control c);

	void getAllControls(vector<Control*> &controls);
	void draw(Graphics graphics, int, int, size_t);
	void keydown(WORD, CHAR);
	void mousePress(short, short, DWORD);

	~Panel();
};

