#include<GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glutSolidCube(2); //building

    glTranslatef(0,1,0);
    glPushMatrix();
    glRotatef(-90,1,0,0);
    glutSolidCone(1.5,1,16,8); //roof
    glPopMatrix();

    glTranslatef(0.75,0.5,-0.75);
    glPushMatrix(); //chimney
    glScalef(1,3,1);
    glutSolidCube(0.25);

    glPopMatrix();
    glPopMatrix();
    glTranslatef(0,-0.65,2);

    //car
    glPushMatrix();
    glPushMatrix(); //body
    glScalef(2,0.5,1);
    glutSolidCube(0.5);
    glPopMatrix();
    glTranslatef(0,0,0.25);
    glPushMatrix();
    glTranslatef(-.4,-.2,0);
    glutSolidTorus(.05,.1,8,8); //wheel
    glTranslatef(.8,0,0);
    glutSolidTorus(.05,.1,8,8); //wheel
    glPopMatrix();
    glTranslatef(0,0,-.5);
    glPushMatrix();
    glTranslatef(-.4,-.2,0);
    glutSolidTorus(.05,.1,8,8); //wheel
    glTranslatef(.8,0,0);
    glutSolidTorus(.05,.1,8,8); //wheel
    glPopMatrix();
    glPopMatrix();

    glFlush();

}
void reshape(int width,int height)
{
    glViewport(0,0,width,height);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow("House");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40,1,4,20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0,5.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
    glutMainLoop();
}
