#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define NUM_POINTS 3
#define PIE 3.142

struct Point{
  float x,y,z;
};

//initial POINTS
struct Point p[NUM_POINTS] = {{0.2,0.4,0.5},{0.0,0.1,0.5},{0.7,0.3,0.5}};
struct Point init_point;
double rotate_m[4][4];
double angle = 0.0;
int angleZ = 1;
void delay();
void clearMatrix();
void multiMat(int index);

void rotation_Zaxis()
{
    clearMatrix();
    angle = (PIE/180*angleZ);

    rotate_m[0][0] = (double)cos((double)angle);
    rotate_m[0][1] = (double)-sin((double)angle);
    rotate_m[1][0] = (double)sin((double)angle);
    rotate_m[1][1] = (double)cos((double)angle);

    for(int i=0;i<NUM_POINTS;i++)
    {
        multiMat(i);
        delay();
        glutPostRedisplay();
    }
}
void delay()
{
    for(int i=0;i<33333;i++)
    for(int j=0;j<33;j++) ;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluLookAt(-0.25,-0.25,0.25,0.0,0.0,0.0,0,1,0);
    glColor3f(0.0,1.0,0.0);

    //draw coordinate lines
    glBegin(GL_LINES);
    glVertex3f(-1,0,0);
    glVertex3f(1,0,0);
    glVertex3f(0,1,0);
    glVertex3f(0,-1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    for(int i=0;i<NUM_POINTS;i++)
     glVertex3f(p[i].x,p[i].y,p[i].z);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    for(int i=0;i<NUM_POINTS;i++)
     glVertex3f(p[i].x,p[i].y,p[i].z+0.2);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(p[0].x,p[0].y,p[0].z);
    glVertex3f(p[0].x,p[0].y,p[0].z+0.2);
    glVertex3f(p[1].x,p[1].y,p[1].z+0.2);
    glVertex3f(p[1].x,p[1].y,p[1].z);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(p[1].x,p[1].y,p[1].z);
    glVertex3f(p[1].x,p[1].y,p[1].z+0.2);
    glVertex3f(p[2].x,p[2].y,p[2].z+0.2);
    glVertex3f(p[2].x,p[2].y,p[2].z);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(p[2].x,p[2].y,p[2].z);
    glVertex3f(p[2].x,p[2].y,p[2].z+0.2);
    glVertex3f(p[0].x,p[0].y,p[0].z+0.2);
    glVertex3f(p[0].x,p[0].y,p[0].z);
    glEnd();

    glColor3f(1.0,0.0,0.0); //front face
    glBegin(GL_POLYGON);
    for(int k=0;k<NUM_POINTS;k++)
        glVertex3f(p[k].x,p[k].y,p[k].z);
    glEnd();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
    rotation_Zaxis();
}
void clearMatrix()
{
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    rotate_m[i][j] = (i == j) ? 1.0 : 0.0;
    //Loading identity matrix
}
void multiMat(int index)
{
    float temp[4][1] = {{p[index].x},{p[index].y},{p[index].z}};
    float nextMat[4][1];
    float sum;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            sum = 0.0;
            for(int k=0;k<4;k++)
                sum = sum+(rotate_m[i][k]*temp[k][j]);
            nextMat[i][j] = sum;
        }
    }
    p[index].x = nextMat[0][0];
    p[index].y = nextMat[1][0];
    p[index].z = nextMat[2][0];
}
void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-2.5,2.5,-2.5*(GLfloat)h/(GLfloat)w,2.5*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    else
        glOrtho(-2.5*(GLfloat)h/(GLfloat)w,2.5*(GLfloat)h/(GLfloat)w,-2.5,2.5,-10.0,10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("3D rotation along z-axis");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glClearColor(1,1,1,1);
    glPointSize(5.0);
    glutMainLoop();
}
