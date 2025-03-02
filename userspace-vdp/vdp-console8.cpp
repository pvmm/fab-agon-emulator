#include "Arduino.h"

// VDP uses various functions before their definition, so here
// vdp-console8.h gives those functions prototypes to avoid errors
#include "vdp-console8.h"

// VDP version-agnostic getters :)
fabgl::VGABaseController *getVDPVGAController() {
	return _VGAController;
}
fabgl::SoundGenerator *getVDPSoundGenerator() {
	return &SoundGenerator;
}

#include "vdp-console8/video.ino"
