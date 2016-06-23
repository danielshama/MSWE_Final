#pragma once

#include "../Panel/Panel.h"
#include "../Button/ButtonItem.h"

struct SelectListener : public MouseListener{
	SelectListener(Control& c) : _c(c){}
	void mousePressed(Button& b, short x, short y, bool isLeft){
		CheckList& tmp = static_cast<CheckList&>(_c);
		tmp.selectIndex(static_cast<ButtonItem&>(b).getIndex());
	}
private:
	Control& _c;
};

class CheckList : public Panel
{
public:
	CheckList(int height, int width, vector<string> options);
	vector<size_t> getSelectedIndices(); //for on the buttonItems and chks who is checked
	void selectIndex(size_t index);
	void deselectIndex(size_t index);
	void keyDown(WORD, CHAR);
	void mousePress(short, short, DWORD);
	~CheckList();
};

