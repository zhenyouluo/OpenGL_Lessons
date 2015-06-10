#include "scene.h"

Scene::Scene(QWidget *parent)
    : QGLWidget(parent)
{
    xn = yn = 0.0;
    up_press = down_press = left_press = right_press = false;
    right_mouse = false;
    left_mouse = false;

    timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    connect(timer,SIGNAL(timeout()),this,SLOT(eventHandler()));
    timer->start();
}

void Scene::initializeGL()
{
    glClearDepth( 1.0f );
    glEnable( GL_DEPTH_TEST );

    glEnable(GL_LIGHTING);

    GLfloat ambient[] = {0.02,0.0,0.0,1.0};
    GLfloat diffuse[] = {1,1,1,1.0};
    GLfloat specular[] = {1,1,1,1};
    GLfloat specref[] = {1,1,1,1};

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

    glMaterialfv(GL_FRONT,GL_SPECULAR, specref);
    glMateriali(GL_FRONT,GL_SHININESS,128);

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

    glLightfv(GL_LIGHT0,GL_POSITION,position);

    glPushMatrix();
    glRotatef(xn,1,0,0);//методы влияющие на поворот вида, в зависимости от праметров
    //которые мы будем регулировать с помощью клавиатуры или мыши
    glRotatef(yn,0,1,0);//-аналогично-

    glRotatef(90,0,-1,0);
    glPushMatrix();
    glScalef(4,4,4);
    glutSolidTeapot(1);
    glPopMatrix();
    glRotatef(90,0,1,0);
    glPopMatrix();
}

void Scene::keyPressEvent(QKeyEvent *ke)
{
    if(ke->key() == Qt::Key_Up)
        up_press = true;

    if(ke->key() == Qt::Key_Down)
        down_press = true;

    if(ke->key() == Qt::Key_Right)
        right_press = true;

    if(ke->key() == Qt::Key_Left)
        left_press = true;
}

void Scene::keyReleaseEvent(QKeyEvent *ke)
{
    if(ke->key() == Qt::Key_Up)
        up_press = false;

    if(ke->key() == Qt::Key_Down)
        down_press = false;

    if(ke->key() == Qt::Key_Right)
        right_press = false;

    if(ke->key() == Qt::Key_Left)
        left_press = false;
}

void Scene::eventHandler()
{
    if(up_press)xn-=1;
    if(down_press)xn+=1;
    if(left_press)yn-=1;
    if(right_press)yn+=1;
}

void Scene::mousePressEvent(QMouseEvent *me)
{
    //Нажатие клавишы мыши. Меняем соответствующие флаги и устанавливаем позицию мыши.
    //Для левой клавиши
    if(me->button() == Qt::LeftButton)
    {
        left_mouse = true;
        mouse_pos.setX(me->x());
        mouse_pos.setY(me->y());
    }

    //Для правой
    if(me->button() == Qt::RightButton)
    {
        right_mouse = true;
    }
}

void Scene::mouseReleaseEvent(QMouseEvent *me)
{
    //Для отпуская мыши аналогично
    if(me->button() == Qt::LeftButton) left_mouse = false;
    if(me->button() == Qt::RightButton) right_mouse = false;
}

void Scene::mouseMoveEvent(QMouseEvent *me)
{

    //При движении мыши, при условии что нажата левая клавиша мыши, м меняем углы поворота объекта
    //и снова фиксируем позицию мыши.
    if(left_mouse == true)
    {
        if(me->x() < mouse_pos.x())
        {
            yn-=1;
            mouse_pos.setX(me->x());
        }

        if(me->x() > mouse_pos.x())
        {
            yn+=1;
            mouse_pos.setX(me->x());
        }

        if(me->y() < mouse_pos.y())
        {
            xn-=1;
            mouse_pos.setY(me->y());
        }

        if(me->y() > mouse_pos.y())
        {
            xn+=1;
            mouse_pos.setY(me->y());
        }
    }
}

Scene::~Scene()
{

}

