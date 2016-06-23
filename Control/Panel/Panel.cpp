#include "Panel.h"


Panel::Panel(int height, int width) : Control(width) {
	setHeight(height);
}

void Panel::getAllControls(vector<Control &> &controls) {
	controls = this->controls;
}

bool Panel::addControl(Control &control, short x, short y) {
	control.setLocation({ x, y });
	if (!validSpace(control)) {
		return false;
	}
	else {
		controls.push_back(control);
	}

}

bool Panel::validSpace(Control c) {
	short bodyTop = this->getBodyTop();
	short bodyLeft = this->getBodyLeft();
	short controllerTop = c.getTop();
	short controllerLeft = c.getLeft();

	//checking if in the panel limits
	if (controllerTop > bodyTop || controllerLeft > bodyLeft) return false;
	if ((controllerTop + c.getHeight()) > (bodyTop + this->getHeight() - 1)) return false;
	if ((controllerLeft + c.getWidth()) > (bodyLeft + this->getWidth() - 1)) return false;

	//checking if posision is clear against all the other controllers in the panel
	return validSpaceWithControllers(c);
}

bool Panel::validSpaceWithControllers(Control c) {
	int size = controls.size();
	bool valid = true;
	for (int i = 0; i < size; i++) {
		if (!controls[i].validSpace(c)) {
			valid = false;
			break;
		}
	}
	return valid;
}

Panel::~Panel() {

}
