#include "pasabajos.h"

PasaBajos::PasaBajos()
{

}

void PasaBajos::filtrar(Imagen *imagen)
{
    float constante = 1/9;
    int R, G, B;
    Pixel pixel;

    for(int f=1; f<imagen->getFilas()-1; f++)
    {
        for(int c=1; c<imagen->getColumnas()-1; c++)
        {
            R = constante*(imagen->getPixel(f,c).getR()
                +imagen->getPixel(f+1,c+1).getR()
                +imagen->getPixel(f+1,c).getR()
                +imagen->getPixel(f,c+1).getR()
                +imagen->getPixel(f-1,c).getR()
                +imagen->getPixel(f,c-1).getR()
                +imagen->getPixel(f-1,c-1).getR()
                +imagen->getPixel(f-1,c+1).getR()
                +imagen->getPixel(f+1,c-1).getR());

            G = constante*(imagen->getPixel(f,c).getG()
                +imagen->getPixel(f+1,c+1).getG()
                +imagen->getPixel(f+1,c).getG()
                +imagen->getPixel(f,c+1).getG()
                +imagen->getPixel(f-1,c).getG()
                +imagen->getPixel(f,c-1).getG()
                +imagen->getPixel(f-1,c-1).getG()
                +imagen->getPixel(f-1,c+1).getG()
                +imagen->getPixel(f+1,c-1).getG());

            B = constante*(imagen->getPixel(f,c).getB()
                +imagen->getPixel(f+1,c+1).getB()
                +imagen->getPixel(f+1,c).getB()
                +imagen->getPixel(f,c+1).getB()
                +imagen->getPixel(f-1,c).getB()
                +imagen->getPixel(f,c-1).getB()
                +imagen->getPixel(f-1,c-1).getB()
                +imagen->getPixel(f-1,c+1).getB()
                +imagen->getPixel(f+1,c-1).getB());

           imagen->modificaPixeldeMatriz(f, c, R, G, B);
        }
    }
}

PasaBajos::~PasaBajos()
{

}
