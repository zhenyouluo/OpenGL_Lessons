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
    /*glViewport() подгоняет размеры прямоугольника, в
      который осуществляется графический вывод под размер всего окна. Три следующих
      вызова определяют координатную систему для рисования таким образом, чтобы левый
      нижний угол имел координаты (0,0), в правый верхний (w,h)
    */
    gluOrtho2D(-1,1,-1,1);
    /*gluOrtho2D() помещает
      начало координат в самый левый нижний квадрат листа и указывает, что каждый
      квадрат представляет собой одну единицу. Теперь, когда вы будете рисовать точки,
      линии и полигоны, они будут появляться на бумаге в легко предсказуемых квадратах.
    */
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0.0,0.0);

    GLfloat x1[] = {-0.25,-0.25};
    GLfloat x2[] = {0.25,0.25};
    glRectfv(x1,x2); //Альтернативная функция отрисовки прямоугольника(не требудет скобок
    //glBegin/glEnd )


    //Отрисовка окружности
    GLint circle_points=100; //Количество точек в круге
    GLfloat angle;
    glBegin(GL_LINE_LOOP);   //Каждая точка, соеденяется с прошлой, а последняя точка, с первой

    for(int i=0;i<circle_points;i++)
    {
        angle=2*M_PI*i/circle_points;
        glVertex2f(cos(angle),sin(angle));
    }
    glEnd();


    //Переливание цветов по средством изменения цвета во время прорисовки вершин
    glBegin(GL_LINES);
    glColor3f(0.0,1.0,0.0); //зеленый
    glVertex2f(-0.50,-0.50);
    glColor3f(0.0,0.0,1.0); //синий
    glVertex2f(0.50,-0.50);
    glEnd();

    //Регулировка толщины линий
    glLineWidth(7.0);  //Регулирует толщину линий. По умолчанию она равна 0.0
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,0.0); //желтый
    glVertex2f(-0.50,0.50);
    glColor3f(1.0,0.0,1.0); //фиолетовый
    glVertex2f(0.50,0.50);
    glEnd();
    glLineWidth(1.0);  //Не забывайте вернуть состояние толщины обратно,
                       //иначе все остальные линии будут с толщиной 7.

    //Также существует функция glPointSize(), которая регулирует размер точки.

    //Шаблоны отрезков
    glLineStipple(1,0x3F07);
    glEnable(GL_LINE_STIPPLE); //glEnable(GL_...) - одна из самых частых функций OpenGL
                               //Это активация какого либо состояния. В данный момент
                               //мы активировали шаблоны отрезков. Некоторые из этих функций
                               //настроек, указываются в методе initializeGL(), который
                               //вызывается один раз, при первом запуске программы OGL.
                               //Обратная ей функция glDisable(GL...) отключает какое либо
                               //включенное состояние
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glColor3f(0.0,1.0,1.0); //бирюзовый
    glVertex2f(-0.55,0.50);
    glColor3f(1.0,0.5,0.5); //персиковый
    glVertex2f(-0.55,-0.50);
    glEnd();
    glLineWidth(1.0);
    glDisable(GL_LINE_STIPPLE);
}

Scene::~Scene()
{

}

