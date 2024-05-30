#include<GL/glut.h>

// Define a 32x32 stipple pattern
GLubyte stipplePattern[128] = {
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
    0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
};

    void myInit()
    {
        glClearColor(0.0,0.0,1.0,1.0);
        gluOrtho2D(0.5,0.5,0.05,0.5);
        glColor3d(1.0,0.0,0.0);
    }
void display()
{
    glColor3f(1,0,0);
    //glPointSize(9);

    glEnable(GL_POLYGON_STIPPLE);
    glPolygonStipple(stipplePattern);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5f,-0.5f);
    glVertex2f(0.5f,-0.5f);
    glVertex2f(0.5f,0.5f);
    glVertex2f(-0.5f,0.5f);
    glEnd();
    /*
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);    // V0 (central vertex)
    glVertex2f(0.5f, 0.0f);    // V1
    glVertex2f(0.5f, 0.5f);    // V2
    glVertex2f(0.0f, 0.5f);    // V3
    glVertex2f(-0.5f, 0.5f);   // V4
    glVertex2f(-0.5f, 0.0f);   // V5
    glVertex2f(0.0f, -0.5f);   // V6
    glEnd();*/

    /*
    //Quad Strip
    glBegin(GL_QUAD_STRIP);
    glVertex2f(-0.75f, -0.5f);  // V0
    glVertex2f(-0.75f, 0.5f);   // V1
    glVertex2f(-0.25f, -0.5f);  // V2
    glVertex2f(-0.25f, 0.5f);   // V3
    glVertex2f(0.25f, -0.5f);   // V4
    glVertex2f(0.25f, 0.5f);    // V5
    glVertex2f(0.75f, -0.5f);   // V6
    glVertex2f(0.75f, 0.5f);    // V7
    glEnd();*/


    /*
    //Line Loop
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f, -0.5f);  // V0
    glVertex2f(0.5f, -0.5f);   // V1
    glVertex2f(-0.5f, 0.0f);    // V2
    glVertex2f(0.5f, 0.0f);   // V3
    glVertex2f(-0.5f, 0.5f);   // V4
    glVertex2f(0.5f, 0.5f);   // V5
    glEnd();*/

    /*glBegin(GL_QUADS);
    // First Quad
    glVertex2f(-0.5f, -0.5f);  // V0
    glVertex2f(-0.5f, 0.5f);   // V1
    glVertex2f(0.5f, 0.5f);    // V2
    glVertex2f(0.5f, -0.5f);   // V3

    // Second Quad
    glVertex2f(-0.75f, -0.75f);  // V4
    glVertex2f(-0.75f, -0.25f);  // V5
    glVertex2f(-0.25f, -0.25f);  // V6
    glVertex2f(-0.25f, -0.75f);  // V7
    glEnd();*/

    /*
    //Triangles
    glBegin(GL_TRIANGLES);
    // First Triangle
    glVertex2f(-0.5f, -0.5f);  // V0
    glVertex2f(0.0f, 0.5f);    // V1
    glVertex2f(0.5f, -0.5f);   // V2

    // Second Triangle
    glVertex2f(-0.75f, -0.75f);  // V3
    glVertex2f(-0.25f, 0.25f);   // V4
    glVertex2f(0.75f, -0.75f);   // V5
    glEnd();
    */

    /*
    //Shared points triangle (2 triangles with points shared)
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(1.0f, 0.5f);
    glEnd();

    /*
    //LINES
    glBegin(GL_LINES);
    glVertex2f(-0.5f, -0.5f);  // V0
    glVertex2f(0.5f, -0.5f);   // V1 (First Line Segment)

    glVertex2f(-0.5f, 0.0f);   // V2
    glVertex2f(0.5f, 0.0f);    // V3 (Second Line Segment)

    glVertex2f(-0.5f, 0.5f);   // V4
    glVertex2f(0.5f, 0.5f);    // V5 (Third Line Segment)
    glEnd();*/

    /*
    //POLYGON
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.5f);  // V0
    glVertex2f(-0.5f, 0.5f);   // V1
    glVertex2f(0.0f, 0.75f);   // V2
    glVertex2f(0.5f, 0.5f);    // V3
    glVertex2f(0.5f, -0.5f);   // V4
    glEnd();*/


    /*
    //POINTS
    glBegin(GL_POINTS);
    glVertex2f(0,0);
    glVertex2f(0,0.3);
    glVertex2f(0.3,0.3);
    glVertex2f(0.3,0);
    glEnd();*/

    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutCreateWindow("Triangle Fan");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}

