#include "biciItem.h"

BiciItem::BiciItem(Bici* b, Shop* bs, QWidget* parent) : QObject(parent) , bici(b) , biciShop(bs) {
    marca = new QLineEdit(parent);
    marca->setText(QString::fromStdString(b->getMarca()));

    tipo = new QLabel(parent);
    tipo->setEnabled(false);
    Strada* str = dynamic_cast<Strada*>(b);
    MTB* mtb = dynamic_cast<MTB*>(b);
    if(str)
        tipo->setText("Strada");
    if(mtb)
        tipo->setText("MTB");

    telaio = new QCheckBox(parent);
    telaio->setText("Telaio in Carbonio");
    if(str)
        if(str->haTelaioCarb())
            telaio->setCheckState(Qt::Checked);
        else
            telaio->setCheckState(Qt::Unchecked);
    else
        telaio->setEnabled(false);

    freni = new QCheckBox(parent);
    freni->setText("Freni a Disco");
    if(mtb)
        if(mtb->haFreniDisco())
            freni->setCheckState(Qt::Checked);
        else
            freni->setCheckState(Qt::Unchecked);
    else
        freni->setEnabled(false);

    prezzo = new QLineEdit(parent);
    prezzo->setReadOnly(true);
    prezzo->setText(QString::number(b->prezzo()));

    connect(marca,SIGNAL(textChanged(const QString &)),this,SLOT(changeMarca(const QString&)));
    connect(telaio,SIGNAL(stateChanged(int)),this,SLOT(changeTelaio(int)));
    connect(freni,SIGNAL(stateChanged(int)),this,SLOT(changeFreni(int)));
}


QLineEdit* BiciItem::getMarca() const { return marca; }


QLabel* BiciItem::getTipo() const { return tipo; }


QCheckBox* BiciItem::getTelaio() const { return telaio; }


QCheckBox* BiciItem::getFreni() const { return freni; }


QLineEdit* BiciItem::getPrezzo() const { return prezzo; }


void BiciItem::changeMarca(const QString qs) {
    bici->setMarca(qs.toStdString());
}


void BiciItem::changeTelaio(int x) {
    Strada* str = dynamic_cast<Strada*>(bici);
    if(str)
        str->setTelaio(x);
    prezzo->setText(QString::number(bici->prezzo()));
}


void BiciItem::changeFreni(int x) {
    MTB* mtb = dynamic_cast<MTB*>(bici);
    if(mtb)
        mtb->setFreni(x);
    prezzo->setText(QString::number(bici->prezzo()));
}
