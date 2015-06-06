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
    glMatrixMode(GL_PROJECTION); //Это значит, что будем работать с матрицей проекции
                                 //То есть, например, задавать координатную ось.
    glLoadIdentity();            //Загружаем единичную матрицу, то есть сбрасываем все ее настройки

    glOrtho(-1,1,-1,1,1,-1);     //Задаем трехмерную координатную ось

    glMatrixMode(GL_MODELVIEW);  //Теперь работаем с матрицой модели/вида
    glLoadIdentity();
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2,0.3,0.4);
    glRotatef(0.2,1,1,1); //Для наглядности примера, забегая вперед, мы решили повернуть наш вид
                          //Каждую итерацию таймера, мы вращаем наш икосаэдр на угол равный
                          //0.2 градуса, вокруг оси x,y и z одновременно.
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    draw_icosahedron();   //Поместили реализацию рисования икосаедра в отдельную функцию
}

void Scene::draw_icosahedron()
{

  #define X .525731112119133606
  #define Z .850650808352039932

      //Создаем массив всех координат икосаедра
      GLfloat vdata[12][3] =
      {
            {-X,0.0,Z},{X,0.0,Z},{-X,0.0,-Z},{X,0.0,-Z},
            {0.0,Z,X},{0.0,Z,-X},{0.0,-Z,X},{0.0,-Z,-X},
            {Z,X,0.0},{-Z,X,0.0},{Z,-X,0.0},{-Z,-X,0.0}
      };

      //Теперь все грани, с помощью массива индексов
      GLuint tindices[20][3] =
      {
            {1,4,0},{4,9,0},{4,5,9},{8,5,4},{1,8,4},
            {1,10,8},{10,3,8},{8,3,5},{3,2,5},{3,7,2},
            {3,10,7},{10,6,7},{6,11,7},{6,0,11},{6,1,0},
            {10,1,6},{11,0,9},{2,11,9},{5,2,9},{11,2,7}
      };

    //Еще один пример отрисовки:
    glBegin(GL_TRIANGLES);
    for(int i=0;i<20;i++)
    {
        //Здесь помещается информация о цвете
        glVertex3fv(&vdata[tindices[i][0]][0]);
        glVertex3fv(&vdata[tindices[i][1]][0]);
        glVertex3fv(&vdata[tindices[i][2]][0]);
    }
    glEnd();
}

Scene::~Scene()
{

}

