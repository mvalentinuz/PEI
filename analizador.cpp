#include "analizador.h"

Analizador::Analizador()
{
    funcionRojos.resize(256);
    funcionVerdes.resize(256);
    funcionAzules.resize(256);
    funcionIntensidades.resize(256);
}

void Analizador::setImagen(Imagen *nuevaImagen)
{
    imagen = nuevaImagen;
}

void Analizador::analizar()
{
    Pixel pixel;
    int sumatoria=0, sumatoriaR=0, sumatoriaG=0, sumatoriaB=0;

    if(imagen->getId()=="P3" || imagen->getId()=="P6")
    {
        rojos.clear();
        verdes.clear();
        azules.clear();

        for(int f=0; f<imagen->getFilas(); f++)
        {
            for(int c=0; c<imagen->getColumnas(); c++)
            {
                pixel=imagen->getPixel(f,c);

                rojos.push_back(pixel.getR());
                verdes.push_back(pixel.getG());
                azules.push_back(pixel.getB());

                sumatoriaR+=pixel.getR();
                sumatoriaG+=pixel.getG();
                sumatoriaB+=pixel.getB();
            }
        }
        promedioR=sumatoriaR/(rojos.size());
        promedioG=sumatoriaG/(verdes.size());
        promedioB=sumatoriaB/(azules.size());

        int varianzaR=0, varianzaG=0, varianzaB=0;

        for(unsigned long long i=0; i<rojos.size(); i++)
        {
            varianzaR+=pow(rojos[i]-promedioR, 2);
            varianzaG+=pow(verdes[i]-promedioG, 2);
            varianzaB+=pow(azules[i]-promedioB, 2);
        }

        desvio_estandarR=sqrt(varianzaR/rojos.size());
        desvio_estandarG=sqrt(varianzaG/verdes.size());
        desvio_estandarB=sqrt(varianzaB/azules.size());

        sort(rojos.begin(), rojos.end());
        sort(verdes.begin(), verdes.end());
        sort(azules.begin(), azules.end());

        unsigned long long ultimo = rojos.size()-1;
        minimoR=rojos[0];
        maximoR=rojos[ultimo];
        minimoG=verdes[0];
        maximoG=verdes[ultimo];
        minimoB=azules[0];
        maximoB=azules[ultimo];

        int repeticion_R=0, repeticion_G=0, repeticion_B=0, maxima_repeticion_R=0, maxima_repeticion_G=0, maxima_repeticion_B=0;

        for(unsigned long long i=1; i<rojos.size()-1; i++)
        {
            if(rojos[i]==rojos[i-1]){
                repeticion_R++;
                if(repeticion_R>maxima_repeticion_R)
                {
                    maxima_repeticion_R=repeticion_R;
                    modaR=rojos[i];
                }
            }
            else
            {
                repeticion_R=0;
            }

            if(verdes[i]==verdes[i-1])
            {
                repeticion_G++;
                if(repeticion_G>maxima_repeticion_G)
                {
                    maxima_repeticion_G=repeticion_G;
                    modaG=verdes[i];
                }
            }
            else
            {
                repeticion_G=0;
            }

            if(azules[i]==azules[i-1]){
                repeticion_B++;
                if(repeticion_B>maxima_repeticion_B)
                {
                    maxima_repeticion_B=repeticion_B;
                    modaB=azules[i];
                }
            }
            else
            {
                repeticion_B=0;
            }
        }

        cout<<"promedio R: "<<promedioR<<" promedio G: "<<promedioG<<" promedio B: "<<promedioB<<endl;
        cout<<"desvio R: "<<desvio_estandarR<<" desvio G: "<<desvio_estandarG<<" desvio B: "<<desvio_estandarB<<endl;
        cout<<"moda R: "<<modaR<<" moda G: "<<modaG<<" moda B: "<<modaB<<endl;
        cout<<"maximo R: "<<maximoR<<" maximo G: "<<maximoG<<" maximo B: "<<maximoB<<endl;
        cout<<"minimo R: "<<minimoR<<" minimo G: "<<minimoG<<" minimo B: "<<minimoB<<endl;
    }

    else
    {
        intensidad.clear();
        for(int f=0; f<imagen->getFilas(); f++)
        {
            for(int c=0; c<imagen->getColumnas(); c++)
            {
                pixel=imagen->getPixel(f,c);
                intensidad.push_back(pixel.getR());
                sumatoria+=pixel.getR();
            }
        }

        promedio=sumatoria/(intensidad.size());

        int varianza=0;
        for(unsigned long long i=0; i<intensidad.size(); i++)
        {
            varianza+=pow(intensidad[i]-promedio, 2);
        }

        desvio_estandar=sqrt(varianza/intensidad.size());

        sort(intensidad.begin(), intensidad.end());

        unsigned long long ultimo = intensidad.size()-1;
        minimo=intensidad[0];
        maximo=intensidad[ultimo];

        int repeticion=0, maxima_repeticion=0;

        for(unsigned long long i=1; i<intensidad.size()-1; i++)
        {
            if(intensidad[i]==intensidad[i-1])
            {
                repeticion++;
                if(repeticion>maxima_repeticion)
                {
                maxima_repeticion=repeticion;
                moda=intensidad[i];
                }
            }
            else
            {
                repeticion=0;
            }
        }
        cout<<"promedio: "<<promedio<<endl;
        cout<<"desvio: "<<desvio_estandar<<endl;
        cout<<"moda: "<<moda<<endl;
        cout<<"maximo: "<<maximo<<endl;
        cout<<"minimo: "<<minimo<<endl;
    }
}

