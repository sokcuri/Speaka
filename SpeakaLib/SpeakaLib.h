#pragma once
#include <iostream>
using namespace std;

enum class FormFactor
{
	RemoteNetworkDevice,
	Speakers,
	LineLevel,
	Headphones,
	Microphone,
	Headset,
	Handset,
	UnknownDigitalPassthrough,
	SPDIF,
	DigitalAudioDisplayDevice,
	UnknownFormFactor
};

struct OutWaveDevice
{
	OutWaveDevice(wstring id, wstring name, FormFactor formFactor, int num)
	{
		this->id = id;
		this->name = name;
		this->formFactor = formFactor;
		this->num = num;
	}

	wstring id;
	wstring name;
	FormFactor formFactor;
	int num;
};

void PrintDeviceList();
void SetAudioDevice(FormFactor formFactor, int sequence = 0);