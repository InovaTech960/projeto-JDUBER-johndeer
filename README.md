# projeto-JDUBER-johndeer
# Introduçao
A empresa John Deere identificou um desafio operacional em suas instalações de fabricação: a gestão e controle eficientes de seus veículos de transporte internos. Atualmente, esses veículos são operados com a falta de um sistema de rastreamento eficaz.
 A proposta é desenvolver uma solução inovadora que permita o rastreamento em tempo real desses veículos. Isso não só melhorará a eficiência operacional, mas também fornecerá insights valiosos sobre a utilização dos veículos.
Além disso, a empresa deseja um aplicativo com uma interface de usuário intuitiva, semelhante à do Uber, para facilitar a interação com o sistema de rastreamento. Este aplicativo permitirá aos usuários localizar facilmente os veículos e monitorar seu status em tempo real

O objetivo é desenvolver uma solução integrada de software e hardware capaz de monitorar em tempo real a localização dos carrinhos de transporte de peças ao longo da linha de produção da John Deere. Vamos utilizar o ESP32 para escanear redes Wi-Fi e calcular a posição estimada com base na intensidade do sinal. Em seguida, configuraremos o ESP32 para enviar os dados para um broker MQTT, como o Mosquitto, que os encaminhará para o servidor Apache, Desenvolveremos um aplicativo Android em Kotlin para exibir os dados de localização usando a API do Google Maps. O aplicativo fará requisições ao servidor para obter dados atualizados via broker MQTT.
# Desenvolvimento
