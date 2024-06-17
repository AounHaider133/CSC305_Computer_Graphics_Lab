

    #include<GL/glut.h>
    #include<stdio.h>
    #include<iostream>
    using namespace std;

    float _angle = 30.0f;
    float _cameraAngle = 90.0f;
    int flag = 1;
    void rotatedown()
    {
        _angle += 2.0f;
        if(_angle > 360)
            _angle -= 360;
        glutPostRedisplay();
    }
    void rotateup()
    {
        _angle -= 2.0f;
        if(_angle > 360)
            _angle -= 360;
        glutPostRedisplay();
    }
    void rotateleft()
    {
        _cameraAngle -= 2.0f;
        if(_cameraAngle > 360)
            _cameraAngle -= 360;

        glutPostRedisplay();

    }
    void rotateright()
    {
        _cameraAngle += 2.0f;
        if(_cameraAngle > 360)
            _cameraAngle -= 360;
        glutPostRedisplay();
    }

    //Called when a key is pressed
    void handleKeyPress(unsigned char key,int x,int y)
    {
        switch(key)
        {
            case 27: //ESC key
                exit(0);
            break;
            case 'd': rotatedown();
            break;
            case 'u': rotateup();
            break;
            case 'l': rotateleft();
            break;
            case 'r': rotateright();
            break;
            case 's': flag = 1;

            printf("\n coming in s");
            glutPostRedisplay();
            break;
            case 'w': flag = 0;
            printf("\n coming in w");
            glutPostRedisplay();
            break;
        }
    }

    void initRendering()
    {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);
        glClearColor(0.0f,0.0f,0.0f,0.0f);
        //change the background to black
    }
    void handleResize(int w,int h)
    {
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
    }

    //Draw the 3D scene
    void drawScene()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if(flag == 1)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glRotatef(-_cameraAngle,0.0f,0.0f,1.0f);
            glTranslatef(0.0f,0.0f,-5.0f);
            glPushMatrix();
            glTranslatef(0.0f,-1.0f,0.0f);
            glRotatef(_angle,0.0f,1.0f,0.0f);

            glColor3f(1.0f,0.0f,1.0f);
            glutSolidTorus(0.25,0.6,30,30);
            glTranslatef(0.0f,0.0f,0.22f);
            glColor3f(1.0f,1.0f,0.0);
            glutSolidTorus(0.25,0.78,30,30);

            glTranslatef(0.0f,0.0f,-0.63f);
            glColor3f(0.0,0.0,0.8f);
            glRotatef(270.0f,1.0f,0.0f,0.0f);
            glRotatef(90.0f,0.0f,1.0f,0.0f);
            glutSolidTeapot(0.51f);
            glPopMatrix();
            glPushMatrix();

            glTranslatef(0.22f,1.0f,0.0f);
            glRotatef(_angle,0.0f,1.0f,0.0f);
            glColor3f(0.0f,1.0f,0.0f);
            glutSolidTorus(0.25,0.6,30,30);
            glColor3f(0.5f,0.5f,0.0);
            glTranslatef(0.0f,0.0f,-0.35f);
            glutSolidSphere(0.63,20,20);
            glPopMatrix();
        }
        if(flag == 0)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glRotatef(-_cameraAngle,0.0f,0.0f,1.0f);
            glTranslatef(0.0f,0.0f,-5.0f);

            glPushMatrix();
            glTranslatef(0.0f,-1.0f,0.0f);
            glRotatef(_angle,0.0f,1.0f,0.0f);
            glColor3f(1.0f,0.0f,1.0f);
            glutWireTorus(0.25,0.6f,30,30);
            glTranslatef(0.0f,0.0f,0.22f);
            glColor3f(1.0f,1.0f,0.0f);
            glutWireTorus(0.25,0.78,30,30);

            glTranslatef(0.0f,0.0f,-0.63f);
            glColor3f(0.0f,0.0f,0.8f);
            glRotatef(270.0f,1.0f,0.0f,0.0f);
            glRotatef(90.0f,0.0f,1.0f,0.0f);
            glutWireTeapot(0.51f);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.22f,1.0f,0.0f);
            glRotatef(_angle,0.0f,1.0f,0.0f);
            glColor3f(0.0f,1.0f,0.0f);
            glutWireTorus(0.25,0.6,30,30);
            glColor3f(0.5f,0.5f,0.0f);
            glTranslatef(0.0f,0.0f,-0.35f);
            glutWireSphere(0.63,20,20);
            glPopMatrix();
        }
        glutSwapBuffers();

    }
    int main(int argc,char** argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutCreateWindow("3D Objects");

        initRendering();
        //glutFullScreen();
        glutDisplayFunc(drawScene);
        glutKeyboardFunc(handleKeyPress);
        glutReshapeFunc(handleResize);
        glutMainLoop();
    }
