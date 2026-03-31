#pragma once
#ifndef ECOSISTEMA_H
#define ECOSISTEMA_H
 
#endif
 
#include "Clases.h"
 
class Ecosistema {
private:
    Animal** rio;
    int tamano;
 
    int celdaVaciaAleatoria(Animal**) const; // Para crear aniamles en celdas vacias
 
public:
    Ecosistema(int tamano);
    ~Ecosistema();
 
    void inicializar();
    void mostrar();
    void paso();  // ejecuta un paso de tiempo
};
 