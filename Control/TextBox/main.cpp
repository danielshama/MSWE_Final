#include <string>
#include "../EventEngine/EventEngine.h"
#include "TextBox.h"
using namespace std;


int main(int argc, char **argv)
{
	TextBox tName(20);
	tName.setValue("Sherlock Holmes sfasaf");
	tName.setBorder(BorderType::Double);
	tName.setLocation({ 10, 20 });
	Control::setFocus(&tName);
	EventEngine engine;
	engine.run(tName);
	return 0;
}