class PID_FLR
{
private:
    float Kp, Ki, Kd;
    float erro_anterior, integral;

public:
    PID_FLR(float kp, float ki, float kd)
    {
        Kp = Kp;
        Ki = Ki;
        Kd = Kd;
        erro_anterior = 0;
        integral = 0;
    }

    /**
     * @brief Calcula a saída do controlador PID com base no setpoint e no valor médio atual.
     *
     * Esta função implementa um controlador PID (Proporcional, Integral, Derivativo) que ajusta a saída
     * com base no erro entre o setpoint desejado e o valor médio atual. O termo proporcional é calculado
     * diretamente pelo erro, o termo integral é acumulado ao longo do tempo, e o termo derivativo é baseado
     * na variação do erro.
     *
     * @param setpoint O valor desejado que se quer alcançar.
     * @param valor_medio O valor atual medido.
     * @return A saída do controlador PID que deve ser usada para ajustar o sistema.
     */
    float calcular(float setpoint, float valor_medio)
    {
        // Calcula o erro
        float erro = setpoint - valor_medio;

        // Calcula o termo integral
        integral += erro;

        // Calcula o termo derivativo
        float derivativo = erro - erro_anterior;

        // Calcula a saída do PID
        float saida = Kp * erro + Ki * integral + Kd * derivativo;

        // Atualiza o erro anterior
        erro_anterior = erro;

        return saida;
    }

    /**
     * @brief Reseta os valores de integral e erro anterior para zero.
     * 
     * Esta função é usada para resetar o estado interno do controlador PID,
     * especificamente definindo o termo integral e o termo de erro anterior para zero.
     * Isso pode ser útil ao reinicializar o controlador PID ou ao iniciar
     * um novo processo de controle.
     */
    void resetar()
    {
        integral = 0;
        erro_anterior = 0;
    }
};