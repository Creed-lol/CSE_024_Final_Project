#include "Point.h"
#include <GL/freeglut.h>
#include <algorithm>

Point::Point() {
    x = 0.0;
    y = 0.0;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 7;
}

Point::Point(float x, float y) : Point() {
    this->x = x;
    this->y = y;
}

Point::Point(float x, float y, float r, float g, float b) : Point(x, y) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Point::Point(float x, float y, float r, float g, float b, int size) : Point(x, y, r, g, b) {
    this->size = size;
}

void Point::translate(float dx, float dy) {
    x += dx;
    y += dy;
}

void Point::scale(float factor) {
    int oldSize = size;
    int newSize = std::max(1, int(oldSize * factor));
    // HS - encounters rounding error if size change isn't a pixel
    if (factor > 1.0f && newSize == oldSize) {
        newSize = oldSize + 1;
    }
    else if (factor < 1.0f && newSize == oldSize && oldSize > 1) {
        newSize = oldSize - 1;
    }

    size = newSize;
}

void Point::draw() const {
    glColor3f(r, g, b);
    glPointSize(size);

    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

void Point::setColor(float nr, float ng, float nb) {
    r = nr; g = ng; b = nb;
}

bool Point::contains(float px, float py) const {
    float dx = px - x;
    float dy = py - y;
    float distanceSquared = dx * dx + dy * dy;
    float radius = size / 200.0f;  
    return distanceSquared <= radius * radius;
}


float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

float Point::getR() const {
    return r;
}

float Point::getG() const {
    return g;
}

float Point::getB() const {
    return b;
}

int Point::getSize() const {
    return size;
}
