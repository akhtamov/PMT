#include "container.h"
#include <string>


void Shape::readFromFile(ifstream& in) 
{

    if (!in.is_open()) {
        throw std::invalid_argument("Error reading file!");
    }

    string line;
    getline(in, line);

    switch (atoi(line.c_str())) {
    case Shape::COLOR_RED    : color_ = Shape::COLOR_RED;    break;
    case Shape::COLOR_ORANGE : color_ = Shape::COLOR_ORANGE; break;
    case Shape::COLOR_YELLOW : color_ = Shape::COLOR_YELLOW; break;
    case Shape::COLOR_GREEN  : color_ = Shape::COLOR_GREEN;  break;
    case Shape::COLOR_BLUE   : color_ = Shape::COLOR_BLUE;   break;
    case Shape::COLOR_CYAN   : color_ = Shape::COLOR_CYAN;   break;
    case Shape::COLOR_PURPLE : color_ = Shape::COLOR_PURPLE; break;
    }
    getline(in, line);
    density_ = atof(line.c_str());
}


void Shape::writeToFile(ofstream& out) 
{

    if (!out.is_open()) {
        throw std::invalid_argument("Error writing file!");
    }

    string color;
    switch (color_) {
    case Shape::COLOR_RED    : color = "red";    break;
    case Shape::COLOR_ORANGE : color = "orange"; break;
    case Shape::COLOR_YELLOW : color = "yellow"; break;
    case Shape::COLOR_GREEN  : color = "green";  break;
    case Shape::COLOR_BLUE   : color = "blue";   break;
    case Shape::COLOR_CYAN   : color = "cyan";   break;
    case Shape::COLOR_PURPLE : color = "purple"; break;
    default                  : color = "unknown color";
    }
    out << "Density is " << density_ << endl
        << "Color is "   << color    << endl << endl;

}

float Shape::computePerimeter()
{
    return 0;
}

void Shape::multimethod(Shape* other, ofstream& out)
{
    out << "Unknown type of shape" << endl;
}

void Shape::mmRectangle(ofstream& out)
{
    out << "RECTANGLE and unknown type of shape" << endl;
}

void Shape::mmCircle(ofstream& out)
{
    out << "CIRCLE and unknown type of shape" << endl;
}

void Shape::mmTriangle(ofstream& out)
{
    out << "TRIANGLE and unknown type of shape" << endl;
}

void Circle::readFromFile(ifstream& in) 
{

    if (!in.is_open()) {
        throw std::invalid_argument("Error reading file!");
    }

    Shape::readFromFile(in);

    string line;
    getline(in, line);
    xCenter_ = atoi(line.c_str());

    getline(in, line);
    yCenter_ = atoi(line.c_str());

    getline(in, line);
    radius_ = atoi(line.c_str());
}

void Circle::writeToFile(ofstream& out) 
{
    if (!out.is_open()) {
        throw std::invalid_argument("Error writing file!");
    }

    out << "Type of shape is CIRCLE"                                           << endl
        << "Center's coordinates are (" << xCenter_ << ", " << yCenter_ << ")" << endl
        << "Radius is "                 << radius_                             << endl
        << "Perimeter is "              << computePerimeter()                  << endl;
    Shape::writeToFile(out);
}


float Circle::computePerimeter()
{
    return (float)2 * 3.14 * radius_;
}

void Circle::multimethod(Shape* other, ofstream& out)
{
    other->mmCircle(out);
}

void Circle::mmRectangle(ofstream& out)
{
    out << "RECTANGLE and CIRCLE" << endl;
}

void Circle::mmCircle(ofstream& out)
{
    out << "CIRCLE and CIRCLE" << endl;
}

void Circle::mmTriangle(ofstream& out)
{
    out << "TRIANGLE and CIRCLE" << endl;
}

void Circle::setCircle(int x, int y, int radius)
{
    if (radius <= 0) {
        throw std::invalid_argument("The radius should be a positive number!");
    }

    xCenter_ = x;
    yCenter_ = y;
    radius_ = radius;
}


int Circle::getXCenter()
{
    return xCenter_;
}

int Circle::getYCenter()
{
    return yCenter_;
}

int Circle::getRadius()
{
    return radius_;
}


void Rectangle::readFromFile(ifstream& in) {

    if (!in.is_open()) {
        throw std::invalid_argument("Error reading file!");
    }

    Shape::readFromFile(in);

    string line;
    getline(in, line);
    xLeftUpCorner_ = atoi(line.c_str());

    getline(in, line);
    yLeftUpCorner_ = atoi(line.c_str());

    getline(in, line);
    xRightDownCorner_ = atoi(line.c_str());

    getline(in, line);
    yRightDownCorner_ = atoi(line.c_str());
}

void Rectangle::writeToFile(ofstream& out) {

    if (!out.is_open()) {
        throw std::invalid_argument("Error writing file!");
    }

    out << "Type of shape is RECTANGLE" << endl
        << "Left angle's coordinates are ("  << xLeftUpCorner_     << ", " << yLeftUpCorner_    << ')' << endl
        << "Right angle's coordinates are (" << xRightDownCorner_  << ", " << yRightDownCorner_ << ')' << endl
        << "Perimeter is "                   << computePerimeter()                                     << endl;
    Shape::writeToFile(out);
}


