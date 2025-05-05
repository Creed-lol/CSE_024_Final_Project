// Written by Harman Singh
// I converted all the shapes/scribbles to drawables so that there was one place where everything is stored
// All shapes are carried over from my previous assignment

#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable {
public:
    virtual ~Drawable() {}
    virtual void draw() const = 0;
    virtual bool contains(float x, float y) const = 0;
    virtual void translate(float dx, float dy) = 0;
    virtual void scale(float factor) = 0;
    virtual void setColor(float r, float g, float b) = 0;
};

#endif
