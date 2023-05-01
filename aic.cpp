#include "aic.h"

AIC::AIC()
{

}

void AIC::leer(Imagen *punteroImagen, string ruta)
{
    archivo.open(ruta, ios::binary | ios::out);
    if(!archivo.is_open())
    {
        cout<<"El archivo AIC no se abrio correctamente."<<endl;
        exit(0);
    }
    else
    {
        string linea;
        archivo.seekg(0, ios::beg);

        getline(archivo, linea);
        punteroImagen->setId(linea);

        getline(archivo, linea);
        punteroImagen->setMetadatos(linea);

        getline(archivo, linea, ' ');
        punteroImagen->setColumnas(stoi(linea));

        getline(archivo, linea);
        punteroImagen->setFilas(stoi(linea));

        punteroImagen->redimensionarMatriz();

        getline(archivo, linea);
        punteroImagen->setValorMaximo(stoi(linea));


        int monocromo = 0, repeticiones = 0, filas = 0, columnas = 0;

        if(punteroImagen->getId()=="P2C")
        {
            while(!archivo.eof())
            {
                archivo>>monocromo;
                archivo>>repeticiones;
                for(int i = 0; i<repeticiones; i++)
                {
                    punteroImagen->modificaPixeldeMatriz(filas,columnas,monocromo,monocromo,monocromo);
                    filas++;
                    columnas++;
                }
            }
        }
        else
        {
            cout<<"Error de lectura AIC: El ID no es valido."<<endl;
        }
    }
    archivo.close();
}

void AIC::guardar(Imagen *punteroImagen, string ruta, string ID)
{
    archivo.open(ruta, ios::binary | ios::out);
    if(!archivo.is_open())
    {
        cout<<"El archivo AIC no se abrio correctamente"<<endl;
    }
    else
    {
        archivo.seekg(0, ios::beg);

        archivo<<"P2C"<<endl;
        archivo<<punteroImagen->getMetadatos()<<endl;
        archivo<<punteroImagen->getColumnas()<<" "<<punteroImagen->getFilas()<<endl;
        archivo<<punteroImagen->getValorMaximo()<<endl;

        int aparicionesEnSerie = 1;
        Pixel pixel, pixelAnterior;

        for(int f=1; f<punteroImagen->getFilas(); f++)
        {
            for(int c=1; c<punteroImagen->getColumnas(); c++)
            {
                pixelAnterior = punteroImagen->getPixel(f-1,c-1);
                pixel = punteroImagen->getPixel(f,c);
                if(pixelAnterior.getR()==pixel.getR())
                {
                    aparicionesEnSerie++;
                }
                else
                {
                    archivo<<pixelAnterior.getR()<<" "<<aparicionesEnSerie<<" ";
                    aparicionesEnSerie = 1;
                }
            }
        }
    }
    archivo.close();
}

AIC::~AIC()
{

}
