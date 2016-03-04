# Getting started with the Riffle datalogger

## Overview

The Riffle (ver 0.1.8) can be programmed in the Arduino IDE as a an "Arduino UNO" board.  Its onboard real time clock (RTC) is temperature compensated for improved accuracy; the temperature sensor on the RTC can be accessed for a simple datalogging demonstration (see 'Basic datalogging' below).

## Blink Test

### Required hardware 

- a Riffle
- a 3.5 - 6 V battery source with a JST connector. 

The Riffle should arrived pre-programmed to blink its onboard LED every second, to indicate that the board is working.

### Required software

- None

### Procedure 

1. Plug the battery into the general-chemistry battery connector (labeled "General" on the underside of the circuit board)
2. Make sure that the onboard switch is switched to "GEN" 

The Riffle should blink if the firmware has been loaded properly.

## Basic datalogging

### Required hardware

- Riffle datalogger
- CR1220 coin cell battery
- main battery (3.7 V - 6 v)
- microUSB cable
- a microSD card

### Required software

The [Arduino IDE](https://www.arduino.cc/en/Main/Software) should be installed on your computer

Additionally, you'll need to install the following libraries in a 'libraries' folder within your Arduino IDE sketchbook folder:

- [Low Power](https://github.com/rocketscream/Low-Power)
- [DS3232RTC](http://github.com/JChristensen/DS3232RTC)
- [Streaming](http://arduiniana.org/libraries/streaming/)
- [Time](https://github.com/PaulStoffregen/Time)

### Procedure

**Setting the Real Time Clock.** 

First, we'll want to set the real time clock (RTC), which is useful for assigning accurate timestamps to recorded measurements. The Arduino code in [set_rtc.ino](./set_rtc.ino) is an Arduino sketch that allows one to set the time manually.  It will then be maintained for as long as the RTC battery lasts (typically, a year or more). 

> Note: if you don't care about 'absolute' time values, but only about the amount of time elapsed since logging began, you can skip this step.

1. Insert a CR1220 coin cell in coin cell holder on the Riffle board.
1. Load [set_rtc.ino](./set_rtc.ino) onto the Riffle, selecting "Arduino UNO" as the 'Board' in the Tools menu.
2. Open the Arduino Serial Terminal (setting the baud rate appropriately)
3. Enter in the current date and time, using the following format:

> year,month,day,hour,minute,second, 

Where:

- year can be two or four digits
- month is 1-12-
- day is 1-31
- hour is 0-23, and
- minute and second are 0-59.       

Hit 'enter' after you are done, and you should see that the date will have changed in the Serial Monitor.

** Basic datalogging **

Now, we're ready to set the Riffle up for basic datalogging.  The code in [riffle_logger_test](./riffle_logger_test) is an Arduino sketch that will repeatedly log data to the sd card, and sleep for N seconds  in between.  N can be set to any multiple of 8 seconds; it comes set to N=1, so that the Riffle will log every 8 seconds or so.   The format of the output is:

> Timestamp, RTC temperature, battery level, analog0 voltage

The code defaults to saving data to a file called 'Datalog1.csv' on the SD card.

1. Insert a microSD card into the microSD card holder on the Riffle.
2. Load [riffle_logger_test](./riffle_basic_logging.ino) onto the Riffle, selecting "Arduino UNO" as the 'board' file.
3. Plug a battery into the general-chemistry battery connector (labeled "General" on the underside of the circuit board)
4. Make sure that the onboard switch is switched to "GEN" 

The Riffle should initially blink a few times at a rate of once per second.  If everything goes well (the SD card can be accessed, etc), the Riffle should then blink every 8 or so seconds, recording data at every blink.

