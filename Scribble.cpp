// Written by Harman Singh
#include "Scribble.h"
#include <GL/freeglut.h>
#include <cmath>


Scribble::Scribble() {

}

void Scribble::addPoint(Point* pt) {
    points.push_back(pt);
}

void Scribble::draw() const {
    for (Point* pt : points) {
        pt->draw();
    }
}

// Just made each scribble a series of points
bool Scribble::contains(float px, float py) const {
    for (Point* pt : points) {
        if (pt->contains(px, py)) {
            return true;
        }
    }
    return false;
}

void Scribble::translate(float dx, float dy) {
    for (auto pt : points) {
        pt->translate(dx, dy);
    }
}

void Scribble::scale(float factor) {
    for (auto pt : points) pt->scale(factor);
}

void Scribble::setColor(float nr, float ng, float nb) {
    for (auto pt : points) {
        pt->setColor(nr, ng, nb);
    }
}
