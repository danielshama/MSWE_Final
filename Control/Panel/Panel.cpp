#include "Panel.h"


Panel::Panel(int height, int width) : Control(width) {
	setHeight(height);
}

void Panel::getAllControls(vector<Control *> controls) {
	controls = this->controls;
}

bool Panel::addControl(Control *control, short x, short y) {
	control->setLocation({ x , y });
	if (validSpace(*control)) {
		controls.push_back(control);
		return true;
	}
	
	return false;
}

bool Panel::validSpace(Control c) {
	short bodyTop = getBodyTop();
	short bodyLeft = getBodyLeft();
	short controllerTop = c.getTop();
	short controllerLeft = c.getLeft();

	//checking if in the panel limits
	if (controllerTop < bodyTop || controllerLeft < bodyLeft) return false;
	if ((controllerTop + c.getHeight()) > (bodyTop + this->getHeight() - 2)) return false;
	if ((controllerLeft + c.getWidth() - 2) > (bodyLeft + this->getWidth() - 2)) return false;

	//checking if posision is clear against all the other controllers in the panel
	return validSpaceWithControllers(c);
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

void Panel::mousePressed(short x, short y, DWORD click) {
	//check if click is in the panel limits
	if (x < this->getLeft() || (x > this->getLeft() + this->getWidth())) return;
	if (y < this->getTop() || (y > this->getTop() + this->getHeight())) return;

	int size = controls.size();
	for (int i = 0; i < size; i++) {//check which controller owns the mouse position
		controls[i]->mousePressed(x, y, click);
	}
}

void Panel::draw(Graphics graphics, int x, int y, size_t t) {
	Control::draw(graphics, getLeft(), getTop(), t);
	graphics.setBackground(graphics.convertToColor(getBackGround()));
	graphics.setForeground(graphics.convertToColor(getForeground()));

	int size = controls.size();
	for (int i = 0; i < size; i++) {
		graphics.moveTo(controls[i]->getBodyLeft(), controls[i]->getBodyTop());
		controls[i]->draw(graphics, controls[i]->getBodyLeft(), controls[i]->getBodyTop(), t);
	}
	graphics.resetColors();
}

void Panel::setLocation(COORD coord) {
	COORD tmp = {getBodyLeft(),getBodyTop()};
	short moveVer, moveHer;
	Control::setLocation(coord);
	int size = controls.size();
	for (size_t i = 0; i < size; i++) {
		moveVer = controls[i]->getBodyTop() - tmp.Y;
		moveHer = controls[i]->getBodyLeft() - tmp.X;
		controls[i]->setLocation({ coord.X + moveHer, coord.Y + moveVer});
	}
}

Panel::~Panel() {

}
