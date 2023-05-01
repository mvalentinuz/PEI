#include "pnm.h"

PNM::PNM()
{

}

void PNM::leer(Imagen *punteroImagen, string ruta)
{
    archivo.open(ruta, ios::binary | ios::in);
    if(!archivo.is_open())
    {
        cout<<"El archivo PNM no se abrio correctamente."<<endl;
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

        try
        {
            if(punteroImagen->getFilas()==0 || punteroImagen->getColumnas()==0)
                throw true;
        }

        catch (bool corrupto)
        {
            cout<<"ERROR: El archivo PNM leido es corrupto."<<endl;
            exit(0);
        }

        punteroImagen->redimensionarMatriz();
        if(punteroImagen->getId()!="P1" && punteroImagen->getId()!="P4")
        {
            getline(archivo, linea);
            punteroImagen->setValorMaximo(stoi(linea));
        }

        int R=0, G=0, B=0, monocromo=0;

        if(punteroImagen->getId()=="P1" || punteroImagen->getId()=="P2")
        {
            for(int f=0; f<punteroImagen->getFilas(); f++)
            {
                for(int c=0; c<punteroImagen->getColumnas(); c++)
                {
                    archivo>>monocromo;

                    punteroImagen->modificaPixeldeMatriz(f,c,monocromo,monocromo,monocromo);
                }
            }
        }

        if(punteroImagen->getId()=="P3")
        {
            for(int f=0; f<punteroImagen->getFilas(); f++)
            {
                for(int c=0; c<punteroImagen->getColumnas(); c++)
                {
                    archivo>>R>>G>>B;

                    punteroImagen->modificaPixeldeMatriz(f,c,R,G,B);
                }
            }
        }

        if(punteroImagen->getId()=="P4" || punteroImagen->getId()=="P5")
        {
            for(int f=0; f<punteroImagen->getFilas(); f++)
            {
                for(int c=0; c<punteroImagen->getColumnas(); c++)
                {
                    archivo.read((char*)&monocromo, 1);

                    punteroImagen->modificaPixeldeMatriz(f,c,monocromo,monocromo,monocromo);
                }
            }
        }

        if(punteroImagen->getId()=="P6")
        {
            for(int f=0; f<punteroImagen->getFilas(); f++)
            {
                for(int c=0; c<punteroImagen->getColumnas(); c++)
                {
                    archivo.read((char*)&R, 1);
                    archivo.read((char*)&G, 1);
                    archivo.read((char*)&B, 1);

                    punteroImagen->modificaPixeldeMatriz(f,c,R,G,B);
                }
            }
        }
    }
    archivo.close();
}

void PNM::guardar(Imagen *punteroImagen, string ruta, string ID)
{
    if(ID=="P1"||ID=="P2"||ID=="P3"){
        archivo.open(ruta, ios::out);
        if(!archivo.is_open())
        {
            cout<<"El archivo PNM no se abrio correctamente"<<endl;
        }
        else
        {
            archivo.seekg(0, ios::beg);

            archivo<<ID.c_str()<<endl;
            archivo<<punteroImagen->getMetadatos()<<endl;
            archivo<<punteroImagen->getColumnas()<<" "<<punteroImagen->getFilas()<<endl;

            if(punteroImagen->getId()!="P1")
            {
                archivo<<punteroImagen->getValorMaximo()<<endl;
            }

            Pixel pixel;

            if(ID=="P1" || ID=="P2")
            {
                for(int f=0; f<punteroImagen->getFilas(); f++)
                {
                    for(int c=0; c<punteroImagen->getColumnas(); c++)
                    {
                        pixel = punteroImagen->getPixel(f,c);
                        archivo<<pixel.getR()<<" ";
                    }
                }
            }

            if(ID=="P3")
            {
                for(int f=0; f<punteroImagen->getFilas(); f++)
                {
                    for(int c=0; c<punteroImagen->getColumnas(); c++)
                    {
                        pixel = punteroImagen->getPixel(f,c);
                        archivo<<pixel.getR()<<" ";
                        archivo<<pixel.getG()<<" ";
                        archivo<<pixel.getB()<<" ";
                    }
                }
            }
        }
        archivo.close();
    }

    if(ID=="P4"||ID=="P5"||ID=="P6"){
        archivo.open(ruta, ios::binary | ios::out);
        if(!archivo.is_open())
        {
            cout<<"El archivo PNM no se abrio correctamente"<<endl;
        }
        else
        {
            archivo.seekg(0, ios::beg);

            archivo<<ID.c_str()<<endl;
            archivo<<punteroImagen->getMetadatos()<<endl;
            archivo<<punteroImagen->getColumnas()<<" "<<punteroImagen->getFilas()<<endl;

            if(punteroImagen->getId()!="P4")
            {
                archivo<<punteroImagen->getValorMaximo()<<endl;
            }

            int R=0, G=0, B=0;
            Pixel pixel;

            if(ID=="P4" || ID=="P5")
            {
                for(int f=0; f<punteroImagen->getFilas(); f++)
                {
                    for(int c=0; c<punteroImagen->getColumnas(); c++)
                    {
                        pixel = punteroImagen->getPixel(f,c);
                        R = pixel.getR();
                        archivo.write((char*)&R, 1);
                    }
                }
            }

            if(ID=="P6")
            {
                for(int f=0; f<punteroImagen->getFilas(); f++)
                {
                    for(int c=0; c<punteroImagen->getColumnas(); c++)
                    {
                        pixel = punteroImagen->getPixel(f,c);
                        R = pixel.getR();
                        G = pixel.getG();
                        B = pixel.getB();
                        archivo.write((char*)&R, 1);
                        archivo.write((char*)&G, 1);
                        archivo.write((char*)&B, 1);
                    }
                }
            }
            else
            {
                cout<<"Error de guardado PNM: ID no valido"<<endl;
            }
        }
        archivo.close();
    }
}

PNM::~PNM()
{

}
