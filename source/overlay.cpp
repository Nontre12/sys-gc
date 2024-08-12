#include "overlay.h"

#include "gui.h"

void OverlayTest::initServices() {}

void OverlayTest::exitServices() {}

void OverlayTest::onShow() {}

void OverlayTest::onHide() {}

std::unique_ptr<tsl::Gui> OverlayTest::loadInitialGui() { return initially<GuiTest>(); }