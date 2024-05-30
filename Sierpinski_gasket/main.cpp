#include<GL/glut.h>

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    //gluOrtho2D(0.0,200.0,0.0,150.0);
    //gluOrtho2D(0.0,200.0*2,0.0,150.0);
    //gluOrtho2D(0.0,200.0,0.0,150.0*2);

    //gluOrtho2D(-100.0,100.0,-75,75);
    //gluOrtho2D(-100.0*2,100.0*2,-75.0,75.0);
    //gluOrtho2D(-100.0,100.0,-75.0,75.0*2);
    //gluOrtho2D(1.0,0.0,-1.0,1.0);
    glColor3d(0.0,1.0,0.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glVertex2d(0,-25);
    glVertex2d(50,-25);
    glVertex2d(50,25);
    glVertex2d(0,25);
    glEnd();

    glFlush();
}

void reshape(int width,int height)
{
    glViewport(0,0,width,height);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(400,300);
    glutCreateWindow("Half Triangle");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    init();
    glutMainLoop();
}

