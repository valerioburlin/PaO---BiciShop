#include "myMainWindow.h"

MyMainWindow::MyMainWindow(Shop& bs, QWidget *parent) : QMainWindow(parent) , biciShop(bs) {
    setGeometry(200,140,900,500);
    setWindowTitle("Bici Shop");

    QMenu* file = new QMenu("File",this);
    menuBar()->addMenu(file);

    QAction* inserisci = new QAction("Nuova Bici",this);
    file->addAction(inserisci);
    connect(inserisci,SIGNAL(triggered()),this,SLOT(addBici()));

    QAction* cerca = new QAction("Cerca Bici",this);
    file->addAction(cerca);
    connect(cerca,SIGNAL(triggered()),this,SLOT(cercaBici()));

    tab = new Tabella(biciShop,this);
    setCentralWidget(tab);
    for(int i=0; i<biciShop.getSize(); i++)
    {
        BiciItem* bi = new BiciItem(biciShop.getBici(i),&biciShop,tab);
        tab->inserisciElemento(bi);
    }

    QStatusBar* statbar = new QStatusBar(this);

    QPushButton* aggiorna = new QPushButton("Aggiorna",this);
    connect(aggiorna,SIGNAL(clicked()),tab,SLOT(refresh()));

    QPushButton* elimina = new QPushButton("Elimina",this);
    connect(elimina,SIGNAL(clicked()),tab,SLOT(eliminaElemento()));

    QPushButton* quit = new QPushButton("Esci",this);
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    statbar->setFont(QFont("Helvetica",12));
    statbar->addWidget(elimina);
    statbar->addWidget(aggiorna);
    statbar->addWidget(quit);
    setStatusBar(statbar);
}


void MyMainWindow::addBici() {
    NuovaBici* nuova = new NuovaBici(biciShop,this);
    nuova->show();
    connect(nuova,SIGNAL(aggiuntaBici()),centralWidget(),SLOT(refresh()));
}


void MyMainWindow::cercaBici() {
    CercaBici* cerca = new CercaBici(biciShop,tab,this);
    cerca->show();
}
