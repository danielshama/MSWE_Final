#pragma once

#include "Panel.h"
#include "../Button/ButtonItem.h"

class ListPanel : public Panel
{
protected:
	size_t itemInFocus();
public:
	ListPanel(int height, int width, vector<string> options);
	void setForeground(ForegroundColor color);
	void setBackGround(BackgroundColor color);
	~ListPanel();
};

