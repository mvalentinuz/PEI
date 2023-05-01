/*!
 *  \class      AIC
 *  \brief      Clase que manipula archivos de formato aic.
 *  \details    Esta clase accede a un archivo con extensión .aic para extraer sus datos en un objeto imagen o bien guarda los datos de una imagen en formato aic.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef AIC_H
#define AIC_H
#include "archivo.h"

class AIC: public Archivo
{
private:
    fstream archivo; /// \param archivo Permite abrir el archivo para lectura o escritura.
public:
    AIC();
    /*!
     * \brief      leer Este método heredado de la clase Archivo permite leer un archivo en formato AIC.
     * \param[in]  punteroImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     * \param[in]  ruta String que contiene la ruta del archivo de imagen a leer.
     */
    void leer(Imagen *punteroImagen, string ruta) override;

    /*!
     * \brief      guardar Este método heredado de la clase Archivo permite guardar un archivo en formato AIC.
     * \param[in]  punteroImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     * \param[in]  ruta String que contiene la ruta del archivo de imagen a leer.
     * \param[in]  ID String que contiene el ID característico de la imagen a leer.
     */
    void guardar(Imagen *punteroImagen, string ruta, string ID) override;

    ~AIC() override;
};

#endif // AIC_H
