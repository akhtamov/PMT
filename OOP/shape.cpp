#include "container.h"
#include <string>


void Shape::ReadShapeFromFile(ifstream& in) {

    if (!in.is_open())
    {
        throw std::invalid_argument("Error reading file!");
    }

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

    if (!out.is_open())
    {
        throw std::invalid_argument("Error writing file!");
    }

    out << "Density is " << _density << endl;
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
    out << "Color is " << color<< "\n\n";

}


float Shape::CalculateThePerimeter()
{
    return 0;
}


void Circle::ReadShapeFromFile(ifstream& in) {

    if (!in.is_open())
    {
        throw std::invalid_argument("Error reading file!");
    }

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

    if (!out.is_open())
    {
        throw std::invalid_argument("Error writing file!");
    }

    out << "Type of shape is CIRCLE" << endl;
    out << "Center's coordinates are (" << _xCenter << ", " << _yCenter << ")"
        << endl;
    out << "Radius is " << _radius << endl;
    out << "Perimeter is " << CalculateThePerimeter() << endl;
    Shape::WriteShapeToFile(out);
}


float Circle::CalculateThePerimeter()
{
    return (float)2 * 3.14 * _radius;
}

void Circle::SetCircle(int x, int y, int radius)
{
    if (radius <= 0)
    {
        throw std::invalid_argument("The radius should be a positive number!");
    }

    _xCenter = x;
    _yCenter = y;
    _radius = radius;
}


int Circle::GetXCenter()
{
    return _xCenter;
}

int Circle::GetYCenter()
{
    return _yCenter;
}

int Circle::GetRadius()
{
    return _radius;
}


void Rectangle::ReadShapeFromFile(ifstream& in) {

    if (!in.is_open())
    {
        throw std::invalid_argument("Error reading file!");
    }

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

    if (!out.is_open())
    {
        throw std::invalid_argument("Error writing file!");
    }

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
    return floor (2 * ( abs(_xLeftUpCorner - _xRightDownCorner) + abs(_yLeftUpCorner - _yRightDownCorner) ) * 100) / 100;
}

bool Shape::Compare(Shape *other)
{
    return CalculateThePerimeter() < other->CalculateThePerimeter();
}

void Shape::WriteRectangleToFile(ofstream& out)
{
    if (!out.is_open())
    {
        throw std::invalid_argument("Error writting file!");
    }

    out << "";
}


void Rectangle::WriteRectangleToFile(ofstream& out)
{
    if (!out.is_open())
    {
        throw std::invalid_argument("Error writing file!");
    }

    WriteShapeToFile(out);
}

void Rectangle::SetRectangle(int x1, int y1, int x2, int y2)
{
    _xLeftUpCorner = x1;
    _yLeftUpCorner = y1;
    _xRightDownCorner = x2;
    _yRightDownCorner = y2;
}   


int Rectangle::GetXLeftUpCorner()
{
    return _xLeftUpCorner;
}

int Rectangle::GetYLeftUpCorner()
{
    return _yLeftUpCorner;
}

int Rectangle::GetXRightDownCorner()
{
    return _xRightDownCorner;
}

int Rectangle::GetYRightDownCorner()
{
    return _yRightDownCorner;
}



void Shape::SetColor(int value)
{
    if (value < 0 || value > 6)
    {
        throw std::invalid_argument("Error: unknown color!");
    }

    switch (value) {
    case Shape::RED: clr = RED; break;
    case Shape::ORANGE: clr = ORANGE; break;
    case Shape::YELLOW: clr = YELLOW; break;
    case Shape::GREEN: clr = GREEN; break;
    case Shape::BLUE: clr = BLUE; break;
    case Shape::CYAN: clr = CYAN; break;
    case Shape::PURPLE: clr = PURPLE; break;
    }
}

void Shape::SetDensity(float value)
{
    if (value < 0)
    {
        throw std::invalid_argument("The density should be a positive number!");
    }
    _density = value;
}


int Shape::GetColor()
{
    return clr;
}

float Shape::GetDensity()
{
    return _density;
}

void Triangle::SetTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    _x1 = x1; _y1 = y1;
    _x2 = x2; _y2 = y2;
    _x3 = x3; _y3 = y3;
}

void Triangle::ReadShapeFromFile(ifstream& in)
{
    if (!in.is_open())
    {
        throw std::invalid_argument("Error reading file!");
    }

    Shape::ReadShapeFromFile(in);

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

    SetTriangle(x1, y1, x2, y2, x3, y3);

}

void Triangle::WriteShapeToFile(ofstream& out)
{
    if (!out.is_open())
    {
        throw std::invalid_argument("Error writing file!");
    }

    out << "Type of shape is TRIANGLE" << endl;
    out << "Point's coordinates are (" 
        << _x1 << ", " << _y1 << "), (" << _x2 << ", " << _y2 << "), (" << _x3 << ", " << _y3 << ")" << endl;
    out << "Perimeter is " << CalculateThePerimeter() << endl;
    Shape::WriteShapeToFile(out);
}

float Triangle::CalculateThePerimeter()
{
    float first = sqrt(pow( (_x2 - _x1), 2) + pow( (_y2 - _y1), 2) );
    float second = sqrt(pow( (_x2 - _x3), 2) + pow ((_y2 - _y3), 2));
    float third = sqrt( pow( (_x3 - _x1), 2) + pow( (_y3 - _y1), 2));

    return first + second + third;
}

int Triangle::GetX1()
{
    return _x1;
}

int Triangle::GetY1()
{
    return _y1;
}

int Triangle::GetX2()
{
    return _x2;
}

int Triangle::GetY2()
{
    return _y2;
}

int Triangle::GetX3()
{
    return _x3;
}

int Triangle::GetY3()
{
    return _y3;
}
