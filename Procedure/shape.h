#include <iostream>
#include <string>

struct shape
{
    enum type { CIRCLE = 0, RECTANGLE } tp;

    enum color { RED = 0, ORANGE, YELLOW, GREEN, BLUE, CYAN, PURPLE } clr;

    float destiny;

    struct circle
    {
        int xCenter, yCenter, radius;
    } cr;

    struct rectangle
    {
        int xLeftUpCorner, yLeftUpCorner;
        int xRightDownCorner, yRightDownCorner;
    } rct;
};


