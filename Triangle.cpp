#include "Triangle.h"
#include <GL/freeglut.h>
#include "Drawable.h" 

Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    base = 0.2;
    height = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Triangle::Triangle(float x, float y, float base, float height, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->base = base;
    this->height = height;
    this->r = r;
    this->g = g;
    this->b = b;
}

bool Triangle::contains(float px, float py) const {
    float x1 = x;
    float y1 = y + height / 2;
    float x2 = x - base / 2;
    float y2 = y - height / 2;
    float x3 = x + base / 2;
    float y3 = y - height / 2;

    float denom = ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3));
    float a = ((y2 - y3)*(px - x3) + (x3 - x2)*(py - y3)) / denom;
    float b = ((y3 - y1)*(px - x3) + (x1 - x3)*(py - y3)) / denom;
    float c = 1 - a - b;

    return (a >= 0) && (b >= 0) && (c >= 0);
}

void Triangle::draw() const{
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        glVertex2f(x - base/2, y - height/2);
        glVertex2f(x, y + height/2);
        glVertex2f(x + base/2, y - height/2);
    glEnd();
}

void Triangle::translate(float dx, float dy) {
    x += dx;
    y += dy;
}

void Triangle::scale(float factor) {
    base   *= factor;
    height *= factor;
}

void Triangle::setColor(float nr, float ng, float nb) {
    r = nr; g = ng; b = nb;
}