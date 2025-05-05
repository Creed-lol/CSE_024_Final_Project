#ifndef POLYGON_H
#define POLYGON_H
#include "Drawable.h"

class Polygon : public Drawable{
    float x;
    float y;
    int sides;
    float length;
    float r;
    float g;
    float b;

public:
    Polygon();
    Polygon(float x, float y, int sides, float length, float r, float g, float b);
    bool contains(float px, float py) const override;
    void draw() const override;
    void translate(float dx, float dy) override;
    void scale(float factor) override;
    void setColor(float r, float g, float b) override;
    
    friend struct AppTest;
};

#endif