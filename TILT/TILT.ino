int Y = A1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Y, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int val = analogRead(Y);
  Serial.println(val);
  if (val <280 || val>370) {
    Serial.println("FALL DETECTED!!!!");
    
  } else {
    Serial.println("........."); 
  }
  delay(1000);
//}
}
