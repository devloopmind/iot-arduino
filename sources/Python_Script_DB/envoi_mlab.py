import os # Pour executer une commande bash
import datetime # Pour avoir l'heure

from serial import Serial

serial_port = Serial(port='/dev/tty.wchusbserial1410',baudrate=9600)

while True:
	direction_lue = serial_port.readline()
	direction_lue = int(direction_lue) # on le cast en int car readline prend les caracteres charriots
	now = datetime.datetime.now()
	os.system("curl -i -X POST -H \"Content-Type:application/json\" -d '{ \"direction\" : \""+ str(direction_lue) +"\", \"date\" : \""+ str(now.strftime("%Y-%m-%d %H:%M:%S")) +"\" }' https://api.mlab.com/api/1/databases/project-arduino-rs/collections/direction?apiKey=LOfDlu3AOFaGioAYucPxA_WUUBMiAxd9")
	pass