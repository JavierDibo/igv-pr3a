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
 * @param divU Número de divisiones laterales
 * @param divV Número de divisiones en altura
 * @pre Se asume que los parámetros tienen valores válidos
 * @post Se crea una nueva malla de triángulos que representa la cara lateral de
 *       un cilindro con altura a y radio r
 */
igvCilindro::igvCilindro(float r, float a, int divU, int divV)
{	// TODO: Apartado B: Construir la malla de triángulos para representar el cilindro
	// TODO: Apartado C: Añadir el vector de normales
}

/**
 * Destructor
 */
igvCilindro::~igvCilindro()
{
}
