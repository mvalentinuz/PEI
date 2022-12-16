#include "editor.h"

Editor::Editor()
{

}

void Editor::setImagen(Imagen *newImagen)
{
    imagen = newImagen;
}

void Editor::pseudocolorear(string rutaLUT)
{
    lut.cargarLUT(rutaLUT);
    vector<vector<int>> tabla = lut.getTabla();
    Pixel pixel;

    for(int f=0; f<imagen->getFilas(); f++)
    {
        for(int c=0; c<imagen->getColumnas(); c++)
        {
            pixel = imagen->getPixel(f,c);
            imagen->modificaPixeldeMatriz(f, c, tabla[pixel.getR()][1], tabla[pixel.getG()][2], tabla[pixel.getB()][3]);
        }
    }
}

void Editor::aplicarMediana()
{
    filtro = new Mediana;

    filtro->filtrar(imagen);

    delete filtro;
}

void Editor::aplicarPasaBajos()
{
    filtro = new PasaBajos;

    filtro->filtrar(imagen);

    delete filtro;
}

void Editor::ajustarBrillo(int cantidad)
{
    Pixel pixel;
    for(int fila=0; fila<imagen->getFilas(); fila++)
    {
        for(int columna=0; columna<imagen->getColumnas(); columna++)
        {
            pixel = imagen->getPixel(fila, columna);
            imagen->modificaPixeldeMatriz(fila, columna, pixel.getR()+cantidad, pixel.getG()+cantidad, pixel.getB()+cantidad);
        }
    }
}

void Editor::ajustarContraste()
{
    Pixel pixel = imagen->getPixel(0,0);
    int minimoR = pixel.getR(), minimoG = pixel.getG(), minimoB = pixel.getB(), maximoR = pixel.getR(), maximoG = pixel.getG(), maximoB = pixel.getB();

    for(int fila=0; fila<imagen->getFilas(); fila++)
    {
        for(int columna=0; columna<imagen->getColumnas(); columna++)
        {
            pixel = imagen->getPixel(fila, columna);

            if(minimoR>pixel.getR())
            {
                minimoR=pixel.getR();
            }
            if(maximoR<pixel.getR())
            {
                maximoR=pixel.getR();
            }

            if(minimoG>pixel.getG())
            {
                minimoG=pixel.getG();
            }
            if(maximoG<pixel.getG())
            {
                maximoG=pixel.getG();
            }

            if(minimoB>pixel.getB())
            {
                minimoB=pixel.getB();
            }
            if(maximoB<pixel.getB())
            {
                maximoB=pixel.getB();
            }
        }
    }

    int R=0, G=0, B=0;

    for(int fila=0; fila<imagen->getFilas(); fila++)
    {
        for(int columna=0; columna<imagen->getColumnas(); columna++)
        {
            pixel = imagen->getPixel(fila, columna);
            R = (float)(pixel.getR() - minimoR)/(maximoR - minimoR)*(imagen->getValorMaximo());
            G = (float)(pixel.getG() - minimoG)/(maximoG - minimoG)*(imagen->getValorMaximo());
            B = (float)(pixel.getB() - minimoB)/(maximoB - minimoB)*(imagen->getValorMaximo());
            imagen->modificaPixeldeMatriz(fila, columna, R, G, B);
        }
    }


}

void Editor::aplicarNegativo()
{
    Pixel pixel;

    for(int fila=0; fila<imagen->getFilas(); fila++)
    {
        for(int columna=0; columna<imagen->getColumnas(); columna++)
        {
            pixel = imagen->getPixel(fila, columna);
            imagen->modificaPixeldeMatriz(fila, columna, imagen->getValorMaximo()-pixel.getR(), imagen->getValorMaximo()-pixel.getG(), imagen->getValorMaximo()-pixel.getB());
        }
    }
}

void Editor::binarizar(int intensidad)
{
    Pixel pixel;
    int promedio;

    for(int fila=0; fila<imagen->getFilas(); fila++)
    {
        for(int columna=0; columna<imagen->getColumnas(); columna++)
        {
            pixel = imagen->getPixel(fila, columna);
            promedio = (pixel.getR()+pixel.getG()+pixel.getB())/3;

            if(promedio<=intensidad)
            {
               imagen->modificaPixeldeMatriz(fila, columna, 0, 0, 0);
            }
            else
            {
               imagen->modificaPixeldeMatriz(fila, columna, 255, 255, 255);
            }
        }
    }
}

void Editor::colorearSuperficie(vector<vector<bool>> region)
{

    for(int fila=0; fila<imagen->getFilas(); fila++)
    {
        for(int columna=0; columna<imagen->getColumnas(); columna++)
        {
            if(region[fila][columna])
            {
                imagen->modificaPixeldeMatriz(fila, columna, 0, 0, 255);
            }
        }
    }

}

Editor::~Editor()
{

}
