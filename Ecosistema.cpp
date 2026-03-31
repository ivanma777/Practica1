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
 
 
//  parte de santi 22/3, he ido explicando lo que hace cada cosa para que veas mas o menos por donde van los tiros, si hay 
//  algo que veas que esta mal o que piensas que puede ir mejor me dices guapo
 
// Devuelve el num de una celda vacia al azar

//I: La celda vacia aleatoria antes mirama el estado de rio pero no tenia en cuenta si ocurria un paso o no
// lo he cambiado para que mira nuevorio asi tiene en cuenta se ocurrio un paso previo
//lo he hecho por si acaso puede llegar a dar problemas
int Ecosistema::celdaVaciaAleatoria(Animal** estado) const {
    int vacias = 0;
    for (int i = 0; i < tamano; i++)
        if (estado[i] == 0) vacias++;
 
    if (vacias == 0) return -1;
 
    int objetivo = rand() % vacias;
    int contador = 0;
    for (int i = 0; i < tamano; i++) {
        if (estado[i] == 0) {
            if (contador == objetivo) return i;
            contador++;
        }
    }
    return -1;
}
 

void Ecosistema::paso() {
    // Para que no se hagan animales nuevos en el mismo momento
    Animal** nuevoRio = new Animal*[tamano];
    bool*    procesado = new bool[tamano];
 
    for (int i = 0; i < tamano; i++) {
        nuevoRio[i]  = nullptr;
        procesado[i] = false;
    }
 
    for (int i = 0; i < tamano; i++) {
        if (rio[i] == nullptr || procesado[i]) continue;
 
        Animal* animal = rio[i];
        procesado[i] = true;
 
        // 50% se mueve o no
        bool semueve = (rand() % 2 == 0);
 
        int destino = i;
        if (semueve) {
            int dir = (rand() % 2 == 0) ? -1 : 1; // 50% izq o der
            int candidato = i + dir;
            if (candidato >= 0 && candidato < tamano)
                destino = candidato;
            // Si sale del array se queda en su lugar
        }
 
        // Posiconar al animal en su destino
        if (nuevoRio[destino] == nullptr) {
            // Celda libre se crea el animal
            nuevoRio[destino] = animal;
        } else {
            // Chocan dos animales 
            Animal* residente = nuevoRio[destino];
 
            if (residente->getTipo() == animal->getTipo() ) {
                //mismo sexo , se quedan donde estan y aparece nuevo individuo
                if (residente->getSexo() != animal->getSexo()) {
                
                    // Mismo tipo, ambos se quedan donde estaban
                    if (nuevoRio[i] == nullptr)
                        nuevoRio[i] = animal;
                    else
                        delete animal; 

 
                    // Nace un nuevo animal en celda vacía aleatoria
                    int libre = celdaVaciaAleatoria(nuevoRio);
                    if (libre != -1) {
                        if (residente->getTipo() == "Pez")
                            nuevoRio[libre] = new Pez();
                        else
                            nuevoRio[libre] = new Oso();
                    }
                }//añado caso de la fuerza
                else {
                    if (animal ->getFuerza() > residente->getFuerza()) {
                        // El animal más fuerte se queda, el otro muere
                        delete residente;
                        nuevoRio[destino] = animal;
                    } 
                    else 
                    {
                        if (animal->getFuerza() == residente->getFuerza())
                        {
                            nuevoRio[i] = animal;

                        }
                        else {

                            delete animal; // el animal que intenta entrar muere
                        }
					}
                }

            } 
           
            
            else {
                // Oso contra Pez 
                if (animal->getTipo() == "Oso") {
                    delete residente;           // el pez  muere
                    nuevoRio[destino] = animal; // el oso se mueve a la celda
                } else {
                    // pez mueres y el oso se queda
                    delete animal;
                }
            }
        }
    }
 
    // Para reiniciar lo del rio
    delete[] rio;
    rio = nuevoRio;
    delete[] procesado;
}
 