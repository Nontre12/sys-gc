#include "gui.h"

GuiTest::GuiTest() {}

tsl::elm::Element *GuiTest::createUI() {
  auto frame = new tsl::elm::OverlayFrame("sys-gc", "v0.0.1");

  auto list = new tsl::elm::List();
  list->addItem(new tsl::elm::ListItem("Default List Item"));
  frame->setContent(list);

  return frame;
}

void GuiTest::update() {}

bool GuiTest::handleInput(
    u64 keysDown,
    u64 keysHeld,
    const HidTouchState &touchPos,
    HidAnalogStickState joyStickPosLeft,
    HidAnalogStickState joyStickPosRight) {
  return false;  // Return true here to signal the inputs have been consumed
}