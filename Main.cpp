#include "Ecosistema.h"
#include <iostream>

int main() {
    Ecosistema eco(15);

    eco.inicializar();

    std::cout << "Estado inicial:" << std::endl;
    eco.mostrar();

    const int PASOS = 10;
    for (int i = 1; i <= PASOS; i++) {
        eco.paso();
        std::cout << "Paso " << i << ":      ";
        eco.mostrar();
    }

    return 0;
}