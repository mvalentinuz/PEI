#include "interfaz.h"

Interfaz::Interfaz()
{

}

void Interfaz::mostrarInterfaz(QApplication *QApp)
{
    while(true)
    {
        cout<<" ------------- SOFTWARE DE PROCESAMIENTO DIGITAL DE IMAGENES ------------- "<<endl<<endl;

        if(gestor.recuperarUltimoArchivo())
        {
            cout<<"Hay registros de la ultima actividad. Indique si desea abrir el ultimo archivo registrado:"<<endl;
            cout<<"1. Si"<<endl;
            cout<<"0. No"<<endl<<endl;
            bool abrirUltimo;
            cin>>abrirUltimo;

            if(abrirUltimo)
            {
                gestor.abrirDirectorio(rutaDIR, true);
                expositor.setGestor(&gestor);
                indicarAtajos();
                expositor.abrirVentana(500,500,QApp);
            }
            else
            {
                elegirCarpetaDelGestor();
                gestor.abrirDirectorio(rutaDIR, false);
                expositor.setGestor(&gestor);
                indicarAtajos();
                expositor.abrirVentana(500,500,QApp);
            }
        }
        else
        {
            cout<<"No hay registros de una ultima actividad."<<endl;
            elegirCarpetaDelGestor();
            gestor.abrirDirectorio(rutaDIR, false);
            expositor.setGestor(&gestor);
            indicarAtajos();
            expositor.abrirVentana(500,500,QApp);
        }
    }
}

void Interfaz::elegirCarpetaDelGestor()
{
    cout<<endl;
    cout<<"Ingrese el numero de la carpeta a la que desea ingresar: "<<endl<<endl;
    cout<<"1. "<<carpeta1<<endl;
    cout<<"2. "<<carpeta2<<endl;
    cout<<"3. "<<carpeta3<<endl;
    cout<<"4. "<<carpetaDeEdiciones<<endl;
    cout<<endl;

    int opcion;
    cin>> opcion;

    switch(opcion)
    {
    case 1: gestor.setCarpetaActual(carpeta1); break;
    case 2: gestor.setCarpetaActual(carpeta2); break;
    case 3: gestor.setCarpetaActual(carpeta3); break;
    case 4: gestor.setCarpetaActual(carpetaDeEdiciones); break;
    default: cout<<"ERROR: No se ingreso una opcion valida."; exit(0);
    }
}

void Interfaz::indicarAtajos()
{
    cout<<endl;
    cout<<"Atajos de operaciones sobre archivos: "<<endl;
    cout<<"CTRL + Flecha derecha : Pasar al siguiente archivo del directorio."<<endl;
    cout<<"CTRL + Flecha izquierda : Volver al anterior archivo del directorio."<<endl;
    cout<<"CTRL + G : Guardar el archivo."<<endl;
    cout<<endl;

    cout<<"Atajos de analisis de imagen: "<<endl;
    cout<<"CTRL + Click izquierdo : Ejecutar analisis de superficie bajo el cursor."<<endl;
    cout<<"CTRL + H : Mostrar histograma y valores estadisticos de la imagen."<<endl;
    cout<<endl;

    cout<<"Atajos de ajuste de imagen: "<<endl;
    cout<<"CTRL + C : Ajustar el contraste."<<endl;
    cout<<"CTRL + Key_Plus (+) : Subir el brillo."<<endl;
    cout<<"CTRL + Key_Minus (-) : Bajar el brillo."<<endl;
    cout<<endl;

    cout<<"Atajos de filtrado de imagen: "<<endl;
    cout<<"CTRL + S : Aplicar filtro de suavizado."<<endl;
    cout<<"CTRL + M : Aplicar filtro de mediana."<<endl;
    cout<<"CTRL + N : Aplicar filtro negativo."<<endl;
    cout<<"CTRL + B : Binarizar la imagen a partir de una referencia."<<endl;
    cout<<"CTRL + 1 : Aplicar LUT 1."<<endl;
    cout<<"CTRL + 2 : Aplicar LUT 2."<<endl;
    cout<<endl;
}

Interfaz::~Interfaz()
{

}
