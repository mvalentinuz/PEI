/*!
 *  \class      Imagen
 *  \brief      Clase que contiene y gestiona los datos y valores de píxeles.
 *  \details    Esta clase posee, edita y devuelve los datos leídos de un archivo de imagen.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef IMAGEN_H
#define IMAGEN_H
#include <string>
#include <vector>
#include "pixel.h"

using namespace std;

class Imagen
{
private:
    string ID; /// \param id Almacena el ID característico de la imagen.
    string metadatos; /// \param metadatos Almacena los metadatos de la imagen.
    int columnas = 0; /// \param columnas Almacena la cantidad de columnas de la imagen.
    int filas = 0; /// \param filas Almacena la cantidad de filas de la imagen.
    int valorMaximo; /// \param valorMaximo Almacena el valor máximo del rango dinámico de la imagen.
    vector<vector<Pixel>> matriz; /// \param matriz Matriz de vectores de píxeles que ordena los mismos para formar la imagen.

public:
    Imagen();
    /*!
     * \brief      getId Getter de la variable ID.
     * \return     Retorna un string (string).
     */
    const string &getId() const;

    /*!
     * \brief      setId Este método permite establecer el ID de la imagen.
     * \param[in]  newId String que contiene el ID.
     */
    void setId(const string &newId);

    /*!
     * \brief      getMetadatos Getter de la variable metadatos.
     * \return     Retorna un string (string).
     */
    const string &getMetadatos() const;

    /*!
     * \brief      setMetadatos Este método permite establecer los metadatos de la imagen.
     * \param[in]  newMetadatos String que contiene los metadatos.
     */
    void setMetadatos(const string &newMetadatos);

    /*!
     * \brief      getColumnas Getter de la variable columnas.
     * \return     Retorna un entero (int).
     */
    int getColumnas() const;

    /*!
     * \brief      setColumnas Este método permite establecer las columnas de la imagen.
     * \param[in]  newColumnas Entero positivo que contiene las columnas de la imagen.
     */
    void setColumnas(unsigned int newColumnas);

    /*!
     * \brief      getFilas Getter de la variable filas.
     * \return     Retorna un entero (int).
     */
    int getFilas() const;

    /*!
     * \brief      setFilas Este método permite establecer las filas de la imagen.
     * \param[in]  newFilas Entero positivo que contiene las filas de la imagen.
     */
    void setFilas(unsigned int newFilas);

    /*!
     * \brief      getValorMaximo Getter de la variable rutaDirectorio.
     * \return     Retorna un flotante (float).
     */
    int getValorMaximo() const;

    /*!
     * \brief      setValorMaximo Este método permite establecer el valor maximo del rango dinámico de la imagen.
     * \param[in]  newValorMaximo Entero que contiene el valor maximo del rango dinámico de la imagen.
     */
    void setValorMaximo(int newValorMaximo);

    /*!
     * \brief      getPixel Este método permite obtener el píxel de una determinada posición de la matriz de píxeles.
     * \param[in]  fila Entero que contiene la fila del píxel deseado.
     * \param[in]  columna Entero que contiene la columna del píxel deseado.
     * \return     Retorna un objeto Pixel.
     */
    Pixel getPixel(int fila,int columna) const;

    /*!
     * \brief      modificaPixeldeMatriz Este método permite modificar los valores de un píxel de una determinada posición de la matriz de píxeles.
     * \param[in]  fila Entero que contiene la fila del píxel deseado.
     * \param[in]  columna Entero que contiene la columna del píxel deseado.
     * \param[in]  R Entero que contiene el nuevo valor R del píxel.
     * \param[in]  G Entero que contiene el nuevo valor G del píxel.
     * \param[in]  B Entero que contiene el nuevo valor B del píxel.
     */
    void modificaPixeldeMatriz(int fila, int columna, int R, int G, int B);

    /*!
     * \brief      redimensionarMatriz Este método permite establecer la cantidad de filas y columnas de la matriz de píxeles.
     */
    void redimensionarMatriz();

    ~Imagen();
};

#endif // IMAGEN_H
