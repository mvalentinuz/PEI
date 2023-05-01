#include "pasabajos.h"

PasaBajos::PasaBajos()
{

}

void PasaBajos::filtrar(Imagen *punteroImagen)
{
    float constante = 0.11;
    int R, G, B;
    Pixel pixel;

    for(int f=1; f<punteroImagen->getFilas()-1; f++)
    {
        for(int c=1; c<punteroImagen->getColumnas()-1; c++)
        {
            R = constante*(punteroImagen->getPixel(f,c).getR()
                           +punteroImagen->getPixel(f+1,c+1).getR()
                           +punteroImagen->getPixel(f+1,c).getR()
                           +punteroImagen->getPixel(f,c+1).getR()
                           +punteroImagen->getPixel(f-1,c).getR()
                           +punteroImagen->getPixel(f,c-1).getR()
                           +punteroImagen->getPixel(f-1,c-1).getR()
                           +punteroImagen->getPixel(f-1,c+1).getR()
                           +punteroImagen->getPixel(f+1,c-1).getR());

            G = constante*(punteroImagen->getPixel(f,c).getG()
                           +punteroImagen->getPixel(f+1,c+1).getG()
                           +punteroImagen->getPixel(f+1,c).getG()
                           +punteroImagen->getPixel(f,c+1).getG()
                           +punteroImagen->getPixel(f-1,c).getG()
                           +punteroImagen->getPixel(f,c-1).getG()
                           +punteroImagen->getPixel(f-1,c-1).getG()
                           +punteroImagen->getPixel(f-1,c+1).getG()
                           +punteroImagen->getPixel(f+1,c-1).getG());

            B = constante*(punteroImagen->getPixel(f,c).getB()
                           +punteroImagen->getPixel(f+1,c+1).getB()
                           +punteroImagen->getPixel(f+1,c).getB()
                           +punteroImagen->getPixel(f,c+1).getB()
                           +punteroImagen->getPixel(f-1,c).getB()
                           +punteroImagen->getPixel(f,c-1).getB()
                           +punteroImagen->getPixel(f-1,c-1).getB()
                           +punteroImagen->getPixel(f-1,c+1).getB()
                           +punteroImagen->getPixel(f+1,c-1).getB());

            punteroImagen->modificaPixeldeMatriz(f, c, R, G, B);

        }
    }
}

PasaBajos::~PasaBajos()
{

}
