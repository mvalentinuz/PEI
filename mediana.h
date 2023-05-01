/*!
 *  \class      Mediana
 *  \brief      Clase que hereda de Filtro y opera sobre los píxeles de una imagen aplicando un efecto normalización de valores RGB.
 *  \details    Esta clase filtra una imagen mediante el estudio de píxeles vecinos para establecer un valor medio y quitar el efecto de sal y pimienta.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef MEDIANA_H
#define MEDIANA_H
#include "filtro.h"

class Mediana : public Filtro
{
public:
    Mediana();
    /*!
     * \brief      filtrar Este método permite aplicar el filtro de mediana sobre una imagen.
     * \param[in]  punteroImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     */
    void filtrar(Imagen *punteroImagen) override;

    ~Mediana() override;
};

#endif // MEDIANA_H
