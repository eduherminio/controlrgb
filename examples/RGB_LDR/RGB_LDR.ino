/*********************************RGB_LDR********************************
 * 
 *  **********************************Autoria************************************
 *  Eduardo Caceres de la Calle
 *  11/3/16
 *  Sistemas Digitales Avanzados (SDA)
 *  Grado en Ingenieria Electronica Industrial y Automatica
 *  Universidad de Valladolid (UVa) - EII
 *  *****************************************************************************
 *
 *  ******************************Descripción:*****************************
 * El sketch permite controlar la tensión enviada a cada una de las
 * patillas de un RGB a través de sendas LDR
 *  ******************************************************************
*/

#include <controlrgb.h>
controlrgb rgb(9, 10, 11);  // pines correspondientas a las patillas R G B
                            // 8 no tiene para PWM
                          
#define ldr_red    A0       // LDRs
#define ldr_green  A1
#define ldr_blue   A2

const int t=500;                // Tiempo de mantenimiento de cada estado

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(A3));
    // Semilla para la generación de números pseudoaleatorios
    // Toma su valor de una entrada analógica no conectada (ruido)
}

void loop()
{
  // RED
    float lect_red= analogRead(ldr_red);
    float voltaje_red= (float)5*lect_red/1023;    // (0, 5) V
    //float voltaje_red2= map(lec_red, 0, 1023, 0.00, 500)/(float)100;
    float resistencia_red= 10000*(5-voltaje_red)/voltaje_red; // Ohmnios
    int valor_red= map(voltaje_red,0,5,0,255);
    
  // GREEN
    float lect_green= analogRead(ldr_green);
    float voltaje_green= (float)5*lect_green/1023;    // (0, 5) V
    //float voltaje_green2= map(lect_green, 0, 1023, 0.00, 500)/(float)100;
    float resistencia_green= 10000*(5-voltaje_green)/voltaje_green; // Ohmnios
    int valor_green= map(voltaje_green,0,5,0,255);

  // BLUE
    float lect_blue= analogRead(ldr_blue);
    float voltaje_blue= (float)5*lect_blue/1023;    // (0, 5) V
    //float voltaje_blue2= map(lect_blue, 0, 1023, 0.00, 500)/(float)100;
    float resistencia_blue= 10000*(5-voltaje_blue)/voltaje_blue; // Ohmnios
    int valor_blue= map(voltaje_blue,0,5,0,255); 


    rgb.LedRgb(valor_red,valor_green, valor_blue);


  // Muestra a través del puerto serie

  // RED
    Serial.print("\nRojo: Lectura: ");
    Serial.print(lect_red);
    Serial.print("\tVoltaje: ");
    Serial.print(voltaje_red);
    Serial.print("\tResistancia: ");
    Serial.print(resistencia_red);
    Serial.print("\tanalogWrite: ");
    Serial.print(valor_red);
    Serial.print('\n');

  // GREEN
    Serial.print("Verde: Lectura: ");
    Serial.print(lect_green);
    Serial.print("\tVoltaje: ");
    Serial.print(voltaje_green);
    Serial.print("\tResistancia: ");
    Serial.print(resistencia_green);
    Serial.print("\tanalogWrite: ");
    Serial.print(valor_green);
    Serial.print('\n'); 
    
  // BLUE   
    Serial.print("Azul: Lectura: ");
    Serial.print(lect_blue);
    Serial.print("\tVoltaje: ");
    Serial.print(voltaje_blue);
    Serial.print("\tResistancia: ");
    Serial.print(resistencia_blue);
    Serial.print("\tanalogWrite: ");
    Serial.print(valor_blue);
    Serial.print('\n');

    delay(t);
   //delayMicroseconds(0.1*t);
}

