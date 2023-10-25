#include <cmath>
#include "igvCilindro.h"

/**
 * Constructor por defecto
 */
igvCilindro::igvCilindro() : igvMallaTriangulos() {
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
igvCilindro::igvCilindro(float r, float a, int divU, int divV) : igvMallaTriangulos() {
    // Calcular n�mero total de v�rtices y tri�ngulos
    num_vertices = (divU + 1) * (divV + 1); // V�rtices por divisiones en altura y laterales
    num_triangulos = divU * divV * 2; // Dos tri�ngulos por cada cuadro formado por las divisiones

    // Reservar espacio para los arrays de v�rtices y tri�ngulos
    vertices = new float[num_vertices * 3];
    triangulos = new unsigned int[num_triangulos * 3];
    normales = new float[num_vertices * 3];

    // Calcular v�rtices y normales
    for (int j = 0; j <= divV; j++) {
        for (int i = 0; i <= divU; i++) {
            float theta = 2.0f * M_PI * i / divU;
            float x = r * cos(theta);
            float y = j * a / divV;
            float z = r * sin(theta);

            int index = (j * (divU + 1) + i) * 3;
            vertices[index] = x;
            vertices[index + 1] = y;
            vertices[index + 2] = z;

            // Calcular normales
            float magnitude = sqrt(x * x + z * z); // Componente y es 0 para la superficie lateral
            normales[index] = x / magnitude;
            normales[index + 1] = 0; // La componente y de la normal es 0 para la superficie lateral
            normales[index + 2] = z / magnitude;
        }
    }

    // Calcular tri�ngulos
    int tIndex = 0;
    for (int j = 0; j < divV; j++) {
        for (int i = 0; i < divU; i++) {
            int vertIndex = j * (divU + 1) + i;

            // Primer tri�ngulo
            triangulos[tIndex] = vertIndex;
            triangulos[tIndex + 1] = vertIndex + divU + 1;
            triangulos[tIndex + 2] = vertIndex + 1;

            // Segundo tri�ngulo
            triangulos[tIndex + 3] = vertIndex + 1;
            triangulos[tIndex + 4] = vertIndex + divU + 1;
            triangulos[tIndex + 5] = vertIndex + divU + 2;

            tIndex += 6;
        }
    }
}

igvCilindro::~igvCilindro() {
    delete[] vertices;
    delete[] triangulos;
}

