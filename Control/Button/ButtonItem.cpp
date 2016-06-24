#include "ButtonItem.h"


ButtonItem::ButtonItem(string text, int width, size_t index)
	: Button(width, "[ ] " + text), chkedText("[X] " + text), index(index), isCheck(false){}

bool ButtonItem::isChecked(){
	return isCheck;
}

void ButtonItem::mousePressed(short x, short y, bool isLeft){
	if (clickable && (x >= getLeft() || x <= getLeft() + getWidth()) &&
		(y >= getTop() || y <= getTop() + getHeight())){
		listener->mousePressed(*this, x, y, isLeft);
	}
}
void ButtonItem::draw(Graphics graphics, int x, int y, size_t w){
	Control::draw(graphics, getLeft(), getTop(), w);
	if (isChecked()){
		graphics.setBackground(graphics.convertToColor(BackgroundColor::Yellow));
		graphics.setForeground(graphics.convertToColor(BackgroundColor::Teal));
	} else if (isFocus()){
		//insidout
		graphics.setBackground(graphics.convertToColor(getForeground()));
		graphics.setForeground(graphics.convertToColor(getBackGround()));
	} else {
		graphics.setBackground(graphics.convertToColor(getBackGround()));
		graphics.setForeground(graphics.convertToColor(getForeground()));
	}
	graphics.write(getBodyLeft(), getBodyTop(), getValue());
	graphics.resetColors();
}
void ButtonItem::toggle(){
	isCheck = !isCheck;
	string tmp = text;
	text = chkedText;
	chkedText = tmp;
}

size_t ButtonItem::getIndex(){
	return index;
}

ButtonItem::~ButtonItem(){}
