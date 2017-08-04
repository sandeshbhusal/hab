#include <SD.h>
#include <SPI.h>
#include <string.h>
#include "TinyGPS++.h"
#include "SoftwareSerial.h"
#include "MPU/MPU6050.h"
#include <Ethernet.h>
#include "I2Cdev.h"
#include <Wire.h>
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
        int setupMPU(void){
            accelgyro.initialize();
            Serial.println("Testing device connections...");
            Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
            accelgyro.setXAccelOffset(501);
            accelgyro.setYAccelOffset(619);
            accelgyro.setZAccelOffset(2061);
            accelgyro.setXGyroOffset(-26);
            accelgyro.setYGyroOffset(-12);
            accelgyro.setZGyroOffset(35);
                
        }
        int setup(){
            setupSerial();
            setupMPU();
        }
    public:
        int log(String input){
            Serial.println(input);
            File file = SD.open(fileName, FILE_WRITE);
            if(!file)
                Serial.println("Error writing to the Sd card");
            else 
                Serial.println("Written to SD Card!");
            file.println(input);
            file.close();
            return STATUS_OK;
        }
        HAB(void){
            this->setup();
        }
};

class Data{
    public:
        static byte temperature(void){
            signed int chk = 0;
            return chk;
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
                delay(20);
                return "*";
            }
        }
        static String MPU(){
            int16_t ax, ay, az;
            int16_t gx, gy, gz;
            double time;
            String out;
            accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
            out += String(ax);
            out += String(ay); 
            out += String(az); 
            out += String(gx); 
            out += String(gy); 
            out += String(gz); 
            time = millis();
            out += String(time);
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