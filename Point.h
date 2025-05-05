#ifndef POINT_H
#define POINT_H

#include "Drawable.h"


class Point : public Drawable { 
    float x;
    float y;
    float r;
    float g;
    float b;
    int size;

public:
    Point();
    Point(float x, float y);
    Point(float x, float y, float r, float g, float b);
    Point(float x, float y, float r, float g, float b, int size);
    bool contains(float px, float py) const override;
    void draw() const override;
    void translate(float dx, float dy) override;
    void scale(float factor) override;
    void setColor(float r, float g, float b) override;

    float getX() const;
    float getY() const;
    float getR() const;
    float getG() const;
    float getB() const;
    int getSize() const;

    friend struct AppTest;
};

#endif