#include "CGAME.h"
// Use to Debug only
// pseudo-main
int main() {
	GUI::drawPlayArea();
	CPEOPLE player;
	player.setCoord(20, 25);
	player.draw_self();

	return 0;
}
//