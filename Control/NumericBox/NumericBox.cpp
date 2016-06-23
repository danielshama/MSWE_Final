#include "NumericBox.h"


NumericBox::NumericBox(int width, int min, int max):Panel(1,width)
{
	MinusListener listener(NumericBox);
	Button minusBtn(1,"-");
	minusBtn.addListener(MinusListener);
	Label val( 5 ,to_string(min));
	Button plusBtn(1,"+");
	plusBtn.addListener(PlusListener);
	addControl(minusBtn, getBodyLeft(), getBodyTop());
	addControl(val, getBodyLeft() + 1, getBodyTop());
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
int NumericBox::getValue() {};