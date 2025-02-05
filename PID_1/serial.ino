void exibirSerialPID() {
    Serial.print("Erro: ");
    Serial.print(erro);
    Serial.print(" Correcao: ");
    Serial.print(correcao);
    Serial.print(" Velocidade Esquerda: ");
    Serial.print(velocidade_esquerda);
    Serial.print(" Velocidade Direita: ");
    Serial.println(velocidade_direita);
}