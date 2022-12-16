#ifndef AIC_H
#define AIC_H
#include "archivo.h"

class AIC: public Archivo
{
private:
    fstream archivo;
public:
    AIC();
    void leer(Imagen *imagen, string ruta) override;
    void guardar(Imagen *imagen, string ruta, string ID) override;
    ~AIC() override;
};

#endif // AIC_H
