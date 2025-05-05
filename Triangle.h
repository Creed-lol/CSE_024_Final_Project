#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Drawable.h"

class Triangle : public Drawable{
    float x;
    float y;
    float base;
    float height;
    float r;
    float g;
    float b;

public:
    Triangle();
    Triangle(float x, float y, float base, float height, float r, float g, float b);
    bool contains(float px, float py) const override;
    void draw() const override;
    void translate(float dx, float dy) override;
    void scale(float factor) override;
    void setColor(float r, float g, float b) override;
    
    friend struct AppTest;
};

#endif