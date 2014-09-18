#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QtGui>
#include "shop.h"
#include "tabella.h"
#include "biciItem.h"
#include "nuovaBici.h"
#include "cercaBici.h"


class MyMainWindow : public QMainWindow {
    Q_OBJECT
  private:
    Shop& biciShop;
    Tabella* tab;

  public:
    explicit MyMainWindow(Shop& ,QWidget* = 0);

  public slots:
    void addBici();
    void cercaBici();
};

#endif
