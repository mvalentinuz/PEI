#ifndef EXPOSITOR_H
#define EXPOSITOR_H
#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QMouseEvent>
#include <vector>
#include "imagen.h"
#include "gestordearchivos.h"
#include "editor.h"
#include "analizador.h"

using namespace std;

class Expositor: public QOpenGLWidget, protected QOpenGLFunctions
{
protected:
    void initializeGL() override;
    void resizeGL(int ancho, int alto) override;
    void paintGL() override;
    void keyPressEvent(QKeyEvent *evento) override;
    void mousePressEvent(QMouseEvent *evento) override;
private:
    GestorDeArchivos *gestor;
    Imagen imagen;
    Editor editor;
    Analizador analizador;
    float proporcion = 1.0;
    float escala;  // Para matenener las proporciones para cualquier ventana.
    float desplx, desply; // Para desplazar la imagen al centro de la ventana.
    bool mostrarHistograma = false;
public:
    Expositor(GestorDeArchivos *pGestor);
    void abrirVentana(int ancho, int alto, QApplication *QApp);
    void exponer();
    void graficarHistograma();
    ~Expositor();

};

#endif // EXPOSITOR_H
