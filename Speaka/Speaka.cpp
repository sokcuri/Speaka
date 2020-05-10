#include <stdio.h>
#include "../SpeakaLib/SpeakaLib.h"

void usage()
{
	printf("Speaka (https://github.com/sokcuri/speaka)\n");
	printf("Easy switch to default audio device\n");
	printf("\n");
	printf("usage:\n");
	printf("Speaka [FormFactor] [Sequence]\n");
	printf("\n");
	printf("[FormFactor]: Specifies the type of audio device form factor (not case sensitive)\n");
	printf("- Speakers\n- Headphones\n- Headset\n- SPDIF\n- DigitalAudioDisplayDevice\n");
	printf("\n");
	printf("[Sequence]: Specifies the audio device sequence number\n(If you are not sure, execute AudioDeviceList.exe)\n");
	printf("\n");
	printf("example:\n");
	printf("- speaka Speakers 0\n");
	printf("- speaka Headset 1\n");
}

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		usage();
		return -1;
	}
	for (int i = 0; argv[1][i]; i++) {
		argv[1][i] = tolower(argv[1][i]);
	}

	FormFactor formFactor = FormFactor::UnknownFormFactor;

	if (!strcmp(argv[1], "speakers"))
		formFactor = FormFactor::Speakers;
	else if (!strcmp(argv[1], "headphones"))
		formFactor = FormFactor::Headphones;
	else if (!strcmp(argv[1], "headset"))
		formFactor = FormFactor::Headset;
	else if (!strcmp(argv[1], "spdif"))
		formFactor = FormFactor::SPDIF;
	else if (!strcmp(argv[1], "digitalaudiodisplaydevice"))
		formFactor = FormFactor::DigitalAudioDisplayDevice;

	if (formFactor == FormFactor::UnknownFormFactor)
	{
		printf("Invalid Form Factor String");
		usage();
		return -2;
	}

	int sequence = atoi(argv[2]);
	SetAudioDevice(formFactor, sequence);
	return 0;
}