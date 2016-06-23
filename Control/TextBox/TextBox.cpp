#include "TextBox.h"


TextBox::TextBox(int width) : Control(width)
{

}


void TextBox::setValue(string value) {
	value = value;
}

string TextBox::getValue() {
	return value;
}

void TextBox::draw(Graphics graphics, int x, int y, size_t w) {
	Control::draw(graphics, x, y, w);

}

void TextBox::keydown(WORD, CHAR) {

}

void TextBox::mousePress(short, short, DWORD){

}

TextBox::~TextBox()
{
}
