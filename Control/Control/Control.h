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
	int width;
	bool isFocus, isfocusAble, visible;
	COORD location;

	static Control* currentFocused;
public:
	Control();
	void show();
	void hide();
	void setForeground(ForegroundColor color);
	void setBackGround(BackgroundColor color);
	void setBorder(BorderType type);
	void setLocation(COORD);
	virtual void draw(Graphics graphics, int, int, size_t);
	virtual void keydown(WORD, CHAR);
	virtual void mousePress(short, short, DWORD);
	bool canGetFocus();
	bool validSpace(short x, short y); //on me
	bool isFocus();
	bool isVisible();
	short getLeft();
	short getTop();
	vector<Control*> getAllControllers();

	static void setFocuse(Control c);
	static Control* getFocused();

	~Control();
};

