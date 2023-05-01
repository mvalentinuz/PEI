/*!
 *  \class      AIC
 *  \brief      Clase que manipula archivos de formato pnm.
 *  \details    Esta clase accede a un archivo con extensión .pnm para extraer sus datos en un objeto imagen o bien guarda los datos de una imagen en formato pnm.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef PNM_H
#define PNM_H
#include "archivo.h"

class PNM: public Archivo
{
private:
    fstream archivo; /// \param archivo Permite abrir el archivo para lectura o escritura.
public:
    PNM();
    /*!
     * \brief      leer Este método heredado de la clase Archivo permite leer un archivo en formato PNM.
     * \param[in]  punteroImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     * \param[in]  ruta String que contiene la ruta del archivo de imagen a leer.
     */
    void leer(Imagen *punteroImagen, string ruta) override;

    /*!
     * \brief      guardar Este método heredado de la clase Archivo permite guardar un archivo en formato PNM.
     * \param[in]  punteroImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     * \param[in]  ruta String que contiene la ruta del archivo de imagen a leer.
     * \param[in]  ID String que contiene el ID característico de la imagen a leer.
     */
    void guardar(Imagen *punteroImagen, string ruta, string ID) override;

    ~PNM() override;
};

#endif // PNM_H
