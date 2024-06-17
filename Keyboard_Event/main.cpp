#include<GL/glut.h>

void drawSquare()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.25,0.25);
    glVertex2f(0.25,0.75);
    glVertex2f(0.75,0.75);
    glVertex2f(0.75,0.25);
    glEnd();
    glFlush();
}
void mouse(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state ==GLUT_DOWN)
     drawSquare();
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
     exit(0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("square");
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
