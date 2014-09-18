#ifndef SHOP_H
#define SHOP_H

#include "vettore.h"
#include "bici.h"
#include "mtb.h"
#include "strada.h"

class Shop {
  private:
    vettore<Bici*> magazzino;

  public:
    void inserisciBici(Bici* );
    void eliminaBici(int );

    int getSize() const;

    Bici* getBici(int ) const;

    vettore<int> trovaBici(string ,string ,string ,string ) const;
};

#endif
