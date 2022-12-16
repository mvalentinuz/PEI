#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include <string>
#include <vector>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "imagen.h"
#include "pnm.h"
#include "aic.h"

using namespace std;

class GestorDeArchivos
{
private:
    DIR *directorio;
    string ruta_directorio;
    Archivo *archivo;

    string carpeta1 = "grupo_imagenes_1";
    string carpeta2 = "grupo_imagenes_2";
    string carpeta3 = "grupo_imagenes_3_corruptas";
    string carpetaDeEdiciones = "grupo_imagenes_4_nuevas";

    string carpetaActual;
    vector<string> nombre_archivos;
    string nombreArchivoActual;
    int indice;

public:
    GestorDeArchivos();
    void abrirDirectorio(string ruta);
    void leerArchivo(Imagen *imagen);
    void guardarArchivo(Imagen *imagen, string nombre, string formato, string ID);
    void cambiarArchivoActual(bool avanzar);
    const string &getRutaDirectorio() const;
    void setCarpetaActual(string nombreCarpeta);
    ~GestorDeArchivos();

};

#endif // GESTORDEARCHIVOS_H
