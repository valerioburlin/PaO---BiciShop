#ifndef CERCABICI_H
#define CERCABICI_H

#include <QtGui>
#include "shop.h"
#include "tabella.h"

class CercaBici : public QDialog {
    Q_OBJECT
  private:
    Shop& shop;
    Tabella* tab;

    QComboBox* scelta;
    QLineEdit* marca;
    QComboBox* tipo;
    QCheckBox* telaio;
    QCheckBox* freni;

  public:
    explicit CercaBici(Shop& ,Tabella* ,QWidget* =0);

  private slots:
    void cambiaScelta(QString );
    void search();

  signals:

};

#endif
