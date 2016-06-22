#pragma once

#include "../Panel/Panel.h"

struct CloseListener : public MouseListener{
	CloseListener(Control& c) : _c(c){}
	void mousePressed(Button& b, int x, int y, bool isLeft){
		MsgBox& tmp = static_cast<MsgBox&>(_c);
		tmp.hide();
	}
private:
	Control& _c;
};

class MsgBox : public Panel
{
public:
	//send email to the gay about the class name
	MsgBox(int height, int width);
	void setText(string text);
	void setTitle(string text);
	void draw(Graphics graphics, int, int, size_t);
	void mousePress(short, short, DWORD);
	~MsgBox();
};

