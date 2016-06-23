#pragma once

#include "../Panel/Panel.h"


struct SelectListener : public MouseListener{
	SelectListener(Control& c) : _c(c){}
	void mousePressed(Button& b, int x, int y, bool isLeft){
		RadioList& tmp = static_cast<RadioList&>(_c);
		tmp.setSelectedIndex(static_cast<ButtonItem&>(b).getIndex());
	}
private:
	Control& _c;
};

class RadioList : public Panel
{
	size_t selectedIndex;
public:
	RadioList(int height, int width, vector<string> options);
	size_t getSelectedIndex();
	void setSelectedIndex(size_t index);
	void draw(Graphics graphics, int, int, size_t);
	void keydown(WORD, CHAR);
	void mousePress(short, short, DWORD);
	~RadioList();
};

