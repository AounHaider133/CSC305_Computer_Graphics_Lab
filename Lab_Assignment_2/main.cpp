//Lab Assignment: 02
//Submitted to: Aamer Mehmood
//Mr.Aoun Haider
#include<GL/glut.h>
#include<iostream>
#include<math.h>

void init()
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float theta;
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<10000;i++)
    {
        theta = i * 3.142/180;
        glVertex2f(0.6*cos(theta),0.6*sin(theta));
    }
    glEnd();

    glBegin(GL_QUADS); //down_sqr
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.02f,-0.45f);
    glVertex2f(-0.04f,-0.45f);
    glVertex2f(-0.04f,-0.52f);
    glVertex2f(0.02f,-0.52f);
    glEnd();

    glBegin(GL_QUADS); //upper_sqr
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.02f,0.45f);
    glVertex2f(-0.04f,0.45f);
    glVertex2f(-0.04f,0.52f);
    glVertex2f(0.02f,0.52f);
    glEnd();

    glBegin(GL_QUADS); //right_sqr
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.5f,0.08f);
    glVertex2f(0.45f,0.08f);
    glVertex2f(0.45f,0.019f);
    glVertex2f(0.5f,0.019f);
    glEnd();

    glBegin(GL_QUADS); //left_sqr
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.5f,0.08f);
    glVertex2f(-0.45f,0.08f);
    glVertex2f(-0.45f,0.019f);
    glVertex2f(-0.5f,0.019f);
    glEnd();

    glBegin(GL_LINE_LOOP); //hand
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.02f,0.04f);
    glVertex2f(-0.04f,0.04f);
    glVertex2f(0.21f,0.43f);
    glEnd();

    glBegin(GL_LINE_LOOP); //hand
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.02f,0.04f);
    glVertex2f(-0.04f,0.04f);
    glVertex2f(0.02f,-0.35f);
    glEnd();

    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutCreateWindow("House");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
