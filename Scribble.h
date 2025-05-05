#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include <vector>
#include "Drawable.h"
#include "Point.h"

class Scribble : public Drawable {
public:
    Scribble();
    void draw() const override;
    void addPoint(Point* pt);
    bool contains(float px, float py) const override;
    void translate(float dx, float dy) override;
    void scale(float factor) override;
    void setColor(float r, float g, float b) override;
private:
    std::vector<Point*> points;
};


#endif
