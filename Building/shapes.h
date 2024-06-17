// shapes.h
#ifndef SHAPES_H
#define SHAPES_H

#include <GL/glut.h>
#include <cmath>

// Define the Ellipse class
class Ellipse {
public:
    float cx, cy, rx, ry;
    float colorx, colory, colorz;

    Ellipse();
    void setValues(float x, float y, float radX, float radY);
    void assignColor(float a, float b, float c);
    void draw();
};

// Define the Rectangle class
class Rectangle {
public:
    float x1, y1, x2, y2;
    float colorx, colory, colorz;

    Rectangle();
    void setValues(float left, float top, float right, float bottom);
    void assignColor(float a, float b, float c);
    void draw();
};

// Define the Dome class
class Dome {
  public:
    Ellipse e;
    Rectangle r;

    void setValues(float cx, float cy, float r1, float r2, float length);
    void assignColor(float a, float b, float c);
    void draw();
};

// Define the Rhombus class
class Rhombus {
public:
    float x1, x2, x3, x4, y1, y2, y3, y4;
    float colorx, colory, colorz;

    Rhombus();
    void setValues(float x, float y, float xDst, float yDst);
    void assignColor(float a, float b, float c);
    void draw();
};

// Define the Flag class
class Flag {
public:
    Rhombus r;

    void setValues(float x, float y, float dist);
    void assignColor(float a, float b, float c);
    void draw();
};

#endif // SHAPES_H
