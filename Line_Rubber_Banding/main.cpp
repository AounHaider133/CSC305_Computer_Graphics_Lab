
    #include<GL/glut.h>
    #include<iostream>
    using namespace std;

    float xm,ym,xmm,ymm,xm1,ym1,gw=500,gh=600;

    void mouse(int btn,int state,int x,int y)
    {
        if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            xm = x;
            ym = (gh - y);
            glColor3f(0.0,1.0,0.0);
            xmm = x;
            ymm = (gh-y);
        }
        if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            xmm = x;
            ymm = (gh-y);
            glColor3f(0.0,1.0,1.0);
            glLogicOp(GL_COPY);
            glLogicOp(GL_COPY);
        }
    }
    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void move(int x,int y)
    {
        glLogicOp(GL_XOR);

        glBegin(GL_LINES);
        glVertex2f(xm,ym);
        glVertex2f(xmm,ymm);
        glEnd();

        xmm = x;
        ymm = (gh-y);

        glBegin(GL_LINES);
        glVertex2f(xm,ym);
        glVertex2f(xmm,ymm);
        glEnd();

        glFlush();
    }
    void reshape(int w,int h)
    {
        gw = w;
        gh = h;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0,(GLdouble)w,0.0,(GLdouble)h);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glViewport(0,0,w,h);
    }

    void init()
    {
        glClearColor(1.0,1.0,1.0,1.0);
        glViewport(0,0,gw,gh);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0,(GLdouble)gw,0.0,(GLdouble)gh);
        glMatrixMode(GL_MODELVIEW);
    }

    int main(int argc,char** argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500,600);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Rubber band Line");

        init();
        glutMouseFunc(mouse);
        glutMotionFunc(move);
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glEnable(GL_COLOR_LOGIC_OP);
        glutMainLoop();
    }
