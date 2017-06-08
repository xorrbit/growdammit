EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:74xgxx
LIBS:ac-dc
LIBS:actel
LIBS:allegro
LIBS:Altera
LIBS:analog_devices
LIBS:battery_management
LIBS:bbd
LIBS:bosch
LIBS:brooktre
LIBS:cmos_ieee
LIBS:dc-dc
LIBS:diode
LIBS:elec-unifil
LIBS:ESD_Protection
LIBS:ftdi
LIBS:gennum
LIBS:graphic_symbols
LIBS:hc11
LIBS:infineon
LIBS:intersil
LIBS:ir
LIBS:Lattice
LIBS:leds
LIBS:LEM
LIBS:maxim
LIBS:mechanical
LIBS:microchip_dspic33dsc
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic24mcu
LIBS:microchip_pic32mcu
LIBS:modules
LIBS:motor_drivers
LIBS:motors
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp
LIBS:nxp_armmcu
LIBS:onsemi
LIBS:Oscillators
LIBS:powerint
LIBS:Power_Management
LIBS:pspice
LIBS:references
LIBS:relays
LIBS:rfcom
LIBS:RFSolutions
LIBS:sensors
LIBS:silabs
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:switches
LIBS:transf
LIBS:triac_thyristor
LIBS:ttl_ieee
LIBS:video
LIBS:wiznet
LIBS:Worldsemi
LIBS:Xicor
LIBS:zetex
LIBS:Zilog
LIBS:A6_GSM
LIBS:misc
LIBS:nodemcu
LIBS:adafruit
LIBS:GeekAmmo
LIBS:LilyPad-Wearables
LIBS:SparkFun-Aesthetics
LIBS:SparkFun-AnalogIC
LIBS:SparkFun-Boards
LIBS:SparkFun-Capacitors
LIBS:SparkFun-Connectors
LIBS:SparkFun-DigitalIC
LIBS:SparkFun-DiscreteSemi
LIBS:SparkFun-Displays
LIBS:SparkFun-Electromechanical
LIBS:SparkFun-FreqCtrl
LIBS:SparkFun-LED
LIBS:SparkFun-Passives
LIBS:SparkFun-PowerIC
LIBS:SparkFun-Resistors
LIBS:SparkFun-Retired
LIBS:SparkFun-RF
LIBS:SparkFun-Sensors
LIBS:Teensy_3_and_LC_Series_Boards_v1.1
LIBS:User-Submitted
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L NodeMCU_Amica_R2 U?
U 1 1 5938AD4E
P 4300 5250
F 0 "U?" H 4300 6050 50  0000 C CNN
F 1 "NODEMCU 1.0" H 4300 4400 50  0000 C CNN
F 2 "" H 4550 5250 50  0000 C CNN
F 3 "" H 4550 5250 50  0000 C CNN
	1    4300 5250
	1    0    0    -1  
$EndComp
$Comp
L 4052 U?
U 1 1 5938ADBC
P 8200 5150
F 0 "U?" H 8300 5150 50  0000 C CNN
F 1 "4052" H 8300 4950 50  0000 C CNN
F 2 "" H 8200 5150 60  0001 C CNN
F 3 "" H 8200 5150 60  0001 C CNN
	1    8200 5150
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 J?
U 1 1 5938AE89
P 5650 3850
F 0 "J?" H 5650 4050 50  0000 C CNN
F 1 "Soil Moisture" V 5750 3850 50  0000 C CNN
F 2 "" H 5650 3850 50  0001 C CNN
F 3 "" H 5650 3850 50  0001 C CNN
	1    5650 3850
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X04 J?
U 1 1 5938AF52
P 8600 3850
F 0 "J?" H 8600 4100 50  0000 C CNN
F 1 "Si7021" V 8700 3850 50  0000 C CNN
F 2 "" H 8600 3850 50  0001 C CNN
F 3 "" H 8600 3850 50  0001 C CNN
	1    8600 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 J?
U 1 1 5938B053
P 3850 3900
F 0 "J?" H 3850 4100 50  0000 C CNN
F 1 "Ambient Light" V 3950 3900 50  0000 C CNN
F 2 "" H 3850 3900 50  0001 C CNN
F 3 "" H 3850 3900 50  0001 C CNN
	1    3850 3900
	-1   0    0    -1  
