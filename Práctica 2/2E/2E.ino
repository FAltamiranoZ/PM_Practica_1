void setup()
{
DDRB = DDRB | B11111111;
}

void loop()
{
asm (
"inicio: \n\t" 
"cbi 0x05,0x06 \n\t" //AD
"sbi 0x05,0x07 \n\t" //RD
"cbi 0x05,0x04 \n\t" //RI
"sbi 0x05,0x02 \n\t" //VI
"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"cbi 0x05,0x02 \n\t" //VI
"sbi 0x05,0x03 \n\t" //AI
"call tiempo \n\t"
"cbi 0x05,0x03 \n\t" //AI
"sbi 0x05,0x04 \n\t" //RI
"cbi 0x05,0x07 \n\t" //RD
"sbi 0x05,0x05 \n\t" //VD
"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"cbi 0x05,0x05 \n\t" //VD
"sbi 0x05,0x06 \n\t" //AD
"call tiempo \n\t"

"jmp main \n\t"

"tiempo: \n\t"
"LDI r22, 70 \n\t"
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
