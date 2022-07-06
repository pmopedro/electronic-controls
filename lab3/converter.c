
bool comparador = false;
bool old_state = false;
int registrador = 128;
int iteracao = 1;

void setup(){
     // Função para realizar o setup do arduino (roda uma única vez)
     pinMode(13, OUTPUT);
     pinMode(12, INPUT);
     DDRD = B11111111; // Condifura todo registrador da porta D como saída. 
     // Equivale a fazer pinMode(porta, OUTPUT) para porta = 1 a 8. 
     Serial.begin(9600);
     Serial.setTimeout(0.00001);
     PORTD = B00000000; // Seta todo registrador D como saúda (OUTPUT)    
}

void loop() {
  // Função que roda na forma de loop infinito
  iteracao = 1;
  digitalWrite(13, HIGH);
//  delay(0.01);            // espera por 10us
//  digitalWrite(13, LOW);  // desativa o pino digital 13
  comparador=digitalRead(12);
  for(int Bit=0; Bit<=7; Bit++){
      PORTD = PORTD+128/iteracao;
      if (comparador){ 
        // sinal da entrada analógica maior 
        // mantem PORTD
      } else{
        // sinal do DAC maior
        PORTD = PORTD - 128/iteracao; // retorna PORTD a configuracao anterior
      }
      iteracao*=2;
      comparador=digitalRead(12);
  }
  
  digitalWrite(13, LOW);
  delay(5);
//  Serial.print(PORTD);
  // Serial.print(comparador);
  
//   digitalWrite(13, HIGH); // ativa o pino digital 13
//   delay(0.01);            // espera por 10us
//   digitalWrite(13, LOW);  // desativa o pino digital 13
//   delay(5);               // espera por 5ms
}
