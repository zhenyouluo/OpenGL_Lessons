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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,1,-1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2,0.3,0.4);
    glRotatef(0.2,1,1,1);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    draw_icosahedron();
    //Чтобы проверить все расчеты, мы здесь потом подключим свет.
}

void Scene::draw_icosahedron()
{

#define X .525731112119133606
#define Z .850650808352039932

    GLfloat vdata[12][3] =
    {
        {-X,0.0,Z},{X,0.0,Z},{-X,0.0,-Z},{X,0.0,-Z},
        {0.0,Z,X},{0.0,Z,-X},{0.0,-Z,X},{0.0,-Z,-X},
        {Z,X,0.0},{-Z,X,0.0},{Z,-X,0.0},{-Z,-X,0.0}
    };

    GLuint tindices[20][3] =
    {
        {1,4,0},{4,9,0},{4,5,9},{8,5,4},{1,8,4},
        {1,10,8},{10,3,8},{8,3,5},{3,2,5},{3,7,2},
        {3,10,7},{10,6,7},{6,11,7},{6,0,11},{6,1,0},
        {10,1,6},{11,0,9},{2,11,9},{5,2,9},{11,2,7}
    };

    glBegin(GL_TRIANGLES);
    for(int i=0;i<20;i++)
    {
        //Здесь происходит расчет нормалей для поверзностей
        GLfloat d1[3], d2[3], norm[3];
        for(int j=0;j<3;j++)
        {d1[j]=vdata[tindices[i][0]][j]-vdata[tindices[i][1]][j];
            d2[j]=vdata[tindices[i][1]][j]-vdata[tindices[i][2]][j];
        }
        normcrossprod(d1,d2,norm);
        glNormal3fv(norm);

        glVertex3fv(&vdata[tindices[i][0]][0]);
        glVertex3fv(&vdata[tindices[i][1]][0]);
        glVertex3fv(&vdata[tindices[i][2]][0]);
    }
    glEnd();
}

void Scene::normalize(float v[3])
{
    GLfloat d=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
    if(d==0.0)
    {
        // Вывод ошибки "Длина вектора равна 0"
        return;
    }
    v[0]/=d;
    v[1]/=d;
    v[2]/=d;
}

void Scene::normcrossprod(float v1[3], float v2[3], float out[3])
{
    out[0]=v1[1]*v2[2]- v1[2]*v2[1];
    out[1]=v1[2]*v2[0]- v1[0]*v2[2];
    out[2]=v1[0]*v2[1]- v1[1]*v2[0];
    normalize(out);
}

Scene::~Scene()
{

}

