<br/>
<p align="center">
  <a href="https://github.com/devPriceington/SEIS Fire Alarm System">
    <img src="https://www.ageaportal.com/images/aydin_univ.png" alt="Logo" width="150" height="150">
  </a>

  <h3 align="center">SEIS IOT Based Smart Home Fire Alarm System</h3>

  <p align="center">
    This project is a final project made by Istanbul Aydin University Electrical and Electronics Engineering Students for the COM473 INTERNET OF THINGS & INDUSTRY 4.0 course. Since it is a prototype project, it has shortcomings and security vulnerabilities. In this form, it cannot be used directly in a real project. However, it is a useful project in terms of paving the way for developers.
    <br/>
    <br/>
  </p>
</p>

![Stargazers](https://img.shields.io/github/stars/devPriceington/SEIS Fire Alarm System?style=social) 

## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Authors](#authors)
* [Acknowledgements](#acknowledgements)

## About The Project

![Screen Shot](https://www.aydin.edu.tr/en-us/akademik/fakulteler/tip/PublishingImages/Pages/The-Hippocratic-Oath/IAU-WEB-LOGO-ING.png)

This project is a final project made by Istanbul Aydin University Electrical and Electronics Engineering Students for the COM473 INTERNET OF THINGS & INDUSTRY 4.0 course.

The team that carried out the project:
EMRE IŞIK
EMRE SÖZEN
SAMET ENES BAYEZİT
HÜSEYİN PAMUK
ARDA BARBER

Lecturer:
Dr. MHD WASIM RAED

The implementation of an IoT based fire focused smart home system represents a pivotal advancement in addressing fire safety across diverse housing structures. This project aims to fill the safety gap, particularly in older homes, where the absence of modern fire alarm systems has led to tragic consequences. Our s olution provides an affordable, easy to integrate, and compact system that ensures widespread access to advanced fire detection and prevention measures. By leveraging sensors, Wi Fi connectivity, and a user friendly web control panel, our system offers rea l time monitoring and automated fan control. This innovation not only simplifies fire safety but also empowers users with manual control options. The project's core mission is to democratize advanced fire safety measures, contributing to safer living envir onments for all households, regardless of their age or construction.




## Built With

### Software Languages:
* C++
* HTML
* CSS
* JavaScript

### Platforms:
* PlatformIO (Visual Studio Code)
* Proteus 

## Getting Started

### Introduction - Problem Statement

In the realm of home safety, the specter of fire related incidents has persistently haunted households, with a particular gravity in older homes lacking modern fire alarm systems. The repercussions of delayed intervention have been tragically evident. Our project stems from a deeply rooted concern for the lives lost and injuries sustained due to this pressing issue. Recognizing the stark gaps in existing fire safety solutions, we embark ed on a transformative journey to develop an innovative IoT based fire alarm system that transcends the limitations of current options. The landscape of fire safety solutions has witnessed the emergence of various systems, from traditional smoke detectors to sophisticated smart home setups. However, the accessibility of IoT based smart home systems has predominantly been confined to luxury residences, and traditional detectors are often exclusive to newly constructed homes. The primary reason behind this gap lies in the integration process, which is inherently easier during the construction phase. Our mission is to dismantle these barriers and democratize fire safety. We envision a future where an IoT based fire alarm system is not a luxury but an essential component of every home and office, effortlessly deployable without the need for structural m odifications. This initiative is not merely about introducing a product; it is a crusade to make cutting edge fire detection and prevention an integral part of every living space, regardless of its age or construction. Through this project, we strive to pi oneer a paradigm shift in home safety, ushering in a new era of comprehensive protection, peace of mind, and swift responses to fire emergencies for individuals and families worldwide.

### System

Basically, our microcontroller controls and process everything automatically. And we are saving our data with a database. For user interface, you can control your system with web control panel over the database.

![Screen Shot](https://github.com/devPriceington/IOT-Based-Smart-Home-Fire-Alarm-System/blob/main/Images/system.png)


### Components

* ESP32 WROOM 32D
* FAN
* MQ-2 Gas Sensor
* DHT22 Digital Temperature and Humidity Sensor
* 7805CV Voltage Regulator
* IRF510 N Channel Power Mosfet
* 12V Adapter
* Resistors, capacitors, diodes and copper board

## Usage - How It Works?

Proteus Circuit:

![Screen Shot]([Proteus Schematic](https://raw.githubusercontent.com/devPriceington/IOT-Based-Smart-Home-Fire-Alarm-System/main/Images/proteus.png?token=GHSAT0AAAAAACMHJKL2ZWPO4HJTSQT5LGJQZMSW7NA))

The circuit operates by plugging an adapter, reducing the circuit from 220V to 9V, into the socket. Once power is supplied to the circuit, 7805CV efficiently drop the voltage from 9V to 5V. Following the circuit's working principle, data from the MQ2 gas sensor and DHT22 temperature sensor is transmitted to the ESP32 card. And ESP32 process it. Then the ESP32 card transferring the data to the Firebase Realtime Database. Through our website, users can promptly view real-time sensor data. If desired, users can manually adjust the speed data on the website to control the fan connected to the load circuit. Given the system's versatility across different applications, the website can display multiple panels. Information on the website is presented in user-friendly measurement units commonly used in daily life for easy comprehension.
To operate our fan, we are using IRF510 MOSFET. And we are driving the MOSFET with PWM signals producing from ESP32 microcontroller. And we are using C++ software language to program ESP32.
We create an extremely safe system by converting the 220V AC motor we receive from the network to 5V DC with good engineering work.
At the web side, we are using HTML, CSS, JavaScript software languages. And we have a domain to control your IOT device, first of all you need to login your account. After login, you will see your devices. And then, you can easily control and monitorize your system. 

![Screen Shot]([Web Panel Login Screen](https://raw.githubusercontent.com/devPriceington/IOT-Based-Smart-Home-Fire-Alarm-System/main/Images/webLogin.png?token=GHSAT0AAAAAACMHJKL23VMDAWYEWVZSF3ZCZMSXAHQ))

In the control pane you can see the temperature as a Celsius and gas as a ppm values. And according to this values microcontroller arranges fan speed automatically. But if you want, you can control the fan manually from here by clicking the M/A button (A text field will appear, then you should type percentage you want). 
Above the 1050 ppm or 30 degrees, device accepts it is as a dangerous situation and fan works %100. Below 1050 ppm or 24 degrees accepts as a normal situation and fan does not work. And fan speed mapped among the 24 and 30 degrees. It automatically controls the speed according to the temperature.

![Screen Shot]([Web Control Panel](https://raw.githubusercontent.com/devPriceington/IOT-Based-Smart-Home-Fire-Alarm-System/main/Images/webPanel.png?token=GHSAT0AAAAAACMHJKL2DWQQLHAI3LHFOOJAZMSXASQ))

For summary, the microcontroller connects to the Wi-Fi at home, detects temperature and smoke with the sensors on it, processes the data and sends it to the Firebase Realtime Database. Then you can see and control this data on the website we have made.

## Production Stages

Please see the report for detailed project production stages.

### Whole System

![Screen Shot]([Web Control Panel](https://raw.githubusercontent.com/devPriceington/IOT-Based-Smart-Home-Fire-Alarm-System/main/Images/wholeSys.png?token=GHSAT0AAAAAACMHJKL3FWTDMTVHNYPYAMYSZMSXA4A))

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.
* If you have suggestions for adding or removing projects, feel free to [open an issue] to discuss it, or directly create a pull request after you edit the *README.md* file with necessary changes.
* Please make sure you check your spelling and grammar.
* Create individual PR for each suggestion.
* Please also read through the [Code Of Conduct] before posting your first idea as well.



## License

Distributed under the MIT License. See [LICENSE](https://github.com/devPriceington/IOT-Based-Smart-Home-Fire-Alarm-System/blob/main/LICENSE) for more information.

## Author

* **Emre IŞIK** - *Electrical and Electronic Student* - [Emre IŞIK](https://github.com/devPriceington) - *Built ReadME Template*


