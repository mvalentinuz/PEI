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
   /*fstream ar;
   ar.open("..//grupo_imagenes_1//entre_rios_03.ppm", ios::binary);
   if(!ar.is_open()){ cout<<"NO"<<endl;} else{cout<<"SI"<<endl;}*/
   ruta = "C://Users//ROMOANMAFR//Desktop//PEI";
   gestor.setCarpetaActual("grupo_imagenes_1");
   gestor.abrirDirectorio(ruta);

   Expositor e(&gestor);

   e.abrirVentana(500,500,&a);

   return a.exec();
}
