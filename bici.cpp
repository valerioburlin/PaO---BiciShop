#include "bici.h"

double Bici::prezzo_base = 200.0;


Bici::Bici(string s) : marca(s) {}


Bici::~Bici(){}


void Bici::setMarca(string s) { marca = s; }


string Bici::getMarca() const { return marca; }


double Bici::getPrezzoBase() const { return prezzo_base; }



