#include "ListPanel.h"


ListPanel::ListPanel(int height, int width, vector<string> options) :Panel(height, width){
}

void ListPanel::setForeground(ForegroundColor color){
	Control::setForeground(color);
	int size = controls.size();
	for (int i = 0; i < size; i++) {
		controls[i]->setForeground(color);
	}
}
void ListPanel::setBackGround(BackgroundColor color){
	Control::setBackGround(color);
	int size = controls.size();
	for (int i = 0; i < size; i++) {
		controls[i]->setBackGround(color);
	}
}

int ListPanel::itemInFocus(){
	int len = controls.size();
	for (size_t i = 0; i < len; i++){
		if (static_cast<ButtonItem*>(controls[i])->isFocus()){
			return i;
		}
	}
	return -1;
}

void ListPanel::keyDown(WORD click, CHAR chr){
	if (click == VK_DOWN || click == VK_NUMPAD2) { // maybe add click == VK_TAB
		int item = itemInFocus();
		if (item != -1){
			controls[item]->unfocus();
			if (item >= controls.size() - 1) item = 0;
			else item += 1;
		}
		else item = 0;
		controls[item]->focus();
	}
	else if (click == VK_UP || click == VK_NUMPAD8) {
		int item = itemInFocus();

		if (item != -1){
			controls[item]->unfocus();
			if (item == 0) item = controls.size() - 1;
			else item -= 1;
		}
		else item = 0;
		controls[item]->focus();
	}
}


ListPanel::~ListPanel()
{
}
