
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

    int In(ifstream& in);
    int Out(ofstream& out);
};

