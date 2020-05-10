#include <stdio.h>
#include "../SpeakaLib/SpeakaLib.h"

int main(int argc, char** argv)
{
	SetAudioDevice(FormFactor::Headphones, 0);
	return 0;
}