class SensorsRead
{
private:
    int *pinosSensores;     // Array dinâmico para armazenar os pinos dos sensores
    int quantidadeSensores; // Quantidade de sensores conectados
    int *valoresSensores;   // Array dinâmico para armazenar os valores lidos

public:
    SensorsRead()
    {
        quantidadeSensores = 0;
        pinosSensores = nullptr;
        valoresSensores = nullptr;
    }

    /**
     * @brief Destrutor da classe SensorsRead.
     *
     * Este destrutor libera a memória alocada dinamicamente para os arrays
     * pinosSensores e valoresSensores.
     */
    ~SensorsRead()
    {
        delete[] pinosSensores;
        delete[] valoresSensores;
    }

    /**
     * @brief Adiciona um novo sensor ao sistema.
     *
     * Esta função adiciona um novo sensor ao sistema, alocando memória para armazenar
     * o pino e o valor do sensor, copiando os valores antigos para os novos arrays,
     * e configurando o novo pino como entrada.
     *
     * @param pino O número do pino ao qual o novo sensor está conectado.
     */
    void adicionarSensor(int pino)
    {
        // Cria novos arrays com tamanho incrementado
        int *novosPinos = new int[quantidadeSensores + 1];
        int *novosValores = new int[quantidadeSensores + 1];

        // Copia os valores antigos para os novos arrays
        for (int i = 0; i < quantidadeSensores; i++)
        {
            novosPinos[i] = pinosSensores[i];
            novosValores[i] = valoresSensores[i];
        }

        // Adiciona o novo pino e inicializa seu valor
        novosPinos[quantidadeSensores] = pino;
        novosValores[quantidadeSensores] = 0;

        // Libera a memória dos arrays antigos
        delete[] pinosSensores;
        delete[] valoresSensores;

        // Atualiza os ponteiros para os novos arrays
        pinosSensores = novosPinos;
        valoresSensores = novosValores;

        // Incrementa a quantidade de sensores
        quantidadeSensores++;

        // Configura o pino como entrada
        pinMode(pino, INPUT);
    }

    /**
     * @brief Lê os valores dos sensores analógicos.
     *
     * Esta função percorre todos os sensores definidos pela variável `quantidadeSensores`,
     * lê os valores analógicos de cada sensor usando a função `analogRead` e armazena
     * esses valores no array `valoresSensores`.
     */
    void lerSensores()
    {
        for (int i = 0; i < quantidadeSensores; i++)
        {
            valoresSensores[i] = analogRead(pinosSensores[i]);
        }
    }

    /**
     * @brief Obtém o valor de um sensor específico.
     *
     * Esta função retorna o valor do sensor correspondente ao índice fornecido.
     * Se o índice for inválido (menor que 0 ou maior ou igual à quantidade de sensores),
     * a função retornará -1.
     *
     * @param indice O índice do sensor cujo valor deve ser obtido.
     * @return O valor do sensor no índice especificado, ou -1 se o índice for inválido.
     */
    int obterValor(int indice)
    {
        if (indice >= 0 && indice < quantidadeSensores)
        {
            return valoresSensores[indice];
        }
        return -1; // Retorna -1 se o índice for inválido
    }

    int obterQuantidadeSensores()
    {
        return quantidadeSensores;
    }
};