#ifndef MTB_H
#define MTB_H

#include "bici.h"

class MTB : public Bici {
  private:
  	bool freniDisco;
  	static double sovraprezzoMtb;
  
  public:
    MTB(string ="",bool =0 );

  	bool haFreniDisco() const;
  	void setFreni(bool );

  	double getSovraprezzoMTB() const;

  	virtual double prezzo() const;
};

#endif
