#ifndef MEDIANA_H
#define MEDIANA_H
#include "filtro.h"

class Mediana : public Filtro
{
public:
    Mediana();
    void filtrar(Imagen *imagen) override;
    ~Mediana() override;
};

#endif // MEDIANA_H
