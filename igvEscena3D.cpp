#include <cstdlib>
#include <stdio.h>
#include <cmath>

#include "igvEscena3D.h"
#include "igvMallaTriangulos.h"


// Métodos constructores

/**
 * Constructor por defecto
 */
igvEscena3D::igvEscena3D() {  // TODO: Apartado B: Inserta el código para crear un cilindro
    malla = new igvMallaTriangulos();
    anguloX = 0.0f;
    anguloY = 0.0f;
    anguloZ = 0.0f;
}

/**
 * Destructor
 */
igvEscena3D::~igvEscena3D() {
    if (malla != nullptr) {
        delete malla;
        malla = nullptr;
    }
}


// Métodos públicos

/**
 * Método para pintar los ejes coordenados llamando a funciones de OpenGL
 */
void igvEscena3D::pintar_ejes() {
    GLfloat rojo[] = {1, 0, 0, 1.0};
    GLfloat verde[] = {0, 1, 0, 1.0};
    GLfloat azul[] = {0, 0, 1, 1.0};

    glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
    glBegin(GL_LINES);
    glVertex3f(1000, 0, 0);
    glVertex3f(-1000, 0, 0);
    glEnd();

    glMaterialfv(GL_FRONT, GL_EMISSION, verde);
    glBegin(GL_LINES);
    glVertex3f(0, 1000, 0);
    glVertex3f(0, -1000, 0);
    glEnd();

    glMaterialfv(GL_FRONT, GL_EMISSION, azul);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 1000);
    glVertex3f(0, 0, -1000);
    glEnd();
}

/**
 * Método con las llamadas OpenGL para visualizar la escena
 */
void igvEscena3D::visualizar(void) {
    GLfloat color_malla[] = {0, 0.25, 0};
    // crear luces
    // luz puntual para visualizar el cubo
    GLfloat luz0[4] = {2.0, 2.5, 3.0, 1};

    // la luz se coloca aquí si permanece fija y no se mueve con la escena
    glLightfv(GL_LIGHT0, GL_POSITION, luz0);
    glEnable(GL_LIGHT0);

    // crear el modelo
    glPushMatrix(); // guarda la matriz de modelado

    glRotatef(anguloX, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloY, 0.0f, 1.0f, 0.0f);
    glRotatef(anguloZ, 0.0f, 0.0f, 1.0f);

    // se pintan los ejes
    if (ejes) {
        pintar_ejes();
    }

    // la luz se coloca aquí si se mueve junto con la escena
    //glLightfv(GL_LIGHT0,GL_POSITION,luz0);
    glMaterialfv(GL_FRONT, GL_EMISSION, color_malla);

    // TODO: Apartado B: la siguiente llamada hay que sustituirla por la llamada al método visualizar de la malla
    GLUquadric *cyl = gluNewQuadric();
    gluCylinder(cyl, 1, 1, 1, 20, 5);
    gluDeleteQuadric(cyl);
    cyl = nullptr;

    glPopMatrix(); // restaura la matriz de modelado
}

/**
 * Método para consultar si hay que dibujar los ejes o no
 * @retval true Si hay que dibujar los ejes
 * @retval false Si no hay que dibujar los ejes
 */
bool igvEscena3D::get_ejes() {
    return ejes;
}

/**
 * Método para activar o desactivar el dibujado de los _ejes
 * @param _ejes Indica si hay que dibujar los ejes (true) o no (false)
 * @post El estado del objeto cambia en lo que respecta al dibujado de ejes,
 *       de acuerdo al valor pasado como parámetro
 */
void igvEscena3D::set_ejes(bool _ejes) {
    ejes = _ejes;
}

bool igvEscena3D::isEjes() const {
    return ejes;
}

void igvEscena3D::setEjes(bool ejes) {
    igvEscena3D::ejes = ejes;
}

float igvEscena3D::getAnguloX() const {
    return anguloX;
}

void igvEscena3D::setAnguloX(float anguloX) {
    igvEscena3D::anguloX = anguloX;
}

float igvEscena3D::getAnguloY() const {
    return anguloY;
}

void igvEscena3D::setAnguloY(float anguloY) {
    igvEscena3D::anguloY = anguloY;
}

float igvEscena3D::getAnguloZ() const {
    return anguloZ;
}

void igvEscena3D::setAnguloZ(float anguloZ) {
    igvEscena3D::anguloZ = anguloZ;
}

igvMallaTriangulos *igvEscena3D::getMalla() const {
    return malla;
}

void igvEscena3D::setMalla(igvMallaTriangulos *malla) {
    igvEscena3D::malla = malla;
}

