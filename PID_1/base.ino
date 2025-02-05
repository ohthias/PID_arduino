//Sentidos
#define MOTOR_ESQUERDO_FRENTE 5
#define MOTOR_ESQUERDO_TRAS 6
#define MOTOR_DIREITO_FRENTE 9
#define MOTOR_DIREITO_TRAS 10

// Variáveis do PID
float Kp = 2.0;  // Ganho Proporcional
float Ki = 0.0;  // Ganho Integral
float Kd = 1.0;  // Ganho Derivativo

int erro = 0;
int erro_anterior = 0;
int integral = 0;
int derivativo = 0;

/* Calibração */
int velocidade_base = 150;  // Velocidade base dos motores
int velocidade_esquerda, velocidade_direita;

int preto = 200;

void setup() {
  pinMode(MOTOR_ESQUERDO_FRENTE, OUTPUT);
  pinMode(MOTOR_ESQUERDO_TRAS, OUTPUT);
  pinMode(MOTOR_DIREITO_FRENTE, OUTPUT);
  pinMode(MOTOR_DIREITO_TRAS, OUTPUT);

  Serial.begin(9600);
}

void loop() {
    calculoPID();
    analogWrite(MOTOR_ESQUERDO_FRENTE, velocidade_esquerda);
    analogWrite(MOTOR_ESQUERDO_TRAS, 0);
    analogWrite(MOTOR_DIREITO_FRENTE, velocidade_direita);
    analogWrite(MOTOR_DIREITO_TRAS, 0);

    erro_anterior = erro;

    exibirSerialPID();
    delay(10);
}