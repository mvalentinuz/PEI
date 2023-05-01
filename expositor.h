/*!
 *  \class      Expositor
 *  \brief      Clase que grafica la imagen en una ventana como también su histograma.
 *  \details    Esta clase permite graficar cada píxel de una imagen logrando visualizarla en su totalidad. Grafica y permite visualizar el histograma de valores RGB. Responde a los atajos de teclado.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef EXPOSITOR_H
#define EXPOSITOR_H
#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QMouseEvent>
#include <vector>
#include "imagen.h"
#include "gestordearchivos.h"
#include "editor.h"
#include "analizador.h"

using namespace std;

class Expositor: public QOpenGLWidget, protected QOpenGLFunctions
{
protected:
    /*!
     * \brief      initializeGL Este método permite la inicialización de OpenGL.
     */
    void initializeGL() override;

    /*!
     * \brief      resizeGL Este método permite dimensionar el viewport de OpenGL.
     * \param[in]  ancho Entero que da un ancho inicial al viewport.
     * \param[in]  alto Entero que da un alto inicial al viewport.
     */
    void resizeGL(int ancho, int alto) override;

    /*!
     * \brief      paintGL Este método permite configurar las matrices de graficación de OpenGL.
     */
    void paintGL() override;

    /*!
     * \brief      keyPressEvent Este método permite establecer comandos ante el evento de identificación de atajos de teclado.
     * \param[in]  evento Puntero de la clase QKeyEvent para a sus métodos.
     */
    void keyPressEvent(QKeyEvent *evento) override;

    /*!
     * \brief      mousePressEvent Este método permite establecer comandos ante el evento de identificación de click de mouse.
     * \param[in]  evento Puntero de la clase QMouseEvent para a sus métodos.
     */
    void mousePressEvent(QMouseEvent *evento) override;

private:
    GestorDeArchivos *punteroGestor; /// \param punteroGestor Puntero de la clase Gestor que permite acceder al Gestor de Archivos y sus métodos.
    Analizador analizador; /// \param analizador Instancia de la clase Analizador que ejecuta sus métodos sobre la imagen manipulada.
    Editor editor; /// \param editor Instancia de la clase Editor que ejecuta sus métodos sobre la imagen manipulada.
    Imagen imagen; /// \param imagen Instancia de la clase Imagen para acceder a la informaciòn y métodos de la imagen en cuestión.
    float escala;  /// \param escala Permite matener las proporciones de la imagen para cualquier ventana.
    float desplx; /// \param desplx Permite desplazar la imagen al centro ventana en el eje x.
    float desply; /// \param desply Permite desplazar la imagen al centro ventana en el eje y.
    bool mostrarHistograma = false; /// \param mostrarHistograma Variable binaria que da a conocer si el histograma ya está siendo expuesto.
public:
    Expositor();
    /*!
     * \brief      setGestor Este método permite dar al puntero GestorDeArchivos la dirección del gestor para acceder a sus métodos.
     * \param[in]  newPunteroGestor Puntero de la clase GestorDeArchivos para acceder al gestor y sus métodos.
     */
    void setGestor(GestorDeArchivos *newPunteroGestor);

    /*!
     * \brief      abrirVentana Este método permite abrir la ventana en donde se va a exponer la imagen.
     * \param[in]  ancho Entero que da un ancho inicial a la ventana.
     * \param[in]  alto Entero que da un alto inicial a la ventana.
     * \param[in]  QApp Puntero de la clase QApplication para acceder a sus métodos.
     */
    void abrirVentana(int ancho, int alto, QApplication *QApp);

    /*!
     * \brief      exponer Este método permite ejecutar el proceso de graficación de los píxeles de la imagen, dibujando la imagen en su totalidad.
     */
    void exponer();

    /*!
     * \brief      graficarHistograma Este método permite ejecutar el proceso de graficación de las funciones de valores RGB del histograma.
     */
    void graficarHistograma();

    ~Expositor();
};

#endif // EXPOSITOR_H
