#include <fstream>
using namespace std;


class Shape
{
private:
    enum Ñolor { 
        COLOR_RED, 
        COLOR_ORANGE, 
        COLOR_YELLOW, 
        COLOR_GREEN, 
        COLOR_BLUE, COLOR_CYAN, 
        COLOR_PURPLE 
    } color_;

    float density_;

public:
    virtual void readFromFile(ifstream& in);
    virtual void writeToFile(ofstream& out);
    virtual void writeRectangleToFile(ofstream& out);
    virtual float computePerimeter();
   
    bool isPerimeterLess(Shape *other);

    int getColor();
    float getDensity();

    void setColor(int value);
    void setDensity(float value);
};


class Rectangle : public Shape
{
private:
    int xLeftUpCorner_;
    int yLeftUpCorner_;
    int xRightDownCorner_;
    int yRightDownCorner_;
public:
    void readFromFile(ifstream& in) override;
    void writeToFile(ofstream& out) override;
    float computePerimeter() override;
    void writeRectangleToFile(ofstream& out) override;
    
    int getXLeftUpCorner();
    int getYLeftUpCorner();
    int getXRightDownCorner();
    int getYRightDownCorner();

    void setRectangle(int x1, int y1, int x2, int y2);
};


class Circle : public Shape
{
private:
    int xCenter_;
    int yCenter_;
    float radius_;
public:
    void readFromFile(ifstream& in) override;
    void writeToFile(ofstream& out) override;
    float computePerimeter() override;
    
    int getXCenter();
    int getYCenter();
    int getRadius();

    void setCircle(int x, int y, int radius);
};

class Triangle : public Shape
{
private:
    int x1_, y1_;
    int x2_, y2_;
    int x3_, y3_;

public:
    void readFromFile(ifstream& in) override;
    void writeToFile(ofstream& out) override;
    float computePerimeter() override;

 
    int getX1(); int getY1();
    int getX2(); int getY2();
    int getX3(); int getY3();

    void setTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
    
};


