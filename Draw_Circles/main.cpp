#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.142857
#include<iostream>
int circle_radius = 200;
void myInit(void)
{
    //set background color black
    glClearColor(0.0,0.0,0.0,1.0);

    //set picture color green
    glColor3f(0.0,1.0,0.0);

    //set pixel to 1pt
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //set window dimension
    gluOrtho2D(-780,780,-420,420);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    float x,y,i;

    //iterative 'y' up to 2*PI = 360deg with small increment in angle
    for(i=0;i<(2*PI);i+=0.001)
    {
        x = circle_radius * cos(i);
        y = circle_radius * sin(i);

        glVertex2i(x,y);
    }
    glEnd();
    glFlush();
}

int main(int argc,char**argv)
{
    printf("Enter the radius of circle:");
    scanf("%d",&circle_radius);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(740,540);
    glutInitWindowPosition(400,100);

    glutCreateWindow("Circle Drawing");
    myInit();

    glutDisplayFunc(display);
    glutMainLoop();
}
