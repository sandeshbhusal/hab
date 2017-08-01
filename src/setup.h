#include <SD.h>
#include <SPI.h>
#include <string.h>
#include "lib/TinyGPS++.h"
#include "SoftwareSerial.h"
#include "defines.h"

class HAB{
    private:
        void setupTemp(void){
            pinMode(tempPin, INPUT);
        }
        void setupSerial(void){
            Serial.begin(BAUD);
            mySerial.begin(BAUD);
            while(!Serial);
            while(!mySerial);
        }
        int setupSD(void){
            pinMode(SDPin, OUTPUT);
            if(!SD.begin()) return INIT_SD_ERROR;
            return STATUS_OK;
        }
        int setupMPU(void){
            return STATUS_OK;
        }
        int setup(){
            setupSerial();
            // setupTemp();
            // if(setupSD() == INIT_SD_ERROR){
            //     Serial.println(SD_ERROR_MSG);
            // }
            // else{
            //     Serial.println(SD_OK_MSG);
            // }
        }
    public:
        int log(String input){
            Serial.println(input);
            // File file = SD.open(fileName, FILE_READ);
            // if(!file) return FILE_READ_ERROR;
            // file.println(input);
            // file.close();
            return STATUS_OK;
        }
        void log(int code){
            Serial.println(code);
        }
        HAB(void){
            this->setup();
        }
};

class Data{
    public:
        static float temperature(void){
            float voltage = analogRead(tempPin);
            voltage /= 1024;
            voltage = (voltage - 0.33) * 100;
            return voltage;
        }
        static String GPS(){
            //Return data format: Lat|Lng|Alt|Satellites|Date|Time
            while(mySerial.available()>0){
                gps.encode(mySerial.read());
            }
            if(gps.location.isUpdated()){
                String Data =   String(gps.location.lat(), 9)+"|";
                Data +=   String(gps.location.lng(), 9)+"|";
                Data +=   String(gps.altitude.value())+"|";
                Data +=   String(gps.satellites.value())+"|";
                Data +=   String(gps.date.value())+"|";
                Data +=   String(gps.time.value())+"|";
                return Data;
            }
            else{
                delay(200);
                return GPS();
            }
        }
        static String MPU(){
            return "";
        }
};

class utils{
    private:
        String compressor(String data){
            return "";
        }
    public:
        static String formatData(String GPSData, String TempData, String MPUData){
            return "";
        }
};