/*!
 *  \class      Archivo
 *  \brief      Clase abstracta que da herencia a las clases que manipularan archivos de imagen.
 *  \details    Posee las responsabilidades fundamentales de lectura y guardado de un archivo de imagen.
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "imagen.h"


class Archivo
{
public:
    Archivo();
    /*!
     * \brief      leer Este método virtual puro se heredará a una clase polimórfica para codificar la lectura de un archivo de imagen.
     * \param[in]  punteroImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     * \param[in]  ruta String que contiene la ruta del archivo de imagen a leer.
     */
    virtual void leer(Imagen *punteroImagen, string ruta) = 0;

    /*!
     * \brief      guardar Este método virtual puro se heredará a una clase polimórfica para codificar el guardado de un archivo de imagen.
     * \param[in]  punteroImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     * \param[in]  ruta String que contiene la ruta del archivo de imagen a leer.
     * \param[in]  ID String que contiene el ID característico de la imagen a leer.
     */
    virtual void guardar(Imagen *punteroImagen, string ruta, string ID) = 0;

    virtual ~Archivo();

};

#endif // ARCHIVO_H
