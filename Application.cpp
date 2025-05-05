// Written by Harman Singh
// Application class: sets up the main window, toolbar, canvas, and color selector.
// Contains event handlers for drawing tools, selection, and shape manipulation.

#include "Application.h"
using namespace bobcat;
using namespace std;

// Called when the user presses the mouse button on the canvas.
// Depending on the current tool, this will either:
//  - Select & recolor an existing shape (SELECTOR),
//  - Begin a new scribble (PENCIL/ERASER),
//  - Place a new shape (CIRCLE, TRIANGLE, RECTANGLE, POLYGON),
//  - Apply transformations (PLUS, MINUS, BRING_TO_FRONT, SEND_TO_BACK).
void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();

    // SELECTOR mode: pick a shape and immediately repaint it with current RGB
    if (tool == SELECTOR) {
        canvas->selectAt(mx, my);
        Color c = colorSelector->getColor();
        canvas->setSelectedColor(c.getR(), c.getG(), c.getB());
        return;
    }

    Color color = colorSelector->getColor();

    // Start a new freehand scribble when pencil or eraser is chosen
    if (tool == PENCIL || tool == ERASER) {
        Scribble* scribble = new Scribble();
        canvas->setActiveScribble(scribble);
        canvas->addScribble(scribble);
    }
    // Create various shapes
    else if (tool == CIRCLE) {
        canvas->addCircle(mx, my, 0.1f, color.getR(), color.getG(), color.getB());
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(mx, my, 0.2f, 0.2f, color.getR(), color.getG(), color.getB());
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, 0.2f, 0.2f, color.getR(), color.getG(), color.getB());
    }
    else if (tool == POLYGON) {
        canvas->addPolygon(mx, my, 6, 0.1f, color.getR(), color.getG(), color.getB());
    }
    // Transformations
    else if (tool == PLUS) {
        canvas->scaleSelected(1.1f);
    }
    else if (tool == MINUS) {
        canvas->scaleSelected(0.9f);
    }
    else if (tool == BRING_TO_FRONT) {
        canvas->bringToFront(mx, my);
    }
    else if (tool == SEND_TO_BACK) {
        canvas->sendToBack(mx, my);
    }

    canvas->redraw();
}

// Called when the user drags the mouse with the button held down.
// - In PENCIL/ERASER mode, adds points to the current scribble.
// - In SELECTOR mode, drags the selected shape.
void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->continueScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
    }
    else if (tool == ERASER) {
        canvas->continueScribble(mx, my, 1.0, 1.0, 1.0, 14);
    }
    else if (tool == SELECTOR) {
        canvas->moveSelectedTo(mx, my);
    }
}

// Called when the toolbar signals a change (e.g. clear button).
// Currently only handles the CLEAR action to wipe the canvas.
void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();
    if (action == CLEAR) {
        canvas->clear();
    }
}

// Constructor: builds the window and lays out the UI components.
// Registers callbacks for mouse down, drag, and toolbar changes.
Application::Application() {
    window = new Window(25, 75, 650, 680, "Paint Application Shapes");

    toolbar = new Toolbar(0, 0, 50, 600);
    canvas = new Canvas(50, 0, 600, 600);
    colorSelector = new ColorSelector(50, 600, 600, 80);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);

    window->show();
}
