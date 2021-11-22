EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
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
L Power_Management:BTS6163D U?
U 1 1 61716C3B
P 2200 1950
F 0 "U?" H 2200 1675 50  0000 C CNN
F 1 "BTS6163D" H 2200 1584 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-4" H 2200 1700 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Infineon-BTS6163D-DS-v01_00-EN.pdf?fileId=5546d4625a888733015aa3da01a1101e" H 2200 1550 50  0001 C CNN
	1    2200 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:D D?
U 1 1 61718290
P 4100 1450
F 0 "D?" H 4100 1667 50  0000 C CNN
F 1 "D" H 4100 1576 50  0000 C CNN
F 2 "" H 4100 1450 50  0001 C CNN
F 3 "~" H 4100 1450 50  0001 C CNN
	1    4100 1450
	1    0    0    -1  
$EndComp
$Comp
L Fuse~holder:H1810-2x4 U?
U 1 1 6171A3A8
P 2800 1100
F 0 "U?" H 2800 1475 50  0000 C CNN
F 1 "H1810-2x4" H 2800 1384 50  0000 C CNN
F 2 "" H 2700 1100 50  0001 C CNN
F 3 "" H 2700 1100 50  0001 C CNN
	1    2800 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C?
U 1 1 6171AC4A
P 4700 1750
F 0 "C?" H 4815 1796 50  0000 L CNN
F 1 "CP1" H 4815 1705 50  0000 L CNN
F 2 "" H 4700 1750 50  0001 C CNN
F 3 "~" H 4700 1750 50  0001 C CNN
	1    4700 1750
	1    0    0    -1  
$EndComp
$Comp
L Relay:DIPxx-1Axx-13x K?
U 1 1 6171BCD1
P 4050 3000
F 0 "K?" H 4380 3046 50  0000 L CNN
F 1 "HE721A0500" H 4380 2955 50  0000 L CNN
F 2 "Relay_THT:Relay_StandexMeder_DIP_LowProfile" H 4400 2950 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 4050 3000 50  0001 C CNN
	1    4050 3000
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC846 Q?
U 1 1 6171C782
P 3950 2300
F 0 "Q?" H 4141 2346 50  0000 L CNN
F 1 "BC846" H 4141 2255 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4150 2225 50  0001 L CIN
F 3 "https://assets.nexperia.com/documents/data-sheet/BC846_SER.pdf" H 3950 2300 50  0001 L CNN
	1    3950 2300
	1    0    0    -1  
$EndComp
$Sheet
S 5350 1100 700  400 
U 6171D3D4
F0 "PROFET_Diode" 50
F1 "PROFET_Diode.sch" 50
F2 "Enable_Motors" I L 5350 1150 50 
F3 "Bat+" I L 5350 1250 50 
F4 "Diode_Link_M" I L 5350 1350 50 
F5 "PROFET_Out" I L 5350 1450 50 
$EndSheet
$Sheet
S 5450 1950 1000 900 
U 61720A29
F0 "Peripheral_Enabling" 50
F1 "Peripheral_Enabling.sch" 50
$EndSheet
$EndSCHEMATC
