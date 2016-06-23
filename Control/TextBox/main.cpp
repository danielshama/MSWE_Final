#include <string>
#include "../EventEngine/EventEngine.h"
#include "TextBox.h"
#include "../Panel/Panel.h"
using namespace std;


int main(int argc, char **argv)
{
	TextBox tName(20);
	Panel p(25, 50);
	tName.setValue("Sherlock Holmes sfasaf");
	tName.setBorder(BorderType::Double);
	tName.setBackGround(BackgroundColor::Red); 
	tName.setForeground(ForegroundColor::Cyan);
	Control::setFocus(&tName);
	p.setBorder(BorderType::Double);
	p.addControl(&tName, 10, 20);
	EventEngine engine;
	engine.run(p);
	return 0;
}