#ifndef AIC_H
#define AIC_H
#include "archivo.h"

class AIC: public Archivo
{
public:
    AIC();
    void leer(Imagen *imagen, string ruta) override;
    void guardar(Imagen *imagen, string ruta) override;
    ~AIC() override;
};

#endif // AIC_H
