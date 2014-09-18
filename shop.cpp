#include "shop.h"


void Shop::inserisciBici(Bici* b) {
     magazzino.push_back(b);
}

void Shop::eliminaBici(int i) {
     magazzino.erase(i);
}

int Shop::getSize() const { return magazzino.getSize(); }


Bici* Shop::getBici(int i) const { return magazzino[i]; }


vettore<int> Shop::trovaBici(string marca,string tipo,string telaio,string freni) const {
    vettore<int> indici;
    if(marca != "")
    {
        for(int i=0; i<magazzino.getSize(); i++)
        {
            if(magazzino[i]->getMarca() == marca)
                indici.push_back(i);
        }
    }
    if(tipo != "")
    {
        if(tipo == "Strada")
            for(int i=0; i<magazzino.getSize(); i++)
                if(dynamic_cast<Strada*>(magazzino[i]))
                    indici.push_back(i);

        if(tipo == "MTB")
            for(int i=0; i<magazzino.getSize(); i++)
                if(dynamic_cast<MTB*>(magazzino[i]))
                    indici.push_back(i);

    }
    if(telaio == "SI")
    {
        for(int i=0; i<magazzino.getSize(); i++)
        {
            Strada* tmp = dynamic_cast<Strada*>(magazzino[i]);
            if(tmp)
                if(tmp->haTelaioCarb())
                    indici.push_back(i);
        }
    }
    if(telaio == "NO")
    {
        for(int i=0; i<magazzino.getSize(); i++)
        {
            Strada* tmp = dynamic_cast<Strada*>(magazzino[i]);
            if(tmp)
                if( !tmp->haTelaioCarb() )
                    indici.push_back(i);
        }
    }
    if(freni == "SI")
    {
        for(int i=0; i<magazzino.getSize(); i++)
        {
            MTB* tmp = dynamic_cast<MTB*>(magazzino[i]);
            if(tmp)
                if(tmp->haFreniDisco())
                    indici.push_back(i);
        }
    }
    if(freni == "NO")
    {
        for(int i=0; i<magazzino.getSize(); i++)
        {
            MTB* tmp = dynamic_cast<MTB*>(magazzino[i]);
            if(tmp)
                if( !tmp->haFreniDisco() )
                    indici.push_back(i);
        }
    }

    return indici;
}
