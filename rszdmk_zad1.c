#include <LiquidCrystal.h>
#include <util/delay.h>
#include <stdlib.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

char ocitaj_taster()
{
  char taster = 0;
  unsigned char row;
  
  MCUCR &= ~0x10;
  PORTD = 0x0f; 
  
  for(row = 0x80; row != 0x08; row >>= 1)
  {
    DDRD = row;
  _delay_ms(2);
    
    switch(row | ((~PIND) & 0x0f))
    {
      case 0x88:
        taster = '1'; break;
      case 0x84:
        taster = '2'; break;
      case 0x82:
        taster = '3'; break;
      case 0x81:
        taster = 'A'; break;
    
    case 0x48:
        taster = '4'; break;
      case 0x44:
        taster = '5'; break;
      case 0x42:
        taster = '6'; break;
      case 0x41:
        taster = 'B'; break;
    
    case 0x28:
        taster = '7'; break;
      case 0x24:
        taster = '8'; break;
      case 0x22:
        taster = '9'; break;
      case 0x21:
        taster = 'C'; break;
    
    case 0x18:
        taster = '*'; break;
      case 0x14:
        taster = '0'; break;
      case 0x12:
        taster = '#'; break;
      case 0x11:
        taster = 'D'; break;
    }
  }
  
  return taster;
}

byte srce [8] = {
  B00000 ,
  B01010 ,
  B11111 ,
  B11111 ,
  B01110 ,
  B00100 ,
  B00000 ,
};

byte pik [8] = {
  B00100 ,
  B01110 ,
  B11111 ,
  B11111 ,
  B01110 ,
  B00100 ,
  B00000 ,
};

byte karo [8] = {
  B00100 ,
  B01110 ,
  B11111 ,
  B01110 ,
  B01110 ,
  B00100 ,
  B00000 ,
};

byte tref [8] = {
  B00100 ,
  B01110 ,
  B11111 ,
  B01110 ,
  B01100 ,
  B11111 ,
  B00000 ,
};

char lista[5][8];
char karte[5][8] = {srce[8], karo[8], tref[8], pik[8]};
int j;
int kontrola = 0;
int main()
{
  lcd.createChar(0, srce);
  lcd.createChar(1, karo);
  lcd.createChar(2, tref);
  lcd.createChar(3, pik);
  lcd.begin(16, 2);
  lcd.print("Pritisni *");
  while(1)
  {
       char prethodni_taster;
       
       char taster = ocitaj_taster();
       if (taster != '*')
          prethodni_taster = taster;
        if(taster == 0)
          prethodni_taster = 0;
        if(taster == '*'){
          lcd.clear();
          break;
        }  
  }
  
  srand(0);
  
  int n; 
  for(int i = 0; i < 4; i++){
    
    n = rand() % 4;
    switch(n) {
      case 0:
        lcd.write(byte(n));
        break;
      case 1:
        lcd.write(byte(n));
        break;
      case 2:
        lcd.write(byte(n));
        break;
      case 3:
        lcd.write(byte(n));
        break;
    }
  }
  /*
  if(kontrola == 1) {
    kontrola = 0;
    //lcd.clear();
    lcd.print("----");
  }*/
  
  return 0;
}