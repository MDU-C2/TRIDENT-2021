EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
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
U 1 1 6171EB8F
P 5050 2900
AR Path="/6171EB8F" Ref="U?"  Part="1" 
AR Path="/6171D3D4/6171EB8F" Ref="U?"  Part="1" 
F 0 "U?" H 5050 2625 50  0000 C CNN
F 1 "BTS6163D" H 5050 2534 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-4" H 5050 2650 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Infineon-BTS6163D-DS-v01_00-EN.pdf?fileId=5546d4625a888733015aa3da01a1101e" H 5050 2500 50  0001 C CNN
	1    5050 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:D D?
U 1 1 6171F2E6
P 5900 2900
F 0 "D?" H 5900 3117 50  0000 C CNN
F 1 "D" H 5900 3026 50  0000 C CNN
F 2 "" H 5900 2900 50  0001 C CNN
F 3 "~" H 5900 2900 50  0001 C CNN
	1    5900 2900
	-1   0    0    1   
$EndComp
Wire Wire Line
	5750 2900 5650 2900
Text HLabel 4450 2800 0    50   Input ~ 0
Enable_Motors
Text HLabel 4450 2600 0    50   Input ~ 0
Bat+
Text HLabel 5650 2300 2    50   Input ~ 0
Diode_Link_M
Text HLabel 6250 2900 2    50   Input ~ 0
PROFET_Out
Wire Wire Line
	6250 2900 6050 2900
Wire Wire Line
	5650 2300 5650 2900
Connection ~ 5650 2900
Wire Wire Line
	5650 2900 5350 2900
Wire Wire Line
	5050 2600 4450 2600
Wire Wire Line
	4750 2800 4450 2800
$EndSCHEMATC
