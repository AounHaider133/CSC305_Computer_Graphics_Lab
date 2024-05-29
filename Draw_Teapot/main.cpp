//https://math.hws.edu/bridgeman/courses/324/s06/doc/opengl.html#materials
#include<GL/glut.h>
#include<GL/gl.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,1,1);
    glMatrixMode(GL_MODELVIEW);
    //glutSolidTeapot(0.5);
    //glutSolidTetrahedron();
    //glutSolidIcosahedron();
    //glutSolidCube(0.5);
    //glutSolidOctahedron();
    //glutSolidDodecahedron();

    /* draw scene */
    glPushMatrix();
    glPushMatrix();

    glTranslatef(0,0,-3); //middle teapot
    glutWireTeapot(1);

    glTranslatef(0,2,0); //top teapot
    glutSolidTeapot(1);

    glPopMatrix();

    glTranslatef(0,-2,-1); //bottom teapot
    glutSolidTeapot(1);

    //glPopMatrix();
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
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("Computer Graphics - Lab");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60,1,1,10);

    glMatrixMode(GL_MODELVIEW);

    gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
    //glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
    //glFrustum(-1.0,1.0,-1.0,1.0,-2,100);

    glutMainLoop();
}
