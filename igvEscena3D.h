#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else

#include <GL/glut.h>

#endif // defined(__APPLE__) && defined(__MACH__)

#include "igvMallaTriangulos.h"

/**
 * Los objetos de esta clase representan escenas 3D para su visualización
 */
class igvEscena3D {
private:
    // Atributos
    bool ejes = true;   ///< Indica si hay que dibujar los _ejes coordenados o no

    float anguloX, anguloY, anguloZ; ///< Atributos con los ángulos de rotación en X, Y y Z.

    bool normal = false; ///< Indica si hay que usar las normales o no

    bool gouraud = false;

private:
    ///< Indica si hay que usar la visualizacion gouraud o no

    igvMallaTriangulos *malla = nullptr; ///< Malla de triángulos asociada a la escena

public:
    // Constructores por defecto y destructor
    igvEscena3D();

    ~igvEscena3D();

    // Métodos
    // método con las llamadas OpenGL para visualizar la escena
    void visualizar();

    bool get_ejes();

    void set_ejes(bool _ejes);

    bool isEjes() const;

    void setEjes(bool ejes);

    float getAnguloX() const;

    void setAnguloX(float anguloX);

    float getAnguloY() const;

    void setAnguloY(float anguloY);

    float getAnguloZ() const;

    void setAnguloZ(float anguloZ);

    igvMallaTriangulos *getMalla() const;

    void setMalla(igvMallaTriangulos *malla);

    bool getNormal() const;

    void setNormal(bool normal);

    bool getGouraud() const;

    void setGouraud(bool gouraud);

private:
    void pintar_ejes();
};

#endif   // __IGVESCENA3D
