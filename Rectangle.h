#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Drawable.h"

class Rectangle : public Drawable{
    float x;
    float y;
    float width;
    float height;
    float r;
    float g;
    float b;

public:
    Rectangle();
    Rectangle(float x, float y, float width, float height, float r, float g, float b);
    bool contains(float px, float py) const override;
    void draw() const override;
    void translate(float dx, float dy) override;
    void scale(float factor) override;
    void setColor(float r, float g, float b) override;
    friend struct AppTest;
};

#endif