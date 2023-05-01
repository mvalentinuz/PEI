/*!
 *  \class      Pixel
 *  \brief      Clase que recibe y devuelve valores RGB.
 *  \details    Esta clase representa la unidad fundamental de una imagen. Conoce sus valores RGB que le darán color.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
private:
    int R; /// \param R Almacena el valor R del píxel.
    int G; /// \param G Almacena el valor G del píxel.
    int B; /// \param B Almacena el valor B del píxel.
public:
    Pixel();
    /*!
     * \brief      getR Getter de la variable R.
     * \return     Retorna un entero (int).
     */
    int getR() const;

    /*!
     * \brief      setR Este método permite establecer el valor R.
     * \param[in]  newR Entero que contiene el valor R.
     */
    void setR(int newR);

    /*!
     * \brief      getG Getter de la variable G.
     * \return     Retorna un entero (int).
     */
    int getG() const;

    /*!
     * \brief      setG Este método permite establecer el valor G.
     * \param[in]  newG Entero que contiene el valor G.
     */
    void setG(int newG);

    /*!
     * \brief      getB Getter de la variable B.
     * \return     Retorna un entero (int).
     */
    int getB() const;

    /*!
     * \brief      setB Este método permite establecer el valor B.
     * \param[in]  newB Entero que contiene el valor B.
     */
    void setB(int newB);

    ~Pixel();
};

#endif // PIXEL_H
