#ifndef ANALIZADOR_H
#define ANALIZADOR_H
#include "imagen.h"
#include "pixel.h"
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <initializer_list>
#include <iostream>

using namespace std;

class Analizador
{
private:
    float minimo=255, maximo=0, promedio=0, moda=0, desvio_estandar=0;
    float minimoR=255, maximoR=0, promedioR=0, modaR=0, desvio_estandarR=0;
    float minimoG=255, maximoG=0, promedioG=0, modaG=0, desvio_estandarG=0;
    float minimoB=255, maximoB=0, promedioB=0, modaB=0, desvio_estandarB=0;
    vector<int> rojos, verdes, azules, intensidad;
    vector<int> funcionRojos, funcionVerdes, funcionAzules, funcionIntensidades;
    Imagen *imagen;
    int areaMapeada = 0;
    vector<vector<bool>> region;

public:
    Analizador();
    void setImagen(Imagen *nuevaImagen);
    void analizar();
    void generarDatosDeHistograma();
    void detectarRegion(int fila, int columna, int tolerancia);
    void algoritmoDelPintor(int fila, int columna, Pixel referencia, int tolerancia);
    float getPromedio() const;
    const vector<vector<bool> > &getRegionDetectada() const;
    const vector<int> &getFuncionRojos() const;
    const vector<int> &getFuncionVerdes() const;
    const vector<int> &getFuncionAzules() const;
    const vector<int> &getFuncionIntensidades() const;
    float getFrecuenciaModa() const;
    float getMayorFrecuenciaModaRGB() const;
    int getAreaMapeada() const;
    ~Analizador();
};

#endif // ANALIZADOR_H
