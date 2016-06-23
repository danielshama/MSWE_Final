#include "CheckList.h"
#include "../EventEngine/EventEngine.h"

int main(VOID){
	vector<string> strings;
	strings.push_back("aba");
	strings.push_back("fsdf");
	strings.push_back("khj");
	strings.push_back("werewr");
	CheckList* cName = new CheckList(20,30,strings);
	cName->setBorder(BorderType::Double);
	//cName.setLocation({ 10, 20 });
	Control::setFocus(cName);
	EventEngine engine;
	engine.run(*cName);
	return 0;
}