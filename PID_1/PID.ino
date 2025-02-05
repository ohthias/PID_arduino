void calculoPID() {
    int valor_esquerdo = analogRead(SENSOR_ESQUERDO);
    int valor_direito = analogRead(SENSOR_DIREITO);

    if(valor_direito < preto && valor_esquerdo < preto) {
        Serial.println("Ambos os sensores estão vendo preto");
        delay(1000);
        return;
    }
    // Calcula o erro (diferença entre os sensores)
    erro = valor_esquerdo - valor_direito;

    // Calcula o termo integral
    integral += erro;

    // Calcula o termo derivativo
    derivativo = erro - erro_anterior;

    // Calcula a correção do PID
    int correcao = Kp * erro + Ki * integral + Kd * derivativo;

    // Ajusta as velocidades dos motores
    velocidade_esquerda = velocidade_base - correcao;
    velocidade_direita = velocidade_base + correcao;

    // Limita as velocidades dos motores
    velocidade_esquerda = constrain(velocidade_esquerda, 0, 255);
    velocidade_direita = constrain(velocidade_direita, 0, 255);
}