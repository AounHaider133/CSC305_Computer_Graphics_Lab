#include<GL/glut.h>
#include<stdlib.h>

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,50.0,0.0,50.0);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    GLfloat vertices[3][2] = {{0.0,0.0},{25.0,50.0},{50.0,0.0}};
    int j,k;
    int rand();
    glPointSize(3);
    GLfloat p[2] = {7.5,5.0};

    glClear(GL_COLOR_BUFFER_BIT); //clear window
    glBegin(GL_POINTS);
    //compute and plot 5000 points
    for(k = 0; k<5000; k++)
    {
        j = rand()%3; //pick a vertex at random
        //compute point halfway b/w selected vertex and old point
        p[0] = (p[0]+vertices[j][0])/2.0;
        p[1] = (p[1]+vertices[j][1])/2.0;

        //plot new points
        glVertex2fv(p);
    }
    glEnd();
    glFlush(); //clear buffers
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(400,400);
    glutInitWindowPosition(600,200);

    glutCreateWindow("Sierpinski Gasket");
    glutDisplayFunc(display);

    init();

    glutMainLoop();
    return 0;
}
