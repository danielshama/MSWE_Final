#include "CheckList.h"


CheckList::CheckList(int height, int width, vector<string> options) : ListPanel(height, width, options){
	int len = options.size();
	for (int i = 0 ; i < len ; i++){ 
		ButtonItem *btn = new ButtonItem(options[i], getWidth()-4, i);
		btn->setBorder(BorderType::Single);
		SelectListener* lsnr = new SelectListener(*this);
		btn->addListener(*lsnr);
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

void CheckList::onEnterKey(){
	selectIndex(itemInFocus());
}

void CheckList::mousePressed(short x, short y, bool isLeft){
	if (x < this->getLeft() || (x > this->getLeft() + this->getWidth())) return;
	if (y < this->getTop() || (y > this->getTop() + this->getHeight())) return;

	Control::setFocus(this);

	int size = controls.size();
	for (int i = 0; i < size; i++) {
		controls[i]->mousePressed(x, y, isLeft);
	}
}


CheckList::~CheckList(){
	//need to clean all the controls and listeners 
}
