#include <LiquidCrystal.h>
#include <Keypad.h>
#define COLS 20 
#define ROWS 4
const byte filas = 4;
const byte columnas = 3;
byte pinsFilas[filas]={31,32,33,34};
byte pinsColumnas[columnas]={35,36,37};
char teclas[filas][columnas]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

Keypad teclado=Keypad(makeKeymap(teclas),pinsFilas,pinsColumnas,filas,columnas);

//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(38,39,40,41,42,43);

byte Triangulo1[8]={
  B11000,
  B11100,
  B11110,
  B11111,
  B11111,
  B11110,
  B11100,
  B11000,
};
byte Triangulo2[8]={
  B00011,
  B00111,
  B01111,
  B11111,
  B11111,
  B01111,
  B00111,
  B00011,
};
byte Nave[8]={
  B00000,
  B00100,
  B00100,
  B01010,
  B01110,
  B11111,
  B10101,
  B00000,
};
byte Base[8]={
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte Canon[8]={
  B00000,
  B10000,
  B11000,
  B11111,
  B11111,
  B11000,
  B10000,
  B00000,
};
byte Ene[8]={
  B00110,
  B00000,
  B10110,
  B11001,
  B10001,
  B10001,
  B10001,
  B00000,
};
byte Exc[8]={
  B00000,
  B00100,
  B00000,
  B00000,
  B00100,
  B00100,
  B00100,
  B00100,
};
byte Exp[8]={
  B00000,
  B00100,
  B10101,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
};

int opci, velocidad = 200, puntuacion=-1, x=19,y=2;;
bool bucle=true;
char tecla;
long oleada[11];

void setup() {
  // put your setup code here, to run once:

  lcd.createChar (0,Triangulo1);
  lcd.createChar (1,Triangulo2);
  lcd.createChar (2,Nave);
  lcd.createChar (3,Base);
  lcd.createChar (4,Canon);
  lcd.createChar (5,Exp);
  lcd.createChar (6,Exc);
  lcd.createChar (7,Ene);
  lcd.begin(20,4); 
  lcd.setCursor(0, 0);
  lcd.clear();
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  intro();
  menu();
}

void intro(){
  lcd.setCursor(6,1);
    lcd.print("SPATIAL");
    lcd.setCursor(6,2);
    lcd.print("GENOCIDE");
  for(int k=3; k>-1;k--){
    lcd.setCursor(6,1);
    lcd.print("SPATIAL");
    lcd.setCursor(6,2);
    lcd.print("GENOCIDE");
    lcd.setCursor(1,k);
    lcd.write (byte(2));
    lcd.setCursor(18,k);
    lcd.write (byte(2));
    delay(400);
    lcd.clear();
  }
  lcd.setCursor(6,1);
  lcd.print("SPATIAL");
  lcd.setCursor(6,2);
  lcd.print("GENOCIDE");
  delay(1000);
  lcd.clear();
  for(int i=0; i<20;i++){
    lcd.setCursor(i,0);
    lcd.write (byte (0));
    lcd.setCursor(i,1);
    lcd.write (byte (0));
    lcd.setCursor(i,2);
    lcd.write (byte (0));
    lcd.setCursor(i,3);
    lcd.write (byte (0));
    delay(50);
    lcd.clear();
}
   lcd.clear();
  for(int j=20; j>0;j--){
    lcd.setCursor(j,0);
    lcd.write (byte (1));
    lcd.setCursor(j,1);
    lcd.write (byte (1));
    lcd.setCursor(j,2);
    lcd.write (byte (1));
    lcd.setCursor(j,3);
    lcd.write (byte (1));
    delay(50);
    lcd.clear();
}
}

void menu(){
  do{
    lcd.clear();
  while(tecla==NO_KEY){
      tecla=teclado.getKey();
      lcd.setCursor(0,0);
      lcd.print("1.Jugar");
      lcd.setCursor(0,1);
      lcd.print("2.Instrucciones");
      lcd.setCursor(0,2);
      lcd.print("3.Desarrolladores");
    }
   opci=tecla-48;
   tecla=NO_KEY;
   switch (opci){
    case 1:
      juego();
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print("Esquiva balas de los");
      lcd.setCursor(0,1);
      lcd.print("ca");
      lcd.write (byte(7));
      lcd.print("ones utilizando");
      lcd.setCursor(0,2);
      lcd.print("las teclas 2 4 5 6");
      lcd.setCursor(0,3);
      lcd.write (byte(6));
      lcd.print("buena suerte!");
      while(tecla==NO_KEY){
        tecla=teclado.getKey();
      }  
      tecla=NO_KEY;
      break;
     case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Jesus Martinez");
      lcd.setCursor(0,1);
      lcd.print("15300164");
      lcd.setCursor(0,2);
      lcd.print("Kevin Medina");
      lcd.setCursor(0,3);
      lcd.print("15300173");
      while(tecla==NO_KEY){
        tecla=teclado.getKey();
      }  
      tecla=NO_KEY;
      break;
   }
  }while(bucle==true);
}

void juego(){
  velocidad = 200;
  x = 19;
  y = 2;
  puntuacion = -1;
  canones();
  disparos();
}

void canones(){
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.setCursor(0,1);
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.setCursor(0,2);
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.setCursor(0,3);
  lcd.write(byte(3));
  lcd.write(byte(4));
   
}
void nave(){
  lcd.setCursor(x,y);
  lcd.write(byte(2));
}

void disparos(){
  int cont=0,DisPos1=2,DisPos2=2,DisPos3=2,DisPos4=2;
  long num;
  for (int i=0;i<4;i++){
    oleada[i] = random(4);
    //oleada[i]=num;
  }
  puntuacion++;
  if (DisPos1==2&&DisPos2==2&&DisPos3==2&&DisPos4==2){
    canones();
    nave();
    leerTecla();
    nave();
    fin(DisPos1, DisPos2, DisPos3, DisPos4);
    lcd.setCursor(DisPos1,oleada[0]);
    lcd.print("-"); 
    delay(velocidad);
    DisPos1++;
    lcd.clear();
    canones();
    leerTecla();
    nave();
    fin(DisPos1, DisPos2, DisPos3, DisPos4);
    lcd.setCursor(DisPos1,oleada[0]);
    lcd.print("-");
    DisPos1++;
    lcd.clear();
    canones();
    leerTecla();
    nave();
    fin(DisPos1, DisPos2, DisPos3, DisPos4);
    lcd.setCursor(DisPos1,oleada[0]);
    lcd.print("-"); 
    lcd.setCursor(DisPos2,oleada[1]);
    lcd.print("-"); 
    delay(velocidad);
    DisPos1++;
    DisPos2++;
    lcd.clear();
    canones();
    leerTecla();
    nave();
    fin(DisPos1, DisPos2, DisPos3, DisPos4);
    lcd.setCursor(DisPos1,oleada[0]);
    lcd.print("-"); 
    lcd.setCursor(DisPos2,oleada[1]);
    lcd.print("-"); 
    DisPos1++;
    DisPos2++;
    lcd.clear();
    canones();
    leerTecla();
    nave();
    fin(DisPos1, DisPos2, DisPos3, DisPos4);
    lcd.setCursor(DisPos1,oleada[0]);
    lcd.print("-"); 
    lcd.setCursor(DisPos2,oleada[1]);
    lcd.print("-"); 
    lcd.setCursor(DisPos3,oleada[2]);
    lcd.print("-"); 
    delay(velocidad);
    DisPos1++;
    DisPos2++;
    DisPos3++;
    lcd.clear();
    canones();
    leerTecla();
    nave();
    fin(DisPos1, DisPos2, DisPos3, DisPos4);
    lcd.setCursor(DisPos1,oleada[0]);
    lcd.print("-"); 
    lcd.setCursor(DisPos2,oleada[1]);
    lcd.print("-"); 
    lcd.setCursor(DisPos3,oleada[2]);
    lcd.print("-"); 
    delay(velocidad);
    DisPos1++;
    DisPos2++;
    DisPos3++;
    lcd.clear();
    canones();
    tecla = teclado.getKey();
    leerTecla();
    nave();
    fin(DisPos1, DisPos2, DisPos3, DisPos4);
    lcd.setCursor(DisPos1,oleada[0]);
    lcd.print("-"); 
    lcd.setCursor(DisPos2,oleada[1]);
    lcd.print("-"); 
    lcd.setCursor(DisPos3,oleada[2]);
    lcd.print("-"); 
    lcd.setCursor(DisPos4,oleada[3]);
    lcd.print("-"); 
    delay(velocidad);
    DisPos1++;
    DisPos2++;
    DisPos3++;
    DisPos4++;
    lcd.clear();
    canones();
    leerTecla();
    nave();
    fin(DisPos1, DisPos2, DisPos3, DisPos4);
    lcd.setCursor(DisPos1,oleada[0]);
    lcd.print("-"); 
    lcd.setCursor(DisPos2,oleada[1]);
    lcd.print("-"); 
    lcd.setCursor(DisPos3,oleada[2]);
    lcd.print("-"); 
    lcd.setCursor(DisPos4,oleada[3]);
    lcd.print("-"); 
    delay(velocidad);
    DisPos1++;
    DisPos2++;
    DisPos3++;
    DisPos4++;
    lcd.clear();
    canones();
    leerTecla();
    nave();
    fin(DisPos1, DisPos2, DisPos3, DisPos4);
    lcd.setCursor(DisPos1,oleada[0]);
    lcd.print("-"); 
    lcd.setCursor(DisPos2,oleada[1]);
    lcd.print("-"); 
    lcd.setCursor(DisPos3,oleada[2]);
    lcd.print("-"); 
    lcd.setCursor(DisPos4,oleada[3]);
    lcd.print("-"); 
    delay(velocidad);
    DisPos1++;
    DisPos2++;
    DisPos3++;
    DisPos4++;
  }
  do{
    lcd.clear();
    canones();
    leerTecla();
    nave();
    fin(DisPos1, DisPos2, DisPos3, DisPos4);
    if(DisPos1<19){
      lcd.setCursor(DisPos1,oleada[0]);
    lcd.print("-"); 
    }
    if(DisPos2<19){
      lcd.setCursor(DisPos2,oleada[1]);
    lcd.print("-"); 
    }
    if(DisPos3<19){
      lcd.setCursor(DisPos3,oleada[2]);
    lcd.print("-"); 
    }
    if(DisPos4<19){
      lcd.setCursor(DisPos4,oleada[3]);
    lcd.print("-"); 
    }
    delay(velocidad);
    DisPos1++;
    DisPos2++;
    DisPos3++;
    DisPos4++;
  }while(DisPos4<19);
  fin(DisPos1, DisPos2, DisPos3, DisPos4);
  disparos();
  velocidad -= 10;
}

void leerTecla(){
  int mov;
  tecla = teclado.getKey();
    if(tecla!=NO_KEY){
      mov=tecla-48;
      if(mov==2||mov==4||mov==5||mov==6){
        mover(mov);
      }
      tecla=NO_KEY;
    }
}

void mover(int teclap){
  if (teclap==2&&y!=0){
    y--;
  }else if(teclap==4&&x!=2){
    x--;
  }else if(teclap==6&&x!=19){
    x++;
  }else if(teclap==5&&y!=3){
    y++;
  }
}

bool coordenadas(int x1, int x2, int x3, int x4){
  return ((x == x1 && y == oleada[0]) || (x == x2 && y == oleada[1]) || (x == x3 && y == oleada[2]) || (x == x4 && y == oleada[3]));
}

void fin(int DisPos1, int DisPos2, int DisPos3, int DisPos4){
  if (coordenadas(DisPos1, DisPos2, DisPos3, DisPos4)){
    lcd.setCursor(x,y);
    lcd.write(byte(5));
    delay(500);
    lcd.clear();
    lcd.setCursor(4, 1);
    lcd.print("Puntuacion:");
    lcd.setCursor(4, 2);
    lcd.print(puntuacion);
    delay(2000);
    while(tecla==NO_KEY){
        tecla=teclado.getKey();
      }  
      tecla=NO_KEY;
      menu();
  }
}
