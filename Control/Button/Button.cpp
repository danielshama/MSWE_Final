#include "Button.h"

Button::Button(int width, string text) : Control(width), text(text), clickable(true), listener(){
}

void Button::draw(Graphics graphics, int x, int y, size_t w){
	Control::draw(graphics, x, y, w);
	graphics.setBackground(graphics.convertToColor(getBackGround()));
	graphics.setForeground(graphics.convertToColor(getForeground()));
	graphics.write(getBodyLeft(), getBodyTop(), getValue());
	graphics.resetColors();
}
void Button::mousePressed(short x, short y, bool isLeft){
	if (clickable && (x >= getLeft() || x <= getLeft() + getWidth()) &&
		(y >= getTop() || y <= getTop() + getHeight())){
		listener.mousePressed(*this, x, y, isLeft);
	}
}
void Button::setValue(string value){
	text = value;
}
void Button::addListener(MouseListener& listnr){
	listener = listener;
}
string Button::getValue(){
	return text;
}

Button::~Button(){
}
