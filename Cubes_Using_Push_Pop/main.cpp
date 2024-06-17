
    #include<stdlib.h>
    #include<GL/glut.h>

    void display(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINES);
        glVertex3f(-1,0,0);
        glVertex3f(1,0,0);
        glVertex3f(0,1,0);
        glVertex3f(0,-1,0);
        glEnd();

        //glPushMatrix();
        glLoadIdentity();
        glRotatef(10,1.0,0.0,0.0);

        glRotatef(10,0.0,1.0,0.0);
        glTranslatef(0,0,0);
        glColor3f(1.0,0.0,0.0);
        glutWireCube(0.2);
        //glPopMatrix();

        //glPushMatrix();
        //glLoadIdentity();
        glRotatef(10,1.0,0.0,0.0);
        glRotatef(10,0.0,1.0,0.0);

        glTranslatef(-.3,0,0);
        glColor3f(0.0,0.0,1.0);
        glutWireCube(0.2);
        //glPopMatrix();
        glFlush();
    }
    int main(int argc,char** argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Push & Pop");
        glLineWidth(2);
        glClearColor(1.0,1.0,1.0,0.0);
        glutDisplayFunc(display);
        glutMainLoop();
    }
