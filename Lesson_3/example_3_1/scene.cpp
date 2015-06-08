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
    glClearDepth( 1.0f );
    glEnable( GL_DEPTH_TEST );

    glEnable(GL_LIGHTING); //Включаем освещение на сцене

    GLfloat ambient[] = {1,1,1,1}; //Указываем какие цвета общим светом будут освещаться
                                   //Попробуйте изменить параметры этого массива
                                   //Например, можно сделать так, чтобы красный цвет
                                   //не отражался(правильней, не освещался)
                                   //уберем просто из массива красный:0,1,1,1.


    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient);//Включаем общую модель освещения
    glEnable(GL_COLOR_MATERIAL);//Задаем материал просто - цвета
    glColorMaterial(GL_FRONT,GL_AMBIENT);//Передний поверхности отражают общий свет
}

void Scene::resizeGL(int w, int h)
{
    glViewport(0,0,(GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Scene::paintGL()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(1,0,0);

   glBegin(GL_TRIANGLES);
       glColor3f(1,0,0);
       glVertex3f(0,5,0);
       glColor3f(0,1,0);
       glVertex3f(-3,0,0);
       glColor3f(0,0,1);
       glVertex3f(3,0,0);
   glEnd();
}

Scene::~Scene()
{

}

