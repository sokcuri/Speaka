## Speaka by sokcuri
원클릭으로 간단하게 스피커와 헤드셋을 전환하세요! 윈도우 10 아이콘이 내장되어 작업표시줄에 등록해서 쉽고 편리하게 사용할 수 있습니다

* [스피카 리포지토리 방문](https://github.com/sokcuri/Speaka)
* [스피카 다운받으러 가기](https://github.com/sokcuri/speaka/releases)

* 압축 파일을 풀고 해당하는 이름의 exe를 실행시키면 오디오가 해당 폼팩터로 전환됩니다
* 스피커로 전환하고 싶으면 speakers.exe를 실행하고, 헤드셋으로 전환하고 싶으면 headset.exe를 실행하세요!

* 명령줄 유틸리티(Speaka.exe)와 오디오 장치 표시 유틸리티(AudioDeviceList.exe)를 이용해 고급 설정도 얼마든지 가능합니다

소스코드는 MIT 라이센스로 공개되어 있습니다

### 파일 구조
- Speaker.exe (실행 시 스피커로 전환)
- Headphones.exe (실행 시 헤드폰으로 전환)
- Headset.exe (실행 시 헤드셋으로 전환)
- SPDIF.exe (실행 시 SPDIF으로 전환)
- DigitalAudioDisplayDevice.exe (실행 시 디지털 오디오 디스플레이 장치로 전환)
- AudioDeviceList.exe (현재 PC에 연결되어 있는 오디오 장치를 표시합니다)
- Speaka.exe (스피카 명령줄 유틸리티)

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
- 0번 스피커로 스위치하고 싶은 경우
`speaka Speakers 0`

- 1번 헤드셋으로 스위치하고 싶다면
`speaka Headset 1`

AudioDeviceList 유틸리티를 실행시켜 현재 연결되어 있는 오디오 장치를 확인하면 유용합니다
