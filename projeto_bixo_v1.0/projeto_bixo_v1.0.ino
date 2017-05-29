//Ultima versao v1.0 - 26/05
//OBS.: Versao com tentativa falha de implementar o sensor ultrassonico no fim da sexta feira, como tivemos que sair do lab, nao conseguimos identificar o erro.


//Input motor direito : 2 e 4
//PWM Enable direito: 5
//Input motor esquerdo : 8 e 12
//PWM Enable direito: 9
// Couve = motor esquerdo.
// Repolho = motor direito.

//Inclusao de Bibliotecas
#include <Ultrasonic.h> // inclusao da biblioteca Ultrasonic

#define echoPin 6 // Pino que recebe o pulso do echo
#define trigPin 3 // Pino que envia o pulso para o echo

//Instancia o nosso sensor
Ultrasonic ultrasonic(3,6);

#define FRENTE HIGH
#define TRAS LOW

int couve = 8;
int couve2 = 12;
int repolho = 2;
int repolho2 = 4;
int couve3 = 9;
int repolho3 = 5;

void setup() {
  //setup Ultrasonic
  Serial.begin(9600); //Inicializa a comunicação serial: com bsud rate de 9600
  pinMode(trigPin, OUTPUT); //define o pino triger como saida
  pinMode(echoPin, INPUT); //define o pino echo como entrada
  //fim do setup Ultrasonic

  pinMode(couve, OUTPUT);
  pinMode(couve2, OUTPUT);
  pinMode(couve3, OUTPUT);
  pinMode(repolho, OUTPUT);
  pinMode(repolho2, OUTPUT);
  pinMode(repolho3, OUTPUT);
  //digitalWrite(couve3, HIGH);
  //digitalWrite(repolho3, HIGH);
  analogWrite(couve3, 255);
  analogWrite(repolho3, 255);

}

//Criar funções para Frente e Tras // Direita e Esquerda
void controla_motor(int m1, int m2, bool sentido) {
  digitalWrite(m1, sentido);
  digitalWrite(m2, !sentido);
}
void frente(int m1, int m2, int m3, int m4) {
  controla_motor(m1, m2, FRENTE); //
  controla_motor(m3, m4, FRENTE); //
}

void loop() {
  //analogWrite(couve3, 150);
  //analogWrite(repolho3, 220);
  //int executa = 1;
  //if (executa) {
    String input = "";
    while(Serial.available()>0){
      input += (char) Serial.read();
      delay(5);
    }
    if(input == "on"){
      Serial.print(ultrasonic.Ranging(CM));
      Serial.println( "cm" );
      delay(100);
    }/*
    int duracao = 1;
    while (duracao != 20) {
      while (ultrasonic.Ranging(CM) != '5') {
        digitalWrite(couve, LOW);
        digitalWrite(couve2, HIGH);
        digitalWrite(repolho, HIGH);
        digitalWrite(repolho2, LOW);
      }
      if (ultrasonic.Ranging(CM) == '5') {
        //Vira a esquerda
        digitalWrite(couve, LOW);
        digitalWrite(couve2, LOW);
        digitalWrite(repolho, HIGH);
        digitalWrite(repolho2, LOW);
        delay(750);
      }
      duracao++;
    }*/
    /*
      //Inicia os motores andando 10s para frente
      digitalWrite(couve, LOW);
      digitalWrite(couve2, HIGH);
      digitalWrite(repolho, HIGH);
      digitalWrite(repolho2, LOW);
      delay(3000);

      //Gira para direita
      //Desliga o motor direito
      digitalWrite(couve2, HIGH);
      digitalWrite(couve, LOW);
      digitalWrite(repolho, LOW);
      digitalWrite(repolho2, LOW);
      delay(1000);

      //Anda 10s para frente
      digitalWrite(couve, LOW);
      digitalWrite(couve2, HIGH);
      digitalWrite(repolho, HIGH);
      digitalWrite(repolho2, LOW);
      delay(1000);

      //Gira para esquerda
      digitalWrite(couve, LOW);
      digitalWrite(couve2, LOW);
      digitalWrite(repolho, HIGH);
      digitalWrite(repolho2, LOW);
      delay(1000);

      //Para de executar
      digitalWrite(couve, LOW);
      digitalWrite(couve2, LOW);
      digitalWrite(repolho, LOW);
      digitalWrite(repolho2, LOW);
    */
    /*
    while (executa) {

    }*/
  //}
}
