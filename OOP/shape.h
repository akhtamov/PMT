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

    void SetColor(int value);
    void SetDensity(float value);

    int GetColor();
    float GetDensity();


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

    void SetRectangle(int x1, int y1, int x2, int y2);
    
    int GetXLeftUpCorner();
    int GetYLeftUpCorner();
    int GetXRightDownCorner();
    int GetYRightDownCorner();
};


class Circle : public Shape
{
private:
    int _xCenter;
    int _yCenter;
    float _radius;
public:
    void ReadShapeFromFile(ifstream& in) override;
    void WriteShapeToFile(ofstream& out) override;
    float CalculateThePerimeter() override;

    void SetCircle(int x, int y, int radius);
    
    int GetXCenter();
    int GetYCenter();
    int GetRadius();
};

class Triangle : public Shape
{
private:
    int _x1;
    int _y1; 
    int _x2;
    int _y2;
    int _x3;
    int _y3;
public:
    void ReadShapeFromFile(ifstream& in) override;
    void WriteShapeToFile(ofstream& out) override;
    float CalculateThePerimeter() override;

 
    int GetX1(); int GetY1();

    int GetX2(); int GetY2();

    int GetX3(); int GetY3();

    void SetTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
    
};


