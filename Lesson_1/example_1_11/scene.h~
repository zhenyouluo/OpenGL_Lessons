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

    //Координаты вершин
    GLfloat v0[] = {-0.25,0.0,0.0};
    GLfloat v1[] = {0.3,0.0,0.0};
    GLfloat v2[] = {0.1,0.4,0.0};

    //Нормали для этих вершин. Для всего этого полигона, это просто перпендикуляр

    GLfloat n0[] = {0,0,1};
    GLfloat n1[] = {0,0,1};
    GLfloat n2[] = {0,0,1};

    glBegin(GL_POLYGON);
    glNormal3fv(n0); //Указание нормали
    glVertex3fv(v0);
    glNormal3fv(n1);
    glVertex3fv(v1);
    glNormal3fv(n2);
    glVertex3fv(v2);
    glEnd();

    //Для нормализации вектора поделите каждую из трех его координат на его длину
    //Функция OpenGL для нормализации вектора(приведение его к единичному)
    glEnable(GL_NORMALIZE);
}

Scene::~Scene()
{

}

