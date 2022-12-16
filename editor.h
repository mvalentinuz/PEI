#ifndef EDITOR_H
#define EDITOR_H
#include "iostream"
#include "imagen.h"
#include "lut.h"
#include "pixel.h"
#include "analizador.h"
#include "filtro.h"
#include "mediana.h"
#include "pasabajos.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Editor
{
private:
    LUT lut;
    Filtro *filtro;
    Imagen *imagen;
public:
    Editor();
    void setImagen(Imagen *newImagen);
    void pseudocolorear(string rutaLUT);
    void aplicarMediana();
    void aplicarPasaBajos();
    void ajustarBrillo(int cantidad);
    void ajustarContraste();
    void aplicarNegativo();
    void binarizar(int intensidad);
    void colorearSuperficie(vector<vector<bool>> region);
    ~Editor();
};

#endif // EDITOR_H
