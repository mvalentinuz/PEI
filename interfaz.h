/*!
 *  \class      Interfaz
 *  \brief      Clase que se comunica con el usuario indicando funciones de uso. Coordina las operaciones de los objetos fundamentales ante las entradas del usuario.
 *  \details    Esta clase expone por consola un menú de opciones y recibe instrucciones del usuario para ejecutar las responsabilidades del objeto expositor.
 *  \author     Mauro Valentinuz
 *  \version    1.0.0
 *  \date       Fecha de creación: 13-2-2023
 *  \date       Fecha de última modificación: 13-2-2023
 *  \pre
 *  \bug
 *  \warning
 *  \copyright
*/

#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "gestordearchivos.h"
#include "expositor.h"
#include <iostream>
#include <string>
#include <QApplication>

class Interfaz
{
private:
    GestorDeArchivos gestor; /// \param gestor Instancia de la clase GestorDeArchivos que permite acceder a sus métodos.
    Expositor expositor; /// \param expositor Instancia de la clase Expositor que permite acceder a sus métodos.
    string rutaDIR = "../PEI"; /// \param rutaDIR Almacena la raíz de la ruta hacia el directorio.
    string carpeta1 = "grupo_imagenes_1"; /// \param carpeta1 Almacena el nombre de la carpeta 1 que contiene los archivos de imagen.
    string carpeta2 = "grupo_imagenes_2"; /// \param carpeta2 Almacena el nombre de la carpeta 2 que contiene los archivos de imagen.
    string carpeta3 = "grupo_imagenes_3_corruptas"; /// \param carpeta3 Almacena el nombre de la carpeta 3 que contiene los archivos de imagen.
    string carpetaDeEdiciones = "grupo_imagenes_4_nuevas"; /// \param carpetaDeEdiciones Almacena el nombre de la carpeta 4 que contiene los archivos de imagen guardados tras la ejecución del programa.

public:
    Interfaz();

    /*!
     * \brief      mostrarInterfaz Este método permite dar indicaciones al usuario por consola e inicializar las funciones fundamentales del programa.
     * \param[in]  QApp Puntero de la clase QApplication para acceder a sus métodos.
     */
    void mostrarInterfaz(QApplication *QApp);

    /*!
     * \brief      elegirCarpetaDelGestor Este método permite dar indicaciones al usuario por consola para seleccionar la carpeta de archivos de imagen.
     */
    void elegirCarpetaDelGestor();

    /*!
     * \brief      indicarAtajos Este método muestra por consola al usuario todos los atajos de funcionalidades del programa.
     */
    void indicarAtajos();

    ~Interfaz();
};

#endif // INTERFAZ_H
