/*!
 *  \class      Editor
 *  \brief      Clase que edita la información de los píxeles de un objeto imagen.
 *  \details    Esta clase permite aplicar distintos filtros y ajustes a un objeto imagen. Es capaz de colorear superficies detectadas en una imagen.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef EDITOR_H
#define EDITOR_H
#include "iostream"
#include "imagen.h"
#include "lut.h"
#include "pixel.h"
#include "analizador.h"
#include "filtro.h"
#include "mediana.h"
#include "pasabajos.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Editor
{
private:
    LUT lut; /// \param lut Instancia de la clase LUT que permite acceder a la tabla de valores del filtro de pseudocoloreo.
    Filtro *punteroFiltro; /// \param punteroFiltro Puntero de la clase Filtro que permite utilizar una clase heredera de Filtro por upcasting para filtrar una imagen.
    Imagen *punteroImagen; /// \param punteroImagen Puntero de la clase Imagen que permite acceder a la imagen manipulada y sus métodos.
public:
    Editor();
    /*!
     * \brief      setImagen Este método permite dar al puntero Imagen la dirección de la imagen en manipulación.
     * \param[in]  newImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     */
    void setImagen(Imagen *newPunteroImagen);

    /*!
     * \brief      pseudocolorear Este método permite modificar el mapa de colores de la imagen manipulada mediante la tabla de valores obtenida desde la instancia lut.
     * \param[in]  rutaLUT String que contiene la ruta del archivo de extensión .lut.
     */
    void pseudocolorear(string rutaLUT);

    /*!
     * \brief      aplicarMediana Este método permite aplicar el filtro de mediana a una imagen.
     */
    void aplicarMediana();

    /*!
     * \brief      aplicarPasaBajos Este método permite aplicar el filtro de pasa bajos o suavizado a una imagen.
     */
    void aplicarPasaBajos();

    /*!
     * \brief      ajustarBrillo Este método permite subir o bajar el brillo de una imagen modificando la intensidad de los píxeles.
     * \param[in]  cantidad Entero que indica la cantidad de brillo a subir o bajar siendo positivo o negativo respectivamente.
     */
    void ajustarBrillo(int cantidad);

    /*!
     * \brief      ajustarContraste Este método ajustar el contraste de una imagen.
     */
    void ajustarContraste();

    /*!
     * \brief      aplicarNegativo Este método aplica el efecto de negativo a una imagen.
     */
    void aplicarNegativo();

    /*!
     * \brief      binarizar Este método permite binarizar una imagen a partir de una intensidad de referencia.
     * \param[in]  intensidad Entero que indica intensidad de referencia para binarizar.
     */
    void binarizar(int intensidad);

    /*!
     * \brief      colorearSuperficie Este método permite destacar la superficie detectada mediante el coloreo de la misma.
     * \param[in]  region Matriz de booleanos con las dimensiones de la imagen que indica los píxeles identificados como parte de la superficie.
     */
    void colorearSuperficie(vector<vector<bool>> region);

    ~Editor();
};

#endif // EDITOR_H
