#include "gestordearchivos.h"


GestorDeArchivos::GestorDeArchivos()
{

}

void GestorDeArchivos::abrirDirectorio(string raizRuta, bool usarRegistro)
{
    rutaDirectorio = raizRuta;
    string rutaCarpeta = raizRuta+"/"+carpetaActual;
    punteroDirectorio = opendir(rutaCarpeta.c_str());
    if (punteroDirectorio != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entrada;

        while ((entrada = readdir(punteroDirectorio)) != NULL)
        {
            if( entrada->d_name != pto and entrada->d_name != ptopto )
            {
                nombreArchivos.push_back(entrada->d_name);
            }
        }

        /*cout << "Archivos detectados:" << endl;
        for(string& entrada : nombre_archivos)
        {
           cout << "\t" << entrada << endl;
        }*/
        if(!usarRegistro)
        {
            nombreArchivoActual = nombreArchivos[0];
            indice = 0;
        }
        else
        {
            for(int i=0; i<nombreArchivos.size(); i++)
            {
                if(nombreArchivos[i] == nombreArchivoActual)
                {
                    indice = i;
                }
            }
        }
        rutaArchivo = rutaDirectorio+"/"+carpetaActual+"/"+nombreArchivoActual;

    }
    else
    {
        cout<<"ERROR: El directorio no es valido"<<endl;
        exit(0);
    }
    closedir(punteroDirectorio);
}


void GestorDeArchivos::leerArchivo(Imagen *punteroImagen)
{
    string formato = nombreArchivoActual.substr(nombreArchivoActual.find('.')+1);

    if(formato == "aic")
    {
        punteroArchivo = new AIC;

    }
    if(formato == "pnm" || formato == "pgm" || formato == "pbm" || formato == "ppm")
    {
        punteroArchivo = new PNM;

    }
    punteroArchivo->leer(punteroImagen, rutaDirectorio+"/"+carpetaActual+"/"+nombreArchivoActual);
    registrarArchivoActual();
    delete punteroArchivo;
}

void GestorDeArchivos::guardarArchivo(Imagen *punteroImagen, string nombre, string formato, string ID)
{
    if(formato == "aic")
    {
        punteroArchivo = new AIC;
        punteroArchivo->guardar(punteroImagen, rutaDirectorio+"//"+"grupo_imagenes_4_nuevas"+"//"+nombre+"."+formato, ID);
        delete punteroArchivo;
    }
    if(formato == "pnm" || formato == "pgm" || formato == "pbm" || formato == "ppm")
    {
        punteroArchivo = new PNM;
        punteroArchivo->guardar(punteroImagen, rutaDirectorio+"//"+"grupo_imagenes_4_nuevas"+"//"+nombre+"."+formato, ID);
        delete punteroArchivo;
    }
}

void GestorDeArchivos::cambiarArchivoActual(bool avanzar)
{
    if(avanzar && indice < nombreArchivos.size()-1)
    {
        indice++;
        nombreArchivoActual = nombreArchivos[indice];
    }
    else if(!avanzar && indice > 0)
    {
        indice--;
        nombreArchivoActual = nombreArchivos[indice];
    }
    else
    {
        cout<<"Error de indice: Ya no hay mas archivos en esa direccion."<<endl;
    }
}

void GestorDeArchivos::registrarArchivoActual()
{
    registroUltimaImagen.open("registro.txt", ios::out | ios::trunc);

    string aux = rutaDirectorio+"//"+carpetaActual+"//"+nombreArchivoActual;
    registroUltimaImagen<< aux.c_str();

    registroUltimaImagen.close();
}

bool GestorDeArchivos::recuperarUltimoArchivo()
{
    registroUltimaImagen.open("registro.txt", ios::in);
    if(!registroUltimaImagen.is_open())
    {
        return false;
    }
    else
    {
        registroUltimaImagen.seekg(0, ios::end);
        int tamanio = registroUltimaImagen.tellg();
        if(tamanio==0)
        {
            return false;
        }
        else
        {
            registroUltimaImagen.seekg(0, ios::beg);

            getline(registroUltimaImagen, rutaArchivo);

            size_t posicion;
            posicion = rutaArchivo.find("grupo_imagenes_1");

            if (posicion!=string::npos)
            {
                setCarpetaActual("grupo_imagenes_1");
            }
            else
            {
                posicion = rutaArchivo.find("grupo_imagenes_2");

                if (posicion!=string::npos)
                {
                    setCarpetaActual("grupo_imagenes_2");
                }
                else
                {
                    posicion = rutaArchivo.find("grupo_imagenes_3_corruptas");

                    if (posicion!=string::npos)
                    {
                        setCarpetaActual("grupo_imagenes_3_corruptas");
                    }
                    else
                    {
                        posicion = rutaArchivo.find("grupo_imagenes_4_nuevas");

                        if (posicion!=string::npos)
                        {
                            setCarpetaActual("grupo_imagenes_4_nuevas");
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }

            nombreArchivoActual = rutaArchivo.substr(rutaArchivo.find(carpetaActual)+carpetaActual.size()+2);

            registroUltimaImagen.close();

            return true;
        }
    }
}

const string &GestorDeArchivos::getRutaDirectorio() const
{
    return rutaDirectorio;
}

void GestorDeArchivos::setCarpetaActual(string nombreCarpeta)
{
    carpetaActual = nombreCarpeta;
}

GestorDeArchivos::~GestorDeArchivos()
{

}
