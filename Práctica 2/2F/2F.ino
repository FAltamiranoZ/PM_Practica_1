unsigned long previousMillis1 = 0;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600); //Esto define la velocidad de bits por segundo, este es el estandar
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis1 >= 1000) {
    previousMillis1 = currentMillis;
    if (digitalRead(13) == LOW) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }
  
}
