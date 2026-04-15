#pragma once
#include <iostream>
#ifndef CLASES_H
#define CLASES_H
#endif // !CLASES_H


#define print std::cout


class Animal
{
public:
	virtual std::string getTipo() = 0;
	virtual ~Animal() {}
};




//carlos

class Pez : public Animal
{
public:
	std::string getTipo() override {
		return "Pez";
	}

};

class Oso : public Animal
{
public:
	std::string getTipo() override {
		return "Oso";
	}
	bool getSexo() override {
		return (rand() % 2 == 0) ? true : false;
	}
	int getFuerza() override {
		return rand() % 10;
	}
};






//tucu