#include <fstream>
using namespace std;


class Shape
{
private:
    enum _color { RED = 0, ORANGE, YELLOW, GREEN, BLUE, CYAN, PURPLE } clr;
    float _density;
public:
    virtual void ReadShapeFromFile(ifstream& in);
    virtual void WriteShapeToFile(ofstream& out);
    virtual float CalculateThePerimeter();
    bool Compare(Shape *other);
    virtual void WriteRectangleToFile(ofstream& out);

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
    float CalculateThePerimeter() override;
    void WriteRectangleToFile(ofstream& out) override;

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
    float CalculateThePerimeter() override;
};

