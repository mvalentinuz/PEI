#include "imagen.h"


Imagen::Imagen()
{

}

const string &Imagen::getId() const
{
    return ID;
}

void Imagen::setId(const string &newId)
{
    ID = newId;
}

int Imagen::getColumnas() const
{
    return columnas;
}

void Imagen::setColumnas(unsigned int newColumnas)
{
    columnas = newColumnas;
}

int Imagen::getFilas() const
{
    return filas;
}

void Imagen::setFilas(unsigned int newFilas)
{
    filas = newFilas;
}

int Imagen::getValorMaximo() const
{
    return valorMaximo;
}

void Imagen::setValorMaximo(int newValorMaximo)
{
    valorMaximo = newValorMaximo;
}

const string &Imagen::getMetadatos() const
{
    return metadatos;
}

void Imagen::setMetadatos(const string &newMetadatos)
{
    metadatos = newMetadatos;
}

Pixel Imagen::getPixel(int fila, int columna) const
{
    return matriz[fila][columna];
}

void Imagen::modificaPixeldeMatriz(int fila, int columna, int R, int G, int B)
{
    if(R<=255 && R>=0)
    {
        matriz[fila][columna].setR(R);
    }
    else if(R>255)
    {
        matriz[fila][columna].setR(255);
    }
    else
    {
        matriz[fila][columna].setR(0);
    }

    if(G<=255 && G>=0)
    {
        matriz[fila][columna].setG(G);
    }
    else if(G>255)
    {
        matriz[fila][columna].setG(255);
    }
    else
    {
        matriz[fila][columna].setG(0);
    }

    if(B<=255 && B>=0)
    {
        matriz[fila][columna].setB(B);
    }
    else if(B>255)
    {
        matriz[fila][columna].setB(255);
    }
    else
    {
        matriz[fila][columna].setB(0);
    }
}

void Imagen::redimensionarMatriz()
{
    matriz.resize(filas);
    for(int f=0; f<filas; f++)
    {
        matriz[f].resize(columnas);
    }
}

Imagen::~Imagen()
{

}

