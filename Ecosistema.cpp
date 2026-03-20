#include "Ecosistema.h"
#include "Clases.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Ecosistema::Ecosistema(int tamaño) {
    this->tamaño = tamaño;
    rio = new Animal * [tamaño];

    for (int i = 0; i < tamaño; i++) {
        rio[i] = nullptr; // vacío
    }
}

Ecosistema::~Ecosistema() {
    for (int i = 0; i < tamaño; i++) {
        delete rio[i];
    }
    delete[] rio;
}

void Ecosistema::inicializar() {
    srand(time(0));

    int colocados = 0;

    // 5 peces
    while (colocados < 5) {
        int pos = rand() % tamaño;
        if (rio[pos] == nullptr) {
            rio[pos] = new Pez();
            colocados++;
        }
    }

    colocados = 0;

    // 5 osos
    while (colocados < 5) {
        int pos = rand() % tamaño;
        if (rio[pos] == nullptr) {
            rio[pos] = new Oso();
            colocados++;
        }
    }
}

void Ecosistema::mostrar() {
    for (int i = 0; i < tamaño; i++) {
        if (rio[i] == nullptr)
            std::cout << "[ ] ";
        else if (rio[i]->getTipo() == "Pez")
            std::cout << "[P] ";
        else
            std::cout << "[O] ";
    }
    std::cout << std::endl;
}