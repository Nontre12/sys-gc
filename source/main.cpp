#define TESLA_INIT_IMPL
#include <tesla.hpp>

#include "overlay.h"

int main(int argc, char **argv) { return tsl::loop<OverlayTest>(argc, argv); }
