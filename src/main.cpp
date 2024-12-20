#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = 16, TXPin = 17;
static const uint32_t GPSBaud = 9600;

// The TinyGPSPlus object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);
}

void loop()
{
  while (ss.available())
  {
    gps.encode(ss.read());
  }
  Serial.println((gps.speed.kmph()));
  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.println(F("No GPS data received: check wiring"));
}

/*
static const int RXPin = 16, TXPin = 17;
static const uint32_t GPSBaud = 9600;
*/