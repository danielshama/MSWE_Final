#include "CheckList.h"


CheckList::CheckList(int height, int width, vector<string> options):Panel(height,width){
	int len = options.size();
	for (int i = 0 ; i < len ; i++){ 
		ButtonItem btn(options[i], width, height);
		SelectListener lsnr(*this);
		btn.addListener(lsnr);
		addControl(&btn, getBodyLeft(), getBodyTop() + i);
	}
}

vector<size_t> CheckList::getSelectedIndices(){
	vector<size_t> selecteds;
	getAllControls(controls);
	for (int i = 0; i < controls.size(); i++){
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
		
	}
	else if (click == VK_TAB || click == VK_DOWN || click == VK_NUMPAD2) {
		if (clickedItem < amount - 1) {
			items[clickedItem].unclick();
			isClicked[clickedItem] = 0;
			items[clickedItem + 1].click();
			isClicked[clickedItem + 1] = 1;
		}
	}
	else if (click == VK_UP || click == VK_NUMPAD8) {
		if (clickedItem > 0) {
			items[clickedItem].unclick();
			isClicked[clickedItem] = 0;
			items[clickedItem - 1].click();
			isClicked[clickedItem - 1] = 1;
		}
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
