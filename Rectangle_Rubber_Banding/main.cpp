#include<GL/glut.h>
#include<cstdlib>
#include<iostream>
using namespace std;

const int EscapeKey = 27;

const int MouseButtonPress = 0;
const int MouseButtonRelease = 1;
const int MouseLeftButton = 0;
const int MouseMiddleButton = 1;
const int MouseRightButton = 2;
const float White[] = {1.0,1.0,1.0};
//global variables
int ScreenWidth = 800;
int ScreenHeight = 600;

int startx,starty,endx,endy,lastbutton;

//function prototypes
void DrawRectangle(int x1,int y1,int x2,int y2,const float color[]);
//OpenGL callbacks
void display(void);
void reshape(int w,int h);
void keyboard(unsigned char key,int x,int y);
void mouseClick(int button,int state,int x,int y);
void mouseDrag(int x,int y);
void mousemotion(int x,int y);
void idle();
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(ScreenWidth,ScreenHeight);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Rubber band demo");

    glClearColor(0.0,0.0,0.0,0.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseDrag);
    //glutIdleFunc(idle);
    //allow XORing
    glEnable(GL_COLOR_LOGIC_OP);
    //go into OpenGL/GLUT main loop, never return
    glutMainLoop();
    return 0;
}
void DrawRectangle(int x1,int y1,int x2,int y2,const float color[])
{
    glColor3fv(color);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x1,y1);
    glVertex2i(x2,y1);
    glVertex2i(x2,y2);
    glVertex2i(x1,y2);
    glEnd();
    glFlush();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //draw a blue square
    /*glColor3f(0.0,0.5,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(500,300);
    glVertex2f(500,500);
    glVertex2f(700,500);
    glVertex2f(700,300);
    glEnd();*/
    DrawRectangle(startx,starty,endx,endy,White);
    glFlush();
}
void reshape(int w,int h)
{
    ScreenWidth = w;
    ScreenHeight = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,w,0.0,h);
    glViewport(0,0,w,h);
}
void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case EscapeKey:
            exit(0);
        break;
    }
}
void mouseClick(int button,int state,int x,int y)
{
    switch(button)
    {
        case MouseLeftButton:
          //create object
          if(state == MouseButtonPress)
          {
              //store coordinates
              startx = endx = x;
              starty = endy = ScreenHeight - y;
              glLogicOp(GL_XOR);
              DrawRectangle(startx,starty,endx,endy,White);
          }
          else if(state == MouseButtonRelease) //new endpoints
          {
              //erase last rectangle
              DrawRectangle(startx,starty,endx,endy,White);

              //store coordinates
              endx = x;
              endy = ScreenHeight - y;
              //restore to copy mode (default)
              glLogicOp(GL_COPY);
              //force redraw
              glutPostRedisplay();
          }
        break;
        case MouseMiddleButton: //no action
        break;
        case MouseRightButton: //no action
        break;
    }
    lastbutton = button;
}
void mouseDrag(int x,int y)
{
    if(lastbutton == MouseLeftButton)
    {
        //erase previous rectangle
        DrawRectangle(startx,starty,endx,endy,White);
        endx = x;
        endy = ScreenHeight - y;
        //draw new rectangle
        DrawRectangle(startx,starty,endx,endy,White);
    }
}
