# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

TARGET = GSM-krvavec.cpp


ARDUINO_DIR = ../arduino-1.8.3
ARDMK_DIR = ../Arduino-Makefile
BOARD_TAG = uno
#MCU = atmega328p
#ISP_PROG = micronucleus # Use with arduino bootloader
#ISP_PROG = usbtiny # Use without bootloader. Program wuth USBtiny
#ISP_PORT     = /dev/ttyUSB0
#F_CPU = 16500000L

#AVRDUDE = ../arduino-1.8.3/hardware/tools/avr/bin/

USER_LIB_PATH = libraries
ARDUINO_LIBS = Wire SoftwareSerial GPRS_SIM900
#DigisparkSoftSerial DigisparkTinyPinChange



FORCE_MONITOR_PORT = 1

#include ../Arduino-mk-Digispark-master/Arduino.mk
include ../Arduino-Makefile/Arduino.mk
