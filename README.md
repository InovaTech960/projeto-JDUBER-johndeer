# Projeto-JDUBER-johndeer
# Introdução
A empresa John Deere identificou um desafio operacional em suas instalações de fabricação: a gestão e controle eficientes de seus veículos de transporte internos. Atualmente, esses veículos são operados com a falta de um sistema de rastreamento eficaz.
 A proposta é desenvolver uma solução inovadora que permita o rastreamento em tempo real desses veículos. Isso não só melhorará a eficiência operacional, mas também fornecerá insights valiosos sobre a utilização dos veículos.
Além disso, a empresa deseja um aplicativo com uma interface de usuário intuitiva, semelhante à do Uber, para facilitar a interação com o sistema de rastreamento. Este aplicativo permitirá aos usuários localizar facilmente os veículos e monitorar seu status em tempo real

O objetivo é desenvolver uma solução integrada de software e hardware capaz de monitorar em tempo real a localização dos carrinhos de transporte de peças ao longo da linha de produção da John Deere. Vamos utilizar o ESP32 para escanear redes Wi-Fi e calcular a posição estimada com base na intensidade do sinal. Em seguida, configuraremos o ESP32 para enviar os dados para um broker MQTT, como o Mosquitto, que os encaminhará para o servidor Apache, Desenvolveremos um site em worldpress para exibir os dados de localização usando a API do Google Maps. O site fará requisições ao servidor para obter dados atualizados via broker MQTT.
# Desenvolvimento

**Arquitetura da Solução**

A proposta de solução integra diferentes componentes de hardware e software para oferecer um sistema de rastreamento IoT completo. 

**Componentes da Arquitetura**

ESP32: Dispositivo principal de rastreamento que escaneia redes Wi-Fi e calcula a localização dos veículos com base na intensidade do sinal (RSSI).

**Broker MQTT** (Mosquitto): Envia os dados de localização captados pelo ESP32 para o servidor central.

**Servidor Apache**: Responsável por armazenar e processar os dados de localização. Ele atua como o backend que comunica o aplicativo com os dados de rastreamento.

**site (Wordpress + API Google Maps)**: Apresenta os dados de localização em tempo real por meio de um mapa, permitindo aos operadores visualizar e monitorar os veículos de forma fácil e rápida.

**Antena modulo Wireless para arduino**: a antena serve para aumenter o sinal do esp32, consequentemente ajudando na triangulação

# Funcionamento da Solução

**Rastreamento com ESP32:**
O ESP32 escaneia as redes Wi-Fi ao redor e mede a intensidade do sinal (RSSI).
Utilizando um algoritmo de localização, a posição aproximada do veículo é calculada.
Esses dados são enviados para o corretor MQTT (Mosquitto) via Wi-Fi.

**Transmissão via Broker MQTT:**
O broker MQTT recebe os dados do ESP32 e os encaminha ao servidor Apache.

**Servidor Apache:**
O servidor processa os dados recebidos do corretor MQTT e os armazena em um banco de dados, disponibilizando essas informações para o aplicativo Android.

**Site worldpress:**
O aplicativo faz requisições periódicas ao servidor Apache para obter dados atualizados da localização dos veículos.
A interface do aplicativo utiliza a API do Google Maps para mostrar a localização dos veículos em tempo real, de forma semelhante ao que acontece no aplicativo Uber.

**Tecnologias Utilizadas**

**ESP32:** Microcontrolador usado para rastreamento.

**MQTT** (Mosquitto): Protocolo de comunicação leve para IoT.

**Apache:** Servidor web que atua como backend.

**API Google Maps:** Utilizada para exibir a localização dos veículos no site.

# Resultados
**Dados de Localização em Tempo Real**
A solução de entrega de dados de localização em tempo real dos veículos de transporte, exibida diretamente no site em worldpress. Abaixo, segue um exemplo da interface do site, com um print do mapa mostrando a localização dos veículos na fábrica:
![14fbbbe0-4c14-42b0-8ab9-3249acc7e401](https://github.com/user-attachments/assets/f201432a-79e0-4aa6-bc48-6214c06fa06b)

**Melhoria da Eficiência Operacional**
Com a solução de ruptura, a John Deere obterá maior controle sobre a movimentação de veículos internos, resultando em:

**Redução do tempo de inatividade** : Os operadores podem visualizar onde cada veículo está localizado e otimizar suas rotas.

**Melhor gerenciamento da frota** : O sistema oferece insights sobre os padrões de uso dos veículos, identificando possíveis gargalos ou períodos ociosos.

# Imagens e videos do projeto
**Tela inicial**

![14fbbbe0-4c14-42b0-8ab9-3249acc7e401](https://github.com/user-attachments/assets/68e4c44b-91ba-4abd-999d-05c4ccfb18c8)

**Tela do sistema de localização**

![caacaa88-45e3-46f6-a47e-0093eb697a98](https://github.com/user-attachments/assets/7a50f402-d4ac-4195-a25b-4745adeb8757)

**Tela de solicitaçao**

![4035d5b3-38cd-4076-82c0-56d8dc061fe1](https://github.com/user-attachments/assets/3be516be-faf9-4e2b-8175-995ed2c8348f)

**Teste do Prototipo do Hardware**

https://github.com/user-attachments/assets/62a59ec3-b3a7-46cc-85d6-49feeda2111e

**Funcionamento do site**

https://github.com/user-attachments/assets/d59208aa-670c-4aa2-b0fd-556f3bd669a5

