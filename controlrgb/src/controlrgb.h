/* Author: 	    Eduardo C�ceres de la Calle
 * Subject: 	Sistemas Digitales Avanzados (SDA)
 * Degree:      Industrial Electronics and Automatic Control Engineering
 * University:	Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2016, during my first contact with Arduino.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

/*      Librer�a que permite controlar la tonalidad de la iluminaci�n de un RGB 
 *  	mediante el env�o de diferentes tensiones a las tres patillas del mismo
 *	    19/05/16
*/

#ifndef Prueba
#define Prueba

#include "Arduino.h";

class controlrgb
{
public:     // Funciones p�blicas
    controlrgb(int pin_red, int pin_green, int pin_blue);    // Constructor
    /*  Define el pin donde est� conectado el sensor
    *   Quedar� almacenado en la variable _pin
    */

void luz_serial(int rojo, int verde, int azul);
    /*  Muestra por el puerto serie las tres variables que se le pasa
    *   Permite comprobar al usuario qu� mezcla de colores est� mandando al RGB
    */

void LedRgb(int rojo, int verde, int azul);
/*  Adapta (si es necesario) los valores que se le pasan como argumento -> [0, 255]
 *  Transmite una tensi�n proporcional a esos valores (dentro del rango [0,255])
 *  a trav�s de los pines espeficicados por el constructor para los tres leds del RGB
*/


private:    // Variables privadas
    int _red;
    int _green;
    int _blue;
};

#endif
