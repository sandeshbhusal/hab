enum errorClass{
    STATUS_OK,
    FILE_READ_ERROR,
    INIT_SD_ERROR,
    INIT_SERIAL_ERROR,
    INIT_MPU_ERROR,
    INIT_TEMP_ERROR,
    INIT_GPS_ERROR
};

TinyGPSPlus gps;
SoftwareSerial mySerial(9, 8);
dht11 DHT;

#define SDPin       4
#define fileName    "d.ata"
#define tempPin     0
#define BAUD        9600


#define SD_ERROR_MSG        "Error initializing Sd card"
#define FILE_ERROR_MSG      "Error initializing File"
#define SERIAL_ERROR_MSG    "Error initializing Serial"
#define TEMP_ERRR_MSG       "Error initializing Temperature"
#define MPU_ERROR_MSG       "Error initializing MPU"

#define SD_OK_MSG           "OK initializing Sd card"
#define FILE_OK_MSG         "OK initializing File"
#define SERIAL_OK_MSG       "OK initializing Serial"
#define TEMP_OK_MSG         "OK initializing Temperature"
#define MPU_OK_MSG          "OK initializing MPU"