#include <iostream>
#include <string>
#include <fstream>

struct Shape
{
    enum Type { 
        TYPE_CIRCLE, 
        TYPE_RECTANGLE, 
        TYPE_TRIANGLE 
    } type;
    
    enum Color { 
        COLOR_RED, 
        COLOR_ORANGE, 
        COLOR_YELLOW, 
        COLOR_GREEN, 
        COLOR_BLUE, 
        COLOR_CYAN, 
        COLOR_PURPLE 
    } color;
    
    float density;

    struct Circle
    {
        int xCenter, yCenter, radius;
    } circle;

    struct Rectangle
    {
        int xLeftUpCorner, yLeftUpCorner;
        int xRightDownCorner, yRightDownCorner;
    } rectangle;

    struct Triangle
    {
        int x1, y1;
        int x2, y2;
        int x3, y3;
    } triangle;
};


