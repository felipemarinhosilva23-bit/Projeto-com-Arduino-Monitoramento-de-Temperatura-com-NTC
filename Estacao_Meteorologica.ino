// Definições dos Pinos
const int pinoNTC = A0;
const int ledVerde = 2; // Resistor 560 aqui
const int ledVermelho = 3; // Resistor 560 aqui

// Constantes do NTC
const float resTermistor = 10000.0; 
const float resFixa = 10000.0;
const float BETA = 3950.0; // Valor comum para NTCs de 10k

// Variáveis para o controle do piscar (sem travar o código)
unsigned long anteriorMillis = 0;
const long intervalo = 500; // Velocidade do piscar (500ms)
bool estadoLed = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  // --- LÓGICA DE LEITURA DA TEMPERATURA ---
  int leitura = analogRead(pinoNTC);
  float vOut = leitura * (5.0 / 1023.0);
  float resistencia = (resFixa * vOut) / (5.0 - vOut);

  float temperatura;
  temperatura = resistencia / resTermistor;
  temperatura = log(temperatura);
  temperatura /= BETA;
  temperatura += 1.0 / (25.0 + 273.15);
  temperatura = 1.0 / temperatura;
  temperatura -= 273.15;

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  // --- LÓGICA DO PISCAR DOS LEDS ---
  unsigned long atualMillis = millis();
  
  if (atualMillis - anteriorMillis >= intervalo) {
    anteriorMillis = atualMillis;
    estadoLed = !estadoLed; // Inverte o estado (liga/desliga)
  }

  if (temperatura <= 21.0) {
    digitalWrite(ledVerde, estadoLed);   // Verde piscando
    digitalWrite(ledVermelho, LOW);      // Vermelho desligado
  } 
  else {
    digitalWrite(ledVerde, LOW);         // Verde desligado
    digitalWrite(ledVermelho, estadoLed); // Vermelho piscando
  }

  delay(1000); // Pequeno ajuste de estabilidade na leitura
}
