#pragma once

#include <Windows.h>
#include <vector>
#include "../Graphics/Graphics.h"

using namespace std;

enum class BorderType {Single, Double, None};

class Control
{
	int width, height;
	bool isFocused, isfocusable, visible;
	COORD location;
	COORD bodyLocation;
	ForegroundColor foreground;
	BackgroundColor background;
	BorderType borderType;

public:

	Control(int width);
	void show();
	void hide();
	void setForeground(ForegroundColor color);
	void setBackGround(BackgroundColor color);
	ForegroundColor getForeground();
	BackgroundColor getBackGround();
	void setBorder(BorderType type);
	virtual void setLocation(COORD);
	COORD getLocation();
	void focus();
	void unfocus();
	BorderType getBorderType();
	char getBorderTypeHorizontal();
	char getBorderTypeVertical();
	vector<int> getBorderTypeCorners();
	virtual void draw(Graphics graphics, int, int, size_t);
	virtual void keyDown(WORD, CHAR);
	virtual void mousePressed(short, short, DWORD);
	bool canGetFocus();
	bool validSpace(Control c); //on me
	bool isFocus();
	bool isVisible();
	short getLeft();
	short getTop();
	short getBodyLeft();
	short getBodyTop();
	int getWidth();
	int getHeight();
	void setHeight(int);
	void setWidth(int);
	void getAllControls(vector<Control *> &controls);

	static void setFocus(Control* c);
	static Control* getFocus();

	~Control();
};

static Control* currentFocused = NULL;
