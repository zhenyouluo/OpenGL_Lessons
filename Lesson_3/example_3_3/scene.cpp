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

    glEnable(GL_LIGHTING);

    GLfloat ambient[] = {0.02,0.0,0.0,1.0};
    GLfloat diffuse[] = {1,1,1,1.0};
    GLfloat specular[] = {1,1,1,1}; //Отраженный свет
    GLfloat specref[] = {1,1,1,1}; //Коэф. зеркального отражения

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular); //Задаем отражательный свет нашему источнику света
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

    glMaterialfv(GL_FRONT,GL_SPECULAR, specref);
    glMateriali(GL_FRONT,GL_SHININESS,128); //Создание "зайчика"

}

void Scene::resizeGL(int w, int h)
{
    glViewport(0,0,(GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-100,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Scene::paintGL()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(1,0,0);

   glLoadIdentity();

   static GLfloat position[] ={0,0,4.2,1};
   static GLfloat n = 0.0;
   glLightfv(GL_LIGHT0,GL_POSITION,position);



   glPushMatrix();
   glRotatef(90,0,-1,0);
   glRotatef(n+=1,0,0,-1);
   glScalef(4,4,4);
   glutSolidTeapot(1);
   glPopMatrix();

}

Scene::~Scene()
{

}

