#include "CheckList.h"
#include "../EventEngine/EventEngine.h"

int main(VOID){
	Panel p(25, 50);
	p.setLocation({ 10, 10 });
	p.setBorder(BorderType::Single);
	vector<string> strings;
	strings.push_back("aba");
	strings.push_back("fsdf");
	strings.push_back("khj");
	strings.push_back("werewr");
	CheckList cName(16,30,strings);
	cName.setBorder(BorderType::Double);
	//cName.setLocation({ 10, 20 });
	Control::setFocus(&cName);
	cName.setBackGround(BackgroundColor::Green);
	cName.setForeground(ForegroundColor::Orange);
	p.addControl(&cName, 5, 5);
	EventEngine engine;
	engine.run(p);
	return 0;
}