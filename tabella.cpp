#include "tabella.h"

Tabella::Tabella(Shop& s, QWidget* parent) : biciShop(s) , QTableWidget(0,5,parent) {
    QStringList str;
    str << "Marca" << "Tipo" << "Telaio in Carbonio" << "Freni a Disco" << "Prezzo";
    setHorizontalHeaderLabels(str);
}


void Tabella::inserisciElemento(BiciItem* bi) {
    int i = rowCount();
    QTableWidget::insertRow(i);

    setCellWidget(i,0,bi->getMarca());
    setCellWidget(i,1,bi->getTipo());
    setCellWidget(i,2,bi->getTelaio());
    setCellWidget(i,3,bi->getFreni());
    setCellWidget(i,4,bi->getPrezzo());
}


void Tabella::eliminaElemento() {
    int i = QTableWidget::currentRow();
    biciShop.eliminaBici(i);
    QTableWidget::removeRow(i);
}


void Tabella::getTab(vettore<int> indici) {
    for(int i=0; i<rowCount(); i++){
         setRowHidden(i,true);
     }
     for(int i=0; i<indici.getSize(); ++i){
         setRowHidden(indici[i],false);
     }
}


void Tabella::refresh() {
    int i = rowCount();
    for( ; i>=0; i--)
        QTableWidget::removeRow(i);

    for(int i=0; i<biciShop.getSize(); i++)
    {
        BiciItem* bi = new BiciItem(biciShop.getBici(i),&biciShop,this);
        inserisciElemento(bi);
    }
}
