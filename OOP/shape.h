#include <fstream>
using namespace std;


class Shape
{
private:
    enum _color { RED = 0, ORANGE, YELLOW, GREEN, BLUE, CYAN, PURPLE } clr;
public:
    virtual void ReadShapeFromFile(ifstream& in);
    virtual void WriteShapeToFile(ofstream& out);
};


class Rectangle : public Shape
{
private:
    int _xLeftUpCorner;
    int _yLeftUpCorner;
    int _xRightDownCorner;
    int _yRightDownCorner;
public:
    void ReadShapeFromFile(ifstream& in) override;
    void WriteShapeToFile(ofstream& out) override;
};



class Circle : public Shape
{
private:
    int _xCenter;
    int _yCenter;
    int _radius;
public:
    void ReadShapeFromFile(ifstream& in) override;
    void WriteShapeToFile(ofstream& out) override;
};


class Triangle : public Shape
{
private:
    int _x1, _y1;
    int _x2, _y2;
    int _x3, _y3;
public:
    void ReadShapeFromFile(ifstream& in) override;
    void WriteShapeToFile(ofstream& out) override;
};