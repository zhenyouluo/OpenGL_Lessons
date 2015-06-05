#include "scene.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);   //ЭТА СТРОКА ТОЛЬКО ДЛЯ LINUX систем!
    QApplication a(argc, argv);
    Scene w;
    w.show();

    return a.exec();
}

