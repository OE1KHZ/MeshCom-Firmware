#include "i2c_scanner.h"

#include <Wire.h>               

// I2C Scanner Function
String scanI2C()
{

String strInfo = "";

    uint8_t error, address;
    int nDevices = 0;

    char cInfo[100] = {0};

    sprintf(cInfo, "--[I2C] ... Scanner\n");
    strInfo.concat(cInfo);

    #if defined(ESP32)
        Wire.begin(I2C_SDA, I2C_SCL);
    #else
        Wire.begin();
    #endif

    for (address = 1; address < 127; address++)
    {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error == 0)
        {
            String strDev="";
            if(address == 0x20)strDev="MCP23017/0";
            if(address == 0x21)strDev="MCP23017/1";
            if(address == 0x34)strDev="AXP192/2101";
            if(address == 0x3C)strDev="OLED";
            if(address == 0x40)strDev="INA226";
            if(address == 0x70)strDev="TCA9548A/0";
            if(address == 0x71)strDev="TCA9548A/1";
            if(address == 0x76)strDev="BME280/BMP280/BME680";
            if(address == 0x77)strDev="BME280/BMP280/BME680";
            sprintf(cInfo, "[I2C] ... device found at address 0x%02X %s\n", address, strDev.c_str());
            strInfo.concat(cInfo);

            nDevices++;
        }
        else if (error == 4)
        {
            sprintf(cInfo, "[I2C] ... Unknown error at address 0x%02X\n", address);
            strInfo.concat(cInfo);
        }
    }

    if (nDevices == 0)
    {
        sprintf(cInfo, "[I2C] ... No devices found\n");
        strInfo.concat(cInfo);
    }

    return strInfo;

}