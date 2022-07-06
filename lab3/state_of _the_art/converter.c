
int comparador ;
int registrador = 128;
int iteracao = 1;
short int vec[500];
int index=0;
void setup(){
     // Função para realizar o setup do arduino (roda uma única vez)
     pinMode(13, OUTPUT);
     pinMode(12, INPUT);
     DDRD = B11111111; // Condifura todo registrador da porta D como saída. 
     // Equivale a fazer pinMode(porta, OUTPUT) para porta = 1 a 8. 
     Serial.begin(9600);
     PORTD = B00000000; // Seta todo registrador D como saúda (OUTPUT)    
}

void loop() {
  // Função que roda na forma de loop infinito
  float volts;
  iteracao = 1;
  PORTD=0;
  digitalWrite(13, HIGH);
  delay(0.01);
  digitalWrite(13, LOW);

  for(int Bit=0; Bit<=7; Bit++){
      PORTD = PORTD+128/iteracao;
      delayMicroseconds(30);
      comparador=digitalRead(12);
      if (comparador==LOW){
        // sinal do DAC maior
        PORTD = PORTD - 128/iteracao; // retorna PORTD a configuracao anterior
      }
      iteracao*=2;
  }
  
  vec[index]=PORTD;
  index++;
  if(index==500){
    for(int i; i<500;i++){
      Serial.print("(Hex) ");
      Serial.print(vec[i],HEX);
      Serial.print(" = (Dec)");
      Serial.print(vec[i]);
      Serial.print(" = (Volt)");
      volts = float(vec[i])*5/255;
      Serial.println(volts,2);
    }
    delay(1);
    while(1){
      for(int i=0; i<500; i++){
        PORTD = vec[i];
        delayMicroseconds(450);
      }
    }
  }
 // 450us 
}
