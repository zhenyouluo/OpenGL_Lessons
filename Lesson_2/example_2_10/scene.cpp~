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
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_INDEX_ARRAY);
    glClearColor(0.0,0.0,0.0,0.0);
}

void Scene::resizeGL(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,1,-1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void Scene::paintGL()
{
    //Демонстрация построения примитивного псевдо автомобиля с квадратными колесами
    //Где одно колесо куртится в одну сторону, другое в другую с разной скоростью
    //И чтобы при всем при этом вращался сам автомобиль
    example_1();

}

void Scene::example_1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    //В реальных проектах, никогда не вводите статические переменные в таком виде!
    static GLfloat n1 = 0.0;
    static GLfloat n2 = 0.0;

    glPushMatrix();
    glColor3f(0,0,1);
    draw_cube(-0.25,0,0,0.25);
    draw_cube(0.25,0,0,0.25);
    glPopMatrix();

    glColor3f(1,0,1);
    glPushMatrix();
    glTranslatef(-0.25,-0.40,0);
    glRotatef(n1,0,0,1);
    draw_cube(0,0,0,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25,-0.40,0);
    glRotatef(-n2,0,0,3);
    draw_cube(0,0,0,0.1);
    glPopMatrix();

    n1+=1;
    n2+=3;

    glRotatef(0.1,0,0,1);

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

