#pragma once

#include "Button.h"
#include <string>

using namespace std;

class ButtonItem : public Button
{
	string chkedText;
	bool isCheck;
	size_t index;
public:
	ButtonItem(string text, string checkedText, int width, size_t index);
	bool isChecked();
	void toggle();
	string getValue();
	size_t getIndex();
	~ButtonItem();
};

