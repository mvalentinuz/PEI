#ifndef PASABAJOS_H
#define PASABAJOS_H
#include "filtro.h"

class PasaBajos: public Filtro
{
public:
    PasaBajos();
    void filtrar(Imagen *imagen) override;
    ~PasaBajos() override;
};

#endif // PASABAJOS_H
