#include "mediana.h"

Mediana::Mediana()
{

}

void Mediana::filtrar(Imagen *punteroImagen)
{
    Pixel pixel;
    vector<int> rojosDeLaZona3x3, verdesDeLaZona3x3, azulesDeLaZona3x3;

    for(int fila=1; fila<punteroImagen->getFilas()-1; fila++)
    {
        for(int columna=1; columna<punteroImagen->getColumnas()-1; columna++)
        {
            pixel = punteroImagen->getPixel(fila-1, columna-1);
            rojosDeLaZona3x3.push_back(pixel.getR());
            verdesDeLaZona3x3.push_back(pixel.getG());
            azulesDeLaZona3x3.push_back(pixel.getB());

            pixel = punteroImagen->getPixel(fila-1, columna);
            rojosDeLaZona3x3.push_back(pixel.getR());
            verdesDeLaZona3x3.push_back(pixel.getG());
            azulesDeLaZona3x3.push_back(pixel.getB());

            pixel = punteroImagen->getPixel(fila-1, columna+1);
            rojosDeLaZona3x3.push_back(pixel.getR());
            verdesDeLaZona3x3.push_back(pixel.getG());
            azulesDeLaZona3x3.push_back(pixel.getB());

            pixel = punteroImagen->getPixel(fila, columna-1);
            rojosDeLaZona3x3.push_back(pixel.getR());
            verdesDeLaZona3x3.push_back(pixel.getG());
            azulesDeLaZona3x3.push_back(pixel.getB());

            pixel = punteroImagen->getPixel(fila, columna);
            rojosDeLaZona3x3.push_back(pixel.getR());
            verdesDeLaZona3x3.push_back(pixel.getG());
            azulesDeLaZona3x3.push_back(pixel.getB());

            pixel = punteroImagen->getPixel(fila, columna+1);
            rojosDeLaZona3x3.push_back(pixel.getR());
            verdesDeLaZona3x3.push_back(pixel.getG());
            azulesDeLaZona3x3.push_back(pixel.getB());

            pixel = punteroImagen->getPixel(fila+1, columna-1);
            rojosDeLaZona3x3.push_back(pixel.getR());
            verdesDeLaZona3x3.push_back(pixel.getG());
            azulesDeLaZona3x3.push_back(pixel.getB());

            pixel = punteroImagen->getPixel(fila+1, columna);
            rojosDeLaZona3x3.push_back(pixel.getR());
            verdesDeLaZona3x3.push_back(pixel.getG());
            azulesDeLaZona3x3.push_back(pixel.getB());

            pixel = punteroImagen->getPixel(fila+1, columna+1);
            rojosDeLaZona3x3.push_back(pixel.getR());
            verdesDeLaZona3x3.push_back(pixel.getG());
            azulesDeLaZona3x3.push_back(pixel.getB());

            sort(rojosDeLaZona3x3.begin(), rojosDeLaZona3x3.end());
            sort(verdesDeLaZona3x3.begin(), verdesDeLaZona3x3.end());
            sort(azulesDeLaZona3x3.begin(), azulesDeLaZona3x3.end());

            punteroImagen->modificaPixeldeMatriz(fila, columna, rojosDeLaZona3x3[4], verdesDeLaZona3x3[4], azulesDeLaZona3x3[4]);

            rojosDeLaZona3x3.clear();
            verdesDeLaZona3x3.clear();
            azulesDeLaZona3x3.clear();
        }
    }
}

Mediana::~Mediana()
{

}
