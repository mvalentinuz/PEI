/*!
 *  \class      LUT
 *  \brief      Clase que carga y devuelve la tabla de valores de un archivo LUT.
 *  \details    Esta clase accede a un archivo con extensión .lut para extraer su tabla que posteriormente modificará el mapa de colores de una imagen.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef LUT_H
#define LUT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class LUT
{
private:
    vector<vector<int>> tabla; /// \param tabla Matriz de vectores que guarda la tabla de valores para modificar el mapa de colores de una imagen.
public:
    LUT();
    /*!
     * \brief      cargarLUT Este método permite cargar la tabla de valores de un archivo de extensión .lut.
     * \param[in]  ruta String que contiene la ruta del archivo .lut.
     */
    void cargarLUT(string ruta);

    /*!
     * \brief      getTabla Getter de la tabla de valores del LUT.
     * \return     Retorna un vector STL de vectores STL de enteros (vector<vector<int>).
     */
    const vector<vector<int> > &getTabla() const;

    ~LUT();
};

#endif // LUT_H
