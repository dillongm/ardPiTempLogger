#log data from UNO
#pi will read data over USB via serial
#utilizes 'Pyserial'


#TODO: 
#log data to file and attach timestamps to each read
import serial

#obtain serial data
try:
	arduino = serial.Serial("/dev/ttyACM0",timeout = 1)
except:
	print('Error')

rawData= []
count= 0

while count < 3:
	rawData.append(str(arduino.readline()))
	count = count + 1
print(rawData)

#