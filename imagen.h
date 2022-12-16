#ifndef IMAGEN_H
#define IMAGEN_H
#include <string>
#include <vector>
#include <pixel.h>

using namespace std;

class Imagen
{
private:
    string id, metadatos;
    int columnas=0, filas=0;
    float valor_max;
    vector<vector<Pixel>> matriz;

public:
    Imagen();
    const string &getId() const;
    void setId(const string &newId);
    const string &getMetadatos() const;
    void setMetadatos(const string &newMetadatos);
    int getColumnas() const;
    void setColumnas(unsigned int newColumnas);
    int getFilas() const;
    void setFilas(unsigned int newFilas);
    float getValorMaximo() const;
    void setValorMaximo(float newValor_max);
    ~Imagen();

    Pixel getPixel(int fila,int columna) const;
    void modificaPixeldeMatriz(int fila, int columna, int R, int G, int B);
    void redimensionarMatriz();

};

#endif // IMAGEN_H
