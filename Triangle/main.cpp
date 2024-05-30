#include<GL/glut.h>

void myInit()
{
    glClearColor(0.0,0.0,1.0,1.0);
    gluOrtho2D(0,50,0,50);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    //glVertex2f(-0.5,-0.5);
    //glVertex2f(0.5,-0.5);
    //glVertex2f(0.0,0.5);
    glVertex2f(25,25);
    glVertex2f(75,25);
    glVertex2f(50,75);

    glEnd();
    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutCreateWindow("Triangle");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}
