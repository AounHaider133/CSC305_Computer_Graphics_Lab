
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


static void reshape(int width, int height)
{
    glViewport(0,0,(GLsizei)width,(GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);

    glBegin(GL_LINES);
    glVertex2f(0.5f,0.0f); //starting point
    glVertex2f(-0.5f,0.0f);
    glEnd();

    glutSwapBuffers();
}


static void idle(void)
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(400,200);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Line Drawing");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutIdleFunc(idle); //refresh function

    glClearColor(0.0f,0.0f,0.0f,1.0f); //background color

    glutMainLoop();

    return EXIT_SUCCESS;
}
