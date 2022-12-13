#include <QCoreApplication>
#include <QApplication>
#include <string>
#include <iostream>
#include "gestordearchivos.h"
#include "expositor.h"

#include <QOpenGLWidget>
#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <iostream>
#include <vector>
#include <ostream>
#include <QKeyEvent>
#include <QMouseEvent>
using namespace std;

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   GestorDeArchivos gestor;
   string ruta;
   //cin>>ruta;
   ruta = "C:\\Users\\mauro\\OneDrive\\Escritorio\\PEI";
   gestor.setCarpetaActual("grupo_imagenes_1");
   gestor.abrirDirectorio(ruta);

   Expositor e(&gestor);

   e.abrirVentana(500,500,&a);

   return a.exec();
}
