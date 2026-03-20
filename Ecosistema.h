#pragma once
#ifndef ECOSISTEMA_H
#define ECOSISTEMA_H

#endif

#include "Clases.h"

class Ecosistema {
private:
    Animal** rio;
    int tamano;

public:
    Ecosistema(int tamano);
    ~Ecosistema();

    void inicializar();
    void mostrar();
};
