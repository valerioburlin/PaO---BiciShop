#include <QApplication>
#include "myMainWindow.h"
#include "shop.h"

int main(int argc, char* argv[]) try {
    QApplication app(argc,argv);

    Strada uno("Shimano",false);
    Strada due("Shimano",true);
    Strada tre("Atala",false);
    Strada quattro("Atala",true);
    Strada cinque("Cavalera",false);

    MTB x("Cavalera",false);
    MTB y("Cavalera",true);
    MTB z("Rondine",false);
    MTB k("Rondine",true);
    MTB e("Rondine",false);

    Shop biciShop;

    biciShop.inserisciBici(&uno);
    biciShop.inserisciBici(&due);
    biciShop.inserisciBici(&tre);
    biciShop.inserisciBici(&quattro);
    biciShop.inserisciBici(&cinque);
    biciShop.inserisciBici(&x);
    biciShop.inserisciBici(&y);
    biciShop.inserisciBici(&z);
    biciShop.inserisciBici(&k);
    biciShop.inserisciBici(&e);

    app.setWindowIcon(QIcon("img/icona_bike.jpg"));
    MyMainWindow my(biciShop,0);
    my.show();
    return app.exec();
} catch(FuoriPosizione f) {
    cout << f.Mess()<< endl;
}
