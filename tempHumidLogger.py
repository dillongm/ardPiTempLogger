#log data from UNO
#pi will read data over USB via serial
#utilizes 'Pyserial'


#TODO: 
#log data into .txt file and attach timestamps to each read
import serial
import time
import csv


def clean(L): #cleans up serial data
	newList = []
	for i in range(len(L)):
		temp=L[I][2:]
		newList.append(temp[:-5])
	return newList
	
def write(L): #writes data to .txt
	file = open("tempHumidData.txt",mode='w') #CHANGE TO APPEND LATER?
	for i in range(len(L)):
		file.write(L[i] + '\n')
	file.close()


#obtain serial data
try:
	arduino = serial.Serial("/dev/ttyACM0",timeout = 1)
except:
	print('Error')

rawData= []



while True:
	rawData.append(str(arduino.readline()))
	print(rawData)


cleanData = clean(rawData)
write(cleanData)

