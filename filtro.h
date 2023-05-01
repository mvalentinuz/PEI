/*!
 *  \class      Filtro
 *  \brief      Clase abstracta que da herencia a las clases que aplicaran filtros a un objeto imagen.
 *  \details    Posee las responsabilidades fundamentales de filtrado de un archivo de imagen.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef FILTRO_H
#define FILTRO_H
#include "imagen.h"
#include "pixel.h"
#include <vector>
#include <algorithm>

class Filtro
{
public:
    Filtro();
    /*!
     * \brief      filtrar Este método virtual puro se heredará a una clase polimórfica para codificar el filtrado de una imagen.
     * \param[in]  punteroImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     */
    virtual void filtrar(Imagen *punteroImagen) = 0;

    virtual ~Filtro();
};

#endif // FILTRO_H
