#include "gestordearchivos.h"

GestorDeArchivos::GestorDeArchivos()
{

}

void GestorDeArchivos::abrirDirectorio(string ruta)
{
    ruta_directorio = ruta+"\\"+carpetaActual;
    directorio = opendir(ruta_directorio.c_str());
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
    nombreArchivoActual = nombre_archivos[1];
    cout<<nombreArchivoActual<<endl;
    indice = 0;
    }
}


void GestorDeArchivos::leerArchivo(Imagen *imagen)
{
    string aux = nombreArchivoActual;
    string formato = aux.substr(aux.find('.',1)+1);

    if(formato == "aic")
    {
        //archivo = new AIC;
    }
    else
    {
        archivo = new PNM;
    }
    cout<< ruta_directorio+"\\"+nombreArchivoActual<<endl;
    cout<<formato<<endl;

    archivo->leer(imagen, ruta_directorio+"\\"+nombreArchivoActual);

    delete archivo;
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
        cout<<"Error de indice: Ya no hay mas archivos en esa direccion.";
    }
}

void GestorDeArchivos::setCarpetaActual(string nombreCarpeta)
{
    carpetaActual = nombreCarpeta;
}

GestorDeArchivos::~GestorDeArchivos()
{
    closedir(directorio);
}
