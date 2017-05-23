#define PIN_SENSOR_OPTICO A0
#define PIN_POTENCIOMETRO_UMBRAL A1

void setup() {
Serial.begin(115200);
}

void loop() {
  int valorSensor=analogRead(PIN_SENSOR_OPTICO);

  Serial.println(valorSensor);

// Usamos un potenciometro analogico para ajustar el umbral
  int valorPotUmbral=analogRead(PIN_POTENCIOMETRO_UMBRAL);

  
}
