#include<stdio.h>
#include<GL/glut.h>

GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
                        {1.0,1.0,-1.0},{-1.0,1.0,-1.0},
                        {-1.0,-1.0,1.0},{1.0,-1.0,1.0},
                        {1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat normals[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
                        {1.0,1.0,-1.0},{-1.0,1.0,-1.0},
                        {-1.0,-1.0,1.0},{1.0,-1.0,1.0},
                        {1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},
                       {1.0,1.0,0.0},{.0,1.0,0.0},
                       {0.0,0.0,1.0},{1.0,0.0,1.0},
                       {1.0,1.0,1.0},{0.0,1.0,1.0}};

void polygon(int a,int b,int c,int d,int face)
{
    glBegin(GL_POLYGON);
    glColor3fv(colors[face]);
    glNormal3fv(normals[a]);
    glVertex3fv(vertices[a]);

    glNormal3fv(normals[b]);
    glVertex3fv(vertices[b]);

    glNormal3fv(normals[c]);
    glVertex3fv(vertices[c]);

    glNormal3fv(normals[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}
void colorcube()
{
    polygon(0,3,2,1,0);
    polygon(2,3,7,6,1);
    polygon(0,4,7,3,2);
    polygon(1,2,6,5,3);
    polygon(4,5,6,7,4);
    polygon(0,1,5,4,5);
}
static GLfloat theta[] = {2.0,2.0,2.0};
static GLint axis = 2;
static GLdouble viewer[] = {0.0,0.0,0.4}; //initial viewer location

void display()
{
    GLfloat light[3] = {0.0,20.0,0.0};
    GLfloat m[16];
    int i;
    for(i=0;i<16;i++) m[i] = 0.0;
    m[0] = m[5] = m[10] = 1.0;
    m[7] = -1.0/light[1];

    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);

    glPushMatrix();
    glTranslatef(0.0,3.0,0.0);
    glRotatef(theta[0],1.0,0.0,0.0);
    glRotatef(theta[1],0.0,1.0,0.0);
    glRotatef(theta[2],0.0,0.0,1.0);
    colorcube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(light[0],light[1],light[2]);
    glMultMatrixf(m);
    glTranslatef(-light[0],-light[1],-light[2]);
    glColor3f(0.0,0.0,0.0);
    glRotatef(theta[0],1.0,0.0,0.0);
    glRotatef(theta[1],0.0,1.0,0.0);
    glRotatef(theta[2],0.0,0.0,1.0);
    colorcube();
    glPopMatrix();

    //glFlush();
    glutSwapBuffers();
}
void spinCube()
{
    theta[axis] += 2.0;
    if(theta[axis] > 360.0) theta[axis] -= 360.0;
    glutPostRedisplay();
}
void mouse(int btn,int state,int x,int y)
{
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        axis = 0;
    if(btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        axis = 1;
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        axis = 2;

    theta[axis] += 2;
    if(theta[axis] > 360.0)
        theta[axis] -= 360.0;
    display();
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(w <= h)
        glOrtho(-4.0,4.0,-3.0*(GLfloat)h/(GLfloat)w,5.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    else
        glOrtho(-4.0*(GLfloat)w/(GLfloat)h,4.0*(GLfloat)w/(GLfloat)h,-3.0,5.0,-10.0,10.0);

    //glOrtho(-4.0,4.0,-4.0*(GLfloat)h/(GLfloat)w,4.0*(GLfloat)h/(GLfloat)w,-4.0,4.0);
    //glFrustum(-4.0,4.0,-4.0*(GLfloat)h/(GLfloat)w,4.0*(GLfloat)h/(GLfloat)w,1.0,100.0);
    //gluPerspective(45.0,w/h,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("Color-Cube");
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutIdleFunc(spinCube);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
