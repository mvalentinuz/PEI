#include "analizador.h"


Analizador::Analizador()
{
    funcionRojos.resize(256);
    funcionVerdes.resize(256);
    funcionAzules.resize(256);
    funcionIntensidades.resize(256);
}

void Analizador::setImagen(Imagen *newPunteroImagen)
{
    punteroImagen = newPunteroImagen;
}

void Analizador::analizar()
{
    Pixel pixel;
    int sumatoria=0, sumatoriaR=0, sumatoriaG=0, sumatoriaB=0;

    if(punteroImagen->getId()=="P3" || punteroImagen->getId()=="P6")
    {
        rojos.clear();
        verdes.clear();
        azules.clear();

        for(int f=0; f<punteroImagen->getFilas(); f++)
        {
            for(int c=0; c<punteroImagen->getColumnas(); c++)
            {
                pixel=punteroImagen->getPixel(f,c);

                rojos.push_back(pixel.getR());
                verdes.push_back(pixel.getG());
                azules.push_back(pixel.getB());

                sumatoriaR+=pixel.getR();
                sumatoriaG+=pixel.getG();
                sumatoriaB+=pixel.getB();
            }
        }
        promedioR=(float)sumatoriaR/((float)rojos.size());
        promedioG=(float)sumatoriaG/((float)verdes.size());
        promedioB=(float)sumatoriaB/((float)azules.size());

        int varianzaR=0, varianzaG=0, varianzaB=0;

        for(unsigned long long i=0; i<rojos.size(); i++)
        {
            varianzaR+=pow(rojos[i]-promedioR, 2);
            varianzaG+=pow(verdes[i]-promedioG, 2);
            varianzaB+=pow(azules[i]-promedioB, 2);
        }

        desvioEstandarR=sqrt(varianzaR/rojos.size());
        desvioEstandarG=sqrt(varianzaG/verdes.size());
        desvioEstandarB=sqrt(varianzaB/azules.size());

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


        for(unsigned long long i=1; i<rojos.size(); i++)
        {
            if(rojos[i]==rojos[i-1]){
                cantidadDeAparicionesValorR++;
                if(cantidadDeAparicionesValorR>maximaAparicionValorR)
                {
                    maximaAparicionValorR=cantidadDeAparicionesValorR;
                    modaR=rojos[i];
                }
            }
            else
            {
                cantidadDeAparicionesValorR=1;
            }

            if(verdes[i]==verdes[i-1])
            {
                cantidadDeAparicionesValorG++;
                if(cantidadDeAparicionesValorG>maximaAparicionValorG)
                {
                    maximaAparicionValorG=cantidadDeAparicionesValorG;
                    modaG=verdes[i];
                }
            }
            else
            {
                cantidadDeAparicionesValorG=1;
            }

            if(azules[i]==azules[i-1]){
                cantidadDeAparicionesValorB++;
                if(cantidadDeAparicionesValorB>maximaAparicionValorB)
                {
                    maximaAparicionValorB=cantidadDeAparicionesValorB;
                    modaB=azules[i];
                }
            }
            else
            {
                cantidadDeAparicionesValorB=1;
            }
        }
    }

    else
    {
        intensidad.clear();
        for(int f=0; f<punteroImagen->getFilas(); f++)
        {
            for(int c=0; c<punteroImagen->getColumnas(); c++)
            {
                pixel=punteroImagen->getPixel(f,c);
                intensidad.push_back(pixel.getR());
                sumatoria+=pixel.getR();
            }
        }

        promedioIntensidad=(float)sumatoria/((float)intensidad.size());

        int varianza=0;
        for(unsigned long long i=0; i<intensidad.size(); i++)
        {
            varianza+=pow(intensidad[i]-promedioIntensidad, 2);
        }

        desvioEstandarIntensidad=sqrt(varianza/intensidad.size());

        sort(intensidad.begin(), intensidad.end());

        unsigned long long ultimo = intensidad.size()-1;
        minimoIntensidad=intensidad[0];
        maximoIntensidad=intensidad[ultimo];

        for(unsigned long long i=1; i<intensidad.size(); i++)
        {
            if(intensidad[i]==intensidad[i-1])
            {
                cantidadDeAparicionesIntensidad++;
                if(cantidadDeAparicionesIntensidad>maximaAparicionDeIntensidad)
                {
                    maximaAparicionDeIntensidad=cantidadDeAparicionesIntensidad;
                    modaIntensidad=intensidad[i];
                }
            }
            else
            {
                cantidadDeAparicionesIntensidad=1;
            }
        }
    }
}

