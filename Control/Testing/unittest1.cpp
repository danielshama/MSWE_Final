/*#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NumericBox/NumericBox.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

struct GraphicsMock : Graphics{
	GraphicsMock() :Graphics(), _screen(25 * 80, L'\0') {}
	void moveTo(int x, int y){ _cursorX = x; _cursorY = y; }
	void write(string s){
		for (size_t i = 0; i < s.size(); ++i){
			_screen[_cursorY * 80 + _cursorX + i] = s[i];
		}
	}


};

namespace Testing
{		
	TEST_CLASS(UnitTest1)
	{
	public
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, NumericBox::getHeight(), L"message");
		}

	};
}*/