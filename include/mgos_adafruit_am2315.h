// #ifndef _MGOS_AM2315_H_
// #define _MGOS_AM2315_H_

#include "Wire.h"
#ifdef __cplusplus
#include "Adafruit_AM2315.h"
#else
typedef struct AM2315Tag Adafruit_AM2315;
#endif

#ifdef __cplusplus 
extern "C" {
    #endif

    //Initial Adafruit_AM2315 driver
    //Return value: handle opaque pointer
    //CPP constructor
    Adafruit_AM2315 *mgos_adafruit_am2315_create(TwoWire *theI2C);

    // Close DallasTemperature handle. Return value: none.
    void mgos_adafruit_am2315_close(Adafruit_AM2315 *am);

    boolean mgos_adafruit_am2315_begin(Adafruit_AM2315 * am);

    float mgos_adafruit_am2315_readTemperature(Adafruit_AM2315 * am);
    
    float mgos_adafruit_am2315_readHumidity(Adafruit_AM2315 * am);
    
    bool mgos_adafruit_am2315_readTemperatureAndHumidity(Adafruit_AM2315 * am, float*, float*);


}
