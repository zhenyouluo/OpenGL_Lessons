#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <GL/glut.h>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent> //Подключаем библиотеку событий мыши
#include <QPoint> //Подключаем класс для удобного хранения координат мыши

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

    //Обработчики событий мыши
    void mousePressEvent(QMouseEvent* me);   //Нажатие клавиши мыши
    void mouseReleaseEvent(QMouseEvent* me); //Отпускание клавиши мыши
    void mouseMoveEvent(QMouseEvent* me);    //Движение мышью

private:
    QTimer* timer;
    GLfloat xn;
    GLfloat yn;

    bool up_press;
    bool down_press;
    bool left_press;
    bool right_press;

    //Флаги для клаыиш мыши
    bool right_mouse;
    bool left_mouse;
    
    //Координаты положения мыши
    QPoint mouse_pos;

private slots:
    void eventHandler(); //Обработчик событий(клаватуры)
};

#endif // SCENE_H

