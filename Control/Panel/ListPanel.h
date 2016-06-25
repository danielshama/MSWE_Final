#pragma once

#include "Panel.h"
#include "../Button/ButtonItem.h"

class ListPanel : public Panel
{
protected:
	int itemInFocus();
	void switchFocus(int indx);
	//In Inherited need to edit these three functions and not the KeyDown() 
	virtual void onDownKey();
	virtual void onUpKey();
	virtual void onEnterKey();
public:
	ListPanel(int height, int width, vector<string> options);
	void setForeground(ForegroundColor color);
	void setBackGround(BackgroundColor color);
	void keyDown(WORD, CHAR);
	~ListPanel();
};

