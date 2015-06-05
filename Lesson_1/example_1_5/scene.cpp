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
    glOrtho(-1,1,-1,1,1,-1); //Изменили координатное пространство
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.4,0.2,0.0);

    glutWireSphere(0.2,10,10); //Рисуем сферу в центре нашей координатной плоскости
                               //Заметьте, в инийиализации OGL мы изменили координатную ось
                               //нашего пространства
                               //В функции указываем сначала радиус, потом количество линий
                               //по горизонтали, потом по вертикали

    //Применений у библиотеки glut масса. Сама библиотека, использует стандартные функции openGL
    //Также, эта библиотека способна создавать окно. Если бы мы работали без qt мы бы могли
    //использовать библиотека glut для прорисовки фрейма окна, реакции на события мыши, клавиатуры,
    //и т. д.
}

Scene::~Scene()
{

}

