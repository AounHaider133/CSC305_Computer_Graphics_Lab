#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
using namespace std;

const float BOX_SIZE = 7.0f;
//The length of each side of the cube
float _angle = 0;

const GLfloat light_ambient[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat light_diffuse[] = {1.0f,1.0f,0.0f,1.0f};
const GLfloat ligt_specular[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat light_position[] = {500.0f,1000.0f,-200.0f,0.0f};
const GLfloat mat_ambient[] = {0.7f,0.7f,0.7f,1.0f};
const GLfloat mat_diffuse[] = {0.0f,0.0f,1.0f,1.0f};
const GLfloat mat_specular[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat high_shininess[] = {100.0f};

void handleKeyPress(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 27:
            exit(0);
        break;
    }
}
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}
void handleResize(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(float)w/(float)h,1.0,200.0);
}
void drawBox(float x,float y,float z)
{
    glBegin(GL_QUADS);

    //Top face
    glNormal3f(0.0f,1.0f,0.0f);
    glColor4f(x,y,z,0.3);
    glVertex3f(-BOX_SIZE/2,BOX_SIZE/2,-BOX_SIZE/2);
    glVertex3f(-BOX_SIZE/2,BOX_SIZE/2,BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,BOX_SIZE/2,BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,BOX_SIZE/2,-BOX_SIZE/2);

    //Bottom face
    glNormal3f(0.0f,-1.0f,0.0f);
    glColor4f(x,y,z,1.0);
    glVertex3f(-BOX_SIZE/2,-BOX_SIZE/2,-BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,-BOX_SIZE/2,-BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,-BOX_SIZE/2,BOX_SIZE/2);
    glVertex3f(-BOX_SIZE/2,-BOX_SIZE/2,BOX_SIZE/2);

    //Left face
    glNormal3f(-1.0f,0.0f,0.0f);
    glColor4f(x,y,z,0.5f);
    glVertex3f(-BOX_SIZE/2,-BOX_SIZE/2,-BOX_SIZE/2);
    glVertex3f(-BOX_SIZE/2,-BOX_SIZE/2,BOX_SIZE/2);
    glVertex3f(-BOX_SIZE/2,BOX_SIZE/2,BOX_SIZE/2);
    glVertex3f(-BOX_SIZE/2,BOX_SIZE/2,-BOX_SIZE/2);

    //Right face
    glNormal3f(1.0f,0.0f,0.0f);
    glColor4f(x,y,z,0.4f);
    glVertex3f(BOX_SIZE/2,-BOX_SIZE/2,-BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,BOX_SIZE/2,-BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,BOX_SIZE/2,BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,-BOX_SIZE/2,BOX_SIZE/2);

    //Front face
    glNormal3f(0.0f,0.0f,1.0f);
    glColor4f(x,y,z,0.0f);
    glVertex3f(-BOX_SIZE/2,-BOX_SIZE/2,BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,-BOX_SIZE/2,BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,BOX_SIZE/2,BOX_SIZE/2);
    glVertex3f(-BOX_SIZE/2,BOX_SIZE/2,BOX_SIZE/2);

    //Back face
    glNormal3f(0.0f,0.0f,-1.0f);
    glColor4f(x,y,z,1.0f);
    glVertex3f(-BOX_SIZE/2,-BOX_SIZE/2,-BOX_SIZE/2);
    glVertex3f(-BOX_SIZE/2,BOX_SIZE/2,-BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,BOX_SIZE/2,-BOX_SIZE/2);
    glVertex3f(BOX_SIZE/2,-BOX_SIZE/2,-BOX_SIZE/2);

    glEnd();
}
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);

    glScalef(0.5,0.5,0.5);
    glTranslatef(0.0,10.0,-18.5);
    glRotatef(40,1.0,0.0,0.0);
    glRotatef(50,0.0,1.0,0.0);
    glRotatef(-0,0.0,0.0,1.0);
    drawBox(0.0,0.5,1.0);
    glTranslatef(-10.0,-1.0,5.5);
    drawBox(0.0,1.0,0.0);
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400,400);

    glutCreateWindow("2D Transparent Cube");
    initRendering();

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeyPress);
    glutReshapeFunc(handleResize);

    glutMainLoop();
}
