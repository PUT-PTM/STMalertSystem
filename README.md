## 1. STMalertSystem##
STMalertSystem is academic project written in C for Basics of Microprocessors Technology Lab, which was created by two people: Pawel Soja and Sebastian Jena.

It uses STM32F4-Disovery board adn currently supports Android App with user interface, two PIRs, Wi-Fi adapter and one speaker.

## 2. Build##
### 2.1. Clone repo and submodels ###
### 2.2. Release version: ###
### 2.3. Debug version: ###

## 3. Equipment ##
| Item                  | Model             | Links                                |
|-----------------------|-------------------|--------------------------------------|
| STM32F4 Board         | STMF407 Discovery | [Documentation][1]                   |
| PIR Sensor            | HC-SR501          | [Documentation][2]                   |
| Wi-Fi Adapter         | ESP8266           | [Documentation][3]                   |

[1]: http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/PF252419#tab-2
[2]: http://www.mpja.com/download/31227sc.pdf
[3]: https://nurdspace.nl/images/e/e0/ESP8266_Specifications_English.pdf

## 4. Pins connection ##
###ESP8266###
    VCC   -  3V
    GND   -  GND
    TX    -  PA2
    RX    -  PA3
    CH_PD -  3V

###PIR Sensor 1###
    VCC - 5V
    GND - GND
    OUT - PC7

###PIR Sensor 2###
    VCC - 5V
    GND - GND
    OUT - PC6

###SPEAKER###




## 5. Future plans ##
