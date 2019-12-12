#include "mgos_adafruit_am2315.h"

Adafruit_AM2315 *mgos_adafruit_am2315_create(TwoWire *theI2C){
    if(theI2C == nullptr) return nullptr;
    return new Adafruit_AM2315(theI2C);
}

void mgos_adafruit_am2315_close(Adafruit_AM2315 *am){
    if(am != nullptr){
        delete am;
        am = nullptr;
    }
}

boolean mgos_adafruit_am2315_begin(Adafruit_AM2315 *am){
    if(am == nullptr) return false;
    return am->begin();
} 

float mgos_adafruit_am2315_readTemperature(Adafruit_AM2315 *am){
    if(am == nullptr) return DEVICE_DISCONNECTED_C;
    return am->readTemperature();
}

float mgos_adafruit_am2315_readHumidity(Adafruit_AM2315 * am){
    if(am == nullptr) return DEVICE_DISCONNECTED_C;
    return am->readHumidity();
}

bool mgos_adafruit_am2315_readTemperatureAndHumidity(Adafruit_AM2315 *am, float *t, float *h){
    if(am == nullptr) return DEVICE_DISCONNECTED_C;
    return am->readTemperatureAndHumidity((float *)t, (float *)h);
}

