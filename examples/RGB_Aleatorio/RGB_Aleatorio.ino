/*********************************RGB_ALEAT********************************
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
 * El sketch manda valores de tensiones aleatorios a las distintas patillas
 * de un RGB, manteniéndolos durante 1000ms
 *  ******************************************************************
*/

#include <controlrgb.h>
controlrgb rgb(9, 10, 11);   // pines correspondientas a las patillas R G B
                            // 8 no tiene para PWM
                            
const int t=1000;           // Tiempo de mantenimiento de cada estado

void setup()
{
  Serial.begin(9600);
  
  randomSeed(analogRead(A3));
    // Semilla para la generación de números pseudoaleatorios
    // Toma su valor de una entrada analógica no conectada (ruido)
} 

void loop()
{                                   // Generación de números pseudoaleat.
   int valor_red= random(0,255);      // [0,255]
   int valor_green= random(0,255);    // [0,255]
   int valor_blue= random(0,255);     // [0,255]

   rgb.LedRgb(valor_red,valor_green, valor_blue);

   Serial.print("\nRojo: ");
   Serial.print(valor_red);
   Serial.print("\tVerde: ");
   Serial.print(valor_green);
   Serial.print("\tAzul: ");
   Serial.print(valor_blue);

   delay(t);
}

