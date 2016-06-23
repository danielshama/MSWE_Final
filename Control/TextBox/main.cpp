#include <string>
#include "../EventEngine/EventEngine.h"
#include "TextBox.h"
using namespace std;

int main(int argc, char **argv)
{
	
	TextBox tName(20);
	tName.setValue("Sherlock Holmes");
	tName.setBorder(BorderType::Single);
	tName.setLocation({ 10, 10 });
	Control::setFocus(&tName);
	EventEngine engine;
	engine.run(tName);
	return 0;
}