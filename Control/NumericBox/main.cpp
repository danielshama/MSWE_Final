#include "../EventEngine/EventEngine.h"
#include "NumericBox.h"



int main(void) {
	Panel panel(25, 50);
	NumericBox box(10, 4, 10);
	box.setBackGround(BackgroundColor::Black);
	box.setForeground(ForegroundColor::White);
	panel.setLocation({ 3, 0 });
	panel.setBorder(BorderType::Double);
	panel.addControl(&box, 10, 5);
	EventEngine engine;
	engine.run(panel);
}