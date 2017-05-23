#define PIN_SENSOR_OPTICO A0
#define PIN_POTENCIOMETRO_UMBRAL_MAX A3
#define PIN_POTENCIOMETRO_UMBRAL_MIN A2

#define PIN_LED 13

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED,OUTPUT);
}
int old_valorSensor=0;
int iContador=0;
// Usamos dos potenciometros analogicos para ajustar el umbral mínimo y máximo
int valorPotUmbralMax=analogRead(PIN_POTENCIOMETRO_UMBRAL_MAX);
int valorPotUmbralMin=analogRead(PIN_POTENCIOMETRO_UMBRAL_MIN);

void loop() {
  int valorSensor=analogRead(PIN_SENSOR_OPTICO);
  int diffSensor=valorSensor-old_valorSensor; // Calculamos la diferencia con el valor anterior
  old_valorSensor=valorSensor;


  if(iContador%1000==0){
    valorPotUmbralMax=analogRead(PIN_POTENCIOMETRO_UMBRAL_MAX);
    valorPotUmbralMin=analogRead(PIN_POTENCIOMETRO_UMBRAL_MIN);
  }
  iContador  ++;
  
  /*Serial.println(String(valorPotUmbralMin)+
      ", "+String(valorSensor)+
      ", "+String(diffSensor)+
      ", "+String(valorPotUmbralMax));
*/
Serial.print(valorSensor);
Serial.print(",");
Serial.println(diffSensor);
  // activamos el led cuando el valor esté entre los umbrales
  if((valorSensor>valorPotUmbralMax) && (valorSensor<valorPotUmbralMin))
  { digitalWrite(PIN_LED,HIGH);}
  else
  { digitalWrite(PIN_LED,LOW);}
}

