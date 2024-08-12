#ifndef GUI_H_
#define GUI_H_

#include <tesla.hpp>

class GuiTest : public tsl::Gui {
 public:
  GuiTest();

  // Called when this Gui gets loaded to create the UI
  // Allocate all elements on the heap. libtesla will make sure to clean them up when not needed
  // anymore
  virtual tsl::elm::Element *createUI() override;

  // Called once every frame to update values
  virtual void update() override;

  // Called once every frame to handle inputs not handled by other UI elements
  virtual bool handleInput(
      u64 keysDown,
      u64 keysHeld,
      const HidTouchState &touchPos,
      HidAnalogStickState joyStickPosLeft,
      HidAnalogStickState joyStickPosRight) override;
};

#endif  // GUI_H_