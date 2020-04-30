
#include <fstream>
#include <iostream>
#include <string>
#include "shape.h"


using namespace std;

class List
{
public:

    Shape* shape;

    List* prev;
    List* next;

    List* InitList();
    List* AddToList();
    
    int GetListLength(List* prtHead);
    void Sort();
    

    int In(ifstream& in);
    int Out(ofstream& out);
    int OutRectangle(ofstream& out);
};

