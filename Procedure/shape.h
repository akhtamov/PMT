#include <iostream>
#include <string>

struct shape
{
    enum type { CIRCLE = 0, RECTANGLE, TRIANGLE } tp;

    enum color { RED = 0, ORANGE, YELLOW, GREEN, BLUE, CYAN, PURPLE } clr;

    struct circle
    {
        int xCenter, yCenter, radius;
    } cr;

    struct rectangle
    {
        int xLeftUpCorner, yLeftUpCorner;
        int xRightDownCorner, yRightDownCorner;
    } rct;

    struct triangle
    {
        int x1, y1;
        int x2, y2;
        int x3, y3;
    } tr;
};


