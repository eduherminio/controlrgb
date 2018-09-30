/* Author: 	    Eduardo Cáceres de la Calle
 * Subject: 	  Sistemas Digitales Avanzados (SDA)
 * Degree: 	    Industrial Electronics and Automatic Control Engineering
 * University:	Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2016, during my first contact with Arduino.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

/*
 *  	 Ejemplo que ilustra el uso de la librería de creación propia controlrgb.
 *	   Hace que el RGB alterne entre sus colores primarios (rojo, verde, azul)
 *	   con un período de t segundos.
 *	   19/05/16
*/

#include <controlrgb.h>
controlrgb rgb(9, 10, 11);  // pines correspondientas a las patillas R G B
                            // 8 no tiene para PWM
							
int t=1000;		// tiempo de cada estado
void setup()
{
	Serial.begin(9600);
}

void loop()
{
   rgb.LedRgb(255,0,0);		
   delay(t);
   rgb.LedRgb(0,255,0);
   delay(t);
   rgb.LedRgb(0,0,255);
   delay(t);
   
   // rgb.LedRgb(x, y, z )
		// siendo x, y z los valores del analogWrite que se mandan por
		// las patillas 9 (Red), 10 (Green) y 11 (Blue) respectivamente
}
