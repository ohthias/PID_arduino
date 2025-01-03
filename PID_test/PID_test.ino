#include <PID_v1.h>

#define LDR_INPUT 0
#define LED_OUTPUT 3  

double setPoint, input, output;
double Kp = 2, Ki = 10, Kd = 1;

PID myPID(&input, &output, &setPoint, Kp, Ki, Kd, DIRECT);

void setup() {
  Serial.begin(9660);
  input = analogRead(LDR_INPUT);
  setPoint = 100;
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp,Ki,Kd);
}

void loop() {
  input = map(analogRead(LDR_INPUT), 0, 1024, 0, 255);
  myPID.Compute();
  analogWrite(LED_OUTPUT, output);
  Serial.print(input);
  Serial.print(" ");
  Serial.println(output);
}
