//OLLI I2C-Scanner adapted from wire lib examples for marlin
#include "../../../inc/MarlinConfig.h"

#if ANY(EXPERIMENTAL_I2CBUS_SCANNER, EXPERIMENTAL_I2CBUS)

#include "../../../libs/hex_print.h"
#include "../../gcode.h"

#include <Wire.h> // for i2c
/**
 * M262: Scan i2c bus for connected devices
 */
void GcodeSuite::M262() {
  byte error, address;
  int nDevices;

  Wire.begin();
  SERIAL_ECHOLNPGM("Scanning I2C ...");
  SERIAL_EOL();

  nDevices = 0;
  for(address = 1; address < 127; address++) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.

    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0) {
      SERIAL_ECHOLNPAIR("I2C device found at address 0x", hex_byte(address));  
      SERIAL_EOL();
      nDevices++;
    }
    else if (error == 4) {
      SERIAL_ECHOLNPAIR("Unknown error at address 0x", hex_byte(address));  
      SERIAL_EOL();
    }    
  }
  if (nDevices == 0)
    SERIAL_ECHOLNPGM("... No I2C devices found");
  else
    SERIAL_ECHOLNPGM(" ... done");
  SERIAL_EOL();

}
#endif