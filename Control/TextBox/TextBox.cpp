#include "TextBox.h"


TextBox::TextBox(int width) : Control(width) , curserPosition(0){}

void TextBox::setValue(string val) {
	value = val;
	curserPosition = val.length();
}

string TextBox::getValue() {
	return value;
}

void TextBox::draw(Graphics graphics, int x, int y, size_t w) {
	Control::draw(graphics, x, y, w);
	graphics.moveTo(getBodyLeft(), getBodyTop());
	string toPrint = value.substr(0, getWidth() - 2);
	graphics.write(getBodyLeft(), getBodyTop(), toPrint);
	if (isFocus()) {
		graphics.setCursorVisibility(true);
		if (curserPosition > getWidth()-1) 
			graphics.moveTo(getBodyLeft() + getWidth()-3, getBodyTop());
		else 
			graphics.moveTo(getBodyLeft() + curserPosition, getBodyTop());
	}
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

void TextBox::mousePress(short, short, DWORD){

}


void TextBox::moveRight(){
	int x = getBodyLeft() + getWidth();
	if (curserPosition + 1 > getWidth()) return;
	curserPosition++;
}

void TextBox::moveLeft(){
	int x = getBodyLeft();
	if (curserPosition - 1 < getBodyLeft()) return;
	curserPosition--;
}

void TextBox::deleteLeft(){

}

void TextBox::deleteRight(){

}
void TextBox::addCharecter(CHAR c){

}

TextBox::~TextBox()
{
}
