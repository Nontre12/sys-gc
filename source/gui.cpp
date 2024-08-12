#include "gui.h"

GuiTest::GuiTest() {}

tsl::elm::Element *GuiTest::createUI() {
  // A OverlayFrame is the base element every overlay consists of. This will draw the default
  // Title and Subtitle. If you need more information in the header or want to change it's look,
  // use a HeaderOverlayFrame.
  auto frame = new tsl::elm::OverlayFrame("Tesla Example", "v1.3.1");

  // A list that can contain sub elements and handles scrolling
  auto list = new tsl::elm::List();

  // Create and add a new list item to the list
  list->addItem(new tsl::elm::ListItem("Default List Item"));

  // Add the list to the frame for it to be drawn
  frame->setContent(list);

  // Return the frame to have it become the top level element of this Gui
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