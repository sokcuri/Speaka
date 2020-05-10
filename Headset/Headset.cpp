#include <stdio.h>
#include "../SpeakaLib/SpeakaLib.h"

int main(int argc, char** argv)
{
	SetAudioDevice(FormFactor::Headset, 0);
	return 0;
}