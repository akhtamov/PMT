
#include <fstream>
#include <iostream>
#include <string>
#include "shape.h"


using namespace std;

class List
{
public:

    Shape* shape;
    //Rectangle * rectangle;
    //Circle * circle;
   // Triangle * triangle;

    List* prev;
    List* next;

    static List* initialization();
    static List* addElement(List* current, List* head);
    
    static int getLength(List* head);
    void sortByPerimeter(List* head);
    
    List* readFromFile(ifstream& in, List* head);
    void writeToFile(ofstream& out, List* head);
    void writeRectanglesToFile(ofstream& out, List* head);

    void multimethod(ofstream& out, List* head);
};
