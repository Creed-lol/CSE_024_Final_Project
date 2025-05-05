#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath>

Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    sides = 5;
    length = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Polygon::Polygon(float x, float y, int sides, float length, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->sides = sides;
    this->length = length;
    this->r = r;
    this->g = g;
    this->b = b;
}

#include <vector>

bool Polygon::contains(float px, float py) const {
    std::vector<std::pair<float, float>> vertices;
    float angleStep = 2 * M_PI / sides;

    for (int i = 0; i < sides; ++i) {
        float angle = i * angleStep;
        float vx = x + length * cos(angle);
        float vy = y + length * sin(angle);
        vertices.push_back({vx, vy});
    }

    bool inside = false;
    int j = sides - 1;
    for (int i = 0; i < sides; j = i++) {
        float xi = vertices[i].first, yi = vertices[i].second;
        float xj = vertices[j].first, yj = vertices[j].second;

        if ((yi > py) != (yj > py) &&
            (px < (xj - xi) * (py - yi) / (yj - yi + 0.0001f) + xi)) {
            inside = !inside;
        }
    }

    return inside;
}

void Polygon::translate(float dx, float dy) {
    x += dx;
    y += dy;
}

void Polygon::scale(float factor) {
    length *= factor;
}

void Polygon::draw() const {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / sides;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + length * cos(theta), y + length * sin(theta));
        }
    glEnd();
}

void Polygon::setColor(float nr, float ng, float nb) {
    r = nr; g = ng; b = nb;
}