#ifndef OVERLAY_H_
#define OVERLAY_H_

#include <tesla.hpp>

class OverlayTest : public tsl::Overlay {
 public:
  // libtesla already initialized fs, hid, pl, pmdmnt, hid:sys and set:sys
  virtual void initServices() override;

  // Called at the start to initialize all services necessary for this Overlay
  virtual void exitServices() override;

  // Callet at the end to clean up all services previously initialized
  virtual void onShow() override;

  // Called before overlay wants to change from invisible to visible state
  virtual void onHide() override;

  // Called before overlay wants to change from visible to invisible state
  virtual std::unique_ptr<tsl::Gui> loadInitialGui() override;
};

#endif  // OVERLAY_H_