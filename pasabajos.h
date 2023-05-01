/*!
 *  \class      Pasabajos
 *  \brief      Clase que hereda de Filtro y opera sobre los píxeles de una imagen aplicando un efecto suavizado de valores RGB.
 *  \details    Esta clase filtra una imagen mediante el estudio de píxeles vecinos aplicando un kernel de 3x3 para suavizar los valores de los píxeles de una imagen.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/
#ifndef PASABAJOS_H
#define PASABAJOS_H
#include "filtro.h"

class PasaBajos: public Filtro
{
public:
    PasaBajos();
    /*!
     * \brief      filtrar Este método permite aplicar el filtro de pasa bajos o suavizado sobre una imagen.
     * \param[in]  punteroImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     */
    void filtrar(Imagen *punteroImagen) override;

    ~PasaBajos() override;
};

#endif // PASABAJOS_H
