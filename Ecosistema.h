#pragma once
#ifndef ECOSISTEMA_H
#define ECOSISTEMA_H

#endif

#include "Clases.h"

class Ecosistema {
private:
    Animal** rio;
    int tamaño;

public:
    Ecosistema(int tamaño);
    ~Ecosistema();

    void inicializar();
    void mostrar();
};
