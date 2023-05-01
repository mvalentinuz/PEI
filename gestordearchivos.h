/*!
 *  \class      GestorDeArchivos
 *  \brief      Clase que permite acceder a un directorio de archivos y a sus archivos en cuestión.
 *  \details    Esta clase permite el acceso a los archivos de imagen que va a manipular el programa. Coordina la lectura y guardado de imagenes.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include <string>
#include <vector>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "imagen.h"
#include "pnm.h"
#include "aic.h"

using namespace std;

class GestorDeArchivos
{
private:
    DIR *punteroDirectorio; /// \param punteroDirectorio Puntero que permite ejecutar los métodos de la clase DIR para acceder al directorio de archivos.
    Archivo *punteroArchivo; /// \param punteroArchivo Puntero que permite ejecutar los métodos de la clase Archivo.
    vector<string> nombreArchivos; /// \param nombreArchivos Vector que almacena los nombres de los archivos registrados en el directorio.
    string carpetaActual; /// \param carpetaActual Almacena el nombre de la carpeta a la que ingresó el usuario.
    string nombreArchivoActual; /// \param nombreArchivoActual Almacena el nombre del archivo que visualiza el usuario.
    string rutaDirectorio; /// \param rutaDirectorio Almacena la raíz de ruta del directorio de archivos.
    string rutaArchivo; /// \param rutaArchivo Almacena la ruta del archivo.
    fstream registroUltimaImagen; /// \param registroUltimaImagen Almacena el último archivo visualizado por el usuario.
    int indice; /// \param indice Almacena un índice de los archivos en la carpeta para poder controlar el orden de exposición y los límites de la misma.

public:
    GestorDeArchivos();
    /*!
     * \brief      abrirDirectorio Este método permite inicializar el directorio y cargar los archivos de imagen en él.
     * \param[in]  raizRuta String que contiene la ruta del directorio.
     * \param[in]  usarRegistro Booleano que establece si se va a abrir el último archivo visualizado registrado en la anterior ejecución.
     */
    void abrirDirectorio(string raizRuta, bool usarRegistro);

    /*!
     * \brief      leerArchivo Este método permite ejecutar la lectura del archivo de imagen.
     * \param[in]  punteroImagen Puntero de la clase Imagen que permite acceder a sus métodos.
     */
    void leerArchivo(Imagen *punteroImagen);

    /*!
     * \brief      guardarArchivo Este método permite ejecutar el guardado de una imagen en un archivo de imagen.
     * \param[in]  punteroImagen Puntero de la clase Imagen que permite acceder a sus métodos.
     * \param[in]  nombre String que contiene el nombre que tendrá el archivo de imagen al guardar.
     * \param[in]  formato String que contiene el formato en que se va a guardar la imagen.
     * \param[in]  ID String que contiene el ID característico de la imagen.
     */
    void guardarArchivo(Imagen *punteroImagen, string nombre, string formato, string ID);

    /*!
     * \brief      cambiarArchivoActual Este método permite cambiar el archivo en visualización.
     * \param[in]  avanzar Booleano que establece si el nuevo archivo a visualizar es el siguiente o el anterior respecto al original en la lista de archivos cargados.
     */
    void cambiarArchivoActual(bool avanzar);

    /*!
     * \brief      registrarArchivoActual Este método permite registrar el último archivo visualizado.
     */
    void registrarArchivoActual();

    /*!
     * \brief      recuperarUltimoArchivo Este método permite recuperar el último archivo visualizado desde el registro hecho en la anterior ejecución del programa.
     */
    bool recuperarUltimoArchivo();

    /*!
     * \brief      getRutaDirectorio Getter de la variable rutaDirectorio.
     */
    const string &getRutaDirectorio() const;

    /*!
     * \brief      setCarpetaActual Este método permite establecer la carpeta que contiene los archivos de imagen.
     * \param[in]  nombreCarpeta String que contiene el nombre de la carpeta.
     */
    void setCarpetaActual(string nombreCarpeta);

    ~GestorDeArchivos();

};

#endif // GESTORDEARCHIVOS_H
