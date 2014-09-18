#include "cercaBici.h"

CercaBici::CercaBici(Shop& s,Tabella* tb,QWidget* p) : QDialog(p) , shop(s) , tab(tb) {
    setWindowTitle("Cerca Bici");
    setModal(true);
    QHBoxLayout* box_cerca = new QHBoxLayout(this);

    scelta = new QComboBox(this);
    scelta->insertItem(0,"Marca");
    scelta->insertItem(1,"Tipo");
    scelta->insertItem(2,"Telaio");
    scelta->insertItem(3,"Freni");
    connect(scelta,SIGNAL(currentIndexChanged(QString)),this,SLOT(cambiaScelta(QString)));

    marca = new QLineEdit(this);

    tipo = new QComboBox(this);
    tipo->insertItem(0,"Strada");
    tipo->insertItem(1,"MTB");
    tipo->setEnabled(false);

    telaio = new QCheckBox(this);
    telaio->setText("Telaio in Carbonio");
    telaio->setEnabled(false);

    freni = new QCheckBox(this);
    freni->setText("Freni a Disco");
    freni->setEnabled(false);

    QPushButton* ok = new QPushButton("OK",this);
    connect(ok,SIGNAL(clicked()),this,SLOT(search()));

    QPushButton* close = new QPushButton("Esci",this);
    connect(close,SIGNAL(clicked()),this,SLOT(close()));

    box_cerca->addWidget(scelta);
    box_cerca->addWidget(marca);
    box_cerca->addWidget(tipo);
    box_cerca->addWidget(telaio);
    box_cerca->addWidget(freni);
    box_cerca->addWidget(ok);
    box_cerca->addWidget(close);
    setLayout(box_cerca);
}


void CercaBici::cambiaScelta(QString t) {
    if(t == "Marca")
    {
        marca->setEnabled(true);
        tipo->setEnabled(false);
        telaio->setEnabled(false);
        freni->setEnabled(false);
    }
    if(t == "Tipo")
    {
        marca->setEnabled(false);
        tipo->setEnabled(true);
        telaio->setEnabled(false);
        freni->setEnabled(false);
    }
    if(t == "Telaio")
    {
        marca->setEnabled(false);
        tipo->setEnabled(false);
        telaio->setEnabled(true);
        freni->setEnabled(false);
    }
    if(t == "Freni")
    {
        marca->setEnabled(false);
        tipo->setEnabled(false);
        telaio->setEnabled(false);
        freni->setEnabled(true);
    }
}


void CercaBici::search() {
    if(marca->isEnabled())
        tab->getTab( (shop.trovaBici( marca->text().toStdString(),"","","") ) );

    if(tipo->isEnabled())
        tab->getTab( (shop.trovaBici( "",tipo->currentText().toStdString(),"","") ) );

    if(telaio->isEnabled())
        if(telaio->isChecked())
            tab->getTab( (shop.trovaBici( "","","SI","") ) );
        else
            tab->getTab( (shop.trovaBici( "","","NO","") ) );

    if(freni->isEnabled())
        if(freni->isChecked())
            tab->getTab( (shop.trovaBici( "","","","SI") ) );
        else
            tab->getTab( (shop.trovaBici( "","","","NO") ) );

    close();
}
