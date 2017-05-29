//OBS.: Galera comentem aqui em cima quais as mudancas que implementaram ou erros corrigidos e a ultima versao, como nem todo mundo sabe utilizar git ou possui conta no Github, por enquanto esse pode ser o metodo para "controle de versao"
//Ultima versao v1.2 - 29/05
//Mudancas: Funcoes de controle implementadas e um mini teste para ver se estao funcionando corretamente, e troca dos nomes de variaveis "couve" e "repolho" para melhor andamento do codigo.

//Input motor direito : 2 e 4
//PWM Enable direito: 5
//Input motor esquerdo : 8 e 12
//PWM Enable direito: 9
//Couve = motor esquerdo.
//Repolho = motor direito.

//Inclusao de Bibliotecas
#include <Ultrasonic.h> // inclusao da biblioteca Ultrasonic
#define echoPin 6 // Pino que recebe o pulso do echo
#define trigPin 3 // Pino que envia o pulso para o echo
#define FRENTE HIGH
#define TRAS LOW

//Instancia o nosso sensor
Ultrasonic ultrasonic(3, 6);

//Inicializando Variaveis Globais
int m1_esquerdo = 8;
int m2_esquerdo = 12;
int m1_direito = 2;
int m2_direito = 4;
int esquerdo3 = 9;
int direito3 = 5;

////////////////Funcoes de comando
//m1 = m1_esquerdo
//m2 = m2_esquerdo
//m3 = m1_direito
//m4 = m2_direito

void parar(int m1, int m2, int m3, int m4) { //Precisa avaliar se este seria o melhor metodo para "desligar" totalmente os motores.
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
void controla_motor(int m1, int m2, bool sentido) { //Precisa buscar uma maneira de poder utiliza-la para as funcoes de girar em ambos os sentido **** <-------------- OBS
  digitalWrite(m1, sentido);
  digitalWrite(m2, !sentido);
}
void frente(int m1, int m2, int m3, int m4) {
  controla_motor(m1, m2, !FRENTE);  // Deve-se utilizar o oposto de FRENTE, no caso TRAS, para que os comandos digitalWrite fiquem corretos, sendo assim LOW e HIGH opostos.
  controla_motor(m3, m4, FRENTE);
}
void tras(int m1, int m2, int m3, int m4) {
  controla_motor(m1, m2, !TRAS); // Deve-se utilizar o oposto de TRAS, no caso FRENTE, para que os comandos digitalWrite fiquem corretos, sendo assim LOW e HIGH opostos.
  controla_motor(m3, m4, TRAS);
}
void gira_sentido_horario(int m1, int m2, int m3, int m4) {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}
void gira_sentido_anti_horario(int m1, int m2, int m3, int m4) {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
////////////////Fim das Funcoes de comando

void setup() {
  //setup Ultrasonic
  //Serial.begin(9600); //Inicializa a comunicação serial: com bsud rate de 9600
  //pinMode(trigPin, OUTPUT); //define o pino triger como saida
  //pinMode(echoPin, INPUT); //define o pino echo como entrada
  //fim do setup Ultrasonic

  pinMode(m1_esquerdo, OUTPUT);
  pinMode(m2_esquerdo, OUTPUT);
  pinMode(esquerdo3, OUTPUT);
  pinMode(m1_direito, OUTPUT);
  pinMode(m2_direito, OUTPUT);
  pinMode(direito3, OUTPUT);
  //digitalWrite(esquerdo3, HIGH);
  //digitalWrite(direito3, HIGH);
  analogWrite(esquerdo3, 255);
  analogWrite(direito3, 255);

}

void loop() {
  //Teste de funcionamento das funcoes em conjunto com o ultrassonico:
  int executa = 1;
  if (executa) {
    //Funciona durante 10s
    int duracao = 1000;
    while ( duracao < 20000) {
      //Inicia os motores andando para frente enquanto distancia < 5CM
      while (ultrasonic.Ranging(CM) < 5) {
        frente(m1_esquerdo, m2_esquerdo, m1_direito, m2_direito);
      }
      if (ultrasonic.Ranging(CM) >= 5) {
        //Gira para direita
        //Desliga o motor direito
        gira_sentido_horario(m1_esquerdo, m2_esquerdo, m1_direito, m2_esquerdo);
        delay(2000);
      }
      duracao += 1000;
    }

    //Para de executar
    parar(m1_esquerdo, m2_esquerdo, m1_direito, m2_direito);

    while (executa) {

    }
  }
}
