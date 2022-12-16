#include "aic.h"

AIC::AIC()
{

}

void AIC::leer(Imagen *imagen, string ruta)
{
    archivo.open(ruta, ios::binary | ios::out);
    if(!archivo.is_open())
    {
        cout<<"El archivo no se abrio correctamente"<<endl;
    }
    else
    {
        string linea;
        archivo.seekg(0, ios::beg);

        getline(archivo, linea);
        imagen->setId(linea);

        getline(archivo, linea);
        imagen->setMetadatos(linea);

        getline(archivo, linea, ' ');
        imagen->setColumnas(stoi(linea));

        getline(archivo, linea);
        imagen->setFilas(stoi(linea));

        imagen->redimensionarMatriz();

        getline(archivo, linea);
        imagen->setValorMaximo(stoi(linea));


        int monocromo = 0, repeticiones = 0, filas = 0, columnas = 0;

        if(imagen->getId()=="P2C")
        {
            while(!archivo.eof())
            {
                archivo>>monocromo;
                archivo>>repeticiones;
                for(int i = 0; i<repeticiones; i++)
                {
                    imagen->modificaPixeldeMatriz(filas,columnas,monocromo,monocromo,monocromo);
                    filas++;
                    columnas++;
                }
            }
        }
        else
        {
            cout<<"Error de lectura: El ID no es valido."<<endl;
        }
    }
    archivo.close();
}

void AIC::guardar(Imagen *imagen, string ruta, string ID)
{
    archivo.open(ruta, ios::binary | ios::out);
    if(!archivo.is_open())
    {
        cout<<"El archivo no se abrio correctamente"<<endl;
    }
    else
    {
        archivo.seekg(0, ios::beg);

        archivo<<"P2C"<<endl;
        archivo<<imagen->getMetadatos()<<endl;
        archivo<<imagen->getColumnas()<<" "<<imagen->getFilas()<<endl;
        archivo<<imagen->getValorMaximo()<<endl;

        int aparicionesEnSerie = 1;
        Pixel pixel, pixelAnterior;

        for(int f=1; f<imagen->getFilas(); f++)
        {
            for(int c=1; c<imagen->getColumnas(); c++)
            {
                pixelAnterior = imagen->getPixel(f-1,c-1);
                pixel = imagen->getPixel(f,c);
                if(pixelAnterior.getR()==pixel.getR())
                {
                    aparicionesEnSerie++;
                }
                else
                {
                    archivo<<pixelAnterior.getR()<<aparicionesEnSerie;
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
