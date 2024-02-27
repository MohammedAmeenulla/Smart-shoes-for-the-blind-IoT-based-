#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
static const int RXPin = 4, TXPin = 5;
static const uint32_t GPSBaud = 9600;


// The TinyGPSPlus object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ss.begin(GPSBaud);
}

void loop() {
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();
}
void displayInfo()
{
  Serial.println(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print("LATITUDE:");
    Serial.println(gps.location.lat(), 6);
      //Blynk.virtualWrite(V8,gps.location.lat(),6);
    Serial.print(F(","));
    Serial.print("LONGITUDE:");
    Serial.println(gps.location.lng(), 6);
    // Blynk.virtualWrite(V9,gps.location.lng(),6);

  }
  else
  {
    Serial.print(F("INVALID"));
  }
  delay(1000);
}
