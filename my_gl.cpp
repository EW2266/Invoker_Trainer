#include "my_gl.h"
//#include <GLUT/glut.h>
//#include <GL/glu.h>
//#include "glut.h"

MyGL::MyGL(QWidget *parent) : QOpenGLWidget(parent)
{
    failed_note = 0;
    xrot = yrot = zrot = 0.0;
    xloc = 100;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(UpdateAnimation()));
    timer->start(100);
}

void MyGL::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
}
/*
void MyGL::text()
{
    char menu[20];
    std::sprintf(menu, "%d", combo);
    int len;
    len = strlen(menu);

    glColor3f(1,1,1);

    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();

    gluOrtho2D( 0, 600, 0, 600 );

    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();

    glLoadIdentity();

    glRasterPos2i(190, 300);


    for ( int i = 0; i < len; ++i )
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, menu[i]);
    }

    glPopMatrix();

    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
}
*/
void MyGL::paintGL()
{
    float theta;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1,0,0);


    glTranslatef(0.0, 0.0, -7.0);


    glTranslatef(xloc/25,yloc/25,zloc/25);
    float r = 0.33;
    glBegin(GL_POLYGON);
    for(int i= 0; i < 360; i++){
        theta = i * 3.142/180;
        glVertex2f(r*cos(theta),r*3*sin(theta));
    }
    glEnd();
    glFlush();

    /*
    glBegin(GL_QUADS);
        glColor3f(1, 0, 0);

        glVertex3f (0.1, 0.1, 0.0);
        glVertex3f (0.9, 0.1, 0.0);
        glVertex3f (0.9, 0.9, 0.0);
        glVertex3f (0.1, 0.9, 0.0);

        DrawCircle(0.0,0.0,0.5,0.0);

        glEnd();

        /* glFlush() forces all the issued command to be executed
        *  as quickly as they are accepted by rendering engine
        *
        glFlush();
    */

}

void MyGL::resizeGL(int w, int h)
{
    //set viewport
    glViewport(0,0,w,h);

    //initialize projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* multiply the current matrix by a perspective matrix
     * void glFrustum(GLdouble left, GLdouble right,GLdouble bottom,GLdouble top,GLdouble nearVal,GLdouble farVal);
     * left, right: Specify the coordinates for the left and right vertical clipping planes.
     * bottom, top: Specify the coordinates for the bottom and top horizontal clipping planes.
     * nearVal, farVal: Specify the distances to the near and far depth clipping planes. Both distances must be positive.
     */
    glFrustum(-2, +2, -2, +2, 4.0, 10.0);

    //initialize modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void MyGL::setRotation(float x, float y, float z)
{
    xrot = x;
    yrot = y;
    zrot = z;
    update();
}

void MyGL::setPosition(float x, float y, float z)
{
    xloc = x;
    yloc = y;
    zloc = z;
    update();
}

int MyGL::getfailed_note(){
    return failed_note;
}

void MyGL::UpdateAnimation()
{
    xloc -= 10;
    if(xloc < -100){
        //failed_note ++;
        //qInfo() <<"current health : " << 5 - failed_note;
        combo = 0;
        //MainWindow::ui
        ResetAnimation();
    }
    this->update();
}



void MyGL::ResetAnimation(){
    xloc = 100;
}




