#include "shape.h"
#include <string>
using namespace std;

struct list
{
    shape shp;
    list* next;
    list* prev;
};

struct list* list_init();
struct list* add_to_list();
bool readFile(string input);
bool writeToFile(string output);
float calculteThePerimeter(list*);