 # NEM LEO DISTANCE
 
 NEM GPS FLYSKY DISTANCE SENSOR on Arduino LEONARDO
 
 Derives and transmits the distance from home to the flysky remote controler screen using a leonardo arduino
 
 ## Software Features :
 
 - Software utilises a GPS, remote control on an arduino Leonardo
 - Sensors and accuators are all in classes
 - Impelements five tasks execution frequencies
 - Auto derive home after 10 seconds since first lock
 - Derives distance and degrees from a target gps LAT LOT
 - Transmits distance and degrees of vehicle from target gps
 - RGB Led indicator - no gps red, gps lock - green, home set - blue
 
 ## Hardware
 
 Sensors :
 
 - Gps : OP gps or Ublox M8N with compass
 - Receiver : flysky F9-ia10b
 
 Main components : 
 - Transmitter : flysky FS-I6X
 - Receiver : [flysky FS-1A10B](https://www.flysky-cn.com/ia10b-canshu)
 - Arduino Leonaro
 
 Other: 
 
 - RGB LED
 - 3 Pin Female connectors, ribbon cable, conectors, board, box, battery, etc
