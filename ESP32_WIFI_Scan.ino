/* Redes disponibles
 *  Realiza una búsqueda de redes Wifi cercanas
 */
#include <WiFi.h>

void setup()
{
    Serial.begin(115200);

    // Si estaba conectada como estación, se desconecta.
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Configuración completada.");
}

void loop()
{
    Serial.println("Busca redes WiFi cercanas");

    //determina el número de redes cercanas
    int n = WiFi.scanNetworks();
    Serial.println("Busqueda completada ");
    
    if (n == 0) {
        Serial.println("NO se encontraron redes.");
    } else {
        Serial.print(n);
        Serial.println(" redes encontradas");
        for (int i = 0; i < n; ++i) {
            // Muestra el SSID y RSSI de cada red encontrada
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");

    // Espera antes de la próxima búsqueda...
    delay(5000);
}
