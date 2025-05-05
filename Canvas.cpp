// Written by Harman Singh
// Canvas class: manages all drawables (shapes & scribbles) in one vector.

#include "Canvas.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Scribble.h"
#include <algorithm> 

Canvas::Canvas(int x,int y,int w,int h)
: bobcat::Canvas_(x,y,w,h),activeScribble(nullptr),selected(nullptr),lastMouseX(0),lastMouseY(0)
{}

void Canvas::addScribble(Scribble* s){
    drawables.push_back(s);
}

void Canvas::addPoint(float x,float y,float r,float g,float b,int size){
    Point* point=new Point(x,y,r,g,b,size);
    if(activeScribble) activeScribble->addPoint(point);
    else drawables.push_back(point);
}

// In reverse draw order so topmost shape is selected
void Canvas::selectAt(float x,float y){
    selected=nullptr;
    for(auto it=drawables.rbegin();it!=drawables.rend();++it){
        if((*it)->contains(x,y)){ selected=*it; break; }
    }
    lastMouseX=x; lastMouseY=y;
    // Debug output (remove in production)
    if(selected) std::cout<<"Shape selected!\n";
    else std::cout<<"Clicked empty space\n";
}

void Canvas::bringToFront(float x,float y){
    selectAt(x,y); if(!selected) return;
    auto it=std::find(drawables.begin(),drawables.end(),selected);
    if(it!=drawables.end()){ drawables.erase(it); drawables.push_back(selected); redraw(); }
}

void Canvas::sendToBack(float x,float y){
    selectAt(x,y); if(!selected) return;
    auto it=std::find(drawables.begin(),drawables.end(),selected);
    if(it!=drawables.end()){ drawables.erase(it); drawables.insert(drawables.begin(),selected); redraw(); }
}

void Canvas::moveSelectedTo(float x,float y){
    if(!selected) return;
    float dx=x-lastMouseX, dy=y-lastMouseY;
    selected->translate(dx,dy);
    lastMouseX=x; lastMouseY=y;
    redraw();
}

void Canvas::scaleSelected(float f){
    if(selected){ selected->scale(f); redraw(); }
}

void Canvas::setSelectedColor(float r,float g,float b){
    if(selected){ selected->setColor(r,g,b); redraw(); }
}

void Canvas::setActiveScribble(Scribble* s){
    activeScribble=s;
}

void Canvas::startScribble(float x,float y,float r,float g,float b,int size){
    activeScribble=new Scribble();
    activeScribble->addPoint(new Point(x,y,r,g,b,size));
    redraw();
}

void Canvas::continueScribble(float x,float y,float r,float g,float b,int size){
    if(activeScribble){
        activeScribble->addPoint(new Point(x,y,r,g,b,size));
        redraw();
    }
}

void Canvas::endScribble(){
    if(activeScribble){
        drawables.push_back(activeScribble);
        activeScribble=nullptr;
        redraw();
    }
}

void Canvas::addCircle(float x,float y,float radius,float r,float g,float b){
    drawables.push_back(new Circle(x,y,radius,r,g,b));
}

void Canvas::addTriangle(float x,float y,float base,float height,float r,float g,float b){
    drawables.push_back(new Triangle(x,y,base,height,r,g,b));
}

void Canvas::addRectangle(float x,float y,float width,float height,float r,float g,float b){
    drawables.push_back(new Rectangle(x,y,width,height,r,g,b));
}

void Canvas::addPolygon(float x,float y,int sides,float sideLength,float r,float g,float b){
    drawables.push_back(new Polygon(x,y,sides,sideLength,r,g,b));
}

void Canvas::clear(){
    for(auto d:drawables) delete d;
    drawables.clear();
    redraw();
}


void Canvas::render(){
    for(auto d:drawables) d->draw();
}
