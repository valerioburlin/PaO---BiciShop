#include <QtGui>
#include <QString>
#include "shop.h"

#ifndef BICIITEM_H
#define BICIITEM_H

class BiciItem : public QObject {
	Q_OBJECT
  private:
  	Bici* bici;
    Shop* biciShop;

    QLineEdit* marca;
    QLabel* tipo;
    QCheckBox* telaio;
    QCheckBox* freni;
    QLineEdit* prezzo;

  public:
    BiciItem(Bici* , Shop* , QWidget* =0);

    QLineEdit* getMarca() const;
    QLabel* getTipo() const;
    QCheckBox* getTelaio() const;
    QCheckBox* getFreni() const;
    QLineEdit* getPrezzo() const;

  public slots:
    void changeMarca(const QString );
    void changeTelaio(int );
    void changeFreni(int );
};

#endif
