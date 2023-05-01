#include "editor.h"

Editor::Editor()
{

}

void Editor::setImagen(Imagen *newPunteroImagen)
{
    punteroImagen = newPunteroImagen;
}

void Editor::pseudocolorear(string rutaLUT)
{
    lut.cargarLUT(rutaLUT);
    vector<vector<int>> tabla = lut.getTabla();
    Pixel pixel;

    for(int f=0; f<punteroImagen->getFilas(); f++)
    {
        for(int c=0; c<punteroImagen->getColumnas(); c++)
        {
            pixel = punteroImagen->getPixel(f,c);
            punteroImagen->modificaPixeldeMatriz(f, c, tabla[pixel.getR()][1], tabla[pixel.getG()][2], tabla[pixel.getB()][3]);
        }
    }
}

void Editor::aplicarMediana()
{
    punteroFiltro = new Mediana;

    punteroFiltro->filtrar(punteroImagen);

    delete punteroFiltro;
}

void Editor::aplicarPasaBajos()
{
    punteroFiltro = new PasaBajos;

    punteroFiltro->filtrar(punteroImagen);

    delete punteroFiltro;
}

void Editor::ajustarBrillo(int cantidad)
{
    Pixel pixel;
    for(int fila=0; fila<punteroImagen->getFilas(); fila++)
    {
        for(int columna=0; columna<punteroImagen->getColumnas(); columna++)
        {
            pixel = punteroImagen->getPixel(fila, columna);
            punteroImagen->modificaPixeldeMatriz(fila, columna, pixel.getR()+cantidad, pixel.getG()+cantidad, pixel.getB()+cantidad);
        }
    }
}

void Editor::ajustarContraste()
{
    Pixel pixel = punteroImagen->getPixel(0,0);
    int minimoR = pixel.getR(), minimoG = pixel.getG(), minimoB = pixel.getB(), maximoR = pixel.getR(), maximoG = pixel.getG(), maximoB = pixel.getB();

    for(int fila=0; fila<punteroImagen->getFilas(); fila++)
    {
        for(int columna=0; columna<punteroImagen->getColumnas(); columna++)
        {
            pixel = punteroImagen->getPixel(fila, columna);

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

    for(int fila=0; fila<punteroImagen->getFilas(); fila++)
    {
        for(int columna=0; columna<punteroImagen->getColumnas(); columna++)
        {
            pixel = punteroImagen->getPixel(fila, columna);
            R = (float)(pixel.getR() - minimoR)/(maximoR - minimoR)*(punteroImagen->getValorMaximo());
            G = (float)(pixel.getG() - minimoG)/(maximoG - minimoG)*(punteroImagen->getValorMaximo());
            B = (float)(pixel.getB() - minimoB)/(maximoB - minimoB)*(punteroImagen->getValorMaximo());
            punteroImagen->modificaPixeldeMatriz(fila, columna, R, G, B);
        }
    }


}

void Editor::aplicarNegativo()
{
    Pixel pixel;

    for(int fila=0; fila<punteroImagen->getFilas(); fila++)
    {
        for(int columna=0; columna<punteroImagen->getColumnas(); columna++)
        {
            pixel = punteroImagen->getPixel(fila, columna);
            punteroImagen->modificaPixeldeMatriz(fila, columna, punteroImagen->getValorMaximo()-pixel.getR(), punteroImagen->getValorMaximo()-pixel.getG(), punteroImagen->getValorMaximo()-pixel.getB());
        }
    }
}

void Editor::binarizar(int intensidad)
{
    Pixel pixel;
    int promedio;

    for(int fila=0; fila<punteroImagen->getFilas(); fila++)
    {
        for(int columna=0; columna<punteroImagen->getColumnas(); columna++)
        {
            pixel = punteroImagen->getPixel(fila, columna);
            promedio = (pixel.getR()+pixel.getG()+pixel.getB())/3;

            if(promedio<=intensidad)
            {
               punteroImagen->modificaPixeldeMatriz(fila, columna, 0, 0, 0);
            }
            else
            {
               punteroImagen->modificaPixeldeMatriz(fila, columna, 255, 255, 255);
            }
        }
    }
}

void Editor::colorearSuperficie(vector<vector<bool>> region)
{
    for(int fila=0; fila<punteroImagen->getFilas(); fila++)
    {
        for(int columna=0; columna<punteroImagen->getColumnas(); columna++)
        {
            if(region[fila][columna])
            {
                punteroImagen->modificaPixeldeMatriz(fila, columna, 0, 0, 255);
            }
        }
    }

}

Editor::~Editor()
{

}
