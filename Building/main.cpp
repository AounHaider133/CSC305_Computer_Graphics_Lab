#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

#define SW 750
#define SH 750
#define m1X -1.2*xSc
#define m2X 0.1*xSc
float yM1,yM2;

const float DEG2RAD = 3.14159/180;
float leftmost,rightmost;
float alignYBottom;

#define FLAG1 1
#define RHOM1 2
#define E1 3
#define E2 4
#define E3 5
#define E4 6
#define DOME1 7
#define DOOR1 8
#define BASE 9
#define FLAG2 10
#define RHOM2 11
#define E5 12
#define E6 13
#define E7 14
#define E8 15
#define E9 16
#define EBUN 17
#define RBUN 18
#define RM2 19
#define LW 20
#define RW 21
#define MW 22
#define RED 23
#define PINK 24
#define YELLOW 25
#define AQUA 26
#define GREEN 27
#define BLUE 28
#define BLACK 29
#define WHITE 30
#define BROWN 31
#define DGREEN 32
#define DBLUE 33
#define ORANGE 34
#define CRIMSON 35
#define GOLD 36
#define GREY 37
#define VIOLET 38
#define SGREEN 39
#define WHEAT 40
#define MUD 41
#define RBROWN 42
#define ORCHID 43
#define TURQUOISE 44
#define PLUM 45
#define SBROWN 46
#define DGREY 47

int selected = 0;
void gl_draw();
void gl_init(int x,int h);
void gl_select(int x,int y);
void gl_setall(GLint hits,GLuint *buff);
void mouseClick();
void mousedw(int x,int y,int but);
void list_hits(GLint hits,GLuint *names);
float xSc = 1.5, ySc = 2;

class Triangle{
  public:
      float colorx,colory,colorz;
      float x1,x2,x3,y1,y2,y3;
      Triangle()
      {
          colorx = 1;
          colory = 1;
          colorz = 1;
      }
      void SetValues(float x1p,float y1p,float x2p, float y2p,float x3p,float y3p)
      {
          x1 = x1p;
          y1 = y1p;
          x2 = x2p;
          y2 = y2p;
          x3 = x3p;
          y3 = y3p;
      }
      void assignColor(float a,float b,float c)
      {
          colorx = a;
          colory = b;
          colorz = c;
      }
      void draw(void)
      {
          glBegin(GL_POLYGON);
          glColor3f(colorx,colory,colorz);
          glVertex2f(x1,y1);
          glVertex2f(x2,y2);
          glVertex2f(x3,y3);
          glEnd();

          glBegin(GL_LINE_LOOP);
          glColor3f(0,0,0);
          glVertex2f(x1,y1);
          glVertex2f(x2,y2);
          glVertex2f(x3,y3);
          glEnd();
      }
};
class Ellipse{
  public:
      float left;
      float right;
      float cx,cy,r1,r2;
      float colorx,colory,colorz;
      Ellipse()
      {
          colorx = 1;
          colory = 1;
          colorz = 1;
          left = 0;
          right = 0;
      }
      void setValues(float cxp,float cyp,float r1p,float r2p)
      {
          cx = cxp;
          cy = cyp;
          r1 = r1p;
          r2 = r2p;
      }
      void assignColor(float a,float b,float c)
      {
          colorx = a;
          colory = b;
          colorz = c;
      }
      void draw(void)
      {
          float theta = 2 * 3.1415926 / 360;
          float c = cosf(theta);
          float s = sinf(theta);
          float t;
          float x = r1;
          float y = r2;

          glBegin(GL_TRIANGLE_FAN);
          glColor3f(colorx,colory,colorz);
          leftmost = 100;

          for(int ii=0;ii<360;ii++)
          {
              glVertex2f(r1*x + cx,r2*y + cy);
              if(r1*x + cx < leftmost)
                leftmost = r1*x + cx;

              //apply the rotation matrix
              t = x;
              x = c*x - s*y;
              y = s*t + c*y;
          }
          left = leftmost;
          glEnd();
          glBegin(GL_LINE_LOOP); //to draw border
          glColor3f(0,0,0);
          for(int ii = 0; ii<360;ii++)
          {
              glVertex2f(r1*x+cx,r2*y+cy);

              //apply the rotation
              t = x;
              x = c*x - s*y;
              y = s*t + c*y;
          }
          glEnd();
      }
};
class Rectangle{
  public:
      float x1,y1,x2,y2;
      float colorx,colory,colorz;
      char* name;
      Rectangle()
      {
          colorx = 1;
          colory = 1;
          colorz = 1;
      }
      void setValues(float x1p,float y1p,float x2p,float y2p)
      {
          x1 = x1p;
          y1 = y1p;
          x2 = x2p;
          y2 = y2p;
          draw();
      }
      void assignColor(float a,float b,float c)
      {
          colorx = a;
          colory = b;
          colorz = c;
      }
      void setColorName(char *n)
      {
          name = n;
      }
      void draw(void)
      {
          glBegin(GL_POLYGON);
          glColor3f(colorx,colory,colorz);
          glVertex2f(x1,y1);
          glVertex2f(x2,y1);
          glVertex2f(x2,y2);
          glVertex2f(x1,y2);
          glEnd();

          glBegin(GL_LINES);
          glColor3f(0,0,0);
          glVertex2f(x1,y1);
          glVertex2f(x1,y2);
          glEnd();

          glBegin(GL_LINES);
          glColor3f(0,0,0);
          glVertex2f(x2,y1);
          glVertex2f(x2,y2);
          glEnd();
          glBegin(GL_LINES);
          glColor3f(0,0,0);
          glVertex2f(x2,y2);
          glVertex2f(x1,y2);
          glEnd();
      }
};
class Dome{
  public:
      Ellipse e;
      Rectangle r;
      void setValues(float cx,float cy,float r1,float r2,float length)
      {
          e.setValues(cx,cy,r1,r2);
          e.draw();
          e.right = cx*ySc - e.left;
          r.setValues(e.left,cy,e.right,cy-length);
      }
      void assignColor(float a,float b,float c)
      {
          e.assignColor(a,b,c);
          r.assignColor(a,b,c);
      }
      void Draw(void)
      {
          e.draw();
          r.draw();
      }
};
class Flag{
  public:
      Triangle t;

