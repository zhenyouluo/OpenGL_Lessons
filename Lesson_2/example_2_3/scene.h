#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <GL/glu.h>
#include <QTimer>
#include <cmath>

class Scene : public QGLWidget
{
    Q_OBJECT

public:
    Scene(QWidget *parent = 0);
    ~Scene();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    void draw_icosahedron();
    void normalize(float v[3]);
    void normcrossprod(float v1[3], float v2[3], float out[3]);
    QTimer* timer;
};

#endif // SCENE_H

