#include "ButtonItem.h"


ButtonItem::ButtonItem(string text, int width, size_t index)
	: Button(width, "[ ] " + text), chkedText("[X] " + text), index(index), isCheck(false){}

bool ButtonItem::isChecked(){
	return isCheck;
}

void ButtonItem::mousePressed(short x, short y, bool isLeft){
	if (clickable){
		toggle();
		listener->mousePressed(*this, x, y, isLeft);
	}
}

void ButtonItem::toggle(){
	isCheck != isCheck;
	string tmp = text;
	text = chkedText;
	chkedText = tmp;
}

size_t ButtonItem::getIndex(){
	return index;
}

ButtonItem::~ButtonItem(){}
