// Written by Harman Singh
// ColorSelector: RGB controls with +/- buttons and background preview because I couldn't get the input boxes to work :(

#include "ColorSelector.h"
#include <algorithm>
#include <FL/Enumerations.H>

using namespace bobcat;

ColorSelector::ColorSelector(int x, int y, int w, int h)
: Group(x, y, w, h)
{
    box(FL_FLAT_BOX);

    int sliceW = w / 3;
    int btnW = 50;
    int inputW = sliceW - 2 * btnW;
    int H = h - 30;

    int baseX = x;
    // RED controls
    rMinus = new Button(baseX, y, btnW, H, "-");
    rInput = new IntInput(baseX + btnW, y, inputW, H, "");
    rPlus  = new Button(baseX + btnW + inputW, y, btnW, H, "+");
    rInput->readonly(true);
    rInput->value(0);

    // GREEN controls
    baseX += sliceW;
    gMinus = new Button(baseX, y, btnW, H, "-");
    gInput = new IntInput(baseX + btnW, y, inputW, H, "");
    gPlus  = new Button(baseX + btnW + inputW, y, btnW, H, "+");
    gInput->readonly(true);
    gInput->value(0);

    // BLUE controls
    baseX += sliceW;
    bMinus = new Button(baseX, y, btnW, H, "-");
    bInput = new IntInput(baseX + btnW, y, inputW, H, "");
    bPlus  = new Button(baseX + btnW + inputW, y, btnW, H, "+");
    bInput->readonly(true);
    bInput->value(0);


    ON_CLICK(rMinus, ColorSelector::onButtonClick);
    ON_CLICK(rPlus, ColorSelector::onButtonClick);
    ON_CLICK(gMinus, ColorSelector::onButtonClick);
    ON_CLICK(gPlus, ColorSelector::onButtonClick);
    ON_CLICK(bMinus, ColorSelector::onButtonClick);
    ON_CLICK(bPlus, ColorSelector::onButtonClick);

    updateBackgroundColor(); 
}

void ColorSelector::onButtonClick(Widget* sender)
{
    int v;
    // I changed the step size to 10 because it was super annoying to keep clicking
    if (sender == rMinus) {
        v = std::max(0, rInput->value() - 10);
        rInput->value(v);
    } else if (sender == rPlus) {
        v = std::min(255, rInput->value() + 10);
        rInput->value(v);
    } else if (sender == gMinus) {
        v = std::max(0, gInput->value() - 10);
        gInput->value(v);
    } else if (sender == gPlus) {
        v = std::min(255, gInput->value() + 10);
        gInput->value(v);
    } else if (sender == bMinus) {
        v = std::max(0, bInput->value() - 10);
        bInput->value(v);
    } else if (sender == bPlus) {
        v = std::min(255, bInput->value() + 10);
        bInput->value(v);
    }

    updateBackgroundColor(); 
    redraw();
}

void ColorSelector::updateBackgroundColor()
{
    int r = std::min(255, std::max(0, rInput->value()));
    int g = std::min(255, std::max(0, gInput->value()));
    int b = std::min(255, std::max(0, bInput->value()));
    color(fl_rgb_color(r, g, b)); 
}

Color ColorSelector::getColor() const
{
    int r = std::min(255, std::max(0, rInput->value()));
    int g = std::min(255, std::max(0, gInput->value()));
    int b = std::min(255, std::max(0, bInput->value()));
    return Color(r / 255.0f, g / 255.0f, b / 255.0f);
}
