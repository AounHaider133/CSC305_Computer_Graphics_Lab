#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

void init()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glColor3f(1.0f,0.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glRasterPos2d(3,85);
    const char* str = "Press key to draw shape: r - rectangle, t - triangle, c - circle, p - polygon";

    for (const char* c = str; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
    glFlush();
}
void DrawRectangle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(20.0f, 30.0f);
    glVertex2f(20.0f, 60.0f);
    glVertex2f(60.0f, 60.0f);
    glVertex2f(60.0f, 30.0f);
    glEnd();
    glFlush();
}
void DrawCircle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<100000;i++)
    {
        int theta = i*3.142/180; //deg2rad
        glVertex2f(50+20*cos(theta),60+20*sin(theta));
    }
    glEnd();
    glFlush();
}
void DrawPolygon()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(30.0f, 20.0f);
    glVertex2f(40.0f, 70.0f);
    glVertex2f(70.0f, 60.0f);
    glVertex2f(80.0f, 20.0f);
    glVertex2f(50.0f, 10.0f);
    glEnd();
    glFlush();
}
void DrawTriangle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(50.0f, 70.0f);
    glVertex2f(30.0f, 30.0f);
    glVertex2f(70.0f, 30.0f);
    glEnd();
    glFlush();
}

void keys(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 'r':
        case 'R':
            DrawRectangle();
        break;
        case 'p':
        case 'P':
            DrawPolygon();
        break;
        case 'c':
        case 'C':
            DrawCircle();
        break;
        case 't':
        case 'T':
            DrawTriangle();
        break;
        case 27:
            exit(0);
        break;
    }
    //glutPostRedisplay();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,500);
    glutCreateWindow("Midterm_Lab");
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    init();
    glutMainLoop();
    return 0;
}
