#include "ComboBox.h"


ComboBox::ComboBox(int width, vector<string> options) : ListPanel(getHeight(), width, options) {
	int len = options.size();
	setHeight((len+1)*3 + 2);
	int wid = getWidth();
	//create the label
	choosen = new Label(getWidth() - 4, options[0]);
	choosen->setBorder(BorderType::Double);
	addControl(choosen, getBodyLeft() , getBodyTop());

	//create the open/close button
	Button *toggleBtn = new Button(1, "+");
	toggleBtn->setBackGround(BackgroundColor::Blue);
	toggleBtn->setBorder(BorderType::Single);
	SelectListener* lsnr = new SelectListener(*this);
	toggleBtn->addListener(*lsnr);
	//addControl(toggleBtn, getBodyLeft(), getBodyTop());

	//create the options
	string str = string(Control::getWidth(),' ');
	for (int i = 0; i < len; i++) {
		string toInsert = (options[i]+str).substr(0, getWidth());
		ButtonItem *btn = new ButtonItem(toInsert, getWidth() - 4, i);
		btn->setBorder(BorderType::Single);
		SelectListener* lsnr = new SelectListener(*this);
		btn->addListener(*lsnr);
		addControl(btn, getBodyLeft(), getBodyTop() + ((i+1) * 3));
	}
}


size_t ComboBox::getSelectedIndex() {
	return 1;
}

void ComboBox::setSelectedIndex(size_t) {
}

//void ComboBox::draw(Graphics graphics, int, int, size_t) {}

void ComboBox::keyDown(WORD w, CHAR c) {

}
void ComboBox::mousePressed(short, short, bool) {

}
void ComboBox::toggle() {

}

ComboBox::~ComboBox()
{
}
