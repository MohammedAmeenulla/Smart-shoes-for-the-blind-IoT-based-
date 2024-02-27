int BUZZER =6;
const int trig_Pin = 4;
const int echo_Pin = 5;
long duration;
int distance;
void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(trig_Pin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo_Pin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
      digitalWrite(BUZZER,HIGH);

  // Clears the trigPin
  digitalWrite(trig_Pin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_Pin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo_Pin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  if(distance<35){
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.println("ALERT!!!!!STOP!!!!!");
    digitalWrite(BUZZER,HIGH);
    delay(1000);
  }
  else{
    Serial.println("forward!!!!!");
    digitalWrite(BUZZER,HIGH);
  }
}
