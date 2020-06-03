
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

    static List* initialization(List* current, List* head);
    static List* addElement(List* current, List* head);
    
    static int getLength(List* head);
    void sortByPerimeter(List* head);
    
    List* readFromFile(ifstream& in, List* current, List* head);
    int writeToFile(ofstream& out, List* head);
    int writeRectanglesToFile(ofstream& out, List* head);
};

