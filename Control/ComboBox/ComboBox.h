#pragma once

#include "../Panel/Panel.h"

struct SelectListener : public MouseListener{
	SelectListener(Control& c) : _c(c){}
	void mousePressed(Button& b, int x, int y, bool isLeft){
		ComboBox& tmp = static_cast<ComboBox&>(_c);
		tmp.setSelectedIndex(static_cast<ButtonItem&>(b).getIndex());
	}
private:
	Control& _c;
};

struct ToggleListener : public MouseListener{
	ToggleListener(Control& c) : _c(c){}
	void mousePressed(Button& b, int x, int y, bool isLeft){
		ComboBox& tmp = static_cast<ComboBox&>(_c);
		tmp.toggle();
	}
private:
	Control& _c;
};

class ComboBox : public Panel
{
	size_t selectedIndex;
	bool isOpen;
public:
	//add plus btn and label - give the btn listener and remember whe label index for edit the text
	ComboBox(int width, vector<string> options); //need to caculat the heigth and send to Panel const.
	size_t getSelectedIndex();
	void setSelectedIndex(size_t);
	void draw(Graphics graphics, int, int, size_t);
	void keydown(WORD, CHAR);
	void mousePress(short, short, DWORD);
	void toggle();
	~ComboBox();
};

