int cont = 0;

void setup(){
  Serial.begin(9600);
  noInterrupts();
  DDRB = DDRB | B11111111;
  cli();
  TCCR1B = 0; TCCR1A = 0;
  TCCR1B |= (1 << CS12);
  TCNT1 = 3036; // (1/16000000)*256*(2^16-3036)
  TIMSK1 |= (1 << TOIE1);
  sei();
  interrupts();
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
}

ISR(TIMER1_OVF_vect){
 cont = cont +1;
 Serial.println(cont);
}


void loop() {
  if (cont <= 5) {
   digitalWrite(51, HIGH);
   digitalWrite(13, HIGH);
   digitalWrite(50, LOW);
   digitalWrite(12, LOW); 
   digitalWrite(11, LOW);
   digitalWrite(10, LOW);  
  }
  if (cont > 5 && cont <= 6) {
    digitalWrite(51, LOW);
    digitalWrite(50, HIGH);
  }
  if (cont > 6 && cont  <= 11) {
    digitalWrite(50, LOW);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);   
  }
  if (cont > 11 && cont <= 12) {
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }
  if (cont == 13) {
    cont = 0;
  }
}
