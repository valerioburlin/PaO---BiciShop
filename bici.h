#ifndef BICI_H
#define BICI_H

#include <string>
using std::string;

class Bici {
  private:
  	string marca;
  	static double prezzo_base;

  public:
  	Bici(string ="" );
    virtual ~Bici();

  	void setMarca(string );

  	string getMarca() const;
  	double getPrezzoBase() const;

  	virtual double prezzo() const = 0;
};


#endif 
