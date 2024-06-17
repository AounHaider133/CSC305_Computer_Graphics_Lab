#include<GL/glut.h>

int x=2,y=2;
float size = 5;
enum ButtonState{DOWN,UP};
ButtonState bstate = UP;
void drawSquare(int x,int y)
{
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(x+size,y+size);
    glVertex2f(x-size,y+size);
    glVertex2f(x-size,y-size);
    glVertex2f(x+size,y-size);
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawSquare(x,y);
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 0x1B:
        case 'q':
        case 'Q':
            exit(0);
        break;
    }
}
void mouse(int button,int state,int mx,int my)
{
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        exit(0);
}
void motion(int mx,int my)
{
    x = mx;
    //y-axis is downward, so subtract to move it upward
    y = glutGet(GLUT_WINDOW_HEIGHT) - my;
    glutPostRedisplay();
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,w,0,h);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(400,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("pick square");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    reshape(400,400);
    glutMainLoop();
}
