#include "shape.h"
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
}


void Shape::WriteShapeToFile(ofstream& out) {
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
    Shape::WriteShapeToFile(out);
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
    Shape::WriteShapeToFile(out);
}

void Triangle::ReadShapeFromFile(ifstream& in)
{
    Shape::ReadShapeFromFile(in);

    string line;

    getline(in, line);
    _x1 = atoi(line.c_str());

    getline(in, line);
    _y1 = atoi(line.c_str());

    getline(in, line);
    _x2 = atoi(line.c_str());

    getline(in, line);
    _y2 = atoi(line.c_str());

    getline(in, line);
    _x3 = atoi(line.c_str());

    getline(in, line);
    _y3 = atoi(line.c_str());
}

void Triangle::WriteShapeToFile(ofstream& out)
{
    out << "Type of shape is TRIANGLE" << endl;
    out << "Its coordinates are (" << _x1 << ", " << _y1
        << "), (" << _x2 << ", " << _y2 << "), ("
        << _x3 << ", " << _y3 << ")" << endl;
    Shape::WriteShapeToFile(out);
}