#include "CheckList.h"


CheckList::CheckList(int height, int width, vector<string> options) : ListPanel(height, width, options){
	int len = options.size();
	for (int i = 0 ; i < len ; i++){ 
		ButtonItem *btn = new ButtonItem(options[i], getWidth()-4, getHeight());
		SelectListener lsnr(*this);
		btn->addListener(lsnr);
		addControl(btn, getBodyLeft(), getBodyTop() + (i * 3));
	}
}



vector<size_t> CheckList::getSelectedIndices(){
	vector<size_t> selecteds;
	getAllControls(controls);
	int size = controls.size();
	for (int i = 0; i < size; i++){
		if (static_cast<ButtonItem*>(controls[i])->isChecked()) selecteds.push_back(i);
	}
	return selecteds;
}

void CheckList::selectIndex(size_t index){
	static_cast<ButtonItem*>(controls[index])->toggle();
}
void CheckList::deselectIndex(size_t index){
	static_cast<ButtonItem*>(controls[index])->toggle();
}

void CheckList::keyDown(WORD click, CHAR chr){
	if (click == VK_RETURN) {
		selectIndex(itemInFocus());
	}
	else if (click == VK_DOWN || click == VK_NUMPAD2) { // maybe add click == VK_TAB
		size_t item = itemInFocus();
		if (item > controls.size()) item = 0;
		else item += 1;
		Control::setFocus(controls[item]);
	}
	else if (click == VK_UP || click == VK_NUMPAD8) {
		size_t item = itemInFocus();
		if (item == 0) item = controls.size() - 1;
		else item -= 1;
		Control::setFocus(controls[item]);
	}
}

void CheckList::mousePress(short x, short y, DWORD click){
	if (x < this->getLeft() || (x > this->getLeft() + this->getWidth())) return;
	if (y < this->getTop() || (y > this->getTop() + this->getHeight())) return;

	Control::setFocus(this);

	int size = controls.size();
	for (int i = 0; i < size; i++) {
		controls[i]->mousePressed(x, y, click);
	}
}




CheckList::~CheckList(){
}
