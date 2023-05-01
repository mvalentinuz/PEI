/*!
 *  \class      Analizador
 *  \brief      Clase que estudia los datos de un objeto imagen, mapea superficies en la imagen y define las funciones del histograma.
 *  \details    Esta clase realiza cálculos de promedio, desvío estándar, moda, mínimo y máximo valor y máxima aparición de los valores de píxeles en la imagen. Define las curvas de las funciones del histograma. Es capaz de mapear superficies mediante algoritmo del pintor.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef ANALIZADOR_H
#define ANALIZADOR_H
#include "imagen.h"
#include "pixel.h"
#include <vector>
#include <math.h>
#include <algorithm>
#include <initializer_list>
#include <iostream>

using namespace std;

class Analizador
{
private:
    Imagen *punteroImagen; /// \param punteroImagen Puntero de la clase Imagen que permite acceder a la imagen manipulada y sus métodos.

    int minimoIntensidad=255; /// \param minimoIntensidad Almacena el valor de intensidad mínimo registrado entre los píxeles de la imagen.
    int maximoIntensidad=0; /// \param maximoIntensidad Almacena el valor de intensidad máximo registrado entre los píxeles de la imagen.
    int modaIntensidad=0; /// \param modaIntensidad Almacena el valor más frecuente de intensidad entre los píxeles de la imagen.
    float promedioIntensidad=0; /// \param promedioIntensidad Almacena el valor promedio de intensidad calculado de los píxeles de la imagen.
    float desvioEstandarIntensidad=0; /// \param desvioEstandarIntensidad Almacena el desvío estándar de intensidad calculado de los píxeles de la imagen.
    int cantidadDeAparicionesIntensidad=0; /// \param cantidadDeAparicionesIntensidad Se utiliza en la búsqueda del valor más frecuente de intensidad registrando sus apariciones.
    int maximaAparicionDeIntensidad=0; /// \param maximaAparicionDeIntensidad Se utiliza en la búsqueda del valor más frecuente de intensidad registrando la máxima cantidad de apariciones.

    int minimoR=255; /// \param minimoR Almacena el valor R mínimo registrado entre los píxeles de la imagen.
    int maximoR=0; /// \param maximoR Almacena el valor R máximo registrado entre los píxeles de la imagen.
    int modaR=0; /// \param modaR Almacena el valor R más frecuente los píxeles de la imagen.
    float promedioR=0; /// \param promedioR Almacena el valor R promedio calculado de los píxeles de la imagen.
    float desvioEstandarR=0; /// \param desvioEstandarR Almacena el desvío estándar de valores R calculado de los píxeles de la imagen.
    int cantidadDeAparicionesValorR=0; /// \param cantidadDeAparicionesValorR Se utiliza en la búsqueda del valor R más frecuente registrando sus apariciones.
    int maximaAparicionValorR=0; /// \param maximaAparicionValorR Se utiliza en la búsqueda del valor R más frecuente registrando la máxima cantidad de apariciones.

    int minimoG=255; /// \param minimoG Almacena el valor G mínimo registrado entre los píxeles de la imagen.
    int maximoG=0; /// \param maximoG Almacena el valor G máximo registrado entre los píxeles de la imagen.
    int modaG=0; /// \param modaR Almacena el valor G más frecuente los píxeles de la imagen.
    float promedioG=0; /// \param promedioG Almacena el valor G promedio calculado de los píxeles de la imagen.
    float desvioEstandarG=0; /// \param desvioEstandarG Almacena el desvío estándar de valores G calculado de los píxeles de la imagen.
    int cantidadDeAparicionesValorG=0; /// \param cantidadDeAparicionesValorG Se utiliza en la búsqueda del valor G más frecuente registrando sus apariciones.
    int maximaAparicionValorG=0; /// \param maximaAparicionValorG Se utiliza en la búsqueda del valor G más frecuente registrando la máxima cantidad de apariciones.

    int minimoB=255; /// \param minimoB Almacena el valor B mínimo registrado entre los píxeles de la imagen.
    int maximoB=0; /// \param maximoB Almacena el valor B máximo registrado entre los píxeles de la imagen.
    int modaB=0; /// \param modaB Almacena el valor B más frecuente los píxeles de la imagen.
    float promedioB=0; /// \param promedioB Almacena el valor B promedio calculado de los píxeles de la imagen.
    float desvioEstandarB=0; /// \param desvioEstandarB Almacena el desvío estándar de valores B calculado de los píxeles de la imagen.
    int cantidadDeAparicionesValorB=0; /// \param cantidadDeAparicionesValorB Se utiliza en la búsqueda del valor B más frecuente registrando sus apariciones.
    int maximaAparicionValorB=0; /// \param maximaAparicionValorB Se utiliza en la búsqueda del valor B más frecuente registrando la máxima cantidad de apariciones.


    vector<int> rojos; /// \param rojos Este vector almacena todos los valores R registrados en la imagen.
    vector<int> verdes; /// \param verdes Este vector almacena todos los valores G registrados en la imagen.
    vector<int> azules; /// \param azules Este vector almacena todos los valores B registrados en la imagen.
    vector<int> intensidad; /// \param intensidad Este vector almacena todos los valores de intensidad registrados en la imagen.

    vector<int> funcionRojos; /// \param funcionRojos Este vector almacena la curva de valores R en función a su frecuencia de apariciones.
    vector<int> funcionVerdes; /// \param funcionVerdes Este vector almacena la curva de valores G en función a su frecuencia de apariciones.
    vector<int> funcionAzules; /// \param funcionAzules Este vector almacena la curva de valores B en función a su frecuencia de apariciones.
    vector<int> funcionIntensidades; /// \param funcionIntensidades Este vector almacena la curva de valores de intensidades en función a su frecuencia de apariciones.

    int areaMapeada = 0; /// \param areaMapeada Almacena el tamaño de la superficie detectada en unidades de píxeles.
    vector<vector<bool>> region; /// \param region Registra la superficie detectada en una máscara de la imagen original para su posterior coloreo.
    int profundidadRecursiva; /// \param profundidadRecursiva Da un tope a la recursividad del algoritmo de detección de superficies.

public:
    Analizador();
    /*!
     * \brief      setImagen Este método permite dar al puntero Imagen la dirección de la imagen en manipulación.
     * \param[in]  newPunteroImagen Puntero de la clase Imagen para acceder a la imagen manipulada y sus métodos.
     */
    void setImagen(Imagen *newPunteroImagen);

    /*!
     * \brief      analizar Este método ejecuta un análisis de la información de la imagen manipulada registrando los valores de píxeles y calculando sus estadísticas.
     */
    void analizar();

    /*!
     * \brief      generarDatosDeHistograma Este método genera la curva de las funciones del histograma de valores RGB.
     */
    void generarDatosDeHistograma();

    /*!
     * \brief      detectarRegion Este método ejecuta el análisis recursivo de una imagen a partir de una posición en la matriz de píxeles para identificar una superficie desde de una tolerancia dada.
     * \param[in]  fila Variable que indica la fila en donde comenzará el análisis recursivo.
     * \param[in]  columna Variable que indica la columna en donde comenzará el análisis recursivo.
     * \param[in]  tolerancia Variable que indica la tolerancia de referencia para detectar la superficie.
     */
    void detectarRegion(int fila, int columna, int tolerancia);

    /*!
     * \brief      algoritmoDelPintor Este método permite realizar un análisis recursivo de una matriz, conocido como algoritmo del pintor, a partir de un pixel de referencia en la matriz de píxeles para identificar una superficie desde de una tolerancia dada.
     * \param[in]  fila Variable que indica la fila en donde comenzará el análisis recursivo.
     * \param[in]  columna Variable que indica la columna en donde comenzará el análisis recursivo.
     * \param[in]  referencia Pixel en el que inicia el análisis que indica los valores RGB que se tomaran como referencia.
     * \param[in]  tolerancia Variable que indica la tolerancia de referencia para detectar la superficie.
     */
    void algoritmoDelPintor(int fila, int columna, Pixel referencia, int tolerancia);

    /*!
     * \brief      getMaximaAparicionDeIntensidad Getter de la variable maximaAparicionDeIntensidad.
     * \return     Retorna un entero (int).
     */
    int getMaximaAparicionDeIntensidad() const;

    /*!
     * \brief      getMaximaAparicionValorR Getter de la variable maximaAparicionDeValorR.
     * \return     Retorna un entero (int).
     */
    int getMaximaAparicionValorR() const;

    /*!
     * \brief      getMaximaAparicionValorG Getter de la variable maximaAparicionDeValorG.
     * \return     Retorna un entero (int).
     */
    int getMaximaAparicionValorG() const;

    /*!
     * \brief      getMaximaAparicionValorB Getter de la variable maximaAparicionDeValorB.
     * \return     Retorna un entero (int).
     */
    int getMaximaAparicionValorB() const;

    /*!
     * \brief      getPromedioIntensidad Getter de la variable promedioIntensidad.
     * \return     Retorna un flotante (float).
     */
    float getPromedioIntensidad() const;

    /*!
     * \brief      getPromedioR Getter de la variable promedioR.
     * \return     Retorna un flotante (float).
     */
    float getPromedioR() const;

    /*!
     * \brief      getPromedioG Getter de la variable promedioG.
     * \return     Retorna un flotante (float).
     */
    float getPromedioG() const;

    /*!
     * \brief      getPromedioIntensidad Getter de la variable promedioIntensidad.
     * \return     Retorna un flotante (float).
     */
    float getPromedioB() const;

    /*!
     * \brief      getModaIntensidad Getter de la variable modaIntensidad.
     * \return     Retorna un entero (int).
     */
    int getModaIntensidad() const;

    /*!
     * \brief      getModaR Getter de la variable modaR.
     * \return     Retorna un entero (int).
     */
    int getModaR() const;

    /*!
     * \brief      getModaG Getter de la variable modaG.
     * \return     Retorna un entero (int).
     */
    int getModaG() const;

    /*!
     * \brief      getModaB Getter de la variable modaB.
     * \return     Retorna un entero (int).
     */
    int getModaB() const;

    /*!
     * \brief      getMayorFrecuenciaModaIntensidad Devuelve el valor más repetido de intensidad a partir de la función de intensidad del histograma.
     * \return     Retorna un entero (int).
     */
    int getMayorFrecuenciaIntensidad() const;

    /*!
     * \brief      getMayorFrecuenciaRGB Devuelve el valor más repetido de R, G o B a partir de las funciones RGB del histograma.
     * \return     Retorna un entero (int).
     */
    int getMayorFrecuenciaRGB() const;

    /*!
     * \brief      getDesvioEstandarIntensidad Getter de la variable desvioEstandarIntensidad.
     * \return     Retorna un flotante (float).
     */
    float getDesvioEstandarIntensidad() const;

    /*!
     * \brief      getDesvioEstandarR Getter de la variable desvioEstandarR.
     * \return     Retorna un flotante (float).
     */
    float getDesvioEstandarR() const;

    /*!
     * \brief      getDesvioEstandarG Getter de la variable desvioEstandarG.
     * \return     Retorna un flotante (float).
     */
    float getDesvioEstandarG() const;

    /*!
     * \brief      getDesvioEstandarB Getter de la variable desvioEstandarB.
     * \return     Retorna un flotante (float).
     */
    float getDesvioEstandarB() const;

    /*!
     * \brief      getMinimoIntensidad Getter de la variable minimoIntensidad.
     * \return     Retorna un entero (int).
     */
    int getMinimoIntensidad() const;

    /*!
     * \brief      getMaximoIntensidad Getter de la variable maximoIntensidad.
     * \return     Retorna un entero (int).
     */
    int getMaximoIntensidad() const;

    /*!
     * \brief      getMinimoR Getter de la variable minimoR.
     * \return     Retorna un entero (int).
     */
    int getMinimoR() const;

    /*!
     * \brief      getMaximoR Getter de la variable maximoR.
     * \return     Retorna un entero (int).
     */
    int getMaximoR() const;

    /*!
     * \brief      getMinimoG Getter de la variable minimoG.
     * \return     Retorna un entero (int).
     */
    int getMinimoG() const;

    /*!
     * \brief      getMaximoG Getter de la variable maximoG.
     * \return     Retorna un entero (int).
     */
    int getMaximoG() const;

    /*!
     * \brief      getMinimoB Getter de la variable minimoB.
     * \return     Retorna un entero (int).
     */
    int getMinimoB() const;

    /*!
     * \brief      getMaximoB Getter de la variable maximoB.
     * \return     Retorna un entero (int).
     */
    int getMaximoB() const;

    /*!
     * \brief      getFuncionRojos Getter de la variable vector funcionRojos.
     * \return     Retorna un vector STL de enteros (vector<int>).
     */
    const vector<int> &getFuncionRojos() const;

    /*!
     * \brief      getFuncionVerdes Getter de la variable vector funcionVerdes.
     * \return     Retorna un vector STL de enteros (vector<int>).
     */
    const vector<int> &getFuncionVerdes() const;

    /*!
     * \brief      getFuncionAzules Getter de la variable vector funcionAzules.
     * \return     Retorna un vector STL de enteros (vector<int>).
     */
    const vector<int> &getFuncionAzules() const;

    /*!
     * \brief      getFuncionIntensidades Getter de la variable vector funcionIntensidades.
     * \return     Retorna un vector STL de enteros (vector<int>).
     */
    const vector<int> &getFuncionIntensidades() const;

    /*!
     * \brief      getAreaMapeada Getter de la variable areaMapeada.
     * \return     Retorna un entero (int).
     */
    int getAreaMapeada() const;

    /*!
     * \brief      getFuncionIntensidades Getter de la matriz de vectores de booleanos region.
     * \return     Retorna un vector STL de vectores STL de booleanos (vector<vector<bool>>).
     */
    const vector<vector<bool> > &getRegionDetectada() const;

    ~Analizador();
};

#endif // ANALIZADOR_H
