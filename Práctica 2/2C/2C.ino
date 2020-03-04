unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600); //Esto define la velocidad de bits por segundo, este es el estandar
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  /*digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(50, HIGH);
  digitalWrite(51, HIGH);
  delay(1000);                    
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(50, LOW);
  digitalWrite(51, LOW);
  delay(1000);*/
  
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis1 >= 250) {
    previousMillis1 = currentMillis;
    if (digitalRead(13) == LOW) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }
  if (currentMillis - previousMillis2 >= 500) {
  previousMillis2 = currentMillis;
    if (digitalRead(12) == LOW) {
      digitalWrite(12, HIGH);
    } else {
      digitalWrite(12, LOW);
    }
  }
  if (currentMillis - previousMillis3 >= 1000) {
  previousMillis3 = currentMillis;
    if (digitalRead(11) == LOW) {
      digitalWrite(11, HIGH);
    } else {
      digitalWrite(11, LOW);
    }
  }
  if (currentMillis - previousMillis4 >= 2000) {
  previousMillis4 = currentMillis;
    if (digitalRead(10) == LOW) {
      digitalWrite(10, HIGH);
    } else {
      digitalWrite(10, LOW);
    }
  }
  
}
