#ifndef FILTRO_H
#define FILTRO_H
#include "imagen.h"
#include "pixel.h"
#include <vector>
#include <algorithm>

class Filtro
{
public:
    Filtro();
    virtual void filtrar(Imagen *imagen) = 0;
    virtual ~Filtro();
};

#endif // FILTRO_H
