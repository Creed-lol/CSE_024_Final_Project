#ifndef CIRCLE_H
#define CIRCLE_H
#include "Drawable.h"

class Circle : public Drawable {
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;
    bool highlighted;
    float originalR;
    float originalG;
    float originalB;

public:
    Circle();
    Circle(float x, float y, float radius, float r, float g, float b);

    void draw() const override;
    bool contains(float x, float y) const override;
    void translate(float dx, float dy) override;
    void scale(float factor) override;
    void setColor(float r, float g, float b) override;
    friend struct AppTest;
};

#endif
