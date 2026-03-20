#include "Ecosistema.h"
#include "Clases.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Ecosistema::Ecosistema(int tamano) {
    this->tamano = tamano;
    rio = new Animal * [tamano];

    for (int i = 0; i < tamano; i++) {
        rio[i] = nullptr; // void
    }
}

Ecosistema::~Ecosistema() {
    for (int i = 0; i < tamano; i++) {
        delete rio[i];
    }
    delete[] rio;
}

void Ecosistema::inicializar() {
    srand(time(0));

    int colocados = 0;

    // 5 peces
    while (colocados < 5) {
        int pos = rand() % tamano;
        if (rio[pos] == nullptr) {
            rio[pos] = new Pez();
            colocados++;
        }
    }

    colocados = 0;

    // 5 osos
    while (colocados < 5) {
        int pos = rand() % tamano;
        if (rio[pos] == nullptr) {
            rio[pos] = new Oso();
            colocados++;
        }
    }
}

void Ecosistema::mostrar() {
    for (int i = 0; i < tamano; i++) {
        if (rio[i] == nullptr)
            std::cout << "[ ] ";
        else if (rio[i]->getTipo() == "Pez")
            std::cout << "[P] ";
        else
            std::cout << "[O] ";
    }
    std::cout << std::endl;
}