#define SENSOR_ESQUERDO A0
#define SENSOR_DIREITO A1

#define MOTOR_ESQUERDO_FRENTE 5
#define MOTOR_ESQUERDO_TRAS 6
#define MOTOR_DIREITO_FRENTE 9
#define MOTOR_DIREITO_TRAS 10

PID pid(2.0, 0.0, 1.0);  // Kp = 2.0, Ki = 0.0, Kd = 1.0

int velocidade_base = 150;  // Velocidade base dos motores

void setup() {
  pinMode(MOTOR_ESQUERDO_FRENTE, OUTPUT);
  pinMode(MOTOR_ESQUERDO_TRAS, OUTPUT);
  pinMode(MOTOR_DIREITO_FRENTE, OUTPUT);
  pinMode(MOTOR_DIREITO_TRAS, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int valor_esquerdo = analogRead(SENSOR_ESQUERDO);
  int valor_direito = analogRead(SENSOR_DIREITO);

  int erro = valor_esquerdo - valor_direito;

  float correcao = pid.calcular(0, erro);  // Setpoint = 0 (equilíbrio entre os sensores)

  int velocidade_esquerda = velocidade_base - correcao;
  int velocidade_direita = velocidade_base + correcao;

  velocidade_esquerda = constrain(velocidade_esquerda, 0, 255);
  velocidade_direita = constrain(velocidade_direita, 0, 255);

  analogWrite(MOTOR_ESQUERDO_FRENTE, velocidade_esquerda);
  analogWrite(MOTOR_ESQUERDO_TRAS, 0);
  analogWrite(MOTOR_DIREITO_FRENTE, velocidade_direita);
  analogWrite(MOTOR_DIREITO_TRAS, 0);

  // Debug: Imprime os valores no monitor serial
  Serial.print("Erro: ");
  Serial.print(erro);
  Serial.print(" Correcao: ");
  Serial.print(correcao);
  Serial.print(" Velocidade Esquerda: ");
  Serial.print(velocidade_esquerda);
  Serial.print(" Velocidade Direita: ");
  Serial.println(velocidade_direita);

  delay(10);
}