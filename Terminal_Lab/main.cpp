#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

GLfloat angle = 0.0;
void init()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glColor3f(0.0,0.0,0.0);
    glLoadIdentity();
    glTranslatef(0.0f,0.0,-6.0f);
    glRotatef(angle,0.0,1.0,0.0);

    //Pyramid
    glBegin(GL_TRIANGLES);
    //Front face
    glColor3f(1.0,0.0,0.0); //red
    glVertex3f(0.0,1.0,0.0);
    glColor3f(0.0,1.0,0.0); //green
    glVertex3f(-1.0,-1.0,1.0);
    glColor3f(0.0,0.0,1.0); //blue
    glVertex3f(1.0,-1.0,1.0);

    //Back face
    glColor3f(1.0,0.0,0.0); //red
    glVertex3f(0.0,1.0,0.0);
    glColor3f(0.0,1.0,0.0); //green
    glVertex3f(-1.0,-1.0,-1.0);
    glColor3f(0.0,0.0,1.0); //blue
    glVertex3f(1.0,-1.0,-1.0);

    //Right face
    glColor3f(1.0,0.0,0.0); //red
    glVertex3f(0.0,1.0,0.0);
    glColor3f(0.0,0.0,1.0); //blue
    glVertex3f(1.0,-1.0,-1.0);
    glColor3f(0.0,1.0,0.0); //green
    glVertex3f(1.0,-1.0,1.0);

    //Left face
    glColor3f(1.0,0.0,0.0); //red
    glVertex3f(0.0,1.0,0.0);
    glColor3f(0.0,0.0,1.0); //blue
    glVertex3f(-1.0,-1.0,-1.0);
    glColor3f(0.0,1.0,0.0); //green
    glVertex3f(-1.0,-1.0,1.0);

    glEnd();

    glutSwapBuffers();
}
void spinPyramid()
{
    angle += 2.0f;
    if(angle >=360.0)
        angle -= 360.0;
    glutPostRedisplay();
}
void mouse(int btn,int state,int x,int y)
{
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(spinPyramid);
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(NULL);
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(float)w/(float)h,1.0,200.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,500);
    glutCreateWindow("Terminal_Lab");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
