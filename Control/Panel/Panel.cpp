#include "Panel.h"


Panel::Panel(int height, int width) : Control(width) {
	setHeight(height);
}

void Panel::getAllControls(vector<Control*> &controls) {
	controls = this->controls;
}

void Panel::addControl(Control& control, int, int) {

}

bool Panel::validSpace(Control c) {
	
}

bool Panel::validSpaceWithControllers(Control c) {
	int size = controls.size();
	bool valid = true;
	for (int i = 0; i < size; i++) {
		if (!controls[i]->validSpace(c)) {
			valid = false;
			break;
		}
	}
	return valid;
}

Panel::~Panel() {

}
