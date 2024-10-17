#include <WiFi.h>  // Incluir la librería WiFi para conectarse a la red


void setup() {
  // Iniciar la comunicación serie
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  // Configurar el pin del LED RGB
  pinMode(RGB_BUILTIN, OUTPUT);
  
  // Conectar a la red Wi-Fi
  WiFi.begin("Redmi Note 9T", "Sorlada1808"); // Reemplaza con tus credenciales de Wi-Fi
}

void loop() {
  // Esperar hasta que el dispositivo esté conectado a la red
  #ifdef RGB_BUILTIN
  if (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
    return;
  }

  // Obtener la potencia de la señal Wi-Fi
  int32_t rssi = WiFi.RSSI(); // Obtener RSSI (potencia de señal)

  // Mostrar el RSSI en la consola
  Serial.print("Potencia de señal Wi-Fi (RSSI): ");
  Serial.println(rssi);


  if (rssi >= -20 && rssi < -10) { // Rojo de -20 a -10
    rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0);  // Red
  } 
  else if (rssi >= -10 && rssi < -5) { // GREEN de -10 a -5
    rgbLedWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0);  // Green
  } 
  else if (rssi >= -5 && rssi <= 10) { // Color alternativo de -5 a 10
    rgbLedWrite(RGB_BUILTIN, 0, 0, RGB_BRIGHTNESS);  // Blue
  }

  // Esperar un segundo antes de volver a medir
  delay(1000);
  #endif
}


