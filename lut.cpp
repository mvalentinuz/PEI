#include "lut.h"

LUT::LUT()
{
    tabla.resize(256);
    for(int fila=0; fila<256; fila++)
    {
        tabla[fila].resize(4);
    }
}

void LUT::cargarLUT(string ruta)
{
    ifstream archivo;

    archivo.open(ruta.c_str());
    if(!archivo.is_open())
    {
        cout<<"Hubo un error abriendo el archivo LUT"<<endl;
    }

    archivo.ignore(100, '\n');

    for(int fila=0; fila<256; fila++)
    {
        for(int columna=0; columna<4; columna++)
        {
            archivo>>tabla[fila][columna];
        }
    }

    archivo.close();
}

const vector<vector<int> > &LUT::getTabla() const
{
    return tabla;
}

LUT::~LUT()
{

}
