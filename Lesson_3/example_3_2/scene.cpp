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

    static GLfloat ambient[] = {0.02,0.0,0.0,1.0}; //Задаем рассеянный свет. Еле заметный красный
    static GLfloat diffuse[] = {1,1,1,1.0}; //Задаем силу диффузного света

    glEnable(GL_LIGHT0); //Включаем первый источник
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient); //Загружаем рассеянный
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse); //загружаем диффузный
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient); //Загружаем модель освещения
    glEnable(GL_COLOR_MATERIAL); //Материал у нас будет являться цветом
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE); //Передные поверхности реагируют на рассейянный и диффузный свет

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

   static GLfloat position[] ={0,-5,5,1}; //Создаем массив указывающий позицию источника света

   glLightfv(GL_LIGHT0,GL_POSITION,position); //Задаем позицию через массив

   glutSolidSphere(4,60,60); //Создаем сферу, так как для нее уже в полном объеме расчитаны нормали

   //Изменяем позицию источника света
   position[1] +=0.02;

}

Scene::~Scene()
{

}

