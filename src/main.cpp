#include "setup.h"
HAB *balloon;
void setup(){
    balloon = new HAB();
}
void loop(){
    Data dataRead;
    balloon->log(dataRead.GPS());
    balloon->log("Temperature at altitude: ");
    balloon->log(dataRead.temperature());
}