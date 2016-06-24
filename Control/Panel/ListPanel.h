#pragma once

#include "Panel.h"
#include "../Button/ButtonItem.h"

class ListPanel : public Panel
{
protected:
	int itemInFocus();
public:
	ListPanel(int height, int width, vector<string> options);
	void setForeground(ForegroundColor color);
	void setBackGround(BackgroundColor color);
	virtual void keyDown(WORD, CHAR);
	~ListPanel();
};

