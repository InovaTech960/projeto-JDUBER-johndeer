// CODIGO FONTE

#include <SPI.h>
#include <WiFi.h>
#include <math.h>
#include <HTTPClient.h>

// Configuração dos pontos de acesso WiFi (APs) e suas localizações conhecidas
struct AccessPoint {
  String ssid;
  float x;
  float y;
};

// Defina os pontos de acesso e suas coordenadas (x, y)
AccessPoint aps[] = {
  {".", 0.0, 0.0},      // Ponto de acesso 1 na posição (0,0)
  {"CIDA_BRITO_2G", 10.0, 0.0},     // Ponto de acesso 2 na posição (10,0)
  {"TB", 5.0, 8.66}      // Ponto de acesso 3 na posição (5,8.66)
};

const int numAPs = sizeof(aps) / sizeof(aps[0]);

void setup() {
  WiFi.begin(".", "csl280279");
  Serial.begin(115200);  // Configuração do baud rate para 115200
  WiFi.mode(WIFI_STA);
  delay(100);
  Serial.println("Iniciando escaneamento WiFi...");
}

void sendCoordinatesToServer(float x, float y) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String serverUrl = "http://deereuber.local/wp-json/vehicle/v1/coordinates";
    
    // Inicializa a conexão HTTP
    http.begin(serverUrl);

    // Adiciona o tipo de conteúdo
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Cria os parâmetros a serem enviados
    String postData = "x=" + String(x) + "&y=" + String(y);

    // Envia a requisição POST
    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("HTTP Response code: " + String(httpResponseCode));
      Serial.println("Response: " + response);
    } else {
      Serial.println("Error on sending POST: " + String(httpResponseCode));
    }

    // Fecha a conexão
    http.end();
  } else {
    Serial.println("WiFi not connected");
  }
}

void loop() {
  int n = WiFi.scanNetworks();
  Serial.println("Escaneamento concluído.");

  // Array para armazenar RSSI
  float rssiValues[numAPs] = {0};
  bool foundAPs[numAPs] = {false};

  // Coleta os valores de RSSI dos APs conhecidos
  for (int i = 0; i < n; ++i) {
    String ssid = WiFi.SSID(i);
    int32_t rssi = WiFi.RSSI(i);

    for (int j = 0; j < numAPs; ++j) {
      if (ssid == aps[j].ssid) {
        rssiValues[j] = rssi;
        foundAPs[j] = true;
        Serial.print("SSID: ");
        Serial.print(ssid);
        Serial.print(" RSSI: ");
        Serial.println(rssi);
      }
    }
  }

  // Verifica se encontrou todos os APs necessários
  bool allAPsFound = true;
  for (int i = 0; i < numAPs; ++i) {
    if (!foundAPs[i]) {
      allAPsFound = false;
      Serial.print("AP não encontrado: ");
      Serial.println(aps[i].ssid);
    }
  }

  if (allAPsFound) {
    // Converte RSSI para distâncias
    float distances[numAPs];
    for (int i = 0; i < numAPs; ++i) {
      distances[i] = rssiToDistance(rssiValues[i]);
      Serial.print("Distância para ");
      Serial.print(aps[i].ssid);
      Serial.print(": ");
      Serial.print(distances[i]);
      Serial.println(" metros");
    }

    // Calcula a posição estimada usando trilateração
    float x = 0.0, y = 0.0;
    if (calculatePosition(distances, x, y)) {
      Serial.print("Posição estimada: (");
      Serial.print(x);
      Serial.print(", ");
      Serial.print(y);
      Serial.println(")");

      sendCoordinatesToServer(x, y);  // Envia as coordenadas para o servidor
    } else {
      Serial.println("Erro na trilateração. Posições não podem ser determinadas.");
    }

  } else {
    Serial.println("Não encontrou todos os APs necessários para triangulação.");
  }

  delay(5000); // Aguarda 5 segundos antes de escanear novamente
}

float rssiToDistance(int32_t rssi) {
  // Parâmetros empíricos para conversão de RSSI para distância
  float A = -42; // RSSI a 1 metro
  float n = 2.48; // Exponente de perda de propagação
  return pow(10, (A - rssi) / (10 * n));
}

bool calculatePosition(float distances[], float &x, float &y) {
  // Implementação simples de trilateração para 3 pontos
  float x1 = aps[0].x, y1 = aps[0].y;
  float x2 = aps[1].x, y2 = aps[1].y;
  float x3 = aps[2].x, y3 = aps[2].y;
  float r1 = distances[0], r2 = distances[1], r3 = distances[2];

  float A = 2*x2 - 2*x1;
  float B = 2*y2 - 2*y1;
  float C = r1*r1 - r2*r2 - x1*x1 - y1*y1 + x2*x2 + y2*y2;
  float D = 2*x3 - 2*x2;
  float E = 2*y3 - 2*y2;
  float F = r2*r2 - r3*r3 - x2*x2 - y2*y2 + x3*x3 + y3*y3;

  float denominator = (A*E - B*D);
  if (denominator == 0) {
    return false; // Erro, linhas são paralelas ou há um problema na configuração
  }

  x = (C*E - F*B) / denominator;
  y = (A*F - C*D) / denominator;

  // Verifica se o resultado é válido
  if (isnan(x) || isnan(y)) {
    return false; // Resultado inválido
  }

  return true;
}