      void setValues(float x,float y,float dist)
      {
          t.SetValues(x,y,x,y-dist,x+(dist/2),y-(dist/2));
      }
      void assignColor(float a,float b,float c)
      {
          t.assignColor(a,b,c);
      }
      void draw(void)
      {
          t.draw();
      }
};

class Rhombus
{
    public:
        float x1,x2,x3,x4,y1,y2,y3,y4;
        float colorx,colory,colorz;
    Rhombus()
    {
        colorx = 1;
        colory = 1;
        colorz = 1;
    }
    void setValues(float x,float y,float xDst,float yDst)
    {
        x1 = x;
        y1 = y;
        x2 = x - xDst;
        y2 = y - yDst;
        x3 = x;
        y3 = y-2*yDst;
        x4 = x+xDst;
        y4 = y-yDst;
    }
    void assignColor(float a,float b,float c)
    {
        colorx = a;
        colory = b;
        colorz = c;
    }
    void draw(void)
    {
        glBegin(GL_POLYGON);
        glColor3f(colorx,colory,colorz);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0,0,0);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
        glEnd();

    }

};
Flag f1,f2;
Rhombus top1,top2;
Ellipse e1,e2,e3,e4;
Ellipse e5,e6,e7,e8,e9;
Dome dome1,dome2;
Dome door1,door2;
Rectangle base;
Ellipse eBundle;
Rectangle rBundle;
Rectangle rm2;
Dome leftW,rightW,midW;
Rectangle pCOlor[25];
float cx=1,cy=1,cz=1;

