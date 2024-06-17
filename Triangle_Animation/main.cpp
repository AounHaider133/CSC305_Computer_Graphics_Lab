#include<GL/glut.h>

struct Point
{
    float x,y;
};

struct Point triangle[3] = {{-0.5,0.0},{0.5,0.0},{0.0,1.0}};
void handleKeyPress(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 27:
         exit(0);
    }
}
void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w <= h)
        glOrtho(-2.5,2.5,-2.5*(GLfloat)h/(GLfloat)w,2.5*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    else
        glOrtho(-2.5*(GLfloat)w/(GLfloat)h,2.5*(GLfloat)w/(GLfloat)h,-2.5,2.5,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
float _angle = 30.0f;
float _cameraAngle = 0.0f;

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.0,0.0,1.0);
    glRotatef((GLfloat)_angle,0.4,0.3,0.10);
    glBegin(GL_POLYGON);
    for(int i=0;i<3;i++)
        glVertex2f(triangle[i].x,triangle[i].y);
    glEnd();
    glutSwapBuffers();
}
void update(int value)
{
    _angle += 2.0f;
    if(_angle > 360)
        _angle -= 360;

    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Transformations and timers");
    glutDisplayFunc(drawScene);
    glutTimerFunc(25,update,0);
    glutKeyboardFunc(handleKeyPress);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
