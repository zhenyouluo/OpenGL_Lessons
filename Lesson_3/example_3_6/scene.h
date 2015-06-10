#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <GL/glut.h>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>

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
    void keyPressEvent(QKeyEvent* ke);
    void keyReleaseEvent(QKeyEvent* ke);
    void mousePressEvent(QMouseEvent* me);
    void mouseReleaseEvent(QMouseEvent* me);
    void mouseMoveEvent(QMouseEvent* me);

private:
    QTimer* timer;
    GLfloat xn;
    GLfloat yn;

    bool up_press;
    bool down_press;
    bool left_press;
    bool right_press;
    bool right_mouse;
    bool left_mouse;
    QPoint mouse_pos;



private slots:
    void eventHandler();
};

#endif // SCENE_H

