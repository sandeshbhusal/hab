#include "setup.h"
HAB *balloon;
void setup(){
    balloon = new HAB();
    if (!SD.begin(4)) {
        Serial.println("SD Card initialization failed!");
        return;
    }
}
void loop(){
    Data dataRead;
    String GPSDATA = dataRead.GPS();
    if(GPSDATA == "*")
        return;
    else
        balloon->log(GPSDATA);
}