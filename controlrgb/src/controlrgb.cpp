/* Author: 		Eduardo Cáceres de la Calle
 * Subject: 	Sistemas Digitales Avanzados (SDA)
 * Degree: 		Industrial Electronics and Automatic Control Engineering
 * University:	Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2016, during my first contact with Arduino.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

/*	Librería que permite controlar la tonalidad de la iluminación de un RGB 
 *	mediante el envío de diferentes tensiones a las tres patillas del mismo	
 *	19/05/16
*/

#include "Arduino.h"
#include "controlrgb.h"
#include <string.h>

controlrgb::controlrgb(int pin_red, int pin_green, int pin_blue)     // Constructor
{
	_red=	pin_red		+A0;
	_green=	pin_green 	+A0;
	_blue=	pin_blue 	+A0;
}

void controlrgb::luz_serial(int rojo, int verde, int azul)
{
    Serial.print("\nRojo: ");
    Serial.print(rojo);
    Serial.print("\tVerde: ");
    Serial.print(verde);
    Serial.print("\tAzul: ");
    Serial.print(azul);
}

void controlrgb::LedRgb(int rojo, int verde, int azul)
{
	if(rojo>255)		// Limita los valores del analogWrite a [0, 255]
		rojo=255;
	else if(rojo<0)
		rojo=0;
	if(verde>255)
		verde=255;
	else if(verde<0)
		verde=0;
	if(azul>255)
		azul=255;
	else if(azul<0)
		azul=0;
						// Envía la tensión escogida a través de sendos PWM
	analogWrite(_red, rojo);
	analogWrite(_green, verde);
	analogWrite(_blue, azul);
}
