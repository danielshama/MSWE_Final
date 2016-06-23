#include "Button.h"

Button::Button(int width): Control(width), clickable(true){
}

void Button::draw(Graphics graphics, int x, int y, size_t w){
	Control::draw(graphics, x, y, w);
	graphics.write(getLeft() + 1, getTop() + 1, getValue());
}
void Button::mousePressed(short x, short y, bool isLeft){
	if (clickable){
		listener->mousePressed(*this, x, y, isLeft);
	}
}
void Button::setValue(string value){
	text = value;
}
void Button::addListener(MouseListener& listnr){
	listener = &listnr;
}
string Button::getValue(){
	return text;
}

Button::~Button()
{
}
