# Física y arduino con Spinners


Ya tenemos claro que a los chavales les gusta ¿por qué no usarlo para que aprendan?

* Los diseñan
* Los construyen
* Aprenden:
  * Física:
    * Rozamiento
    * Momento de inercia
  * Diseño 3D
  * Mecánica
  * A emprender
    * Presupuestos
    * Relaciones comerciales
    * Estimar el tiempo
* Competiciones
  * Medida de velocidad y duración con Arduino: Tacómetro
    * Sensores para medir la rotación
    * Interrupciones hardware
    * Medida de tiempos
    * Cálculo de velocidades angulares

## Funcionamiento

[Video Comparativa rendimiento rodamiento cerámico (2$) con uno metálico (0,20$)](https://www.youtube.com/watch?v=vLL-T4Z_TNo)


## Diseños

[Spinners con tuercas M8,10,m12](http://www.thingiverse.com/thing:2078940)

![](http://thingiverse-production-new.s3.amazonaws.com/renders/8a/97/bd/ff/4c/39855bbeb329a9963de13dc7203e3b9d_preview_featured.jpg)


[Spinner con 3 tuercas M10](http://www.thingiverse.com/thing:2032459)

![](http://thingiverse-production-new.s3.amazonaws.com/renders/ec/8e/f2/48/3b/021e25b4d2d36b8bf10a288f674b30c8_preview_featured.JPG)

(tarda 1 hora a 0.3)

[otros diseños de spinners con tuercas](http://www.thingiverse.com/search?q=spinner+nuts&sa=)

[Spinner con leds](http://www.thingiverse.com/thing:2245883)

![](http://thingiverse-production-new.s3.amazonaws.com/renders/d8/c4/f6/a1/bf/dc5b2987301b8d285f38f64fef64d8d1_preview_featured.jpg)

## Compras

[100 tuercas M10por 22€](https://www.youtube.com/watch?v=vLL-T4Z_TNo)

[100 rodamientos 608zz por 36€](https://es.aliexpress.com/store/product/608zz-Axial-Ball-Bearing-8mm-skate-bearings-8x22x7-Double-Shielded-100-pieces/722545_32588807551.html)

[10 rodamientos 608zz por 2,5€](https://es.aliexpress.com/item/10pcs-608ZZ-8x22x7-3D-printer-Miniature-Radial-Bearings-Deep-Groove-Ball-Bearings-Skateboard-Scooter-Roller-Wheels/32768021718.html)

[20 rodamientos 608zz Abec9 (sin freno) unos 15€](https://es.aliexpress.com/wholesale?ltype=wholesale&d=y&origin=y&isViewCP=y&catId=0&initiative_id=SB_20170514112051&SearchText=abec9+20pcs&blanktest=0&tc=af)

## Construcción

### Limpieza

[limpieza](https://www.youtube.com/watch?v=mpz3_pZ9Ay0)

## Medidas

### Medida de la rotación con un osciloscopio

[F. Malpartida](https://plus.google.com/u/0/115838143115912805344) ha utilizado un [osciloscopio y  un sensor óptico para ver el giro](https://plus.google.com/u/0/115838143115912805344/posts/DAK4Hzwv4wq)


[Diseño del banco de trabajo](http://www.thingiverse.com/thing:2319223)

![Banco de trabajo  ](https://lh3.googleusercontent.com/yYX_qNNhBxh9jv_kDf6OuWuEjR1RT39J4uf0Z9Nek-gftCXrIdSBEr-lXfouq_7ePGgTZ4KiJIedSw=w1920-h1080-rw-no)

![montaje y osciloscopio](https://lh3.googleusercontent.com/64UsKEqB_Y4bDHtYiWp3PBcoQa2TVebde7kwX1IK3oZbnxkK4Xy6tYsodbi11kou8YQWyObbgMXqrVzbtlqpdjNf7RP8R8ab4Q=w1920-h1080-rw-no)

![osciloscopio](https://lh3.googleusercontent.com/3ejOSjPSpqTRKIvRJfCd2q5CE-CJeAb9N9AMUNG0dyKKppuzllZlEC1yxJbImDtilxzvQQPK0cLxtOmvUCEfpJAoJCmEGqAv9A=w1920-h1080-rw-no)

También propone usar un sensor inductivo


### Medida de rotación con Arduino

![arduino midiendo](./images/1er_test.jpg)

![arduino midiendo](./images/1erTest.png)

El montaje es muy sencillo: un sensor de luz conectado al pin analógico A0

![modelo de test de medida](./images/Montaje_testBench.jpg)

![Diseño](images/Test_Bench_1.03.png)

[Diseño del banco de pruebas](./modelos/Test_bench_v1.03.stl)


#### Código superSimplificado

    void setup() {
      Serial.begin(9600);
    }

    void loop() {
      Serial.println(analogRead(A0));
    }

[Test v0.1](./codigo/TestSpinner_v0.1.ino)

#### Código con cálculo de derivada

![plot diff](./images/spinnerDiffTest.png)

    #define PIN_SENSOR_OPTICO A0
    #define PIN_POTENCIOMETRO_UMBRAL_MAX A3
    #define PIN_POTENCIOMETRO_UMBRAL_MIN A2

    #define PIN_LED 13

    void setup() {
      Serial.begin(115200);
      pinMode(PIN_LED,OUTPUT);
    }

    int old_valorSensor=0;

    void loop() {
      int valorSensor=analogRead(PIN_SENSOR_OPTICO);
      int diffSensor=valorSensor-old_valorSensor; // Calculamos la diferencia con el valor anterior
      old_valorSensor=valorSensor;


    // Usamos dos potenciometros analogicos para ajustar el umbral mínimo y máximo
      int valorPotUmbralMax=analogRead(PIN_POTENCIOMETRO_UMBRAL_MAX);
      int valorPotUmbralMin=analogRead(PIN_POTENCIOMETRO_UMBRAL_MIN);

      Serial.println(String(valorPotUmbralMin)+
          ", "+String(valorSensor)+
          ", "+String(diffSensor)+
          ", "+String(valorPotUmbralMax));

      // activamos el led cuando el valor esté entre los umbrales
      if((valorSensor>valorPotUmbralMax) && (valorSensor<valorPotUmbralMin))
      { digitalWrite(PIN_LED,HIGH);}
      else
      { digitalWrite(PIN_LED,LOW);}
    }

### Practicas a realizar

* "Carreras" de spinners:
  * Más tiempo girando
  * Mayor velocidad
* Construcción
  * A partir de diseños ya hechos
  * Crear diseños para maximizar la inercia, la velocidad...
* Montaje del banco de medida
* Estudio de la física del movimiento

## Dibujando los datos


[python y matlib](http://www.toptechboy.com/tutorial/python-with-arduino-lesson-11-plotting-and-graphing-live-data-from-arduino-with-matplotlib/)


[plotting arduino data](http://www.chemie.unibas.ch/~hauser/open-source-lab/instrumentino/index.html)


[python & arduino](https://playground.arduino.cc/Interfacing/Python)


[plotCat](https://pypi.python.org/pypi/plotcat/1.0.0)

[python plot serial data](http://rwsarduino.blogspot.com.es/2014/12/python-plots-from-serial-input.html)

## Referencias

[How long a Spinner spins](https://www.wired.com/2017/05/the-phyiscs-of-fidget-spinners/) (thanks @ikkaro)

[Physics of a spinner](https://www.wired.com/2017/05/physics-of-a-fidget-spinner)

[Vídeo de impresión 3D de spinners](https://www.youtube.com/watch?v=huC4JagKYh8)
