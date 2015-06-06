#include "scene.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scene w;
    w.setWindowTitle("OGL_2");
    w.show();

    return a.exec();
}

