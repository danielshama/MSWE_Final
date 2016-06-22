#pragma once

#include "../Panel/Panel.h"

struct PlusListener : public MouseListener{
	PlusListener(Control& c) : _c(c){}
	void mousePressed(Button& b, int x, int y, bool isLeft){
		NumericBox& tmp = static_cast<NumericBox&>(_c);
		tmp.setValue(tmp.getValue() + 1);
	}
private:
	Control& _c;
};

struct MinusListener : public MouseListener{
	MinusListener(Control& c) : _c(c){}
	void mousePressed(Button& b, int x, int y, bool isLeft){
		NumericBox& tmp = static_cast<NumericBox&>(_c);
		tmp.setValue(tmp.getValue() - 1);
	}
private:
	Control& _c;
};

class NumericBox : public Panel
{
	int value;
public:
	//add listeners to the buttons + chk if its the first btn in the vector and give him the relevant lisener
	NumericBox(int width, int min, int max);
	void setValue(int value);
	int getValue();
	~NumericBox();
};

