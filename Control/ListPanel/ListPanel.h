#pragma once
#include "../Panel/Panel.h"
#include <vector>

using namespace std;

class ListPanel : Panel
{
public:
	ListPanel();

	//void addControl(Control& control);
	virtual void setSelectedIndex(size_t);
	virtual size_t getSelectedIndex();

	~ListPanel();
};

