#include "gestordearchivos.h"


GestorDeArchivos::GestorDeArchivos()
{

}

void GestorDeArchivos::abrirDirectorio(string ruta)
{
    ruta_directorio = ruta;
    string carpeta = ruta+"//"+carpetaActual;
    directorio = opendir(carpeta.c_str());
    if (directorio != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entrada;

        while ((entrada = readdir(directorio)) != NULL)
        {
            if( entrada->d_name != pto and entrada->d_name != ptopto )
            {
                nombre_archivos.push_back(entrada->d_name);
            }
        }

        cout << "Archivos detectados:" << endl;
        for(string& entrada : nombre_archivos)
        {
            cout << "\t" << entrada << endl;
        }
    nombreArchivoActual = nombre_archivos[0];
    indice = 0;
    }
}


void GestorDeArchivos::leerArchivo(Imagen *imagen)
{
    string aux = nombreArchivoActual;
    string formato = aux.substr(aux.find('.',1)+1);

    if(formato == "aic")
    {
        archivo = new AIC;
        archivo->leer(imagen, ruta_directorio+"//"+carpetaActual+"//"+nombreArchivoActual);
        delete archivo;
    }
    if(formato == "pnm" || formato == "pgm" || formato == "pbm" || formato == "ppm")
    {
        archivo = new PNM;
        archivo->leer(imagen, ruta_directorio+"//"+carpetaActual+"//"+nombreArchivoActual);
        delete archivo;
    }
}

void GestorDeArchivos::guardarArchivo(Imagen *imagen, string nombre, string formato, string ID)
{
    if(formato == "aic")
    {
        archivo = new AIC;
        archivo->guardar(imagen, ruta_directorio+"//"+carpetaDeEdiciones+"//"+nombre+"."+formato, ID);
        delete archivo;
    }
    if(formato == "pnm" || formato == "pgm" || formato == "pbm" || formato == "ppm")
    {
        archivo = new PNM;
        archivo->guardar(imagen, ruta_directorio+"//"+carpetaDeEdiciones+"//"+nombre+"."+formato, ID);
        delete archivo;
    }
    else
    {
        cout<<"Error de guardado: El formato no es valido"<<endl;
    }
}

void GestorDeArchivos::cambiarArchivoActual(bool avanzar)
{
    if(avanzar && indice < nombre_archivos.size()-1)
    {
        indice++;
        nombreArchivoActual = nombre_archivos[indice];
    }
    else if(!avanzar && indice > 0)
    {
        indice--;
        nombreArchivoActual = nombre_archivos[indice];
    }
    else
    {
        cout<<"Error de indice: Ya no hay mas archivos en esa direccion."<<endl;
    }
}

const string &GestorDeArchivos::getRutaDirectorio() const
{
    return ruta_directorio;
}

void GestorDeArchivos::setCarpetaActual(string nombreCarpeta)
{
    carpetaActual = nombreCarpeta;
}

GestorDeArchivos::~GestorDeArchivos()
{
    closedir(directorio);
}
