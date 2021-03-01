# Local MQTT

# MQTT

* Consists of a local mosquitto broker. Version above 2.0. Meaning that config file to the servers must be specified to receive remote connections.

# Node-Red (MQTT Client)

* Consists of a node-red server/dashboard subscribing to humidity and temperature topics acting as a client. 
* A gauge representing the humidity and a graph for the temperature.
* It is also possible to publish on output topic to turn LED on or off. 

# ESP32 (MQTT Client) 

* Consists of an ESP32 connected to WiFi and publishing to topics: temperature and humidity. 
* Subscribes to topic output to turn LED on or off.

Used the help of external websites and sources. Tried to modularize the code for the MQTT connection and initialization. 
