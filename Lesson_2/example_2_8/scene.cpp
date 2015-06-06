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
    glOrtho(-10,10,-10,10,10,-10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void Scene::paintGL()
{
    //Демонстрация построения 3 кубов, и функции камеры
    //example_1();

    //Второй пример, изображает тоже самое что и первый пример,
    //но мы задали другой порт просмотра.
    example_2();
}

void Scene::example_1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glLoadIdentity();
    //Функция наведения камеры
    //Помните, что эта функция, также задает координатную плоскость
    gluLookAt(2,2.5,3,0,0,0,0,1,0);//Первые три параметра - где стоит камера
                                   //Вторые три - куда направлена камера
                                   //Третие три задают вектор направления.
                                   //он задает ориентацию камеры

    glColor3f(0.4,0,0);
    draw_coord_net();
    glColor3f(0.5,0.5,1);
    draw_cube(0,0,0,1);
    draw_cube(0,3,0,1);
    draw_cube(4,0,0,1);

}

void Scene::example_2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glViewport(0,0,300,300); //Иземенили порт просмотра.
    glLoadIdentity();
    gluLookAt(2,2.5,3,0,0,0,0,1,0);
    glColor3f(0.4,0,0);
    draw_coord_net();
    glColor3f(0.5,0.5,1);
    draw_cube(0,0,0,1);
    draw_cube(0,3,0,1);
    draw_cube(4,0,0,1);
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

