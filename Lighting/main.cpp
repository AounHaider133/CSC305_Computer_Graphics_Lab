#include<GL/glut.h>

void displaySolid()
{
    //GLfloat mat_ambient[] = {2.0f,1.0f,1.0f,1.0f};
    GLfloat mat_diffuse[] = {0.5f,0.5f,0.5f,0.5f};
    GLfloat mat_specular[] = {2.0f,2.0f,2.0f,2.0f};
    GLfloat mat_shininess[] = {50.0f};

    //glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

    //set the light source & properties
    GLfloat lightIntensity[] = {0.7f,0.7f,0.7f,1.0f};
    GLfloat light_position[] = {2.0f,6.0f,3.0f,0.0f};
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);

    //set the camera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double winHt = 0.7; //half-height of window
    glOrtho(-winHt*64/48,winHt*64/48,-winHt,winHt,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0);

    //start drawing
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //bigger teapot
    glPushMatrix();
    glColor3f(1.0f,6.0f,0.0f);

    glTranslated(1.2,1.0,0.5);
    //change the value of x,y and z to move the teapot
    //plot in x,y and z axis
    glRotated(45,0,1,0);
    glutSolidTeapot(0.17);
    glPopMatrix();
    //cube
    glPushMatrix();
    glColor3f(0.0f,0.0f,1.0f);
    glTranslated(0.95,0.60,0.30);
    glRotated(65,0,1,0);
    glutSolidCube(0.3f);

    //cylinder
    GLUquadricObj *qobj;
    qobj = gluNewQuadric();
    glPushMatrix();
    gluQuadricDrawStyle(qobj,GL_FILL); //flat shaded
    gluQuadricNormals(qobj,GLU_SMOOTH);
    glColor3f(0.0f,1.0f,1.0f);

    glTranslated(-0.82,0.27,0.0);
    glRotated(90,5.0,0.0,0.0);
    glRotated(30,0.0,0.0,5.0);
    gluCylinder(qobj,0.15,0.15,0.4,360,360);
    glPopMatrix();

    //smaller teapot
    glPushMatrix();
    glColor3f(1.0f,0.4f,0.9f);
    glTranslated(-0.8,0.32,-0.1);
    //change the value of x,y and z to move the teapot
    //plot in x,y & z axis
    glutSolidTeapot(0.1);
    glPopMatrix();
    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("Simple shaded scene having teapot on a cube");
    glutDisplayFunc(displaySolid);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST | GL_NORMALIZE | GL_COLOR_MATERIAL);
    glClearColor(1,1,1,0);
    glViewport(0,0,640,480);
    glutMainLoop();
}
