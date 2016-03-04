# riffle-getting-started

## Hardware requirements

- Riffle datalogger
- CR1220 coin cell battery
- main battery (3.7 V - 6 v)

## Blinking the onboard LED 

- code

## Setting the Real Time Clock

The real time clock (RTC) is useful for assigning accurate timestamps to recorded measurements.
 
There is an Arduino sketch that allows one to set the time manually.  It will then be maintained for as long as the RTC battery lasts (typically, a year or more). 

## Basic datalogging

This sketch will log data to the sd card at intervals of N seconds.  The format of the output is:


> Timestamp, RTC temperature, battery level, analog0 voltage

It defaults to saving data to a file called 'Datalog1.csv'.



