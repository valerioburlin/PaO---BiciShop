#ifndef NUOVABICI_H
#define NUOVABICI_H

#include <QtGui>
#include "shop.h"

class NuovaBici : public QDialog {
    Q_OBJECT
  private:
    Shop& shop;

    QLineEdit* marca;
    QComboBox* tipo;
    QCheckBox* telaio;
    QCheckBox* freni;

  public:
    explicit NuovaBici(Shop& ,QWidget* =0);
private slots:
    void cambiaBici(QString );
    void aggiungiBici();
signals:
    void aggiuntaBici();
};

#endif
