#pragma once

#include "../Panel/ListPanel.h"
#include "../Button/ButtonItem.h"
#include "../Label/Label.h"



class ComboBox : public ListPanel
{
	struct SelectListener : public MouseListener {
		SelectListener(Control& c) : _c(c) {}
		void mousePressed(Control& b, short x, short y, bool isLeft) {
			ComboBox& tmp = static_cast<ComboBox&>(_c);
			int index = static_cast<ButtonItem&>(b).getIndex();
			tmp.setSelectedIndex(static_cast<ButtonItem&>(b).getIndex());
		}
	private:
		Control& _c;
	};

	struct ToggleListener : public MouseListener {
		ToggleListener(Control& c) : _c(c) {}
		void mousePressed(Control& b, short x, short y, bool isLeft) {
			ComboBox& tmp = static_cast<ComboBox&>(_c);
			tmp.toggle();
		}
	private:
		Control& _c;
	};

	Label *choosen;
	size_t selectedIndex;
	bool isOpen;
public:
	//add plus btn and label - give the btn listener and remember whe label index for edit the text
	ComboBox(int width, vector<string> options); //need to caculat the heigth and send to Panel const.
	size_t getSelectedIndex();
	void setSelectedIndex(size_t);
	//void draw(Graphics graphics, int, int, size_t);
	void keyDown(WORD, CHAR);
	void mousePressed(short, short, bool);
	void toggle();
	~ComboBox();
};

