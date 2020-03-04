int cont = 0;

void setup() {
  Serial.begin(9600); //Esto define la velocidad de bits por segundo, este es el estandar
  pinMode(13, OUTPUT);
  DDRB = DDRB | B11111111;
  cli();
  TCCR0A = 0;
  TCCR0B = 1;
  TCNT1H = 0; //No se puede declarar tcnt1h si no se declaró tccr0a, por ejemplo, si yo declaro tccr0a y tccr0b y luego tcnt0, este no va a funcionar.
  TCNT1L = 0;
  sei();
}

void loop() {
  digitalWrite(13, HIGH);
  funcdelay();
  digitalWrite(13, LOW);
  funcdelay();
}

void funcdelay(){
  asm (
"inicio: \n\t" 
"call tiempo \n\t"
"break \n\t"

"tiempo: \n\t"
"LDI r20, 0 \n\t"
"OUT TCNT1L,r20 \n\t"
"OUT TCNT1H,r20 \n\t"
/*
"LDI r22, 30 \n\t"
"LOOP_3: \n\t"
"LDI r21, 255 \n\t"
"LOOP_2: \n\t"

"LOOP_1: \n\t"
"in r20, TIFR0 \n\t"


"DEC r21 \n\t"
"BRNE LOOP_2 \n\t"
"DEC r22 \n\t"
"BRNE LOOP_3 \n\t"*/
"ret \n\t"
);
}
