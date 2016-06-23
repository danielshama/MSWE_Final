#pragma once

#include <Windows.h>
#include <vector>
#include "../Graphics/Graphics.h"

using namespace std;

enum class ForegroundColor {Red, Green, Blue, Purple, Teal, Yellow, White, Black};
enum class BackgroundColor { Red, Green, Blue, Purple, Teal, Yellow, White, Black };
enum class BorderType {Single, Double, None};

class Control
{
	int width, height;
	bool isFocused, isfocusable, visible;
	COORD location;
	ForegroundColor foreground;
	BackgroundColor background;
	BorderType borderType;

	static Control* currentFocused;
public:
	Control(int width);
	void show();
	void hide();
	void setForeground(ForegroundColor color);
	void setBackGround(BackgroundColor color);
	void setBorder(BorderType type);
	void setLocation(COORD);
	void focus();
	void unfocus();
	BorderType getBorderType();
	char getBorderTypeHorizontal();
	char getBorderTypeVertical();
	virtual void draw(Graphics graphics, int, int, size_t);
	virtual void keydown(WORD, CHAR);
	virtual void mousePressed(short, short, DWORD);
	bool canGetFocus();
	bool validSpace(Control c); //on me
	bool isFocus();
	bool isVisible();
	short getLeft();
	short getTop();
	int getWidth();
	int getHeight();
	vector<Control*> getAllControls();

	static void setFocus(Control* c);
	static Control* getFocus();

	~Control();
};

