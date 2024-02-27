

const int trig_Pin_F = 11;
const int echo_Pin_F = 12;
long duration_F;
int distance_F;


const int trig_Pin_R = 8;
const int echo_Pin_R = 9;

long duration_R;
int distance_R;

int x = A0;
int buzzer = 5;
int F,R;
String str,SF,SR,f;
void setup() {
  pinMode(trig_Pin_F, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo_Pin_F, INPUT);
   pinMode(x, INPUT);
    pinMode(trig_Pin_R, OUTPUT); // Sets the trigPin as an Output
    pinMode(echo_Pin_R, INPUT);// Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
 

}

void loop() {
  forward();
  right();
  fall_status();
  str = String(F) + ","  + String(SF) + "," + String(R) + "," + String(SR)+ "," + String(f);
  Serial.println(str);
  delay(1000);
  
}

void forward(){
  // Clears the trigPin
    digitalWrite(trig_Pin_F, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trig_Pin_F, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_Pin_F, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration_F = pulseIn(echo_Pin_F, HIGH);
    // Calculating the distance
    F= duration_F*0.034/2;
    // Prints the distance on the Serial Monitor
    //Serial.print("Distance_F:");
    //F = distance_F;
    if (F < 30 ){
      SF = "ALERT FORWARD!!!!!!";
      tone(buzzer,4000);
    }
    else{
      SF = "!!!!!!";
      noTone(buzzer);
    }
}

void right(){
  // Clears the trigPin
    digitalWrite(trig_Pin_R, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trig_Pin_R, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_Pin_R, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration_R = pulseIn(echo_Pin_R, HIGH);
    // Calculating the distance
    R= duration_R*0.034/2;
    // Prints the distance on the Serial Monitor
    //Serial.print("Distance_R:");
    //D_R = distance_R;
    if (R < 30 ){
      SR = "RIGHT ALERT!!!!!!";
      digitalWrite(buzzer,HIGH);
    }
    else{
      SR = "!!!!!!"; 
      digitalWrite(buzzer,LOW);
    }
}

void fall_status(){
  int val = analogRead(x);
  if (val < 287 ) {
    f = "FALL DETECTED!!!!";
    digitalWrite(buzzer,HIGH);
    tone(buzzer,4000);
  } 
  else {
    f = "........."; 
  }
}
