#ifndef PNM_H
#define PNM_H
#include "archivo.h"

class PNM: public Archivo
{
private:
    //fstream archivo;
public:
    PNM();
    void leer(Imagen *imagen, string ruta) override;
    void guardar(Imagen *imagen, string ruta) override;
    ~PNM() override;
};

#endif // PNM_H