$EndComp
Text GLabel 7300 5650 0    60   Input ~ 0
MUX_S0
Text GLabel 6850 5750 0    60   Input ~ 0
MUX_S1
Text GLabel 5150 4850 2    60   Input ~ 0
MUX_S0
Text GLabel 5600 4950 2    60   Input ~ 0
MUX_S1
Wire Wire Line
	4750 4850 5150 4850
$Comp
L GND #PWR?
U 1 1 5938BB1F
P 4100 4100
F 0 "#PWR?" H 4100 3850 50  0001 C CNN
F 1 "GND" H 4100 3950 50  0000 C CNN
F 2 "" H 4100 4100 50  0001 C CNN
F 3 "" H 4100 4100 50  0001 C CNN
	1    4100 4100
	1    0    0    -1  
$EndComp
Text GLabel 6000 3750 2    60   Input ~ 0
SOIL_ENABLE
Wire Wire Line
	6000 3750 5850 3750
Text GLabel 4200 3800 2    60   Input ~ 0
LIGHT_ENABLE
Text GLabel 5700 4750 2    60   Input ~ 0
SOIL_ENABLE
Text GLabel 4950 4650 2    60   Input ~ 0
LIGHT_ENABLE
Wire Wire Line
	4750 4650 4950 4650
Wire Wire Line
	5700 4750 4750 4750
Text GLabel 5750 5350 2    60   Input ~ 0
TEMP_DA
Text GLabel 5050 5250 2    60   Input ~ 0
TEMP_CL
Text GLabel 8200 3900 0    60   Input ~ 0
TEMP_DA
Text GLabel 7700 4000 0    60   Input ~ 0
TEMP_CL
$Comp
L GND #PWR?
U 1 1 5938BF2F
P 8350 4050
F 0 "#PWR?" H 8350 3800 50  0001 C CNN
F 1 "GND" H 8350 3900 50  0000 C CNN
F 2 "" H 8350 4050 50  0001 C CNN
F 3 "" H 8350 4050 50  0001 C CNN
	1    8350 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 3700 8350 3700
Wire Wire Line
	8350 3700 8350 4050
Text GLabel 7700 3800 0    60   Input ~ 0
TEMP_ENABLE
Text GLabel 5050 5450 2    60   Input ~ 0
TEMP_ENABLE
Text GLabel 6000 3950 2    60   Input ~ 0
SOIL_SIG
Wire Wire Line
	5850 3950 6000 3950
$Comp
L GND #PWR?
U 1 1 5938C0ED
P 5900 4050
F 0 "#PWR?" H 5900 3800 50  0001 C CNN
F 1 "GND" H 5900 3900 50  0000 C CNN
F 2 "" H 5900 4050 50  0001 C CNN
F 3 "" H 5900 4050 50  0001 C CNN
	1    5900 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3850 5900 3850
Wire Wire Line
	5900 3850 5900 4050
Wire Wire Line
	4050 3900 4100 3900
Wire Wire Line
	4100 3900 4100 4100
Text GLabel 4200 4000 2    60   Input ~ 0
LIGHT_SIG
Wire Wire Line
	4050 4000 4200 4000
Wire Wire Line
	4050 3800 4200 3800
Text GLabel 7400 4650 0    60   Input ~ 0
SOIL_SIG
Text GLabel 6900 4550 0    60   Input ~ 0
LIGHT_SIG
Wire Wire Line
	4750 4950 5600 4950
Wire Wire Line
	8400 3800 7700 3800
Wire Wire Line
	8400 3900 8200 3900
Wire Wire Line
	8400 4000 7700 4000
Text GLabel 3650 4550 0    60   Input ~ 0
ESP_AD0
Wire Wire Line
	3850 4550 3650 4550
Text GLabel 9100 4550 2    60   Input ~ 0
ESP_AD0
Wire Wire Line
	9100 4550 8900 4550
$Comp
L GND #PWR?
U 1 1 5938CDBF
P 4850 6000
F 0 "#PWR?" H 4850 5750 50  0001 C CNN
F 1 "GND" H 4850 5850 50  0000 C CNN
F 2 "" H 4850 6000 50  0001 C CNN
F 3 "" H 4850 6000 50  0001 C CNN
	1    4850 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 5850 4850 5850
