#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include "Color.h"

class ColorSelector : public bobcat::Group {
    bobcat::Button*   rMinus;
    bobcat::IntInput* rInput;
    bobcat::Button*   rPlus;

    bobcat::Button*   gMinus;
    bobcat::IntInput* gInput;
    bobcat::Button*   gPlus;

    bobcat::Button*   bMinus;
    bobcat::IntInput* bInput;
    bobcat::Button*   bPlus;

    void onButtonClick(bobcat::Widget* sender);
    void updateBackgroundColor();

public:
    ColorSelector(int x, int y, int w, int h);
    Color getColor() const;

    friend struct AppTest;
};

#endif