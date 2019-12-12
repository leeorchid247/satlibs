let Adafruit_AM2315 = {
  //ERROR Code
  DEVICE_DISCONNECTED_C: -127,

  _create: ffi("void *mgos_adafruit_am2315_create(void *)"),
  _close: ffi("void mgos_adafruit_am2315_close(void *)"),
  _begin: ffi(" boolean mgos_adafruit_am2315_begin(void *)"),
  _readTemperature: ffi("float mgos_adafruit_am2315_readTemperature(void *)"),
  _readHumidity: ffi("float mgos_adafruit_am2315_readHumidity(void *)"),
  _readAll: ffi(
    "bool mgos_adafruit_am2315_readTemperatureAndHumidity(void *, float*, float*)"
  ),
  _byte2hex: function(byte) {
    let hex_char = "0123456789abcdef";
    return hex_char[(byte >> 4) & 0x0f] + hex_char[byte & 0x0f];
  },

  _proto: {
    close: function() {
      return Adafruit_AM2315._close(this.am);
    }
  },

  create: function(i2c) {
    let obj = Object.create(Adafruit_AM2315._proto);
    obj.am = Adafruit_AM2315._create(i2c.i2c);
    return obj;
  },

  begin: function() {
    return Adafruit_AM2315._begin(this.am);
  },

  readTemperature: function() {
    return Adafruit_AM2315._readTemperature(this.am);
  },

  readHumidity: function() {
    return Adafruit_AM2315._readHumidity(this.am);
  },

  readAll: function() {
    return Adafruit_AM2315._readAll(this.am);
  }
};
