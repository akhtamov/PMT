#include "container.h"
#include <string>


void Shape::ReadShapeFromFile(ifstream& in) {
    string line;

    // { RED = 0, ORANGE, YELLOW, GREEN, BLUE, CYAN, PURPLE } clr;

    getline(in, line);
    switch (atoi(line.c_str()))
    {
    case Shape::RED: clr = Shape::RED; break;
    case Shape::ORANGE: clr = Shape::ORANGE; break;
    case Shape::YELLOW: clr = Shape::YELLOW; break;
    case Shape::GREEN: clr = Shape::GREEN; break;
    case Shape::BLUE: clr = Shape::BLUE; break;
    case Shape::CYAN: clr = Shape::CYAN; break;
    case Shape::PURPLE: clr = Shape::PURPLE; break;
    }
    getline(in, line);
    _density = atof(line.c_str());
}


void Shape::WriteShapeToFile(ofstream& out) {

    out << "Destiny is " << _density << endl;
    string color;
    switch (clr) {
    case Shape::RED: color = "red"; break;
    case Shape::ORANGE: color = "orange"; break;
    case Shape::YELLOW: color = "yellow"; break;
    case Shape::GREEN: color = "green"; break;
    case Shape::BLUE: color = "blue"; break;
    case Shape::CYAN: color = "cyan"; break;
    case Shape::PURPLE: color = "purple"; break;
    default: color = "unknown color";
    }
    out << "Color is " << color << endl << endl;

}


float Shape::CalculateThePerimeter()
{
    return 0;
}


void Circle::ReadShapeFromFile(ifstream& in) {

    Shape::ReadShapeFromFile(in);

    string line;

    getline(in, line);
    _xCenter = atoi(line.c_str());

    getline(in, line);
    _yCenter = atoi(line.c_str());

    getline(in, line);
    _radius = atoi(line.c_str());
}


void Circle::WriteShapeToFile(ofstream& out) {
    out << "Type of shape is CIRCLE" << endl;
    out << "Center's coordinates are (" << _xCenter << ", " << _yCenter << ")"
        << endl;
    out << "Radius is " << _radius << endl;
    out << "Perimeter is " << CalculateThePerimeter() << endl;
    Shape::WriteShapeToFile(out);
}


float Circle::CalculateThePerimeter()
{
    return 2 * 3.14 * _radius;
}


void Rectangle::ReadShapeFromFile(ifstream& in) {

    Shape::ReadShapeFromFile(in);

    string line;

    getline(in, line);
    _xLeftUpCorner = atoi(line.c_str());

    getline(in, line);
    _yLeftUpCorner = atoi(line.c_str());

    getline(in, line);
    _xRightDownCorner = atoi(line.c_str());

    getline(in, line);
    _yRightDownCorner = atoi(line.c_str());
}

void Rectangle::WriteShapeToFile(ofstream& out) {
    out << "Type of shape is RECTANGLE" << endl;
    out << "Left angle's coordinates are (" << _xLeftUpCorner << ", "
        << _yLeftUpCorner << ')' << endl;
    out << "Right angle's coordinates are (" << _xRightDownCorner << ", "
        << _yRightDownCorner << ')' << endl;
    out << "Perimeter is " << CalculateThePerimeter() << endl;
    Shape::WriteShapeToFile(out);
}


float Rectangle::CalculateThePerimeter()
{
    return 2 * ( abs(_xLeftUpCorner - _xRightDownCorner) + abs(_yLeftUpCorner - _yRightDownCorner) );
}

bool Shape::Compare(Shape *other)
{
    return CalculateThePerimeter() < other->CalculateThePerimeter();
}

void Shape::WriteRectangleToFile(ofstream& out)
{
    out << "";
}


void Rectangle::WriteRectangleToFile(ofstream& out)
{
    WriteShapeToFile(out);
}

