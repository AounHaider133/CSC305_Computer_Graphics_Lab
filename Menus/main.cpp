
    #include<GL/glut.h>
    #include<GL/gl.h>

    int red=0,green=1,blue=0;

    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(red,green,blue);
        glBegin(GL_POLYGON);
        glVertex2f(-0.5,-0.5);
        glVertex2f(-0.5,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,-0.5);
        glEnd();
        glFlush();
    }
    int sub_menu;
    void color_menu(int id)
    {
        switch(id)
        {
            case 2: //red
                red = 1;
                green = 0;
                blue = 0;
            break;
            case 3: //blue
                red = 0;
                green = 0;
                blue = 1;
            break;
            case 4: //green
                red = 0;
                green = 1;
                blue = 0;
            break;
        }
        glutPostRedisplay();
    }
    void top_menu(int id)
    {
        switch(id)
        {
            case 1:
              exit(0);
              break;
            default:
                color_menu(id);
                break;
        }
    }
    int main(int argc,char** argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500,500);

        glutInitWindowPosition(0.0,0.0);
        glutCreateWindow("rectangle");
        glutDisplayFunc(display);

        sub_menu = glutCreateMenu(color_menu);
        glutAddMenuEntry("RED",2);
        glutAddMenuEntry("BLUE",3);
        glutAddMenuEntry("YELLOW",4);
        glutCreateMenu(top_menu);

        glutAddMenuEntry("QUIT",1);
        glutAddSubMenu("COLOR",sub_menu);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutMainLoop();
        return 0;
    }