Wire Wire Line
	4850 5150 4850 6000
Wire Wire Line
	4750 5150 4850 5150
Connection ~ 4850 5850
$Comp
L GND #PWR?
U 1 1 5938CE22
P 3750 6050
F 0 "#PWR?" H 3750 5800 50  0001 C CNN
F 1 "GND" H 3750 5900 50  0000 C CNN
F 2 "" H 3750 6050 50  0001 C CNN
F 3 "" H 3750 6050 50  0001 C CNN
	1    3750 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 5850 3750 5850
Wire Wire Line
	3750 5450 3750 6050
Wire Wire Line
	3850 5450 3750 5450
Connection ~ 3750 5850
$Comp
L GND #PWR?
U 1 1 5938CE97
P 9000 5750
F 0 "#PWR?" H 9000 5500 50  0001 C CNN
F 1 "GND" H 9000 5600 50  0000 C CNN
F 2 "" H 9000 5750 50  0001 C CNN
F 3 "" H 9000 5750 50  0001 C CNN
	1    9000 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 5650 9000 5650
Wire Wire Line
	9000 5650 9000 5750
$Comp
L GND #PWR?
U 1 1 5938CF77
P 7400 5850
F 0 "#PWR?" H 7400 5600 50  0001 C CNN
F 1 "GND" H 7400 5700 50  0000 C CNN
F 2 "" H 7400 5850 50  0001 C CNN
F 3 "" H 7400 5850 50  0001 C CNN
	1    7400 5850
	1    0    0    -1  
$EndComp
NoConn ~ 8900 4950
NoConn ~ 7500 4750
NoConn ~ 7500 4850
NoConn ~ 7500 4950
NoConn ~ 7500 5050
NoConn ~ 7500 5150
NoConn ~ 7500 5250
NoConn ~ 3850 4850
NoConn ~ 3850 4950
NoConn ~ 3850 5050
NoConn ~ 3850 5150
NoConn ~ 3850 5250
NoConn ~ 4750 5550
NoConn ~ 4750 5650
NoConn ~ 4750 5750
$Comp
L +3.3V #PWR?
U 1 1 5938D061
P 5150 5850
F 0 "#PWR?" H 5150 5700 50  0001 C CNN
F 1 "+3.3V" H 5150 5990 50  0000 C CNN
F 2 "" H 5150 5850 50  0001 C CNN
F 3 "" H 5150 5850 50  0001 C CNN
	1    5150 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 5950 5150 5950
$Comp
L +3.3V #PWR?
U 1 1 5938D104
P 3550 5400
F 0 "#PWR?" H 3550 5250 50  0001 C CNN
F 1 "+3.3V" H 3550 5540 50  0000 C CNN
F 2 "" H 3550 5400 50  0001 C CNN
F 3 "" H 3550 5400 50  0001 C CNN
	1    3550 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 5550 3550 5550
Wire Wire Line
	3550 5550 3550 5400
NoConn ~ 3850 5950
Text GLabel 3450 5750 0    60   Input ~ 0
WAKE
Wire Wire Line
	3850 5750 3450 5750
Text GLabel 5700 4550 2    60   Input ~ 0
WAKE
Wire Wire Line
	5700 4550 4750 4550
Wire Wire Line
	4750 5050 4950 5050
Wire Wire Line
	4950 5050 4950 5950
Connection ~ 4950 5950
Wire Wire Line
	5050 5250 4750 5250
Wire Wire Line
	4750 5350 5750 5350
Wire Wire Line
	5050 5450 4750 5450
Wire Wire Line
	5150 5950 5150 5850
NoConn ~ 3850 5650
NoConn ~ 3850 5350
Wire Wire Line
	7500 5450 7400 5450
Wire Wire Line
	7400 5450 7400 5850
Wire Wire Line
	7500 5650 7300 5650
Wire Wire Line
	7500 5750 6850 5750
Wire Wire Line
	6900 4550 7500 4550
Wire Wire Line
	7500 4650 7400 4650
$EndSCHEMATC
