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
    glClear(GL_COLOR_BUFFER_BIT); //Посмотрите, что произойдет с анимацией, если не
                                  //Производить очистку полотна
    glColor3f(1,0.0,0.0);

    //В реальных проектах, никогда не создавайте статические переменные такого рода!
    //Создавайте их в заголовочном файле, и инициализируйте в конструкторе

    static GLfloat   n     =  0.0;    //Переменная координата.
    static GLboolean up    =  true;   //Движение координаты вверх
    static GLboolean down  =  false;  //или вниз
    const  GLfloat   SPEED =  0.02;   //Скорость движения координаты


    glBegin(GL_LINES); //Рисуем линии(для линии необходимы две вершины)
    //Первая линия
    glVertex3f(-0.50,0,0);
    glVertex3f(0,n,0);
    //Вторая линия
    glVertex3f(0,n,0);
    glVertex3f(0.50,0,0);
    glEnd();

    if(n>=0.80) {up = false; down = true;} //Граничные условия для координаты.
    if(n<=-0.80){up = true; down = false;} //В зависимости от условый, меняем флаг
                                           //направления координаты

    if(up == true) n += SPEED; //В зависимости от флага направления движения
    else n -= SPEED;           //Выбираем нужную операцию(уменьшение или увеличение
                               //координаты)
}

Scene::~Scene()
{

}

