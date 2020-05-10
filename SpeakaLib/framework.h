// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#include <stdio.h>
#include <initguid.h>
#include <windows.h>
#include "Mmdeviceapi.h"
#include "Propidl.h"
#include "PolicyConfig.h"
#include "Functiondiscoverykeys_devpkey.h"
#include <endpointvolume.h>
#include <Devicetopology.h>
#include <functiondiscoverykeys.h>
#include <tchar.h>

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define SAFE_RELEASE(punk) if ((punk) != NULL) { (punk)->Release(); (punk) = NULL; }

const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
