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
    glClearDepth( 1.0f );// Разрешить очистку буфера глубины
    glEnable( GL_DEPTH_TEST );// Разрешить тест глубины
    glClearColor(0.0,0.0,0.0,0.0);
}

void Scene::resizeGL(int w, int h)
{
    glViewport(0,0,(GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,(GLfloat) w/ (GLfloat) h,1.0,20.0);//Перспективная проекция
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

void Scene::paintGL()
{
    //Демонстрация солнечной системы. Подключите библиотеку glut.
    example_1();
}

void Scene::example_1()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Теперь мы очищаем не только экран
                                                        //но и буффер глубины
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    //Никогда в реальных проектах не используйте статические переменные в таком виде
    static GLfloat n1 = 0.0;
    static GLfloat n2 = 0.0;

    glPushMatrix();

    glPushMatrix();
    glRotatef(n1+=1,1,1,1);
    glColor3f(1,1,0);
    glutWireSphere(1.0,20,16);
    glPopMatrix();

    glRotatef(n1+=1,0,1,0);
    glTranslatef(2,0,0);
    glRotatef(n2+=1,1,1,1);

    glColor3f(0,0,1);
    glutWireSphere(0.2,10,8);
    glPopMatrix();

}

void Scene::draw_cube(GLfloat x, GLfloat y, GLfloat z, GLfloat len)
{
    GLfloat v_cube[] =
    {
        x-len,y+len,z-len,
        x-len,y-len,z-len,
        x+len,y-len,z-len,
        x+len,y+len,z-len,

        x-len,y+len,z+len,
        x-len,y-len,z+len,
        x+len,y-len,z+len,
        x+len,y+len,z+len
    };

    GLubyte i_cube[] = {0,1,2,3,4,5,6,7,0,1,5,4,3,2,6,7,4,0,3,7,5,1,2,6};

    glVertexPointer(3,GL_FLOAT,0,v_cube);
    glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,i_cube);
}

void Scene::draw_coord_net()
{
    GLfloat v_net[] = {
        10,0,0,
        -10,0,0,
        0,10,0,
        0,-10,0,
        0,0,10,
        0,0,-10
    };

    GLubyte i_net[] = {0,1,2,3,4,5};

    glVertexPointer(3,GL_FLOAT,0,v_net);
    glDrawElements(GL_LINES,6,GL_UNSIGNED_BYTE,i_net);
}

Scene::~Scene()
{

}

