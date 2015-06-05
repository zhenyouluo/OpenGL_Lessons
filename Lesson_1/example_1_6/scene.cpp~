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
    glOrtho(0,1,0,1,1,-1);
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.4,0.2,0.0);

    glBegin(GL_POLYGON);
    glVertex3f(0.25,0.25,0.0);
    glVertex3f(0.75,0.25,0.0);
    glVertex3f(0.75,0.75,0.0);
    glVertex3f(0.25,0.75,0.0);
    glEnd();

    //Передавать данные в функции OGL можно не только через параметры, но и через массивы
    //Это удобнее и быстрее
    GLfloat color_array[] = {1.0,0.0,0.0}; //Массив цветов(в данном случае красный)
    glColor3fv(color_array); //Передаем этот массив в функцию установки цвета.
                             //символ "v" в функции, означает, что мы передаем указатель
                             //на массив с данными.

    glBegin(GL_TRIANGLES);   //GL_TRIANGLES - отрисовка треугольников. Для каждого трейгольника
                             //необходимо 3 вершины.
    //Эти вершины, также можно передавать через массивы
    GLfloat x1[] ={0.10,0.34,0.0};
    GLfloat x2[] ={0.29,0.75,0.0};
    GLfloat x3[] ={0.45,0.48,0.0};
    glVertex3fv(x1);
    glVertex3fv(x2);
    glVertex3fv(x3);
    glEnd();
}

Scene::~Scene()
{

}

