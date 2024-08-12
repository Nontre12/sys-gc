#ifndef OVERLAY_H_
#define OVERLAY_H_

#include <tesla.hpp>

class OverlayTest : public tsl::Overlay {
 public:
  // libtesla already initialized fs, hid, pl, pmdmnt, hid:sys and set:sys
  // Called at the start to initialize all services necessary for this Overlay
  virtual void initServices() override;

  // Callet at the end to clean up all services previously initialized
  virtual void exitServices() override;

  // Called before overlay wants to change from invisible to visible state
  virtual void onShow() override;

  // Called before overlay wants to change from visible to invisible state
  virtual void onHide() override;

  virtual std::unique_ptr<tsl::Gui> loadInitialGui() override;
};

#endif  // OVERLAY_H_