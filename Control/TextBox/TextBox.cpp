#include "TextBox.h"


TextBox::TextBox(int width) : Control(width) , curserPosition(0){}

void TextBox::setValue(string val) {
	value = val.substr(0, getWidth() - 2);
	curserPosition = value.substr(0, getWidth() - 2).length();
}

string TextBox::getValue() {
	return value;
}

void TextBox::draw(Graphics graphics, int x, int y, size_t w) {
	Control::draw(graphics, x, y, w);
	graphics.setBackground(graphics.convertToColor(getBackGround()));
	graphics.setForeground(graphics.convertToColor(getForeground()));
	string toPrint = value.substr(0, getWidth() - 2);
	if (toPrint.length() < getWidth() - 2) {
		toPrint = toPrint + string(getWidth() - 2 - toPrint.length(), ' ');
	}
	graphics.write(getBodyLeft(), getBodyTop(), toPrint);
	if (isFocus()) {
		graphics.setCursorVisibility(true);
		if (curserPosition > getWidth()-2) 
			graphics.moveTo(getBodyLeft() + getWidth() - 1, getBodyTop());
		else if (curserPosition == 1) 
			graphics.moveTo(getBodyLeft(), getBodyTop());
		else
			graphics.moveTo(getLeft() + curserPosition, getBodyTop());
	}
	graphics.resetColors();
}

void TextBox::keyDown(WORD kind, CHAR c) {

	switch (kind)
	{

		case VK_RIGHT:
			moveRight();
			break;
		case VK_LEFT:
			moveLeft();
			break;

		case VK_RWIN:
			moveRight();
			break;

		case VK_LWIN:
			moveLeft();
			break;

		case VK_BACK:
			deleteLeft();
			break;

		case VK_DELETE:
			deleteRight();
			break;
		default:
			addCharecter(c);
			break;
	}
}

void TextBox::mousePressed(short x, short y, bool b){
	//check if click is in the textBox limits
	if (x < this->getLeft() || (x > this->getLeft() + this->getWidth())) return;
	if (y < this->getTop() || (y > this->getTop() + this->getHeight())) return;
	Control::setFocus(this);
}


void TextBox::moveRight(){
	int x = getBodyLeft() + getWidth();
	if (getBodyLeft() + curserPosition > getBodyLeft() +  getWidth() - 3) return;
	curserPosition++;
}

void TextBox::moveLeft(){
	if (curserPosition ==  1) return;
	curserPosition--;
}

void TextBox::deleteLeft(){
	if (curserPosition == 1 || !value.length()) {
		moveLeft();
		return;
	}
	value.erase(curserPosition - 2, 1);
	moveLeft();
}

void TextBox::deleteLast(){
	value.erase(getWidth() - 2, 1);
}

void TextBox::deleteRight(){
	if (curserPosition > value.length()) return;
	value.erase(curserPosition - 1, 1);
}

void TextBox::addCharecter(CHAR c){
	if (value.length() == getWidth() - 2) {
		value.insert(curserPosition - 1, 1, c);
		deleteLast();
	}
	else if (!value.length()) {
		value = string("");
		value.insert(0, 1, c);
	}
	else value.insert(curserPosition - 1, 1, c);
	moveRight();
}

TextBox::~TextBox() {}
