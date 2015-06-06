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
    glOrtho(-1,1,-1,1,1,-1);
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.3,0.7);

    //Демонстрация построения полигонов, с указанием граничных ребер.
    
    //Создаем три вершины в пространстве
    GLfloat V0[] = {-0.25,0.0,0.0};
    GLfloat V1[] = {0.3,0.0,0.0};
    GLfloat V2[] = {0.1,0.4,0.0};

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); //Указываем, что все полигоны отображаем как линии.
    glBegin(GL_POLYGON);                      //Начинаем рисовать полигон.
    glEdgeFlag(GL_TRUE);                      //Указываем флаг ребра, что ребро строим.
    glVertex3fv(V0);                          //Строим вершину и соответственно ребро тоже.
    glEdgeFlag(GL_FALSE);                     //Указываем флаг ребра, что у следующей вершины
                                              //ребро не строим  .
    glVertex3fv(V1);                          //Указываем следующю вершину, после прохода
                                              //которой, ребро не будет построено.
    glEdgeFlag(GL_TRUE);      
    glVertex3fv(V2);
    glEnd();

}

Scene::~Scene()
{

}

