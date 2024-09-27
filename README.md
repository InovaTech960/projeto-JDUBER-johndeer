# projeto-JDUBER-johndeer
# Introduçao
A empresa John Deere identificou um desafio operacional em suas instalações de fabricação: a gestão e controle eficientes de seus veículos de transporte internos. Atualmente, esses veículos são operados com a falta de um sistema de rastreamento eficaz.
 A proposta é desenvolver uma solução inovadora que permita o rastreamento em tempo real desses veículos. Isso não só melhorará a eficiência operacional, mas também fornecerá insights valiosos sobre a utilização dos veículos.
Além disso, a empresa deseja um aplicativo com uma interface de usuário intuitiva, semelhante à do Uber, para facilitar a interação com o sistema de rastreamento. Este aplicativo permitirá aos usuários localizar facilmente os veículos e monitorar seu status em tempo real

O objetivo é desenvolver uma solução integrada de software e hardware capaz de monitorar em tempo real a localização dos carrinhos de transporte de peças ao longo da linha de produção da John Deere. Vamos utilizar o ESP32 para escanear redes Wi-Fi e calcular a posição estimada com base na intensidade do sinal. Em seguida, configuraremos o ESP32 para enviar os dados para um broker MQTT, como o Mosquitto, que os encaminhará para o servidor Apache, Desenvolveremos um aplicativo Android em Kotlin para exibir os dados de localização usando a API do Google Maps. O aplicativo fará requisições ao servidor para obter dados atualizados via broker MQTT.
# Desenvolvimento

Arquitetura da Solução
A proposta de solução integra diferentes componentes de hardware e software para oferecer um sistema de rastreamento IoT completo. A arquitetura da solução pode ser visualizada abaixo (substituir pelo diagrama do draw.io ):

**Componentes da Arquitetura**

ESP32: Dispositivo principal de rastreamento que escaneia redes Wi-Fi e calcula a localização dos veículos com base na intensidade do sinal (RSSI).

**Broker MQTT** (Mosquitto): Envia os dados de localização captados pelo ESP32 para o servidor central.

**Servidor Apache**: Responsável por armazenar e processar os dados de localização. Ele atua como o backend que comunica o aplicativo com os dados de rastreamento.

**Aplicativo Android (Wordpress + API Google Maps)**: Apresenta os dados de localização em tempo real por meio de um mapa, permitindo aos operadores visualizar e monitorar os veículos de forma fácil e rápida.

# Funcionamento da Solução

**Rastreamento com ESP32:**
O ESP32 escaneia as redes Wi-Fi ao redor e mede a intensidade do sinal (RSSI).
Utilizando um algoritmo de localização, a posição aproximada do veículo é calculada.
Esses dados são enviados para o corretor MQTT (Mosquitto) via Wi-Fi.

**Transmissão via Broker MQTT:**
O broker MQTT recebe os dados do ESP32 e os encaminha ao servidor Apache.

**Servidor Apache:**
O servidor processa os dados recebidos do corretor MQTT e os armazena em um banco de dados, disponibilizando essas informações para o aplicativo Android.

**Aplicativo Android:**
O aplicativo faz requisições periódicas ao servidor Apache para obter dados atualizados da localização dos veículos.
A interface do aplicativo utiliza a API do Google Maps para mostrar a localização dos veículos em tempo real, de forma semelhante ao que acontece no aplicativo Uber.

**Tecnologias Utilizadas**

**ESP32:** Microcontrolador usado para rastreamento.

**MQTT** (Mosquitto): Protocolo de comunicação leve para IoT.

**Apache:** Servidor web que atua como backend.

**Android/Wordpress:** Plataforma para o aplicativo mobile.

**API Google Maps:** Utilizada para exibir a localização dos veículos no aplicativo.

# Resultados
**Dados de Localização em Tempo Real**
A solução de entrega de dados de localização em tempo real dos veículos de transporte, exibida diretamente no aplicativo Android. Abaixo, segue um exemplo da interface do aplicativo, com um print do mapa mostrando a localização dos veículos na fábrica:

**Melhoria da Eficiência Operacional**
Com a solução de ruptura, a John Deere obteve maior controle sobre a movimentação de veículos internos, resultando em:

**Redução do tempo de inatividade** : Os operadores podem visualizar onde cada veículo está localizado e otimizar suas rotas.

**Melhor gerenciamento da frota** : O sistema oferece insights sobre os padrões de uso dos veículos, identificando possíveis gargalos ou períodos ociosos.

**Facilidade de Uso**
O aplicativo com interface semelhante ao Uber facilita a interação dos operadores com o sistema, simplificando a localização dos veículos e o monitoramento do status.
