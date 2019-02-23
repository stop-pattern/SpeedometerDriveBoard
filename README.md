SpeedometerDriveBoard
===

## table of contents
- [日本語版](#Japanese)[](\readme_jp.md)
- [English](#English)
  - [Requirement](#Requirement)
  - [Installation](#Installation)
    - [board](#board)
    - [code](#code)
  - [Licence](#Licence)
  - [Author](#Author)

---

## Japanese
このリポジトリ内の創造物は、[BIDSid_SerCon](https://github.com/TetsuOtter/BIDSid_SerCon/)を使用する前提で設計されています。  
基板は5000円以下/枚で生産できますが、現在製造中につき値段の詳細については分かりかねます。(分かり次第追記予定  
日本語版は工事中ですのでお手数ですが下記英語版をご覧いただきますよう...

---

## English
This Repository is designed on the premise of using [__BIDSid_SerCon__](https://github.com/TetsuOtter/BIDSid_SerCon/).  
This is for original board on esp32 that created and designed by stop_pattern.  
This board can be produced at less than 5000JPY / piece.  
But do not know details of the price because it is currently under manufacturing.  
(Scheduled to be appended as soon as it is known)  

### Requirement
using:
[BIDSid_SerCon](https://github.com/TetsuOtter/BIDSid_SerCon/).  
supported:
[Bve trainsim](http://bvets.net/)  
support __Bve trainsim__, but the supported version _5.7_ or newer.  
__Bve trainsim__ spported only _Windows Vista_ or _newer_, so support only _Windows Vista_ or _newer_ too.  

### Usage
Change the settings, in the firmware source code according to your own environment.  
write firmware to esp32 through __Arduino IDE__.  


### Installation
#### board:
1. Request PCB service company to manufacture circuit board.  
2. Test manufactured board and Implemented parts.  
#### code:
1. write firmware to esp32 through __Arduino IDE__.  
2. setup [__Bve trainsim__](http://bvets.net/en/download/)  
3. Introduce [__BIDSid_SerCon__](https://github.com/TetsuOtter/BIDSid_SerCon/) into __Bve trainsim__.  

### Licence
board:
[GPLv3](https://www.gnu.org/licenses/gpl-3.0.html)  
code:
[MIT](https://github.com/tcnksm/tool/blob/master/LICENCE)  

### Author
[stop_pattern](https://github.com/stop-pattern)  
