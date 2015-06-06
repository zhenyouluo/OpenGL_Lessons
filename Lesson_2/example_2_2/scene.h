#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <GL/glu.h>
#include <QTimer>

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
    QTimer* timer;
};

#endif // SCENE_H

