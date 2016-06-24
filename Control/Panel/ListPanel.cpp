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

size_t ListPanel::itemInFocus(){
	int len = controls.size();
	for (size_t i = 0; i < len; i++){
		if (static_cast<ButtonItem*>(controls[i])->isChecked()){
			return i;
		}
	}
	return -1;
}

ListPanel::~ListPanel()
{
}
