# 스피카 (Speaka) by sokcuri
원클릭으로 간단하게 스피커와 헤드셋을 전환하세요! 아이콘이 내장되어 작업표시줄에 등록해 쉽고 편리하게 사용할 수 있습니다

https://github.com/sokcuri/Speaka

스피카는 아래 링크에서 다운받을 수 있습니다. 압축 파일을 적당한 폴더에 풀고 폼팩터에 해당하는 프로그램을 실행하세요
스피커로 전환하고 싶으면 Speaker.exe를, 헤드셋으로 전환하고 싶으면 Headset.exe를 실행하면 됩니다

* [스피카 다운받으러 가기](https://github.com/sokcuri/speaka/releases)

소스 코드는 MIT 라이센스로 공개되어 있습니다

## 파일 구조
- Speaker.exe (스피커로 전환)
- Headphones.exe (헤드폰으로 전환)
- Headset.exe (헤드셋으로 전환)
- SPDIF.exe (SPDIF으로 전환)
- DigitalAudioDisplayDevice.exe (디지털 오디오 디스플레이 장치로 전환)
- Utility/AudioDeviceList.exe (현재 PC에 연결되어 있는 오디오 장치를 표시합니다)
- Utility/Speaka.exe (스피카 명령줄 유틸리티)

### 명령줄 유틸리티 사용법
Speaka [FormFactor] [Sequence]

[FormFactor]: 오디오 장치의 폼팩터를 적습니다 (대소문자 관계없음)
- Speakers
- Headphones
- Headset
- SPDIF
- DigitalAudioDisplayDevice

[Sequence]: 오디오 장치의 순번을 적습니다

#### 예시
- 0번 스피커로 스위치하고 싶은 경우: `speaka Speakers 0`

- 1번 헤드셋으로 스위치하고 싶다면: `speaka Headset 1`

* 현재 연결되어 있는 오디오 장치들을 확인하려면 `AudioDeviceList.exe` 유틸리티를 실행하세요
