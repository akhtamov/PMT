#include "shape.h"

using namespace std;

struct List
{
    Shape shape;
    List* next;
    List* prev;
};

List* initialize();
List* addElement(List* current, List* head);
List* readFile(ifstream& file, List* head);

void writeToFile(ofstream& outfile, List * head);
void writeRectanglesToFile(ofstream& outfile, List* head);

float computePerimeter(List*);
int getLength(List* head);
bool isPerimeterLess(List* first, List* second);
void sortByPerimeter(List* head);
void out(List*, ofstream& outfile);
void multimethod(ofstream& out, List* head);

