
    #include<GL/glut.h>
    #include<stdlib.h>
    #include<stdio.h>
    #define DRAW_SQUARE 1

    static void init(void)
    {
        glNewList(DRAW_SQUARE,GL_COMPILE);

        glBegin(GL_POLYGON);
        glVertex2f(0.0,0.0);
        glVertex2f(1.0,0.0);
        glVertex2f(1.0,1.0);
        glVertex2f(0.0,1.0);
        glEnd();
        glTranslatef(1.5,0.0,0.0);

        glEndList();
    }
    void display(void)
    {
        GLuint i;
        glClear(GL_COLOR_BUFFER_BIT);

        for(i=0; i<5; i++)
          glCallList(DRAW_SQUARE);
        glFlush();
    }
    void reshape(int w,int h)
    {
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(w <= h)
            gluOrtho2D(0.0,2.0,-0.5*(GLfloat)h/(GLfloat)w,1.5*(GLfloat)h/(GLfloat)w);
        else
            gluOrtho2D(0.0,2.0*(GLfloat)w/(GLfloat)h,-0.5,1.5);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    void keyboard(unsigned char key,int x,int y)
    {
        switch(key)
        {
            case 27: //ESC
              exit(0);
              break;
        }
    }
    int main(int argc,char** argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(650,50);
        glutCreateWindow("Squares");
        init();
        glutReshapeFunc(reshape);
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutMainLoop();
        return 0;
    }
