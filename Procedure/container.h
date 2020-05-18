#include "shape.h"

using namespace std;

struct list
{
    shape shp;
    list* next;
    list* prev;
};

struct list* list_init();
struct list* add_to_list(list* ptrCur, list* ptrHead);
list * readFile(ifstream& file, list * ptrHead);
bool writeToFile(ofstream& outfile, list * ptrHead);
float calculteThePerimeter(list*);
int getListLength(list* ptrHead);
bool compare(list* first, list* second);
void sortList(list* ptrHead);
bool out(list*, ofstream& outfile);
bool writeRectanglesToFile(ofstream& outfile, list* ptrHead);

