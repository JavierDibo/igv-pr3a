#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "igvMallaTriangulos.h"

/**
 * Constructor parametrizado de una malla de triángulos sin normales en los
 * vértices
 * @param _num_vertices Número de vértices de la nueva malla
 * @param _vertices Dirección de memoria donde se encuentran almacenadas las
 *        coordenadas (formato X,Y,Z) de los vértices. Esta información se
 *        copia en la nueva malla
 * @param _num_triangulos Número de triángulos que forman la malla
 * @param _triangulos Índices (formato v1, v2, v3) a los vértices que forman
 *        cada triángulo. Esta información se copia en el nuevo objeto
 * @pre Se asume que todos los parámetros tienen valores válidos
 * @post La nueva malla almacenará copias de la información que se le pasa como
 *       parámetro
 */
igvMallaTriangulos::igvMallaTriangulos ( long int _num_vertices, float *_vertices
                                         , long int _num_triangulos
                                         , unsigned int *_triangulos ):
                                       num_vertices ( _num_vertices )
                                       , num_triangulos ( _num_triangulos )
{  vertices = new float[num_vertices * 3];
   for ( long int i = 0 ; i < ( num_vertices * 3 ) ; ++i )
   {  vertices[i] = _vertices[i];
   }

   triangulos = new unsigned int[num_triangulos * 3];
   for ( long int i = 0 ; i < ( num_triangulos * 3 ) ; ++i )
   {  triangulos[i] = _triangulos[i];
   }
}

/**
 * Destructor
 */
igvMallaTriangulos::~igvMallaTriangulos ()
{  if ( vertices )
   {  delete []vertices;
      vertices = nullptr;
   }

   if ( normales )
   {  delete []normales;
      normales = nullptr;
   }

   if ( triangulos )
   {  delete []triangulos;
      triangulos = nullptr;
   }
}

/**
 * Método con las llamadas OpenGL para visualizar la malla de triángulos
 */
void igvMallaTriangulos::visualizar() {
    glShadeModel(GL_FLAT);

    // Dibujo de la malla de triángulos
    glBegin(GL_TRIANGLES);
    for (long int i = 0; i < num_triangulos; ++i) {
        for (int j = 0; j < 3; ++j) {
            int vertexIndex = triangulos[i * 3 + j];
            glVertex3f(vertices[vertexIndex * 3], vertices[vertexIndex * 3 + 1], vertices[vertexIndex * 3 + 2]);
        }
    }
    glEnd();
}