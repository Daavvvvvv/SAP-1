#include <LiquidCrystal.h>
int lda = 36;
int add = 37;
int sub = 38;
int mult = 39;
int divv = 40;
int out = 41;
int mod = 42;
int raiz = 43;
int call = 44;
int returnn = 45;
int gotoo = 46;
int mayor = 47;
int menor = 48;
int poww = 49;
int factorial = 50;
int HLT = 51;
int pW1 = 22;
int pW2 = 23;
int pW3 = 24;
int pW4 = 25;
int add2 = 30;
int sub2 = 31;
int mult2 = 32;
int div2 = 33;
int ep = A15;
int lm = A14;
int promEn = A13;
int li = A12;
int ei = A11;
int lb = A10;
int lo = A9;
int la = A8;
int ea = A4;
int eu = A5;
int lc = A6;
int signo = A7;
int mayormenor= 0;
int contador;
int res;
int ec = A3;
int RS = 11;
int E = 9;
int RW = 10;
int D4 = 5;
int D5 = 4;
int D6 = 3;
int D7 = 2;


int auxR;
int valorCall;
int contReturn = 0;
int contFact = 1;
int auxPind;
int auxDiv;
int resultado;

LiquidCrystal lcd(RS,RW, E, D4, D5, D6, D7);

void setup() {

  DDRD = 0B11110000;
  pinMode(36, INPUT);
  pinMode(37, INPUT);
  pinMode(38, INPUT);
  pinMode(39, INPUT);
  pinMode(40, INPUT);
  pinMode(41, INPUT);
  pinMode(42, INPUT);
  pinMode(43, INPUT);
  pinMode(44, INPUT);
  pinMode(45, INPUT);
  pinMode(46, INPUT);
  pinMode(47, INPUT);
  pinMode(48, INPUT);
  pinMode(49, INPUT);
  pinMode(50, INPUT);
  pinMode(51, INPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(add2, OUTPUT);
  pinMode(sub2, OUTPUT);
  pinMode(mult2, OUTPUT);
  pinMode(div2, OUTPUT);
  pinMode(A15, OUTPUT);
  pinMode(A14, OUTPUT);
  pinMode(A13, OUTPUT);
  pinMode(A12, OUTPUT);
  pinMode(A11, OUTPUT);
  pinMode(A10, OUTPUT);
  pinMode(A9, OUTPUT);
  pinMode(A8, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, INPUT);
  pinMode(A3, OUTPUT);

  lcd.begin(16, 2);

  //INPUT PORQUE ENTRAN AL ARDUINO, ES DECIR SON ENTRADAS CON RESPECTO AL ARDUINO
  //OUTPUT PORQUE SALEN DEL ARDUINO, "           SALIDAS                        "

}



void inicio() {
  digitalWrite(ep, 1);
  digitalWrite(lm, 1);
  delay(750);
  digitalWrite(ep, 0);
  digitalWrite(lm, 0);
  delay(750);
  //SE PRENDE Y SE APAGA EL ENABLE PC Y EL LOAD MAR

  digitalWrite(promEn, 1);
  digitalWrite(li, 1);
  delay(750);
  digitalWrite(promEn, 0);
  digitalWrite(li, 0);
  delay(750);
  //SE PRENDE Y SE APAGA EL ENABLE PROM Y LOAD INSTRUCTION

  digitalWrite(ei, 1);
  digitalWrite(lm, 1);
  delay(750);
  digitalWrite(ei, 0);
  digitalWrite(lm, 0);
  delay(750);
  //SE PRENDE Y SE APAGA EL ENABLE INSTRUCTION Y LOAD MAR

}


//SE PASAN LAS COSAS AL ACUMULADOR
void ldaa() {
  digitalWrite(promEn, 1);
  digitalWrite(la, 1);
  auxR = PIND;
  auxPind = PIND;
  delay(750);
  digitalWrite(la, 0);
  digitalWrite(promEn, 0);
  delay(750);
}


//SE PASAN EL NUMERO DE LA SEGUNDA INSTRUCCION AL B REGISTER Y SE HACE LA OPERACION SUMA
void suma() {
  digitalWrite(promEn, 1);
  digitalWrite(lb, 1);
  delay(750);
  digitalWrite(lb, 0);
  digitalWrite(promEn, 0);
  delay(750);
  digitalWrite(add2, 1);
  digitalWrite(add2, 0);
  delay(750);
  digitalWrite(eu, 1);
  digitalWrite(la, 1);
  auxR = PIND;
  auxPind = PIND;
  delay(750);
  digitalWrite(eu, 0);
  digitalWrite(la, 0);

}


//SE PASAN EL NUMERO DE LA SEGUNDA INSTRUCCION AL B REGISTER Y SE HACE LA OPERACION RESTA
void resta() {
  digitalWrite(promEn, 1);
  digitalWrite(lb, 1);
  delay(750);
  digitalWrite(lb, 0);
  digitalWrite(promEn, 0);
  delay(750);
  digitalWrite(sub2, 1);
  digitalWrite(sub2, 0);
  delay(750);
  digitalWrite(eu, 1);
  digitalWrite(la, 1);
  auxR = PIND;
  auxPind = PIND;
  delay(750);
  digitalWrite(eu, 0);
  digitalWrite(la, 0);
}

//SE PASAN EL NUMERO DE LA SEGUNDA INSTRUCCION AL B REGISTER Y SE HACE LA OPERACION MULTIPLICACION
void multiplicacion() {
  digitalWrite(promEn, 1);
  digitalWrite(lb, 1);
  delay(750);
  digitalWrite(lb, 0);
  digitalWrite(promEn, 0);
  delay(750);
  digitalWrite(mult2, 1);
  digitalWrite(mult2, 0);
  delay(750);
  digitalWrite(eu, 1);
  digitalWrite(la, 1);
  auxR = PIND;
  auxPind = PIND;
  delay(750);
  digitalWrite(eu, 0);
  digitalWrite(la, 0);
}


//SE PASAN EL NUMERO DE LA SEGUNDA INSTRUCCION AL B REGISTER Y SE HACE LA OPERACION DIVISION
void division() {
  digitalWrite(promEn, 1);
  auxDiv = PIND;
  delay(750);
  digitalWrite(promEn, 0);
  if (auxDiv > 0) {
    digitalWrite(promEn, 1);
    digitalWrite(lb, 1);
    delay(750);
    digitalWrite(lb, 0);
    digitalWrite(promEn, 0);
    delay(750);
    digitalWrite(div2, 1);
    digitalWrite(div2, 0);
    delay(750);
    digitalWrite(eu, 1);
    digitalWrite(la, 1);
    auxR = PIND;
    auxPind = PIND;
    delay(750);
    digitalWrite(eu, 0);
    digitalWrite(la, 0);
  }else{
    lcd.print("IMPOSIBLE");
    }
}


//SE PASAN EL NUMERO DE LA SEGUNDA INSTRUCCION AL B REGISTER Y SE HACE LA OPERACION POTENCIA
void potencia() {
  digitalWrite(ea, 1);
  digitalWrite(lb, 1);
  delay(750);
  digitalWrite(ea, 0);
  digitalWrite(lb, 0);
  delay(750);
  digitalWrite(mult2, 1);
  digitalWrite(mult2, 0);
  delay(750);
  digitalWrite(eu, 1);
  digitalWrite(la, 1);
  auxR = PIND;
  auxPind = PIND;
  delay(750);
  digitalWrite(eu, 0);
  digitalWrite(la, 0);
  delay(750);
}

//SE USA EL NUMEROP QUE DIO RESULTADO DE LAS OPERACIONES MATEMATICAS Y SE MUESTRA EN EL OUTPUT REGISTER
void salida() {
  digitalWrite(ea, 1);
  digitalWrite(lo, 1);
  resultado = PIND;
  delay(750);
  digitalWrite(ea, 0);
  digitalWrite(lo, 0);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LA OPERACION ES: ");
  if(digitalRead(mayormenor) == 1){
    lcd.setCursor(0,1);
    lcd.print("-");
  }
  lcd.setCursor(1,1);
  lcd.print(resultado);

}

//SE FINALIZA EL PROGRAMA.
void finall() {
  digitalWrite(ep, 1);
  digitalWrite(lm, 1);
  delay(750);
  digitalWrite(ep, 0);
  digitalWrite(lm, 0);
  delay(750);
  digitalWrite(promEn, 1);
  digitalWrite(li, 1);
  delay(750);
  digitalWrite(promEn, 0);
  digitalWrite(li, 0);
  delay(750);
  digitalWrite(ei, 1);
  digitalWrite(lm, 1);
  delay(750);
  digitalWrite(ei, 0);
  digitalWrite(lm, 0);
  delay(750);

  while (true) {};
}

//SE RESTAN LOS DOS NUMEROS Y DEPENDIENDO SI ES POSITIVO O NEGATIVO SE DEFINE SI ES MAYOR O MENOR, ESTO A TRAVES DEL CARRY
void mayorr() {
  digitalWrite(promEn, 1);
  digitalWrite(lb, 1);
  delay(750);
  digitalWrite(lb, 0);
  digitalWrite(promEn, 0);
  delay(750);
  digitalWrite(sub2, 1);
  digitalWrite(sub2, 0);
  delay(750);
  if (digitalRead (signo) == 0) {
    PORTA = 1;
    digitalWrite(ep, 1);
    digitalWrite(lo, 1);
    delay(750);
    digitalWrite(lo, 0);
    digitalWrite(ep, 0);
    delay(750);
    lcd.print("Es mayor");
  } else if (digitalRead(signo) == 1) {
    PORTA = 0;
    digitalWrite(ep, 1);
    digitalWrite(lo, 1);
    delay(750);
    digitalWrite(lo, 0);
    digitalWrite(ep, 0);
    delay(750);
    lcd.print("Es menor");
  }
}

//SE RESTAN LOS DOS NUMEROS Y DEPENDIENDO SI ES POSITIVO O NEGATIVO SE DEFINE SI ES MAYOR O MENOR, ESTO A TRAVES DEL CARRY
void menorr() {
  digitalWrite(promEn, 1);
  digitalWrite(lb, 1);
  delay(750);
  digitalWrite(lb, 0);
  digitalWrite(promEn, 0);
  delay(750);
  digitalWrite(sub2, 1);
  digitalWrite(sub2, 0);
  delay(750);
  if (digitalRead (signo) == 1) {
    PORTA = 0;
    digitalWrite(ep, 1);
    digitalWrite(lo, 1);
    delay(750);
    digitalWrite(lo, 0);
    digitalWrite(ep, 0);
    delay(750);
    lcd.print("Es menor");
  } else if (digitalRead(signo) == 0) {
    PORTA = 1;
    digitalWrite(ep, 1);
    digitalWrite(lo, 1);
    delay(750);
    digitalWrite(lo, 0);
    digitalWrite(ep, 0);
    delay(750);
    lcd.print("Es mayor");
  }
}


void modd() {
  digitalWrite(promEn,1);
  auxDiv = PIND;
  delay(750);
  digitalWrite(promEn,0);
  if(auxDiv > 0){
  digitalWrite(promEn, 1);
  digitalWrite(lb, 1);
  delay(750);
  digitalWrite(lb, 0);
  digitalWrite(promEn, 0);
  delay(750);
  digitalWrite(div2, 1);
  digitalWrite(div2, 0);
  delay(750);
  //SE DIVIDEN LOS DOS NUMEROS EN CUESTION
  digitalWrite(ea, 1);
  digitalWrite(lc, 1);
  delay(750);
  digitalWrite(ea, 0);
  digitalWrite(lc, 0);
  delay(750);
  digitalWrite(eu, 1);
  digitalWrite(la, 1);
  delay(750);
  digitalWrite(eu, 0);
  digitalWrite(la, 0);
  delay(750);
  //EL NUMERO ALMACENADO EN EL ACUMULADOR SE PASA AL C REGISTER, Y EL RESULTADO DEL ALU SE PASA AL ACUMULADOR
  digitalWrite(mult2, 1);
  digitalWrite(mult2, 0);
  delay(750);
  digitalWrite(eu, 1);
  digitalWrite(lb, 1);
  delay(750);
  digitalWrite(eu, 0);
  digitalWrite(lb, 0);
  delay(750);
  //SE MULTIPLICA EL NUMERO ALMACENADO EN EL ACUMULADOR Y C REGISTER Y SE ALMACENA ESE RESULTADO EN EL B REGISTER
  digitalWrite(ec, 1);
  digitalWrite(la, 1);
  delay(750);
  digitalWrite(ec, 0);
  digitalWrite(la, 0);
  delay(750);
  digitalWrite(sub2, 1);
  digitalWrite(sub2, 0);
  delay(750);
  digitalWrite(eu, 1);
  digitalWrite(la, 1);
  delay(750);
  digitalWrite(eu, 0);
  digitalWrite(la, 0);
  delay(750);
  //POR ULTIMO SE PASA LO QUE TENIAMOS EN EL CREGISTER AL ACUMULADOR Y SE RESTA CON EL RESULTADO ANTERIOR ALMACENADO EN EL BREGISTER
  }else{
    lcd.print("IMPOSIBLE");
  }
}
void raizz() {
int contadorR = 1;
int auxR2 = 0;
  while (auxR > 1) {
    PORTA = contadorR;
    digitalWrite(ep, 1);
    digitalWrite(lb, 1);
    delay(750);
    digitalWrite(ep, 0);
    digitalWrite(lb, 0);
    delay(750);
    digitalWrite(sub2, 1);
    digitalWrite(sub2, 0);
    delay(750);
    digitalWrite(eu, 1);
    digitalWrite(la, 1);
    auxR = PIND;
    delay(750);
    digitalWrite(eu, 0);
    digitalWrite(la, 0);
    delay(750);
    contadorR +=2;
    auxR2 ++;

    if(digitalRead(signo)==1){
      auxR = 0;
      auxR2 --;
      digitalWrite(add2,1);
      digitalWrite(add2,0);
    }
  }
  PORTA = auxR2;
  digitalWrite(ep, 1);
  digitalWrite(la, 1);
  auxPind= PIND;
  delay(750);
  digitalWrite(ep, 0);
  digitalWrite(la, 0);
}

void factoriall() {
  while (contFact < auxPind ) {
    PORTA = contFact;
    digitalWrite(ep, 1);
    digitalWrite(lb, 1);
    delay(750);
    digitalWrite(lb, 0);
    digitalWrite(ep, 0);
    delay(750);
    digitalWrite(mult2, 1);
    digitalWrite(mult2, 0);
    delay(750);
    digitalWrite(eu, 1);
    digitalWrite(la, 1);
    auxR= PIND;
    delay(750);
    digitalWrite(eu, 0);
    digitalWrite(la, 0);
    delay(750);
    contFact = contFact + 1;
  }
}


void retornar() {
  while (contReturn < 1) {
    contador = valorCall++;
    contReturn++;
  }
}

void llamar() {
  contador = PORTA;
}

void irA() {
  digitalWrite(ei, 1);
  contador = PIND;
  delay(1000);
  digitalWrite(ei, 0);
}





void loop() {

  PORTA = contador;

  inicio();
  if (digitalRead(lda) == 1) {
    ldaa();
  }
  else if (digitalRead(add) == 1 ) {
    suma();
  }
  else if (digitalRead(sub) == 1 ) {
    resta();
  }
  else if (digitalRead(mult) == 1) {
    multiplicacion();
  }
  else if (digitalRead(divv) == 1) {
    division();

  }
  else if (digitalRead(mod) == 1) {
    modd();
  }
  else if (digitalRead(mayor) == 1) {
    mayorr();
  }
  else if (digitalRead(menor) == 1) {
    menorr();
  }
  else if (digitalRead(poww) == 1) {
    potencia();
  }
  else if (digitalRead(raiz) == 1) {
    raizz();
  }
  else if (digitalRead(out) == 1) {
    salida();
  }
  else if (digitalRead(HLT) == 1) {
    finall();
  }
  else if (digitalRead(returnn) == 1) {
    retornar();
  }
  else if (digitalRead(call) == 1) {
    llamar();
  }
  else if (digitalRead(gotoo) == 1) {
    irA();
  }
  else if (digitalRead(factorial) == 1) {
    factoriall();
  }


  contador++;
}
