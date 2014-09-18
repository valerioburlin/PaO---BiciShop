#include "mtb.h"

double MTB::sovraprezzoMtb = 100.0;


MTB::MTB(string s, bool f) : Bici(s) , freniDisco(f) {}


bool MTB::haFreniDisco() const { return freniDisco; }


void MTB::setFreni(bool f) { freniDisco = f; }


double MTB::getSovraprezzoMTB() const { return sovraprezzoMtb; }


double MTB::prezzo() const {
    if(freniDisco)
		return (getPrezzoBase() + sovraprezzoMtb) * 1.3;
	else
		return getPrezzoBase() + sovraprezzoMtb;
}

