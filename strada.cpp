#include "strada.h"

double Strada::sovraprezzoStrada = 150.0;


Strada::Strada(string s,bool f) : Bici(s) , telaioCarb(f) {}


bool Strada::haTelaioCarb() const { return telaioCarb; }


void Strada::setTelaio(bool f) { telaioCarb = f; }


double Strada::getSovraprezzoStrada() const { return sovraprezzoStrada; }


double Strada::prezzo() const {
    if(telaioCarb)
		return (getPrezzoBase() + sovraprezzoStrada) * 1.5;
	else
		return getPrezzoBase() + sovraprezzoStrada;
}
