#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <GL/glut.h>
#include <QTimer>
#include <QKeyEvent> //Подключили библиотеку событий клавиатуры

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

private:
    QTimer* timer;
    GLfloat xn;
    GLfloat yn;

    //Логические флаги, описывающе нажатие клавиш, вверх, вниз, вправо, влево.
    bool up_press;
    bool down_press;
    bool left_press;
    bool right_press;

private slots:
    void eventHandler(); //Обработчик событий(в нашем случае, пока только клавиатуры)
};

#endif // SCENE_H

