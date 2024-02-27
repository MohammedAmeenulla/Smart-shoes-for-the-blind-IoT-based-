/* Comment this out to disable prints and save space */
#define BLYNK_PRINT DebugSerial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPL3N-H3Xw1K"
#define BLYNK_TEMPLATE_NAME "smart glass"
#define BLYNK_AUTH_TOKEN "riuQ69C5GQvGNFbC_XB4EGHC9Lh57FJQ"


// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

const int trig_Pin_G = 8;//glass
const int echo_Pin_G = 9;
long duration_G;
int distance_G;
int buzzer = 5;
int buz =6;
void setup()
{
  // Debug console
  DebugSerial.begin(9600);
   pinMode(buzzer, OUTPUT);
   pinMode(buz, OUTPUT);
    pinMode(trig_Pin_G, OUTPUT); // Sets the trigPin as an Output
    pinMode(echo_Pin_G, INPUT); // Sets the echoPin as an Input
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void loop()
{
  Blynk.run();
  glass();
}

void glass(){
    digitalWrite(trig_Pin_G, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trig_Pin_G, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_Pin_G, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration_G = pulseIn(echo_Pin_G, HIGH);
    // Calculating the distance
    distance_G= duration_G*0.034/2;
    Blynk.virtualWrite(V11,distance_G);
    if (distance_G < 35){
      digitalWrite(buzzer,HIGH);
      digitalWrite(buz,HIGH);
      Blynk.virtualWrite(V7,"Glass_ALERT!!");
      //Blynk.logEvent("test");
    }
    else{
      digitalWrite(buzzer,LOW);
      digitalWrite(buz,LOW);

      Blynk.virtualWrite(V7,"!!!!!!!");
    }
}
