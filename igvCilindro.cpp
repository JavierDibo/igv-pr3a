#include "igvCilindro.h"

/**
 * Constructor por defecto
 */
igvCilindro::igvCilindro() :igvMallaTriangulos()
{
}

/**
 * Constructor parametrizado
 * @param r Radio de la base del cilindro
 * @param a Altura del cilindro
 * @param divU N�mero de divisiones laterales
 * @param divV N�mero de divisiones en altura
 * @pre Se asume que los par�metros tienen valores v�lidos
 * @post Se crea una nueva malla de tri�ngulos que representa la cara lateral de
 *       un cilindro con altura a y radio r
 */
igvCilindro::igvCilindro(float r, float a, int divU, int divV)
{	// TODO: Apartado B: Construir la malla de tri�ngulos para representar el cilindro
	// TODO: Apartado C: A�adir el vector de normales
}

/**
 * Destructor
 */
igvCilindro::~igvCilindro()
{
}