void drawMosque1(void)
{
    glLoadName(FLAG1);
    f1.setValues(m1X,yM1,0.2*ySc);
    glLoadName(1);
    f1.draw();
    yM1 -= 0.2*ySc;
    //top
    glLoadName(RHOM1);
    top1.setValues(m1X,yM1,0.05*xSc,0.1*ySc);
    top1.draw();
    yM1 -= 0.2*ySc;
    //top ends
    //ellipses
    yM1 -= 0.1*ySc;
    e1.setValues(m1X,yM1,0.4*xSc,0.23*ySc);
    yM1 -= 0.1*ySc;
    e2.setValues(m1X,yM1,0.45*xSc,0.23*ySc);
    yM1 -= 0.1*ySc;
    e3.setValues(m1X,yM1,0.5*xSc,0.23*ySc);
    yM1 -= 0.1*ySc;
    e4.setValues(m1X,yM1,0.55*xSc,0.23*ySc);
    yM1 -= 0.1*ySc;
    glLoadName(E1);
    e1.draw();
    glLoadName(E2);
    e2.draw();
    glLoadName(E3);
    e3.draw();
    glLoadName(E4);
    e4.draw();

    glLoadName(DOME1);
    dome1.setValues(m1X,yM1,0.6*xSc,0.23*ySc,1*ySc);
    dome1.Draw();
    yM1 -= 0.3*ySc;

    glLoadName(DOOR1);
    door1.setValues(m1X,yM1,0.4*xSc,0.2*ySc,1.4);
    yM1 -= 0.8*ySc;

    glLoadName(BASE);
    base.setValues(leftmost-0.4*xSc,yM1,2.5,yM1-0.15*ySc);
    base.draw();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(leftmost-0.4*xSc,yM1);
    glVertex2f(2.5,yM1);
    glEnd();
    alignYBottom = yM1;
}
void drawMosque2()
{
    glLoadName(FLAG2);
    f2.setValues(m2X,yM2,0.2*ySc);
    f2.draw();
    yM2 -= 0.2*ySc;

    //top
    glLoadName(RHOM2);
    top2.setValues(m2X,yM2,0.05*xSc,0.1*ySc);
    top2.draw();
    yM2 -= 0.2*ySc;
    //top ends
    yM2 -= 0.1*ySc;

    //Ellipses
    e5.setValues(m2X,yM2,0.4*xSc,0.23*ySc);
    yM2 -= 0.1*ySc;
    e6.setValues(m2X,yM2,0.5*xSc,0.23*ySc);
    yM2 -= 0.1*ySc;
    e7.setValues(m2X,yM2,0.6*xSc,0.23*ySc);
    yM2 -= 0.1*ySc;
    e8.setValues(m2X,yM2,0.7*xSc,0.23*ySc);
    yM2 -= 0.1*ySc;
    e9.setValues(m2X,yM2,0.8*xSc,0.23*ySc);
    yM2 -= 0.1*ySc;

    glLoadName(E5);
    e5.draw();
    glLoadName(E6);
    e6.draw();
    glLoadName(E7);
    e7.draw();
    glLoadName(E8);
    e8.draw();
    glLoadName(E9);
    e9.draw();

    //these are always together
    glLoadName(EBUN);
    eBundle.setValues(m2X,yM2,0.9*xSc,0.23*ySc);

    eBundle.draw();

    rBundle.setValues(leftmost-0.07*xSc,yM2,(m2X*ySc - leftmost + 0.07*xSc),yM2-0.1*ySc);

    rBundle.draw();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(leftmost,yM2);
    glVertex2f(leftmost-0.07*xSc,yM2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f((m2X*ySc - leftmost + 0.07*xSc),yM2);
    glVertex2f((m2X*ySc - leftmost),yM2);
    glEnd();
    yM2 -= 0.1*ySc;
    //Bundle over

    glLoadName(RM2);
    rm2.setValues(leftmost,yM2,(m2X*ySc - leftmost),alignYBottom);
    rm2.draw();

    //window top = 3/4 of size bottom = 1/4 door bottom = 7/8
    //ellipse: center: (4/5) y(3/4) : x: mx2, mx2+-(?) : ?: 1/3
    //polygons : y = ellipseYs, x: leftmost etc
    float horizontal,vertical;
    horizontal = (m2X - leftmost) * 2;
    vertical = yM2 - alignYBottom;

    glLoadName(LW);

    leftW.setValues((m2X - horizontal/3),(yM2 - vertical/3),0.35*xSc,0.15*ySc,vertical/4);
    leftW.Draw();

    glLoadName(RW);
    rightW.setValues((m2X+horizontal/3),(yM2 - vertical/3),0.35*xSc,0.15*ySc,vertical/4);
    rightW.Draw();

    glLoadName(MW);
    midW.setValues(m2X,(yM2 - vertical/3),0.38*xSc,0.15*ySc,-alignYBottom-vertical/3+yM2);
    midW.Draw();
}
void drawPalette(void)
{
    int x = 1.9;
    int y = 2.9;

    pCOlor[0].assignColor(1,0,0);
    pCOlor[0].setValues(x,y,x+0.2,y-0.2);

    pCOlor[1].assignColor(1,0,1);
    pCOlor[1].setValues(x+0.25,y,x+0.45,y-0.2);

    pCOlor[2].assignColor(1,1,0);
    pCOlor[2].setValues(x+0.5,y,x+0.7,y-0.2);

    pCOlor[3].assignColor(0,1,1);
    pCOlor[3].setValues(x+0.75,y,x+0.95,y-0.2);

    pCOlor[4].assignColor(0,1,0);
    pCOlor[4].setValues(x+1,y,x+1.2,y-0.2);

    pCOlor[5].assignColor(0,0,1);
    pCOlor[5].setValues(x,y-0.25,x+0.2,y-0.45);

    pCOlor[6].assignColor(0,0,0);
    pCOlor[6].setValues(x+0.25,y-0.25,x+0.45,y-0.45);

    pCOlor[7].assignColor(1,1,1);
    pCOlor[7].setValues(x+0.5,y-0.25,x+0.7,y-0.45);

    pCOlor[8].assignColor(0.5,0,0);
    pCOlor[8].setValues(x+0.75,y-0.25,x+0.95,y-0.45);

    pCOlor[9].assignColor(0,0.5,0);
    pCOlor[9].setValues(x+1,y-0.25,x+1.2,y-0.45);

    pCOlor[10].assignColor(0,0,0.5);
    pCOlor[10].setValues(x,y-0.5,x+0.2,y-0.7);

    pCOlor[11].assignColor(1,0.5,0.3);
    pCOlor[11].setValues(x+0.25,y-0.5,x+0.45,y-0.7);

    pCOlor[12].assignColor(0.8,0.07,0);
    pCOlor[12].setValues(x+0.5,y-0.5,x+0.7,y-0.7);

    pCOlor[13].assignColor(1,0.8,0);
    pCOlor[13].setValues(x+0.75,y-0.5,x+0.95,y-0.7);

    pCOlor[14].assignColor(0.6,0.6,0.6);
    pCOlor[14].setValues(x+1,y-0.5,x+1.2,y-0.7);

    pCOlor[15].assignColor(0.51,0.12,0.56);
    pCOlor[15].setValues(x,y-0.75,x+0.2,y-0.95);

    pCOlor[16].assignColor(0.5,0.7,0.5);
    pCOlor[16].setValues(x+0.25,y-0.75,x+0.45,y-0.95);

    pCOlor[17].assignColor(0.9,0.8,0.7);
    pCOlor[17].setValues(x+0.5,y-0.75,x+0.7,y-0.95);

    pCOlor[18].assignColor(0.7,0.5,0.04);
    pCOlor[18].setValues(x+0.75,y-0.75,x+0.95,y-0.95);

    pCOlor[19].assignColor(0.8,0.56,0.56);
    pCOlor[19].setValues(x+1,y-0.75,x+1.2,y-0.95);

    pCOlor[20].assignColor(0.8,0.4,0.83);
    pCOlor[20].setValues(x,y+0.05,x+0.2,y+0.25);

    pCOlor[21].assignColor(0.68,0.93,0.93);
    pCOlor[21].setValues(x+0.25,y+0.05,x+0.45,y+0.25);

    pCOlor[22].assignColor(0.8,0.6,0.8);
    pCOlor[22].setValues(x+0.5,y+0.05,x+0.7,y+0.25);

    pCOlor[23].assignColor(0.95,0.74,0.37);
    pCOlor[23].setValues(x+0.75,y+0.05,x+0.95,y+0.25);

    pCOlor[24].assignColor(0.3,0.3,0.3);
    pCOlor[24].setValues(x+1,y+0.05,x+1.2,y+0.25);

    glLoadName(RED);
    pCOlor[0].draw();

    glLoadName(PINK);
    pCOlor[1].draw();

    glLoadName(YELLOW);
    pCOlor[2].draw();

    glLoadName(AQUA);
    pCOlor[3].draw();

    glLoadName(GREEN);
    pCOlor[4].draw();

    glLoadName(BLUE);
    pCOlor[5].draw();

    glLoadName(BLACK);
    pCOlor[6].draw();

    glLoadName(WHITE);
    pCOlor[7].draw();

    glLoadName(BROWN);
    pCOlor[8].draw();

    glLoadName(DGREEN);
    pCOlor[9].draw();

    glLoadName(DBLUE);
    pCOlor[10].draw();

    glLoadName(ORANGE);
    pCOlor[11].draw();

    glLoadName(CRIMSON);
    pCOlor[12].draw();

    glLoadName(GOLD);
    pCOlor[13].draw();

    glLoadName(GREY);
    pCOlor[14].draw();

    glLoadName(VIOLET);
    pCOlor[15].draw();

    glLoadName(SGREEN);
    pCOlor[16].draw();

    glLoadName(WHEAT);
    pCOlor[17].draw();

    glLoadName(MUD);
    pCOlor[18].draw();

    glLoadName(RBROWN);
    pCOlor[19].draw();

    glLoadName(ORCHID);
    pCOlor[20].draw();

    glLoadName(TURQUOISE);
    pCOlor[21].draw();

    glLoadName(PLUM);
    pCOlor[22].draw();

    glLoadName(SBROWN);
    pCOlor[23].draw();

    glLoadName(DGREY);
    pCOlor[24].draw();
}
void gl_draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLubyte pat[] = {
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
    };

    yM1 = 2.5;
    yM2 = yM1 - 0.6;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
    glEnable(GL_POLYGON_STIPPLE);

    glPolygonStipple(pat);
    glColor3f(0.8,0.3,1);
    glRectf(-500,-500,500,500);
    glDisable(GL_POLYGON_STIPPLE);
    drawMosque1();
    drawMosque2();
    drawPalette();
    char paint[15] = "OPENGL PAINT";

    glColor3f(0,0,0);
    glRasterPos3f(-0.8,2.5,0.3);

    for(int i=0; paint[i]!='\0';i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,paint[i]);
    }
    glutSwapBuffers();
}
void gl_init(int w,int h)
{
    glClearColor(1,1,1,0);
    glShadeModel(GL_FLAT);
    glViewport(0,0,w,h);
    glLoadIdentity();
    gluPerspective(60.0,1.0,0.0001,1000.0);
    glMatrixMode(GL_MODELVIEW);
}
void mouseClick(int button,int state,int x,int y)
{
    if((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
    {
        cout<<"Mouse button "<<button<<" pressed at "<<x<<" "<<y<<endl;
        gl_select(x,SH-y);
    }
}
void gl_select(int x,int y)
{
    GLuint buff[64] = {0};
    GLint hits,view[4];
    int id;

    //Choose buffer where selected objects' meta data will be stored
    glSelectBuffer(64,buff);

    //Retrieve info about the viewport
    glGetIntegerv(GL_VIEWPORT,view);

    //Switching in selection mode
    glRenderMode(GL_SELECT);

    //Clearing the name stack, this stack contains all the information about the objects
    glInitNames();

    //Fill the stack with one element
    glPushName(0);

    //Modifying the viewing volume, restricting selection area around the cursor
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    //Restrict to draw and area around the cursor
    gluPickMatrix(x,y,1.0,1.0,view);
    gluPerspective(60,1.0,0.0001,1000.0);
    //Draw the objects into the screen
    glMatrixMode(GL_MODELVIEW);
    //Draw only the names in the stack and fill the array
    glutSwapBuffers();
    gl_draw();

    //Remember, we do pushMatrix in project mode
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    //Get number of objects drawed in that area and return to render mode
    hits = glRenderMode(GL_RENDER);
    //Print list of objects
    list_hits(hits,buff);
    //Uncomment to show the whole buffer
    //gl_setall(hits,buff)
    glMatrixMode(GL_MODELVIEW);
}
void gl_setall(GLint hits, GLint *buff)
{
    GLint *p;
    int i;
    gl_draw();
    p = buff;
    for(i=0;i<6*4;i++)
    {
        cout<<"Slot "<<i<<" : - Value: "<<p[i]<<endl;
        cout<<"Buff size: "<<(GLubyte)buff[0]<<endl;
    }
}
void handleHit(int object)
{
    switch(object)
    {
        case FLAG1:
            f1.assignColor(cx,cy,cz);
        break;

        case RHOM1:
            top1.assignColor(cx,cy,cz);
        break;

        case E1:
            e1.assignColor(cx,cy,cz);
        break;

        case E2:
            e2.assignColor(cx,cy,cz);
        break;

        case E3:
            e3.assignColor(cx,cy,cz);
        break;

        case E4:
            e4.assignColor(cx,cy,cz);
        break;

        case DOME1:
            dome1.assignColor(cx,cy,cz);
        break;

        case DOOR1:
            door1.assignColor(cx,cy,cz);
        break;

        case BASE:
            base.assignColor(cx,cy,cz);
        break;

        case FLAG2:
            f2.assignColor(cx,cy,cz);
        break;

        case RHOM2:
            top2.assignColor(cx,cy,cz);
        break;

        case E5:
            e5.assignColor(cx,cy,cz);
        break;

        case E6:
            e6.assignColor(cx,cy,cz);
        break;

        case E7:
            e7.assignColor(cx,cy,cz);
        break;

        case E8:
            e8.assignColor(cx,cy,cz);
        break;

        case E9:
            e9.assignColor(cx,cy,cz);
        break;

        case EBUN:
            eBundle.assignColor(cx,cy,cz);
            rBundle.assignColor(cx,cy,cz);
        break;

        case RM2:
            rm2.assignColor(cx,cy,cz);
        break;

        case LW:
            leftW.assignColor(cx,cy,cz);
        break;

        case RW:
            rightW.assignColor(cx,cy,cz);
        break;

        case MW:
            midW.assignColor(cx,cy,cz);
        break;

        case RED:
            cx = 1;
            cy = 0;
            cz = 0;
        break;

        case PINK:
            cx = 1;
            cy = 0;
            cz = 1;
        break;

        case YELLOW:
            cx = 1;
            cy = 1;
            cz = 0;
        break;

        case AQUA:
            cx = 0;
            cy = 1;
            cz = 1;
        break;

        case GREEN:
            cx = 0;
            cy = 1;
            cz = 0;
        break;

        case BLUE:
            cx = 0;
            cy = 0;
            cz = 1;
        break;

        case BLACK:
            cx = 0;
            cy = 0;
            cz = 0;
        break;

        case WHITE:
            cx = 1;
            cy = 1;
            cz = 1;
        break;

        case BROWN:
            cx = 0.5;
            cy = 0;
            cz = 0;
        break;

        case DGREEN:
            cx = 0;
            cy = 0.5;
            cz = 0;
        break;

        case DBLUE:
            cx = 0;
            cy = 0;
            cz = 0.5;
        break;

        case ORANGE:
            cx = 1;
            cy = 0.5;
            cz = 0.3;
        break;

        case CRIMSON:
            cx = 0.8;
            cy = 0.07;
            cz = 0;
        break;

        case GOLD:
            cx = 1;
            cy = 0.8;
            cz = 0;
        break;

        case GREY:
            cx = 0.6;
            cy = 0.6;
            cz = 0.6;
        break;

        case VIOLET:
            cx = 0.51;
            cy = 0.12;
            cz = 0.56;
        break;

        case SGREEN:
            cx = 0.5;
            cy = 0.7;
            cz = 0.5;
        break;

        case WHEAT:
            cx = 0.9;
            cy = 0.8;
            cz = 0.7;
        break;

        case MUD:
            cx = 0.7;
            cy = 0.5;
            cz = 0.04;
        break;

        case RBROWN:
            cx = 0.8;
            cy = 0.56;
            cz = 0.56;
        break;

        case ORCHID:
            cx = 0.8;
            cy = 0.4;
            cz = 0.83;
        break;

        case TURQUOISE:
            cx = 0.68;
            cy = 0.92;
            cz = 0.92;
        break;

        case PLUM:
            cx = 0.8;
            cy = 0.6;
            cz = 0.8;
        break;

        case SBROWN:
            cx = 0.95;
            cy = 0.74;
            cz = 0.37;
        break;

        case DGREY:
            cx = 0.3;
            cy = 0.3;
            cz = 0.3;
        break;
    }
}
void list_hits(GLint hits,GLuint *names)
{
    int i;
    /**For each hit in the buffer are allocated 4 bytes
    1. Number of hits selected (always one, because when we draw each object we use glLoadName,
       so we replace the previous name in the stack)
    2. Min Z
    3. Max Z
    4. Name of the hit (glLoadName) */
    cout<<hits<<" hits:"<<endl;
    int max=0;
    int mi;
    for(i=0;i<hits;i++)
    {
        cout<<"Number: "<<(GLubyte)names[i*4]<<endl;
        cout<<"Min Z: "<<(GLubyte)names[i*4+1]<<endl;
        cout<<"Max Z: "<<(GLubyte)names[i*4+2]<<endl;
        cout<<"Name on stack: "<<(GLubyte)names[i*4+3]<<endl;

        if((GLubyte)names[i*4+3] > max)
        {
            max = (GLubyte)names[i*4+3];
            mi = i;
        }
        cout<<endl;
    }
    handleHit(max);
    gl_draw();
}
void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,3.0,0.0,3.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(SW,SH);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OPENENDED");
    glutDisplayFunc(gl_draw);
    glutReshapeFunc(NULL);
    glutMouseFunc(mouseClick);
    gl_init(SW,SH);
    glutMainLoop();
}