void Analizador::generarDatosDeHistograma()
{
    Pixel pixel;
    int R, G, B, intensidad;

    if(imagen->getId()=="P3" || imagen->getId()=="P6")
        for(int f=0; f<imagen->getFilas(); f++)
        {
            for(int c=0; c<imagen->getColumnas(); c++)
            {
                pixel = imagen->getPixel(f,c);
                R=pixel.getR();
                funcionRojos[R]++;
                G=pixel.getG();
                funcionVerdes[G]++;
                B=pixel.getB();
                funcionAzules[B]++;
            }
        }
    else
    {
       for(int f=0; f<imagen->getFilas(); f++)
       {
            for(int c=0; c<imagen->getColumnas(); c++)
            {
                pixel = imagen->getPixel(f,c);
                intensidad = pixel.getR();
                funcionIntensidades[intensidad]++;
            }
        }
    }
}

void Analizador::detectarRegion(int fila, int columna, int tolerancia)
{
    Pixel pixelReferencia = imagen->getPixel(fila, columna);
    region.clear();
    region.resize(imagen->getFilas());
    for(int f=0; f<imagen->getFilas(); f++)
    {
        region[f].resize(imagen->getColumnas());
    }
    areaMapeada = 0;

    algoritmoDelPintor(fila, columna, pixelReferencia, tolerancia);
}

void Analizador::algoritmoDelPintor(int fila, int columna, Pixel referencia, int tolerancia)
{
    if(fila>=0 && fila<imagen->getFilas() && columna<imagen->getColumnas() && columna>=0)
    {
        Pixel pixel = imagen->getPixel(fila, columna);
        int deltaR = sqrt(pow( (pixel.getR() - referencia.getR()) , 2));
        int deltaG = sqrt(pow( (pixel.getG() - referencia.getG()) , 2));
        int deltaB = sqrt(pow( (pixel.getB() - referencia.getB()) , 2));

        if(deltaR<=tolerancia/2 && deltaG<=tolerancia/2 && deltaB<=tolerancia/2 && !region[fila][columna])
        {
            region[fila][columna] = true;
            areaMapeada++;
            algoritmoDelPintor(fila+1, columna+1, referencia, tolerancia);
            algoritmoDelPintor(fila+1, columna-1, referencia, tolerancia);
            algoritmoDelPintor(fila+1, columna, referencia, tolerancia);
            algoritmoDelPintor(fila-1, columna+1, referencia, tolerancia);
            algoritmoDelPintor(fila-1, columna-1, referencia, tolerancia);
            algoritmoDelPintor(fila-1, columna, referencia, tolerancia);
            algoritmoDelPintor(fila, columna+1, referencia, tolerancia);
            algoritmoDelPintor(fila, columna-1, referencia, tolerancia);
        }
    }
}

float Analizador::getPromedio() const
{
    return promedio;
}

const vector<vector<bool> > &Analizador::getRegionDetectada() const
{
    return region;
}

const vector<int> &Analizador::getFuncionRojos() const
{
    return funcionRojos;
}

const vector<int> &Analizador::getFuncionVerdes() const
{
    return funcionVerdes;
}

const vector<int> &Analizador::getFuncionAzules() const
{
    return funcionAzules;
}

const vector<int> &Analizador::getFuncionIntensidades() const
{
    return funcionIntensidades;
}

float Analizador::getFrecuenciaModa() const
{
    int frecuenciaModa=0;

    frecuenciaModa = *max_element(funcionIntensidades.begin(), funcionIntensidades.end());

    return frecuenciaModa;
}

float Analizador::getMayorFrecuenciaModaRGB() const
{
    int frecuenciaModaR=0, frecuenciaModaG=0, frecuenciaModaB=0;

    frecuenciaModaR = *max_element(funcionRojos.begin(), funcionRojos.end());
    frecuenciaModaG = *max_element(funcionVerdes.begin(), funcionVerdes.end());
    frecuenciaModaB = *max_element(funcionAzules.begin(), funcionAzules.end());

    return max({frecuenciaModaR, frecuenciaModaG, frecuenciaModaB});
}

int Analizador::getAreaMapeada() const
{
    return areaMapeada;
}


Analizador::~Analizador()
{

}
