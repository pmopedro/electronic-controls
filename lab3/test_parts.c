
int comparador ;
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
  comparador=digitalRead(12);
  digitalWrite(13, HIGH);
  PORTD = 128;
  delay(5);
  PORTD=64;
  delay(5);
  PORTD=32;
  delay(5);
  PORTD=16;
  delay(5);
  PORTD=8;
  delay(5);
  PORTD=4;
  digitalWrite(13, LOW);
  delay(1);
//  Serial.print(PORTD);
//  Serial.print(comparador);
  
//  digitalWrite(13, HIGH); // ativa o pino digital 13
//  delay(0.01);            // espera por 10us
//  digitalWrite(13, LOW);  // desativa o pino digital 13
//  delay(5);               // espera por 5ms
}
