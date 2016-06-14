#STMalertSystem#


##Overview##
STMalertSystem is academic project written in C for Basics of Microprocessors Technology Lab, which was created by two people.
It able to inform you with sound effects on Android App when PIR Sensors detect some move.

It uses STM32F4-Disovery board and currently supports Android App with user interface, two PIRs, Wi-Fi adapter and one speaker.


##Tools##
<ul>
  <li>CooCox CoIDE</li>
  <li>Hercules Utility</li>
  <li>Android Studio</li>
</ul>


##Equipment ##
| Item                  | Model             | Links                                |
|-----------------------|-------------------|--------------------------------------|
| STM32F4 Board         | STMF407 Discovery | [Documentation][1]                   |
| PIR Sensor            | HC-SR501          | [Documentation][2]                   |
| Wi-Fi Adapter         | ESP8266           | [Documentation][3]                   |

[1]: http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/PF252419#tab-2
[2]: http://www.mpja.com/download/31227sc.pdf
[3]: https://nurdspace.nl/images/e/e0/ESP8266_Specifications_English.pdf


##Pins connection ##
####ESP8266####
    VCC   -  3V
    GND   -  GND
    TX    -  PA2
    RX    -  PA3
    CH_PD -  3V

####PIR Sensor 1####
    VCC - 5V
    GND - GND
    OUT - PC7

####PIR Sensor 2####
    VCC - 5V
    GND - GND
    OUT - PC6

####SPEAKER####
    VCC - 5V
    GND - GND
    AMP - PA4
    
    
##How To Run##
####Android App####
<ul>
  <li>Open Project in Android Studio</li>
  <li>Plug your device in debugging mode</li>
  <li>Run it, the app will be automatically installed on a device</li>
</ul>

####CooCox CoIDE Project####
<ul>
  <li>Open Project in CooCox CoIDE</li>
  <li>Build project</li>
  <li>Flash</li>
</ul>
####Hercules & ESP8266####
  [Configure ESP8266 as Server][4]
  [4]: https://github.com/boseji/ESP8266-Store/wiki/AT-Command-firmware-based-Client-Server


##Future plans##
<ul>
<li>Adding extra sensors</li>
</ul>

##License##
This project can be used under MIT license

##Credits##
<ul>
<li>Paweł Soja</li>
<li>Sebastian Jena</li>
<li>Supervisor: Tomasz Mańkowski</li>
</ul>


