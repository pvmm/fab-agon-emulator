#include "fabgl.h"
#include "dispdrivers/vga16controller.h"
#include "vdp.h"

/* Buffer must be big enough for any screen resolution - up to 1024x768x3 bytes :) */
static void copyVgaFramebuffer(int *outWidth, int *outHeight, void *buffer)
{
	auto vga = getVDPVGAController();
	const int w = vga->getScreenWidth();
	const int h = vga->getScreenHeight();
	*outHeight = h;
	*outWidth = w;
	// rect is inclusive range
	Rect rect(0, 0, w-1, h-1);
	vga->readScreen(rect, (fabgl::RGB888*)buffer);
}

static fabgl::RGB888 buf[1024*768];

int main() {
	printf("Starting the userspace fabgl+VDP...\n");
	// VDP_GP to get past wait_ez80
	z80_send_to_vdp(23);
	z80_send_to_vdp(0);
	z80_send_to_vdp(0x80);
	z80_send_to_vdp(1);
	setup();
	auto vga = fabgl::VGA16Controller::instance();
	int h, w;
	copyVgaFramebuffer(&w, &h, buf);
	printf("Screen dimensions: %d x %d\n", w, h);
	printf("Dumping VGA framebuffer post-VDP-setup():\n");

	for (int y=0; y<16; y++) {
		for (int x=0; x<100; x++) {
			printf("%c", buf[y*w + x].B ? 'X' : ' ');
		}
		printf("\n");
	}

	is_fabgl_terminating = true;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	printf("Bye nenê!\n");
}
