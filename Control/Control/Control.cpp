#include "Control.h"



Control::Control(int _width) : 
	width(_width), isFocused(false), isfocusable(false), visible(true), height(1){
	setBorder(BorderType::None);
	setLocation({ 0, 0 });
	width += 2;
	height += 2;
	background = BackgroundColor::Black;
	foreground = ForegroundColor::White;
}

void Control::show(){
	visible = true;
}
void Control::hide(){
	visible = false;
}
void Control::focus(){
	isFocused = true;
}
void Control::unfocus(){
	isFocused = false;
}
void Control::setForeground(ForegroundColor color){
	foreground = color;
}
void Control::setBackGround(BackgroundColor color){
	background = color;
}

ForegroundColor Control::getForeground(){
	return foreground;
}
BackgroundColor Control::getBackGround(){
	return background;
}

void Control::setBorder(BorderType type){
	borderType = type;
}

BorderType Control::getBorderType(){
	return borderType;
}
char Control::getBorderTypeHorizontal(){
	switch (getBorderType())
	{
	case BorderType::Single:
			return '-';
			break;
	case BorderType::Double:
		return '=';
		break;
	default:
		return NULL;
		break;
	}
}
char Control::getBorderTypeVertical(){
	switch (getBorderType())
	{
	case BorderType::Single:
		return '|';
		break;
	case BorderType::Double:
		return 186; // ' || '
		break;
	default:
		return NULL;
		break;
	}
}
void Control::setLocation(COORD c){
	location = c;
	bodyLocation = { c.X + 1, c.Y + 1 };
}
void Control::draw(Graphics graphics, int x, int y, size_t w){
	string str(width, getBorderTypeHorizontal());
	graphics.write(getLeft(), getTop(), str);
	
	for (int i = 0; i < height - 1; i++){
		string strv(width, ' ');
		strv[0] = getBorderTypeVertical();
		strv[width-1] = getBorderTypeVertical();
		graphics.write(getLeft(), (getTop() + 1 ) + i, strv);
	}
	graphics.write(location.X, location.Y + (height - 1), str);
}

void Control::keyDown(WORD, CHAR){} 

void Control::mousePressed(short x, short y, DWORD click){
	//check if click is in the panel limits
	if (x < this->getLeft() || (x > this->getLeft() + this->getWidth())) return;
	if (y < this->getTop() || (y > this->getTop() + this->getHeight())) return;

	Control::setFocus(this);
}

bool Control::canGetFocus(){
	return isfocusable;
}
bool Control::validSpace(Control c){
	//take care for the border
	if ((c.getLeft() + c.getWidth()) < getLeft() ||
		(getLeft() + getWidth()) < c.getLeft()) {
		return true;
	}
	else if ( (c.getTop() + c.getHeight() ) > getTop() ||
		(getTop() + getHeight()) < c.getTop()) {
		return true;;
	}
	return false;
}
bool Control::isFocus(){
	return isFocused;
}
bool Control::isVisible(){
	return visible;
}
short Control::getLeft(){
	return location.X;
}
short Control::getTop(){
	return location.Y;
}

short Control::getBodyLeft(){
	return bodyLocation.X;
}
short Control::getBodyTop(){
	return bodyLocation.Y;
}

int Control::getWidth(){
	return width;
}
int Control::getHeight(){
	return height;
}

void Control::setHeight(int h) {
	height = h;
}

void Control::setWidth(int w) {
	width = w;
}

void Control::getAllControls(vector<Control *> &controls){

}
	
void Control::setFocus(Control* c){
	if (currentFocused != NULL)
		currentFocused->unfocus();
	currentFocused = c;
	c->focus();
}
Control* Control::getFocus(){
	return currentFocused;
}
Control::~Control(){

}