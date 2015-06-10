#include "scene.h"

Scene::Scene(QWidget *parent)
    : QGLWidget(parent)
{
    xn = yn = 0.0;
    up_press = down_press = left_press = right_press = false;
    right_mouse = left_mouse = false;

    timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    connect(timer,SIGNAL(timeout()),this,SLOT(eventHandler()));
    timer->start();
}

//Никогда не создавайте глобальные переменные в таком виде
GLfloat lightPos[] = {0,0,50,1};
GLfloat ambientLight[] = {0.5,0.1,0.1,1.0};
GLfloat specular[] = {1,1,1,1};
GLfloat specref[] = {1,1,1,1};
GLfloat spotDir[] = {0,0,-1}; //Направление прожектора

void Scene::initializeGL()
{
    glEnable( GL_DEPTH_TEST );
    glClearDepth( 1.0f );
    glShadeModel(GL_SMOOTH); //Сглаживание пикселей
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    //Прожекторные эффекты:
    //Угол конуса освещения составляет 60 градусов
    glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,40.0f);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT,GL_SPECULAR, specref);
    glMateriali(GL_FRONT,GL_SHININESS,128);
    glClearColor(0.0,0.0,0.0,0.0);
}

void Scene::resizeGL(int w, int h)
{
    glViewport(0,0,(GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-60,60,-60,60,-100,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        //Поворачивается система координат
        glRotatef(xn,1,0,0);
        glRotatef(yn,0,1,0);
        //Задается новое положение и направление в повернутых координатах
        glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
        glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spotDir);
        //Рисуется красный конус, и окружающий источник света
        glColor3ub(255,0,0);
        //Транслируется начало координат, чтобы переместить конус в место положения источника света
        glTranslatef(lightPos[0],lightPos[1],lightPos[2]);
        glutSolidCone(4,6,15,15);
        //Рисуется немного смещенная сфера, обозначающая электрическую лампочку
        //Сохраняются переменные состояния освещения
        glPushAttrib(GL_LIGHTING_BIT);
            glDisable(GL_LIGHTING);
                glColor3ub(255,255,0);
            glutSolidSphere(3,30,30);
        //Восстанавливаются переменные состояния освещения
        glPopAttrib();
    //Восстанавливаются координатные преобразования
    glPopMatrix();
    //Устанавливаются цвет материала и рисуется сфера
    glColor3ub(0,0,255);
    glutSolidSphere(15,60,60);
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
    if(me->button() == Qt::LeftButton)
    {
        left_mouse = true;
        mouse_pos.setX(me->x());
        mouse_pos.setY(me->y());
    }

    if(me->button() == Qt::RightButton)
    {
        right_mouse = true;
    }
}

void Scene::mouseReleaseEvent(QMouseEvent *me)
{
    if(me->button() == Qt::LeftButton) left_mouse = false;
    if(me->button() == Qt::RightButton) right_mouse = false;
}

void Scene::mouseMoveEvent(QMouseEvent *me)
{
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

