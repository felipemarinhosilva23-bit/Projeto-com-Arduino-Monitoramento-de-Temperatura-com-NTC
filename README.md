Monitoramento de Temperatura com Arduino e NTC 10k
📌 Descrição

Este projeto consiste no desenvolvimento de um sistema de monitoramento de temperatura utilizando um Arduino e um termistor NTC 10k (BETA 3950).

A temperatura ambiente é medida por meio de um divisor de tensão, convertida via ADC (Conversor Analógico-Digital) do Arduino e calculada matematicamente utilizando a Equação Beta do termistor.

Com base na temperatura medida:

🔵 LED Verde pisca quando a temperatura está ≤ 21 °C

🔴 LED Vermelho pisca quando a temperatura está > 21 °C

O projeto foi desenvolvido com foco em:

Aplicação prática de eletrônica básica

Modelagem matemática aplicada a sensores

Boas práticas de programação em C++

Controle de tempo sem bloqueio utilizando millis()

🎯 Objetivos

Implementar leitura analógica de sensor resistivo

Converter resistência em temperatura real (°C)

Aplicar controle de temporização sem uso de delay() para lógica principal

Organizar código de forma clara e escalável

🧰 Componentes Utilizados

Arduino (Uno/Nano)

Termistor NTC 10k (BETA 3950)

Resistor 10k (divisor de tensão)

2 LEDs (Verde e Vermelho)

2 Resistores 560Ω

Protoboard e jumpers

🔧 Funcionamento do Sistema

O NTC forma um divisor de tensão com um resistor fixo de 10kΩ.

O Arduino realiza a leitura analógica da tensão no ponto intermediário.

A resistência do termistor é calculada.

A temperatura é obtida utilizando a Equação Beta:

<img width="218" height="73" alt="image" src="https://github.com/user-attachments/assets/49941546-f9d9-43e7-b9b0-91da2a58a938" />


Com base na temperatura calculada, o sistema controla o LED correspondente.

O piscar é realizado utilizando controle baseado em millis() (sistema não bloqueante para o LED).

💻 Estrutura do Código

O código está organizado em:

🔹 Definição de pinos e constantes

🔹 Configuração inicial (setup)

🔹 Loop principal (loop)

Leitura do sensor

Processamento matemático

Controle de tempo

Acionamento dos LEDs

📊 Conceitos Aplicados

Leitura ADC (10 bits – 0 a 1023)

Divisor de tensão

Termistores NTC

Equação Beta

Controle de tempo com millis()

Lógica condicional aplicada ao hardware

🚀 Possíveis Melhorias Futuras

Implementação de histerese para evitar oscilações próximas ao limiar

Aplicação de média móvel para suavização da leitura

Exibição da temperatura em display LCD 16x2

Envio de dados para monitoramento gráfico via Serial Plotter

Integração com ESP32 para envio via WiFi

📎 Motivação

Este projeto foi desenvolvido como parte do meu aprofundamento prático em eletrônica e programação aplicada ao hardware, buscando consolidar conceitos técnicos através da experimentação e implementação real.
