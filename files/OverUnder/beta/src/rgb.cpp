#include "main.h"

sylib::Addrled ledStrip1(22, 7, 25);
sylib::Addrled ledStrip2(22, 8, 25);

void rgb (void) {
    ledStrip1.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
	ledStrip1.cycle(*ledStrip1, 4, true);
	ledStrip2.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
	ledStrip2.cycle(*ledStrip2, 4, true);}