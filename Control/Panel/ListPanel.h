#pragma once

#include "Panel.h"

class ListPanel : public Panel
{
public:
	ListPanel(int height, int width, vector<string> options);
	void setForeground(ForegroundColor color);
	void setBackGround(BackgroundColor color);
	~ListPanel();
};

