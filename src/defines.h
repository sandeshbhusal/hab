enum errorClass{
    STATUS_OK,
    FILE_READ_ERROR,
    INIT_SD_ERROR,
    INIT_SERIAL_ERROR,
    INIT_MPU_ERROR,
    INIT_TEMP_ERROR,
    INIT_GPS_ERROR
};

MPU6050 accelgyro;
TinyGPSPlus gps;
SoftwareSerial mySerial(9, 8);

// #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
// #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
// #endif


#define IMUInt      2
#define SDPin       4
#define fileName    "data.txt"
#define tempPin     0
#define BAUD        9600