float Rectangle::computePerimeter()
{
    return floor (2 * ( abs(xLeftUpCorner_ - xRightDownCorner_) + abs(yLeftUpCorner_ - yRightDownCorner_) ) * 100) / 100;
}

bool Shape::isPerimeterLess(Shape *other)
{
    return computePerimeter() < other->computePerimeter();
}

void Shape::writeRectangleToFile(ofstream& out)
{
    if (!out.is_open()) {
        throw std::invalid_argument("Error writting file!");
    }

    out << "";
}


void Rectangle::writeRectangleToFile(ofstream& out)
{
    if (!out.is_open()) {
        throw std::invalid_argument("Error writing file!");
    }

    writeToFile(out);
}

void Rectangle::multimethod(Shape* other, ofstream& out)
{
    other->mmRectangle(out);
}

void Rectangle::mmRectangle(ofstream& out)
{
    out << "RECTANGLE and RECTANGLE" << endl;
}

void Rectangle::mmCircle(ofstream& out)
{
    out << "CIRCLE and RECTANGLE" << endl;
}

void Rectangle::mmTriangle(ofstream& out)
{
    out << "TRIANGLE and RECTANGLE" << endl;
}


void Rectangle::setRectangle(int x1, int y1, int x2, int y2)
{
    xLeftUpCorner_ = x1;
    yLeftUpCorner_ = y1;
    xRightDownCorner_ = x2;
    yRightDownCorner_ = y2;
}   


int Rectangle::getXLeftUpCorner()
{
    return xLeftUpCorner_;
}

int Rectangle::getYLeftUpCorner()
{
    return yLeftUpCorner_;
}

int Rectangle::getXRightDownCorner()
{
    return xRightDownCorner_;
}

int Rectangle::getYRightDownCorner()
{
    return yRightDownCorner_;
}

void Shape::setColor(int value)
{
    if (value < 0 || value > 6) {
        throw std::invalid_argument("Error: unknown color!");
    }

    switch (value) {
    case Shape::COLOR_RED    : color_ = COLOR_RED;    break;
    case Shape::COLOR_ORANGE : color_ = COLOR_ORANGE; break;
    case Shape::COLOR_YELLOW : color_ = COLOR_YELLOW; break;
    case Shape::COLOR_GREEN  : color_ = COLOR_GREEN;  break;
    case Shape::COLOR_BLUE   : color_ = COLOR_BLUE;   break;
    case Shape::COLOR_CYAN   : color_ = COLOR_CYAN;   break;
    case Shape::COLOR_PURPLE : color_ = COLOR_PURPLE; break;
    }
}

void Shape::setDensity(float value)
{
    if (value < 0)
    {
        throw std::invalid_argument("The density should be a positive number!");
    }
    density_ = value;
}


int Shape::getColor()
{
    return color_;
}

float Shape::getDensity()
{
    return density_;
}

void Triangle::setTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    x1_ = x1; y1_ = y1;
    x2_ = x2; y2_ = y2;
    x3_ = x3; y3_ = y3;
}

void Triangle::readFromFile(ifstream& in)
{
    if (!in.is_open())
    {
        throw std::invalid_argument("Error reading file!");
    }

    Shape::readFromFile(in);

    string line;

    getline(in, line);
    int x1 = atoi(line.c_str());
    getline(in, line);
    int y1 = atoi(line.c_str());

    getline(in, line);
    int x2 = atoi(line.c_str());
    getline(in, line);
    int y2 = atoi(line.c_str());

    getline(in, line);
    int x3 = atoi(line.c_str());
    getline(in, line);
    int y3 = atoi(line.c_str());

    setTriangle(x1, y1, x2, y2, x3, y3);

}

void Triangle::writeToFile(ofstream& out)
{
    if (!out.is_open())
    {
        throw std::invalid_argument("Error writing file!");
    }

    out << "Type of shape is TRIANGLE"                                  << endl
        << "Point's coordinates are (" << x1_ << ", " << y1_ << "), (" 
                                       << x2_ << ", " << y2_ << "), (" 
                                       << x3_ << ", " << y3_ << ")"     << endl;
    out << "Perimeter is "             << computePerimeter()            << endl;
    Shape::writeToFile(out);
}

float Triangle::computePerimeter()
{
    return sqrt(pow((x2_ - x1_), 2) + pow((y2_ - y1_), 2)) +
           sqrt(pow((x2_ - x3_), 2) + pow((y2_ - y3_), 2)) +
           sqrt(pow((x3_ - x1_), 2) + pow((y3_ - y1_), 2));
}

void Triangle::multimethod(Shape* other, ofstream& out)
{
    other->mmTriangle(out);
}

void Triangle::mmRectangle(ofstream& out)
{
    out << "RECTANGLE and TRIANGLE" << endl;
}

void Triangle::mmCircle(ofstream& out)
{
    out << "CIRCLE and TRIANGLE" << endl;
}

void Triangle::mmTriangle(ofstream& out)
{
    out << "TRIANGLE and TRIANGLE" << endl;
}


int Triangle::getX1()
{
    return x1_;
}

int Triangle::getY1()
{
    return y1_;
}

int Triangle::getX2()
{
    return x2_;
}

int Triangle::getY2()
{
    return y2_;
}

int Triangle::getX3()
{
    return x3_;
}

int Triangle::getY3()
{
    return y3_;
}
