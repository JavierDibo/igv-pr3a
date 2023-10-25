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
 * @param divU Número de divisiones laterales
 * @param divV Número de divisiones en altura
 * @pre Se asume que los parámetros tienen valores válidos
 * @post Se crea una nueva malla de triángulos que representa la cara lateral de
 *       un cilindro con altura a y radio r
 */
igvCilindro::igvCilindro(float r, float a, int divU, int divV) : igvMallaTriangulos() {
    // Calcular número total de vértices y triángulos
    num_vertices = (divU + 1) * (divV + 1); // Vértices por divisiones en altura y laterales
    num_triangulos = divU * divV * 2; // Dos triángulos por cada cuadro formado por las divisiones

    // Reservar espacio para los arrays de vértices y triángulos
    vertices = new float[num_vertices * 3];
    triangulos = new unsigned int[num_triangulos * 3];
    normales = new float[num_vertices * 3];

    // Calcular vértices y normales
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

    // Calcular triángulos
    int tIndex = 0;
    for (int j = 0; j < divV; j++) {
        for (int i = 0; i < divU; i++) {
            int vertIndex = j * (divU + 1) + i;

            // Primer triángulo
            triangulos[tIndex] = vertIndex;
            triangulos[tIndex + 1] = vertIndex + divU + 1;
            triangulos[tIndex + 2] = vertIndex + 1;

            // Segundo triángulo
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

