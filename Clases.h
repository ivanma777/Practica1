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

};






//tucu