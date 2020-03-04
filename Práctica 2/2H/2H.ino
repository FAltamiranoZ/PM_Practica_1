int cont = 0;
unsigned long previousMillis1 = 0;

void setup() {
  Serial.begin(9600); //Esto define la velocidad de bits por segundo, este es el estandar
  pinMode(13, OUTPUT);
  DDRB = DDRB | B11111111;
  cli();
  DDRD &= ~(1 << DDD1);
  PORTD |= (1 << PORTD1);
  EICRA |= (1 << ISC10);
  EIMSK |= (1 << INT1);
  sei();
}
  
ISR(INT1_vect){
  cont = cont + 1;
  Serial.println(cont);
}

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
