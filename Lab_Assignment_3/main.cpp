//Write a program to display 12x12 chess board
#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

void init()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glShadeModel(GL_FLAT);
}

void display()
{
    int x,y,color=0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    for(x=1;x<=12;x++)
    {
        if(color == 0) //black
        {
            glColor3f(0.0,0.0,0.0);
            color = 1;
        }
        else{
            glColor3f(1.0,0.0,0.0);
            color = 0;
        }
        for(y=1;y<=12;y++)
        {
            if(color == 0) //black
            {
                glColor3f(0.0,0.0,0.0);
                color = 1;
            }
            else
            {
                glColor3f(1.0,1.0,1.0);
                color = 0;
            }
            glBegin(GL_QUADS);
            glVertex2f(37.5+37.5*x,37.5+37.5*y);
            glVertex2f(37.5*x,37.5+37.5*y);
            glVertex2f(37.5*x,37.5*y);
            glVertex2f(37.5+37.5*x,37.5*y);
            glEnd();
        }
    }

    glFlush();
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0,(float)w/(float)h,1.0,200.0);
    gluOrtho2D(0.0,(GLdouble)w,0.0,(GLdouble)h);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(475,475);
    glutCreateWindow("Terminal_Lab");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;
}
