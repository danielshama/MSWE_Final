#include "ComboBox.h"


ComboBox::ComboBox(int width, vector<string> options) : ListPanel(getHeight(), width, options), closeHeight(5), isOpen(false){
	int len = options.size();
	openHeight = (len + 1) * 3 + 2;
	setHeight(openHeight);
	int wid = getWidth();
	//create the label
	choosen = new Label(getWidth() - 7, options[0]);
	choosen->setBorder(BorderType::Double);
	addControl(choosen, getBodyLeft(), getBodyTop());

	//create the open/close button
	Button *toggleBtn = new Button(1, "+");
	toggleBtn->setBackGround(BackgroundColor::Blue);
	toggleBtn->setBorder(BorderType::Single);
	SelectListener* lsnr = new SelectListener(*this);
	toggleBtn->addListener(*lsnr);
	addControl(toggleBtn, getBodyLeft() + getWidth() - 5, getBodyTop());

	//create the options
	string str = string(Control::getWidth(),' ');
	for (int i = 0; i < len; i++) {
		string toInsert = (options[i]+str).substr(0, getWidth());
		ButtonItem *btn = new ButtonItem(toInsert, getWidth() - 4, i);
		btn->setBorder(BorderType::Single);
		SelectListener* lsnr = new SelectListener(*this);
		btn->addListener(*lsnr);
		addControl(btn, getBodyLeft(), getBodyTop() + ((i+1) * 3));
	}

	setHeight(closeHeight);
	toggle();
}


size_t ComboBox::getSelectedIndex() {
	return 1;
}

void ComboBox::setSelectedIndex(size_t) {
}


void ComboBox::draw(Graphics graphics, int, int, size_t t) {
	
	Control::draw(graphics, getLeft(), getTop(), t);
	graphics.setBackground(graphics.convertToColor(getBackGround()));
	graphics.setForeground(graphics.convertToColor(getForeground()));
	for (int i = 0; i < 2; i++) {
		graphics.moveTo(controls[i]->getBodyLeft(), controls[i]->getBodyTop());
		controls[i]->draw(graphics, controls[i]->getBodyLeft(), controls[i]->getBodyTop(), t);
	}
	if (isOpen) {
		int size = controls.size();
		for (int i = 2; i < size; i++) {
			graphics.moveTo(controls[i]->getBodyLeft(), controls[i]->getBodyTop());
			controls[i]->draw(graphics, controls[i]->getBodyLeft(), controls[i]->getBodyTop(), t);
		}
	}
	graphics.resetColors();
}

void ComboBox::keyDown(WORD w, CHAR c) {

}
void ComboBox::mousePressed(short x, short y , bool isLeft) {
	if (x < this->getLeft() || (x > this->getLeft() + this->getWidth())) return;
	if (y < this->getTop() || (y > this->getTop() + this->getHeight())) return;
	Control::setFocus(this);
	if (x == getBodyLeft() + getWidth() - 5 && y == getBodyTop()) {
		controls[1]->mousePressed(x, y, isLeft);

	}
	int size = controls.size();
	for (int i = 0; i < size; i++) {
		controls[i]->mousePressed(x, y, isLeft);
	}
}
void ComboBox::toggle() {
	if (isOpen) {
		isOpen = false;
		setHeight(closeHeight);
	}
	else {
		isOpen = true;
		setHeight(openHeight);
	}
}

ComboBox::~ComboBox()
{
}
