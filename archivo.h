#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "imagen.h"


class Archivo
{
public:
    Archivo();
    virtual void leer(Imagen *imagen, string ruta) = 0;
    virtual void guardar(Imagen *imagen, string ruta, string ID) = 0;
    virtual ~Archivo();

};

#endif // ARCHIVO_H
