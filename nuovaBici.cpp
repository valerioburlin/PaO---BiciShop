#include "nuovaBici.h"

NuovaBici::NuovaBici(Shop& s,QWidget* p) : shop(s) , QDialog(p) {
    setWindowTitle("Inserisci Nuova Bici");
    setModal(true);
    QHBoxLayout* box = new QHBoxLayout(this);

    marca = new QLineEdit(this);

    tipo = new QComboBox(this);
    tipo->insertItem(0,"Strada");
    tipo->insertItem(1,"MTB");
    connect(tipo,SIGNAL(currentIndexChanged(QString)),this,SLOT(cambiaBici(QString)));

    telaio = new QCheckBox(this);
    telaio->setText("Telaio in Carbonio");

    freni = new QCheckBox(this);
    freni->setText("Freni a Disco");
    freni->setEnabled(false);

    QPushButton* ok = new QPushButton("OK",this);
    QPushButton* close = new QPushButton("Esci",this);

    box->addWidget(marca);
    box->addWidget(tipo);
    box->addWidget(telaio);
    box->addWidget(freni);
    box->addWidget(ok);
    box->addWidget(close);
    setLayout(box);
    connect(ok,SIGNAL(clicked()),this,SLOT(aggiungiBici()));
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
}

void NuovaBici::cambiaBici(QString t){
    if(t == "Strada")
    {
        telaio->setEnabled(true);
        freni->setEnabled(false);
    }
    if(t == "MTB")
    {
        telaio->setEnabled(false);
        freni->setEnabled(true);
    }

}

void NuovaBici::aggiungiBici(){
    QString m = marca->text();
    if(tipo->currentText() == "Strada")
    {
        bool t = telaio->checkState();
        shop.inserisciBici(new Strada(m.toStdString(),t));
    }
    if(tipo->currentText() == "MTB")
    {
        bool f=freni->checkState();
        shop.inserisciBici(new MTB(m.toStdString(),f));
    }
    emit aggiuntaBici();
    close();
}




