
#include <fstream>
#include <iostream>
#include <string>
#include "shape.h"


using namespace std;

class List
{
public:


    Shape* shape;
    Rectangle * rectangle;
    Circle * circle;
    Triangle * triangle;

    List* prev;
    List* next;

    static List* InitList(List* ptrCur, List* ptrHead);
    static List* AddToList(List* ptrCur, List* ptrHead);
    
    static int GetListLength(List* prtHead);
    void Sort(List* ptrHead);
    

    List* In(ifstream& in, List *ptrCur, List *ptrHead);
    int Out(ofstream& out, List* ptrHead);
    int OutRectangle(ofstream& out, List* ptrHead);
};

