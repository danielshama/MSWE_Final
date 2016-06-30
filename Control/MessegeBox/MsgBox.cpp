#include "MsgBox.h"


MsgBox::MsgBox(int height, int width) : Panel(height, width)
{
	//toggleMsgBox();
	setLayer(2);
	isfocusable = false;
	title = new Label(width-2, "temp");
	text = new Label(width-2, "text text text");
	okBtn = new Button(width / 2, Label::makeStringInTheMiddle(width/2, "OK"));
	CloseListener *closeListener = new CloseListener(*this);
	okBtn->addListener(*closeListener);
	title->setLayer(2);
	text->setLayer(2);
	okBtn->setLayer(2);
	title->setBorder(BorderType::Single);
	text->setBorder(BorderType::Single);
	okBtn->setBorder(BorderType::Single);
	addControl(title, 1,1);//addControll return bool -> need to think what to do with that
	addControl(text,1,4);
	addControl(okBtn, (width / 4), height-4);//We want the button to be in the middle of the msgBox
}

void MsgBox::mousePressed(short x, short y, bool isLeft) {
	//check if click is in the panel limits
	if (x < this->getLeft() || (x > this->getLeft() + this->getWidth()) ||
		y < this->getTop() || (y > this->getTop() + this->getHeight())) {
		toggleMsgBox();
		hide();
	}

	controls[2]->mousePressed(x, y, isLeft);
}

void MsgBox::setText(string text) {
	this->text->setValue(text);
}

void MsgBox::setTitle(string text) {
	title->setValue(text);
}



void MsgBox::keyDown(WORD click, CHAR chr){
	if (click == VK_RETURN) {
		toggleMsgBox();
		hide();
	}
}

MsgBox::~MsgBox()
{
}
