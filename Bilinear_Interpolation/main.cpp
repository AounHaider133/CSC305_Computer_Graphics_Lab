#include<GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,1.0); //blue
    glVertex2f(-0.5,-0.5);
    glColor3f(0.0,1.0,0.0); //green
    glVertex2f(0.5,-0.5);
    glColor3f(1.0,0.0,0.0); //red
    glVertex2f(0.0,1.0);
    glEnd();
    glFlush(); //single buffer, so need a flush
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutCreateWindow("Single Triangle");
    glutDisplayFunc(display);
    glutMainLoop();
}
