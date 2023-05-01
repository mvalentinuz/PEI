#include <QCoreApplication>
#include <QApplication>
#include "interfaz.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Interfaz interfaz;
    interfaz.mostrarInterfaz(&a);

    return a.exec();
}
