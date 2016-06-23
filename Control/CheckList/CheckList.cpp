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
void CheckList::draw(Graphics graphics, int x, int y, size_t w){
	//no need
}

void CheckList::keyDown(WORD event, CHAR chr){

}

void CheckList::mousePress(short, short, DWORD){
	//no need
}

CheckList::~CheckList(){
}
