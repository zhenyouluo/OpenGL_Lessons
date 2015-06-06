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
    //Пример демонстрирует то, как отодвинули куб вправо,
    //затем его повернули вокруг оси Z на 33 градуса
    //а затем подняли его вверх
    example_1();

    //Пример демонстрирует постоянное проделывание этих операций
    //Только со значениями поменьше
    //example_2();

}

void Scene::example_1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glLoadIdentity();
    glColor3f(1.0,0.0,0.0);
    draw_coord_net();
    glLoadIdentity();
    glTranslatef(0.50,0,0);
    glRotatef(33,0,0,1);
    glTranslatef(0,0.50,0.0);
    glColor3f(0.2,0.3,0.4);
    draw_cube(0,0,0,0.10);
}

void Scene::example_2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glTranslatef(0.1,0,0);
    glRotatef(15,0,0,1);
    glTranslatef(0,0.1,0.0);
    glColor3f(0.2,0.3,0.4);
    draw_cube(0,0,0,0.10);
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
        1,0,0,
        -1,0,0,
        0,1,0,
        0,-1,0,
        0,0,1,
        0,0,-1
    };

    GLubyte i_net[] = {0,1,2,3,4,5};

    glVertexPointer(3,GL_FLOAT,0,v_net);
    glDrawElements(GL_LINES,6,GL_UNSIGNED_BYTE,i_net);
}

Scene::~Scene()
{

}

