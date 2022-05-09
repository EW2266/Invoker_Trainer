#ifndef MyGL_H
#define MyGL_H


#include <QtWidgets>
#include <QtOpenGL>
#include <glfw3.h>
//#include <GL/glu.h>
#include<QOpenGLWidget>
#include "mainwindow.h"

class MyGL : public QOpenGLWidget
{
    Q_OBJECT
public:
    QTimer *timer;
    explicit MyGL(QWidget *parent = 0);
    int failed_note;
    int combo;
    void setRotation(float x, float y, float z);
    void setPosition(float x, float y, float z);
    void ResetAnimation();
    int getfailed_note();


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void text();

signals:

public slots:
    void UpdateAnimation();
private:
    float xrot,yrot,zrot,xloc,yloc,zloc;
};

#endif // QGLBEGIN_H
