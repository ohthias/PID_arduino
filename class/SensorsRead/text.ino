LeituraSensores sensores;

void setup() {
  sensores.adicionarSensor(A0);  // Sensor esquerdo
  sensores.adicionarSensor(A1);  // Sensor direito

  Serial.begin(9600);
}

void loop() {
  // Lê os valores dos sensores
  sensores.lerSensores();

  int valorEsquerdo = sensores.obterValor(0);  // Primeiro sensor (índice 0)
  int valorDireito = sensores.obterValor(1);   // Segundo sensor (índice 1)

  Serial.print("Sensor Esquerdo: ");
  Serial.print(valorEsquerdo);
  Serial.print(" | Sensor Direito: ");
  Serial.println(valorDireito);

  delay(100);
}