void Analizador::generarDatosDeHistograma()
{
    Pixel pixel;
    int R, G, B, intensidad;

    if(punteroImagen->getId()=="P3" || punteroImagen->getId()=="P6")
        for(int f=0; f<punteroImagen->getFilas(); f++)
        {
            for(int c=0; c<punteroImagen->getColumnas(); c++)
            {
                pixel = punteroImagen->getPixel(f,c);
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
        for(int f=0; f<punteroImagen->getFilas(); f++)
        {
            for(int c=0; c<punteroImagen->getColumnas(); c++)
            {
                pixel = punteroImagen->getPixel(f,c);
                intensidad = pixel.getR();
                funcionIntensidades[intensidad]++;
            }
        }
    }
}

void Analizador::detectarRegion(int fila, int columna, int tolerancia)
{
    Pixel pixelReferencia = punteroImagen->getPixel(fila, columna);
    region.clear();
    region.resize(punteroImagen->getFilas());
    for(int f=0; f<punteroImagen->getFilas(); f++)
    {
        region[f].resize(punteroImagen->getColumnas());
    }
    areaMapeada = 0;
    profundidadRecursiva = 0;
    algoritmoDelPintor(fila, columna, pixelReferencia, tolerancia);
}

void Analizador::algoritmoDelPintor(int fila, int columna, Pixel referencia, int tolerancia)
{
    ++profundidadRecursiva;
    if(profundidadRecursiva<3000){
        if(fila>=0 && fila<punteroImagen->getFilas() && columna<punteroImagen->getColumnas() && columna>=0)
        {
            Pixel pixel = punteroImagen->getPixel(fila, columna);
            int deltaR = sqrt(pow( (pixel.getR() - referencia.getR()) , 2));
            int deltaG = sqrt(pow( (pixel.getG() - referencia.getG()) , 2));
            int deltaB = sqrt(pow( (pixel.getB() - referencia.getB()) , 2));

            if(deltaR<=tolerancia && deltaG<=tolerancia && deltaB<=tolerancia && !region[fila][columna])
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
    --profundidadRecursiva;
}

float Analizador::getPromedioIntensidad() const
{
    return promedioIntensidad;
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

int Analizador::getMayorFrecuenciaIntensidad() const
{
    int frecuenciaModa=0;

    frecuenciaModa = *max_element(funcionIntensidades.begin(), funcionIntensidades.end());

    return frecuenciaModa;
}

int Analizador::getMayorFrecuenciaRGB() const
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

int Analizador::getMaximaAparicionDeIntensidad() const
{
    return maximaAparicionDeIntensidad;
}

int Analizador::getModaIntensidad() const
{
    return modaIntensidad;
}

int Analizador::getMaximaAparicionValorR() const
{
    return maximaAparicionValorR;
}

int Analizador::getModaR() const
{
    return modaR;
}

float Analizador::getPromedioR() const
{
    return promedioR;
}

float Analizador::getPromedioG() const
{
    return promedioG;
}

float Analizador::getPromedioB() const
{
    return promedioB;
}

int Analizador::getModaG() const
{
    return modaG;
}

int Analizador::getModaB() const
{
    return modaB;
}

float Analizador::getDesvioEstandarIntensidad() const
{
    return desvioEstandarIntensidad;
}

float Analizador::getDesvioEstandarR() const
{
    return desvioEstandarR;
}

float Analizador::getDesvioEstandarG() const
{
    return desvioEstandarG;
}

float Analizador::getDesvioEstandarB() const
{
    return desvioEstandarB;
}

int Analizador::getMinimoIntensidad() const
{
    return minimoIntensidad;
}

int Analizador::getMaximoIntensidad() const
{
    return maximoIntensidad;
}

int Analizador::getMinimoR() const
{
    return minimoR;
}

int Analizador::getMaximoR() const
{
    return maximoR;
}

int Analizador::getMinimoG() const
{
    return minimoG;
}

int Analizador::getMaximoG() const
{
    return maximoG;
}

int Analizador::getMinimoB() const
{
    return minimoB;
}

int Analizador::getMaximoB() const
{
    return maximoB;
}

int Analizador::getMaximaAparicionValorG() const
{
    return maximaAparicionValorG;
}

int Analizador::getMaximaAparicionValorB() const
{
    return maximaAparicionValorB;
}


Analizador::~Analizador()
{

}
