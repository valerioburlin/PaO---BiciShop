#ifndef STRADA_H
#define STRADA_H

#include "bici.h"

class Strada : public Bici {
  private:
  	bool telaioCarb;
  	static double sovraprezzoStrada;

  public:
    Strada(string ="",bool =0);

  	bool haTelaioCarb() const;
  	void setTelaio(bool );

  	double getSovraprezzoStrada() const;

  	virtual double prezzo() const;
};

#endif
