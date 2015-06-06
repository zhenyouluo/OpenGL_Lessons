#include "scene.h"

Scene::Scene(QWidget *parent)
    : QGLWidget(parent)
{
    timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    timer->start();
}

void Scene::initializeGL()
{
    glClearColor(0.0,0.0,0.0,0.0);

}

void Scene::resizeGL(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    gluOrtho2D(-1,1,-1,1);
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Красный полигон отрисованный против часовой:
    //(Отрисовка полигонов ПРОТИВ часовой, по умолчанию делает полигон лицевым)
    glColor3f(1,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.25,0.50);
    glVertex2f(-0.25,0.25);
    glVertex2f(0.25,0.25);
    glVertex2f(0.25,0.50);
    glEnd();

    //Синий полигон отрисованный по часовой:
    //(Отрисовка полигонов ПО часовой, по умолчанию делает полигон обратным)
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(0.25,-0.25);
    glVertex2f(0.25,-0.50);
    glVertex2f(-0.25,-0.50);
    glVertex2f(-0.25,-0.25);
    glEnd();

    glPolygonMode(GL_FRONT,GL_FILL); //Лицевые полигоны отобразить как закрашенные
    glPolygonMode(GL_BACK,GL_LINE);  //Обратные полигоны отобразить в виде линий
                                     //Также, любые полигоны можно отобразить в виде точек:
                                     //например: glPolygonMode(GL_FRONT,GL_POINT);

    //Указание лицевых граней и удаление нелицевых граней:

    //Стоит по умолчанию, лицвые грани те - что отриовываются против часовой
    //glFrontFace(GL_CCW);
    //Если требуется сделать наоборот, то применяется функция:
    //glFrontFace(GL_CW); //Испытайте эту функцию

    //Для того, чтобы использовать механизм удаления нелицевых граней включите его
    //следующим образом:
    //glEnable(GL_CULL_FACE);

    //Игнорировать обратные грани:(по умолчанию, стоит именно это состояние)
    //glCullFace(GL_BACK);
    //Игнорировать лицевые грани:
    //glCullFace(GL_FRONT);
    //Также, можно игнорировать и лицевые и обратные грани:
    //glCullFace(GL_FRONT_AND_BACK);
}

Scene::~Scene()
{

}

