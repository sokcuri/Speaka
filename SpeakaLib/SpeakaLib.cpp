// SpeakaLib.cpp : 정적 라이브러리를 위한 함수를 정의합니다.
//
#include <atlbase.h>
#include <locale>
#include <locale.h>
#include "framework.h"
#include "SpeakaLib.h"

HRESULT SetDefaultAudioPlaybackDevice(wstring devID)
{
	IPolicyConfigVista* pPolicyConfig;
	ERole reserved = eConsole;

	HRESULT hr = CoCreateInstance(__uuidof(CPolicyConfigVistaClient),
		NULL, CLSCTX_ALL, __uuidof(IPolicyConfigVista), (LPVOID*)&pPolicyConfig);
	if (SUCCEEDED(hr))
	{
		hr = pPolicyConfig->SetDefaultEndpoint(devID.c_str(), reserved);
		pPolicyConfig->Release();
	}
	return hr;
}

vector<OutWaveDevice> GetAvailableDevice()
{
	vector<OutWaveDevice> Devices;
	unordered_map<FormFactor, int> counts;

	UINT count;
	HRESULT hr = S_OK;
	CComPtr<IMMDeviceEnumerator> pEnumerator;
	CComPtr<IMMDeviceCollection> pCollection;

	hr = CoCreateInstance(CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL, IID_IMMDeviceEnumerator, (void**)&pEnumerator);
	if (FAILED(hr))
		return Devices;

	hr = pEnumerator->EnumAudioEndpoints(EDataFlow::eRender, DEVICE_STATE_ACTIVE, &pCollection);
	if (FAILED(hr))
		return Devices;

	hr = pCollection->GetCount(&count);
	if (FAILED(hr))
		return Devices;

	if (count == 0)
		return Devices;


	auto GetFriendlyName = [](CComPtr<IPropertyStore> pProps) -> wstring
	{
		wstring name;
		PROPVARIANT varName;
		PropVariantInit(&varName);

		auto hr = pProps->GetValue(PKEY_Device_FriendlyName, &varName);
		if (FAILED(hr)) {
			PropVariantClear(&varName);
			return nullptr;
		}
		name = varName.pwszVal;
		PropVariantClear(&varName);
		return name;
	};

	auto GetID = [](CComPtr<IMMDevice> pEndpoint) -> wstring
	{
		wstring ID;
		LPWSTR pwszID = NULL;
		auto hr = pEndpoint->GetId(&pwszID);
		if (FAILED(hr)) {
			CoTaskMemFree(pwszID);
			return nullptr;
		}
		ID = pwszID;
		CoTaskMemFree(pwszID);
		return ID;
	};

	auto GetFormFactor = [](CComPtr<IPropertyStore> pProps) -> FormFactor
	{
		PROPVARIANT varFormFactor;
		PropVariantInit(&varFormFactor);

		auto hr = pProps->GetValue(PKEY_AudioEndpoint_FormFactor, &varFormFactor);
		if (FAILED(hr)) {
			return FormFactor::UnknownFormFactor;
		}

		auto formFactor = (FormFactor)varFormFactor.uintVal;
		PropVariantClear(&varFormFactor);
		return formFactor;
	};


	for (ULONG i = 0; i < count; i++)
	{
		CComPtr<IMMDevice> pEndpoint;
		CComPtr<IPropertyStore> pProps;

		hr = pCollection->Item(i, &pEndpoint);
		if (FAILED(hr))
			continue;

		hr = pEndpoint->OpenPropertyStore(STGM_READ, &pProps);
		if (FAILED(hr))
			continue;

		auto ID = GetID(pEndpoint);
		auto formFactor = GetFormFactor(pProps);
		auto name = GetFriendlyName(pProps);

		DWORD deviceState = 0;
		hr = pEndpoint->GetState(&deviceState);
		if (hr != S_OK) {
			continue;
		}

		auto num = counts[formFactor]++;

		Devices.push_back(OutWaveDevice(ID, name, formFactor, num));
	}

	return Devices;
}

wstring FormFactorToString(FormFactor formFactor)
{
	switch (formFactor)
	{
		case FormFactor::RemoteNetworkDevice:
			return L"RemoteNetworkDevice";
		case FormFactor::Speakers:
			return L"Speakers";
		case FormFactor::LineLevel:
			return L"LineLevel";
		case FormFactor::Headphones:
			return L"Headphones";
		case FormFactor::Microphone:
			return L"Microphone";
		case FormFactor::Headset:
			return L"Headset";
		case FormFactor::Handset:
			return L"Handset";
		case FormFactor::UnknownDigitalPassthrough:
			return L"UnknownDigitalPassthrough";
		case FormFactor::SPDIF:
			return L"SPDIF";
		case FormFactor::DigitalAudioDisplayDevice:
			return L"DigitalAudioDisplayDevice";
		case FormFactor::UnknownFormFactor:
		default:
			return L"UnknownFormFactor";
	}
}

void PrintDeviceList()
{
	int n = 0;
	std::wcout.imbue(std::locale(""));
	CoInitialize(NULL);
	auto Device = GetAvailableDevice();
	for (const auto& d : Device)
	{
		wcout << L"#" << d.num << L" [" << FormFactorToString(d.formFactor) << L"]" << endl;
		wcout << d.name << endl << d.id << endl << endl;
	}

	CoUninitialize();
}

void SetAudioDevice(FormFactor formFactor, int sequence)
{
	int n = 0;

	std::wcout.imbue(std::locale(""));

	CoInitialize(NULL);
	auto Device = GetAvailableDevice();
	for (const auto &d: Device)
	{
		if (d.formFactor == formFactor)
		{
			if (sequence == d.num)
			{
				SetDefaultAudioPlaybackDevice(d.id);
				wcout << L"Set Device to " << d.name << endl;
				return;
			}
			n++;
		}
	}

	CoUninitialize();
}
