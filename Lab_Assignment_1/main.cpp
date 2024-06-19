#include<GL/glut.h>
#include<iostream>

void init()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glColor3f(1.0f,0.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
    glMatrixMode(GL_MODELVIEW);
}
void Draw_Figure(GLfloat matrix[3][11])
{
    int i = 0;

    //Original house
    glPushMatrix();
    glTranslatef(-2.0,5.0,0.0);
    //Rectangle
    glColor3f(1.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
    for(i=0;i<4;i++)
        glVertex2f(matrix[0][i],matrix[1][i]);
    glEnd();

    //Triangle
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_TRIANGLES);
    for(i=4;i<7;i++)
        glVertex2f(matrix[0][i],matrix[1][i]);
    glEnd();

    //Rectangle
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    for(i=7;i<11;i++)
        glVertex2f(matrix[0][i],matrix[1][i]);
    glEnd();
    glPopMatrix();

    //Scaled by half house
    glPushMatrix();
    glTranslatef(50.0,5.0,0.0);
    //Rectangle
    glColor3f(1.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
    for(i=0;i<4;i++)
        glVertex2f(matrix[0][i]/2,matrix[1][i]/2);
    glEnd();

    //Triangle
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_TRIANGLES);
    for(i=4;i<7;i++)
        glVertex2f(matrix[0][i]/2,matrix[1][i]/2);
    glEnd();

    //Rectangle
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    for(i=7;i<11;i++)
        glVertex2f(matrix[0][i]/2,matrix[1][i]/2);
    glEnd();
    glPopMatrix();
}
void display()
{
    //rectangle,triangle,rectangle
    GLfloat house[3][11] = {{30,60,60,30,25,65,45,40,50,50,40},{0,0,20,20,20,20,50,0,0,10,10},{1,1,1,1,1,1,1,1,1,1,1}};
    glClear(GL_COLOR_BUFFER_BIT);
    Draw_Figure(house);
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
