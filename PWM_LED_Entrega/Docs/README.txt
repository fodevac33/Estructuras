Autor: Juan Felipe Osorio Franco

LED_PWM

El programa controla la intensidad luminica de un Led conectado al pin PA5 a traves de una señal PWM que asu vez esta controlada
por una lectura de un potenciometro conectado al pin A0 a traves de un convertidor analogico - digital (ADC).


### Funciones
Las principales funciones del programa son:

void SystemClock_Config(void);
Inizializa el reloj del procesador a 80Mhz

void Configure_ADC(void);
Hace la configuracion basica del ADC

void Activate_ADC(void);
Activa el ADC

void ConversionStartPoll_ADC_GrpRegular(void);
Inizializa la conversion en el ADC

void Configure_TIMPWMOutput(void);
Inicializa la señal PWM en un pin especifico 

void Configure_DutyCycle(uint32_t OCMode);
Cambia el ciclo de trabajo de la señal PWM al entero OCMode (Entre 0 y 100)


### Compensacion logaritmica
Dado que el ojo humano percibe la luz de forma logaritmica es pertinente realizar algun tipo de compensacion a la 
intensidad del led para que se pueda percibir como si fuera lineal, para esto se aplica una compensacion cuadratica:

double cuadratica = pow((porcentaje / 10.0), 2);
double porcentaje_cuadratico = (cuadratica > 100) ? 100 : cuadratica;

Se compensa por la funcion (x/10)² lo cual genero mejores resultados que una compensacion exponencial en la practica.
