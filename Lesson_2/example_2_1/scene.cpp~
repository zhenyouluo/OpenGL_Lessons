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
    gluOrtho2D(0,1,0,1);
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Вершинные массивы:
    //Шаг 1: Включение массивов:

    glEnableClientState(GL_VERTEX_ARRAY); //Включаем массив координат вершин
    glEnableClientState(GL_NORMAL_ARRAY); //Включаем массив нормалей для этих же вершин
    glEnableClientState(GL_COLOR_ARRAY);  //Включаем массив цветов
    glEnableClientState(GL_INDEX_ARRAY);  //Включаем массив индексов

    glDisableClientState(GL_NORMAL_ARRAY); //Пример отключения какого-либо из массивов

    //ВНИМАНИЕ! ВСЕ МАССИВЫ КОТОРЫЕ МЫ ВКЛЮЧИЛИ, МЫ ОБЯЗАНЫ УКАЗАТЬ!

    //Шаг 2: Указание данных для массивов:

    //Создаем массив вершин
    GLfloat vertices[]= {0.25, 0.25,
                       0.100, 0.325,
                       0.175, 0.25,
                       0.175, 0.325,
                       0.250, 0.25,
                       0.325, 0.325};

    GLfloat colors[]= {1.0, 0.2, 0.2,
                       0.2, 0.2, 1.0,
                       0.8, 1.0, 0.2,
                       0.75, 0.75, 0.75,
                       0.35, 0.35, 0.35,
                       0.5, 0.5, 0.5};

    GLfloat indices[] = {0,1,2,3,4,5}; // Просто указали индексы, так как они есть на самом деле

    //Загрузка вершинных массивов.
    glColorPointer(3,GL_FLOAT, 0, colors); //Сначала, например, загрузим массив цветов
                                           //3 - Количество параметров у цвета(RGB)
                                           //GL_FLOAT - тип параметров у цвета
                                           //0 - плотность упаковки. В данном случае max.
                                           //colors - передаем сам массив цветов

    glVertexPointer(2,GL_FLOAT, 0, vertices); //Загрузка вершин.
                                            //2 - Количество координат у вершины
                                            //GL_FLOAT - тип параметров у вершины
                                            //0 - плотность упаковки. В данном случае max.
                                            //vertices - передаем сам массив вершин

    glIndexPointer(GL_INT,0,indices);      //Загркжаем массив индексов

    //Шаг 3: Разрешение данных

    // Первый способ:

    glBegin(GL_TRIANGLES);
    glArrayElement(2); //Рисует определенный элемент в списке вершин
                       //(в данном случае 3, отсчет с нуля)

    glArrayElement(3);
    glArrayElement(5);
    glEnd();

    //Второй способ:

    //Представим, что у нас есть массив вершин, скажем, куба.
    GLfloat v_cube[]= {0.50, 0.75,
                       0.50, 0.50,
                       0.75, 0.50,
                       0.75, 0.75,

                       0.60, 0.85,
                       0.60, 0.60,
                       0.85, 0.60,
                       0.85, 0.85};

    //Его массив цветов
    GLfloat c_cube[]= {1,0,0,
                       1,0,0,
                       1,0,0,
                       1,0,0,

                       1,0,1,
                       1,0,1,
                       1,0,1,
                       1,0,1};

    //И существуют отдельные индексы для его передней, задней, боковой.. поверхностей
    GLubyte frontIndices[] = {0,1,2,3};
    GLubyte rightIndices[] = {3,2,6,7};
    GLubyte bottomIndices[] = {5,1,2,6};
    GLubyte backIndices[] = {4,5,6,7};
    GLubyte leftIndices[] = {0,1,5,4};
    GLubyte topIndices[] = {4,0,3,7};

    //Загружаем новые индексы
    glVertexPointer(2,GL_FLOAT, 0, v_cube);
    glColorPointer(3,GL_FLOAT, 0, c_cube);

    //Делаем так, чтобы рисовались только линнии
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    glDrawElements(GL_QUADS,4,GL_UNSIGNED_BYTE,frontIndices); //Указываем что будем рисовать
                                                              //Затем количество индексов
                                                              //Потом массив индексов
    glDrawElements(GL_QUADS,4,GL_UNSIGNED_BYTE,rightIndices);
    glDrawElements(GL_QUADS,4,GL_UNSIGNED_BYTE,bottomIndices);
    glDrawElements(GL_QUADS,4,GL_UNSIGNED_BYTE,backIndices);
    glDrawElements(GL_QUADS,4,GL_UNSIGNED_BYTE,leftIndices);
    glDrawElements(GL_QUADS,4,GL_UNSIGNED_BYTE,topIndices);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //Возвращаем состояние обратно

    //Третий способ:
    //Можно было собрать все индексы вместе:
    GLubyte all[] = {0,1,2,3,3,2,6,7,5,1,2,6,4,5,6,7,0,1,5,4,4,0,3,7};

    //И отрисовать все сразу одной функцией:
    //glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,allIndices);
}

Scene::~Scene()
{

}

