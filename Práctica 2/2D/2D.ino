void setup()
{
DDRB = DDRB | B11111111;
}

void loop()
{
asm (
"inicio: \n\t" 
"sbi 0x05,0x07 \n\t" //.25
"sbi 0x05,0x06 \n\t" //.5
"sbi 0x05,0x05 \n\t" //1
"sbi 0x05,0x04 \n\t" //2
"call tiempo \n\t"
"cbi 0x05,0x07 \n\t" //.25
"call tiempo \n\t"
"sbi 0x05,0x07 \n\t" //.25
"cbi 0x05,0x06 \n\t" //.5
"call tiempo \n\t"
"cbi 0x05,0x07 \n\t" //.25
"call tiempo \n\t"
//1 segundo
"sbi 0x05,0x07 \n\t" //.25
"sbi 0x05,0x06 \n\t" //.5
"cbi 0x05,0x05 \n\t" //1
"call tiempo \n\t"
"cbi 0x05,0x07 \n\t" //.25
"call tiempo \n\t"
"sbi 0x05,0x07 \n\t" //.25
"cbi 0x05,0x06 \n\t" //.5
"call tiempo \n\t"
"cbi 0x05,0x07 \n\t" //.25
"call tiempo \n\t"
//2 segundos
"sbi 0x05,0x07 \n\t" //.25
"sbi 0x05,0x06 \n\t" //.5
"sbi 0x05,0x05 \n\t" //1
"cbi 0x05,0x04 \n\t" //2
"call tiempo \n\t"
"cbi 0x05,0x07 \n\t" //.25
"call tiempo \n\t"
"sbi 0x05,0x07 \n\t" //.25
"cbi 0x05,0x06 \n\t" //.5
"call tiempo \n\t"
"cbi 0x05,0x07 \n\t" //.25
"call tiempo \n\t"
//3 segundos
"sbi 0x05,0x07 \n\t" //.25
"sbi 0x05,0x06 \n\t" //.5
"cbi 0x05,0x05 \n\t" //1
"call tiempo \n\t"
"cbi 0x05,0x07 \n\t" //.25
"call tiempo \n\t"
"sbi 0x05,0x07 \n\t" //.25
"cbi 0x05,0x06 \n\t" //.5
"call tiempo \n\t"
"cbi 0x05,0x07 \n\t" //.25
"call tiempo \n\t"
//4 segundos
"jmp main \n\t"

"tiempo: \n\t"
"LDI r22, 20 \n\t"
"LOOP_3: \n\t"
"LDI r21, 255 \n\t"
"LOOP_2: \n\t"
"LDI r20, 255 \n\t"
"LOOP_1: \n\t"
"DEC r20 \n\t"
"BRNE LOOP_1 \n\t"
"DEC r21 \n\t"
"BRNE LOOP_2 \n\t"
"DEC r22 \n\t"
"BRNE LOOP_3 \n\t"
"ret \n\t"
);
}
