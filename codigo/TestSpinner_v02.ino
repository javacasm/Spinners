#define PIN_SENSOR_OPTICO A0
#define PIN_POTENCIOMETRO_UMBRAL_MAX A3
#define PIN_POTENCIOMETRO_UMBRAL_MIN A2

#define PIN_LED 13

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED,OUTPUT);
}

void loop() {
  int valorSensor=analogRead(PIN_SENSOR_OPTICO);

  

// Usamos un potenciometro analogico para ajustar el umbral
  int valorPotUmbralMax=analogRead(PIN_POTENCIOMETRO_UMBRAL_MAX);
  int valorPotUmbralMin=analogRead(PIN_POTENCIOMETRO_UMBRAL_MIN);

  Serial.println(String(valorPotUmbralMin)+", "+String(valorSensor)+", "+String(valorPotUmbralMax));

  if((valorSensor>valorPotUmbralMax) && (valorSensor<valorPotUmbralMin))
  { digitalWrite(PIN_LED,HIGH);}
  else
  { digitalWrite(PIN_LED,LOW);}
}
