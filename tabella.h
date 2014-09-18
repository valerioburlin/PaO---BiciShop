#include <QtGui>
#include <QTableWidget>
#include "shop.h"
#include "biciItem.h"

#ifndef TABELLA_H
#define TABELLA_H

class Tabella : public QTableWidget {
	Q_OBJECT
  private:
    Shop& biciShop;

  public:
    Tabella(Shop& , QWidget* =0);

    void getTab(vettore<int> );

  public slots:
    void inserisciElemento(BiciItem* );

    void eliminaElemento();

    void refresh();
};

#endif
