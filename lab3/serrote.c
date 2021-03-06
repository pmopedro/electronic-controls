/*
==============================================================================
RAMPA DIGITAL DE 8 BITS
Este código faz um sinal de rampa através de 8 saídas digitais do Arduino Uno. 
==============================================================================
Por Lucas Ribeiro de Oliveira.
PED da disciplina EE641 - Lab. de eltrônica básica II
==============================================================================
*/
void setup() {
 // Função para realizar o setup do arduino (roda uma única vez)
 
 DDRD = B11111111; // Condifura todo registrador da porta D como saída. 
 // Equivale a fazer pinMode(porta, OUTPUT) para porta = 1 a 8. 
 Serial.begin(9600);
 PORTD = B00000000; // Seta todo registrador D como saúda (OUTPUT)       // Delay inicial de 3s
}

void loop() {
  // Função que roda na forma de loop infinito
  // repetição para percorrer todo vetor
  Serial.print("Iniciando");
  delay(100);
  for (int i=0; i < 255;i=i+32){
   PORTD = i; // Fornece o valor desejado no registrador PORTD,
   Serial.print(PORTD,HEX); 
   Serial.print("\n");
   //de forma sequencial, a partir do incremente de i
   delay(1000); // Delay de 1s
  }
  for (int i=255; i >= 0; i=i-32){
   PORTD = i; // Fornece o valor desejado no registrador PORTD, 
   Serial.print(PORTD,HEX);
   Serial.print("\n");
   //de forma sequencial, a partir do incremente de i
   delay(1000); // Delay de 1s
  }
}
