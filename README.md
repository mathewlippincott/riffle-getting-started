# Getting started with the Riffle datalogger

## Hardware requirements

- Riffle datalogger
- CR1220 coin cell battery
- main battery (3.7 V - 6 v)

## First steps


### Blinking the onboard LED 

[riffle_blink.ino](./riffle_blink.ino) simply blinks the onboard LED (pin 9).

### Setting the Real Time Clock

The real time clock (RTC) is useful for assigning accurate timestamps to recorded measurements.
 
[set_rtc.ino](./set_rtc.ino) is an Arduino sketch that allows one to set the time manually.  It will then be maintained for as long as the RTC battery lasts (typically, a year or more). 

This code requires that the following libraries be installed in the "libraries" folder in your Arduino IDE sketchbook:

- [DS3232RTC](http://github.com/JChristensen/DS3232RTC)
- [Streaming](http://arduiniana.org/libraries/streaming/)
- [Time](https://github.com/PaulStoffregen/Time)

### Basic datalogging

[riffle_logger_test](./riffle_logger_test) is a sketch that will log data to the sd card every N seconds, sleeping in between measurements. N can be set to any multiple of 8 seconds. The format of the output is:

> Timestamp, RTC temperature, battery level, analog0 voltage

The code defaults to saving data to a file called 'Datalog1.csv'.

The code requires that the following libraries be installed in the "libraries" folder in your Arduino IDE sketchbook:

- [Low Power](https://github.com/rocketscream/Low-Power)
- [DS3232RTC](http://github.com/JChristensen/DS3232RTC)


