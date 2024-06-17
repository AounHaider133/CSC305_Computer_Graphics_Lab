#include<stdio.h>
#include<GL/glut.h>
GLfloat x = 0;
void init(GLdouble a,GLdouble b,GLdouble c,GLdouble d)
{
    GLfloat light_ambient[] = {a,b,c,d};
    GLfloat light_diffuse[] = {a,b,c,d};
    GLfloat light_specular[] = {1.0,1.0,1.0,1.0};
    GLfloat light_position[] = {1.0,1.0,1.0,0.5};
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}
void animate()
{
    x += 0.01;
    if(x >= 1)
        x = 0;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //Code for drawing lower sphere
    glPushMatrix();
    glTranslatef(-0.5+x,0,0);
    glRotatef(-60,1,0,0);
    glColor3f(1.0,0.0,0.0);
    init(1,0,0,0);
    glutSolidTorus(0.22,0.16,50,50);
    glPopMatrix();

    //Code for drawing upper sphere
    glPushMatrix();
    init(1,0,0,0);
    glTranslatef(-0.48+x,0.3,-0.25);
    glutSolidSphere(0.2,50,20);
    glPopMatrix();

    //Code for drawing beak of bird
    glPushMatrix();
    init(1,0,1,0);
    glTranslatef(-0.48+x,0.15,-0.5);
    glRotatef(45,1,0,0);
    glutSolidCone(0.04,0.12,100,100);
    glPopMatrix();

    //Code for left eye of bird
    glPushMatrix();
    glTranslatef(-0.58+x,0.2,-0.5);
    init(1,1,1,1);
    glutSolidSphere(0.015,50,20);
    glPopMatrix();

    //Code for right eye of bird
    glPushMatrix();
    glTranslatef(-0.38+x,0.2,-0.5);
    init(1,1,1,1);
    glutSolidSphere(0.015,50,20);
    glPopMatrix();

    //Code for drawing tail of bird
    glPushMatrix();
    glTranslatef(-0.42+x,0,0.25);
    glRotatef(-64,1,0,0);
    glRotatef(10,0,1,0);
    glColor3f(1.0,1.0,0.0);
    GLUquadric *cyll = gluNewQuadric();
    gluCylinder(cyll,0.05,0.05,0.75,100,100);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}
void mouse(int btn,int state,int x,int y)
{
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(animate);
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(NULL);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("CSC354 - Lab Task 4");
    init(1,1,0,0);
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();
}
