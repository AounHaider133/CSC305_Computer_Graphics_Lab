// shapes.cpp
#include "shapes.h"

Ellipse::Ellipse() : colorx(1), colory(1), colorz(1) {}

void Ellipse::setValues(float x, float y, float radX, float radY) {
    cx = x;
    cy = y;
    rx = radX;
    ry = radY;
}

void Ellipse::assignColor(float a, float b, float c) {
    colorx = a;
    colory = b;
    colorz = c;
}

void Ellipse::draw() {
    glColor3f(colorx, colory, colorz);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++) {
        float theta = i * (M_PI / 180);
        glVertex2f(cx + rx * cos(theta), cy + ry * sin(theta));
    }
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float theta = i * (M_PI / 180);
        glVertex2f(cx + rx * cos(theta), cy + ry * sin(theta));
    }
    glEnd();
}

Rectangle::Rectangle() : colorx(1), colory(1), colorz(1) {}

void Rectangle::setValues(float left, float top, float right, float bottom) {
    x1 = left;
    y1 = top;
    x2 = right;
    y2 = bottom;
}

void Rectangle::assignColor(float a, float b, float c) {
    colorx = a;
    colory = b;
    colorz = c;
}

void Rectangle::draw() {
    glColor3f(colorx, colory, colorz);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void Dome::setValues(float cx, float cy, float r1, float r2, float length) {
    e.setValues(cx, cy, r1, r2);
    e.draw();
    r.setValues(cx - r1, cy, cx + r1, cy - length);
}

void Dome::assignColor(float a, float b, float c) {
    e.assignColor(a, b, c);
    r.assignColor(a, b, c);
}

void Dome::draw() {
    e.draw();
    r.draw();
}

Rhombus::Rhombus() : colorx(1), colory(1), colorz(1) {}

void Rhombus::setValues(float x, float y, float xDst, float yDst) {
    x1 = x;
    y1 = y;
    x2 = x - xDst;
    y2 = y - yDst;
    x3 = x;
    y3 = y - 2 * yDst;
    x4 = x + xDst;
    y4 = y - yDst;
}

void Rhombus::assignColor(float a, float b, float c) {
    colorx = a;
    colory = b;
    colorz = c;
}

void Rhombus::draw() {
    glColor3f(colorx, colory, colorz);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void Flag::setValues(float x, float y, float dist) {
    r.setValues(x, y, dist / 2, dist / 4);
}

void Flag::assignColor(float a, float b, float c) {
    r.assignColor(a, b, c);
}

void Flag::draw() {
    r.draw();
}
