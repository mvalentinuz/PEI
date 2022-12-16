#include "pnm.h"

PNM::PNM()
{

}

void PNM::leer(Imagen *imagen, string ruta)
{
    archivo.open(ruta, ios::binary | ios::in);
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
        if(imagen->getId()!="P1" && imagen->getId()!="P4")
        {
        getline(archivo, linea);
        imagen->setValorMaximo(stoi(linea));
        }

        int R=0, G=0, B=0, monocromo=0;

        if(imagen->getId()=="P1" || imagen->getId()=="P2")
        {
            for(int f=0; f<imagen->getFilas(); f++)
            {
                for(int c=0; c<imagen->getColumnas(); c++)
                {
                    archivo>>monocromo;

                    imagen->modificaPixeldeMatriz(f,c,monocromo,monocromo,monocromo);
                }
            }
        }

        if(imagen->getId()=="P3")
        {
            for(int f=0; f<imagen->getFilas(); f++)
            {
                for(int c=0; c<imagen->getColumnas(); c++)
                {
                    archivo>>R>>G>>B;

                    imagen->modificaPixeldeMatriz(f,c,R,G,B);
                }
            }
        }

        if(imagen->getId()=="P4" || imagen->getId()=="P5")
        {
            for(int f=0; f<imagen->getFilas(); f++)
            {
                for(int c=0; c<imagen->getColumnas(); c++)
                {
                    archivo.read((char*)&monocromo, 1);

                    imagen->modificaPixeldeMatriz(f,c,monocromo,monocromo,monocromo);
                }
            }
        }

        if(imagen->getId()=="P6")
        {
            for(int f=0; f<imagen->getFilas(); f++)
            {
                for(int c=0; c<imagen->getColumnas(); c++)
                {
                    archivo.read((char*)&R, 1);
                    archivo.read((char*)&G, 1);
                    archivo.read((char*)&B, 1);

                    imagen->modificaPixeldeMatriz(f,c,R,G,B);
                }
            }
        }
    }
    archivo.close();
}

void PNM::guardar(Imagen *imagen, string ruta, string ID)
{
    archivo.open(ruta, ios::binary | ios::out);
    if(!archivo.is_open())
    {
        cout<<"El archivo no se abrio correctamente"<<endl;
    }
    else
    {
        archivo.seekg(0, ios::beg);

        archivo<<ID.c_str()<<endl;
        archivo<<imagen->getMetadatos()<<endl;
        archivo<<imagen->getColumnas()<<" "<<imagen->getFilas()<<endl;

        if(imagen->getId()!="P1" && imagen->getId()!="P4")
        {
        archivo<<imagen->getValorMaximo()<<endl;
        }

        int R=0, G=0, B=0;
        Pixel pixel;

        if(ID=="P1" || ID=="P2")
        {
            for(int f=0; f<imagen->getFilas(); f++)
            {
                for(int c=0; c<imagen->getColumnas(); c++)
                {
                    pixel = imagen->getPixel(f,c);

                    archivo<<pixel.getR();
                }
            }
        }

        if(ID=="P3")
        {
            for(int f=0; f<imagen->getFilas(); f++)
            {
                for(int c=0; c<imagen->getColumnas(); c++)
                {
                    pixel = imagen->getPixel(f,c);
                    R = pixel.getR();
                    G = pixel.getG();
                    B = pixel.getB();

                    archivo<<R<<G<<B;
                }
            }
        }

        if(ID=="P4" || ID=="P5")
        {
            for(int f=0; f<imagen->getFilas(); f++)
            {
                for(int c=0; c<imagen->getColumnas(); c++)
                {
                    pixel = imagen->getPixel(f,c);
                    R = pixel.getR();
                    archivo.write((char*)&R, 1);
                }
            }
        }

        if(ID=="P6")
        {
            for(int f=0; f<imagen->getFilas(); f++)
            {
                for(int c=0; c<imagen->getColumnas(); c++)
                {
                    pixel = imagen->getPixel(f,c);
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
            cout<<"Error de lectura: ID no valido"<<endl;
        }
    }
    archivo.close();
}

PNM::~PNM()
{

}
