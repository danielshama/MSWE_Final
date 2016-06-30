#include "NumericBox.h"



NumericBox::NumericBox(int width, int min, int max):Panel(5,width)
{
	value = min;
	MinusListener* minusListener = new MinusListener(*this);
	PlusListener* plusListener = new PlusListener(*this);
	//Create minus btn and attach listener.
	Button *minusBtn = new Button(1,"-");
	minusBtn->addListener(*minusListener);
	//minusBtn->setHeight(1);
	//Create label the number starts from the minimum.
	Label *labelVal = new Label( width - 8 ,to_string(min));
	labelVal->setForeground(ForegroundColor::Blue);
	
	//Create '+' btn and attach listener.
	Button *plusBtn = new Button(1,"+");
	//plusBtn->setHeight(1);
	plusBtn->addListener(*plusListener);
	
	addControl(minusBtn, getBodyLeft(), getBodyTop());
	addControl(labelVal, getBodyLeft() +((width-8)/2), getBodyTop());
	addControl(plusBtn, labelVal->getLeft() + labelVal->getWidth(), getBodyTop());
	this->min = min;
	this->max = max;
}


NumericBox::~NumericBox()
{
}

void NumericBox::setValue(int val) {
	
	if ( val < min || val >max) return;
	else {
		static_cast<Label*>(controls[1])->setValue(to_string(val));
	}
};
int NumericBox::getValue() {	
	string val = static_cast<Label*>(controls[1])->getValue();
	return stoi(val);
};
