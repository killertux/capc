#include <QtGui/QApplication>
#include "Classes/Capc/Capc.hpp"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Capc capc;
    capc.show();
    return app.exec();
}
