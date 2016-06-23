#include "NumericBox.h"



NumericBox::NumericBox(int width, int min, int max):Panel(1,width)
{
	MinusListener minusListener(*this);
	PlusListener plusListener(*this);
	//Create minus btn and attach listener.
	Button *minusBtn = new Button(1,"-");
	minusBtn->addListener(minusListener);
	//Create label.
	Label val( 5 ,to_string(min));
	//Create '+' btn and attach listener.
	Button *plusBtn = new Button(1,"+");
	plusBtn->addListener(plusListener);
	
	addControl(minusBtn, getBodyLeft() + getWidth() - 2, getBodyTop());
	addControl(&val, getBodyLeft() + 1, getBodyTop());
	addControl(plusBtn, getBodyLeft() + 2, getBodyTop());
	this->min = min;
	this->max = max;
}


NumericBox::~NumericBox()
{
}

void NumericBox::setValue(int val) {
	if (value + val < min || value + val >max) return;
	else value += val;
};
int NumericBox::getValue() {return value;};
