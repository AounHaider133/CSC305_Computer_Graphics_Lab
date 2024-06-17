#include<GL/glut.h>

void update(int);
void update1(int);
void update2(int);
void drawScene();
void keyboard(unsigned char key,int x,int y);
void handleResize(int w,int h);

GLfloat a1=0.0,b1=0.0,c1=0.0;
GLfloat a2=0.0,b2=0.0,c2=0.0;
GLfloat a3=0.0,b3=0.0,c3=0.0;

GLfloat vertices[] = {-0.5,0.5,0.0,0.5,0.0,2.0,-0.5,2.0,0.4,1.9,0.2,1.6,-0.7,1.6,-0.9,1.9,-0.7,1.1,0.2,1.1,0.4,1.4,-0.9,1.4,-0.7,0.6,0.2,0.6,0.4,0.9,-0.9,0.9};
GLubyte cubeIndices[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("Traffic signal");
    //glEnableClientState(GL_VERTEX_ARRAY);
    //glVertexPointer(2,GL_FLOAT,0,vertices);
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutTimerFunc(1000,update,0);
    glutKeyboardFunc(keyboard);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
void handleResize(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
}
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f,0.0f,-5.0f);
    glPushMatrix();

    glTranslatef(0.0f,-1.0f,0.0f);
    glColor3f(0.5f,0.5f,0.5f);
    //Middle Rectangle
    glBegin(GL_QUADS);
    glVertex3f(-0.5f,0.5f,0.0f);
    glVertex3f(0.0f,0.5f,0.0f);
    glVertex3f(0.0f,2.0f,0.0f);
    glVertex3f(-0.5f,2.0f,0.0f);
    glEnd();

    glColor3f(0.6f,0.6f,0.6f);
    //Top-Right Quad
    glBegin(GL_QUADS);
    glVertex3f(0.0f,1.6f,0.0f);
    glVertex3f(0.2f,1.6f,0.0f);
    glVertex3f(0.4f,1.9f,0.0f);
    glVertex3f(0.0f,1.9f,0.0f);
    glEnd();

    //Middle right Quad
    glBegin(GL_QUADS);
    glVertex3f(0.0f,1.1f,0.0f);
    glVertex3f(0.2f,1.1f,0.0f);
    glVertex3f(0.4f,1.4f,0.0f);
    glVertex3f(0.0f,1.4f,0.0f);
    glEnd();

    //Bottom right Quad
    glBegin(GL_QUADS);
    glVertex3f(0.0f,0.6f,0.0f);
    glVertex3f(0.2f,0.6f,0.0f);
    glVertex3f(0.4f,0.9f,0.0f);
    glVertex3f(0.0f,0.9f,0.0f);
    glEnd();

    //Top Left Quad
    glBegin(GL_QUADS);
    glVertex3f(-0.5f,1.6f,0.0f);
    glVertex3f(-0.7f,1.6f,0.0f);
    glVertex3f(-0.9f,1.9f,0.0f);
    glVertex3f(-0.5f,1.9f,0.0f);
    glEnd();

    //Middle left Quad
    glBegin(GL_QUADS);
    glVertex3f(-0.5f,1.1f,0.0f);
    glVertex3f(-0.7f,1.1f,0.0f);
    glVertex3f(-0.9f,1.4f,0.0f);
    glVertex3f(-0.5f,1.4f,0.0f);
    glEnd();

    //Bottom left Quad
    glBegin(GL_QUADS);
    glVertex3f(-0.5f,0.6f,0.0f);
    glVertex3f(-0.7f,0.6f,0.0f);
    glVertex3f(-0.9f,0.9f,0.0f);
    glVertex3f(-0.5f,0.9f,0.0f);
    glEnd();
    //glDrawElements(GL_QUADS,16,GL_UNSIGNED_BYTE,cubeIndices);

    //Red Light
    glPushMatrix();
    glTranslatef(-0.5f,2.5f,-5.0f);
    glColor3f(a1,b1,c1);
    glutSolidSphere(0.3,200,2);
    glPopMatrix();
    glPopMatrix();

    //Yellow Light
    glPushMatrix();
    glTranslatef(-0.5f,0.5f,-5.0f);
    glColor3f(a2,b2,c2);
    glutSolidSphere(0.3,200,2);
    glPopMatrix();

    //Green Light
    glPushMatrix();
    glTranslatef(-0.5f,-0.5f,-5.0f);
    glColor3f(a3,b3,c3);
    glutSolidSphere(0.3,200,2);
    glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
void update(int value)
{
    a1=1.0;
    b1=0.0;
    c1=0.0;
    a2=0.0;
    b2=0.0;
    c2=0.0;
    a3=0.0;
    b3=0.0;
    c3=0.0;
    drawScene();
    glutPostRedisplay();
    glutTimerFunc(1000,update1,0);
}
void update1(int value)
{
    a1=0.0;
    b1=0.0;
    c1=0.0;
    a2=1.0;
    b2=1.0;
    c2=0.0;
    a3=0.0;
    b3=0.0;
    c3=0.0;
    drawScene();
    glutPostRedisplay();
    glutTimerFunc(1000,update2,0);
}
void update2(int value)
{
    a1=0.0;
    b1=0.0;
    c1=0.0;
    a2=0.0;
    b2=0.0;
    c2=0.0;
    a3=0.0;
    b3=1.0;
    c3=0.0;
    drawScene();
    glutPostRedisplay();
    glutTimerFunc(1000,update,0);
}
void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 27:
          exit(0);
        break;
    }
}
