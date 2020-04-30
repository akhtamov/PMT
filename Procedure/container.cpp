#include "container.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
using namespace std;

list* ptrHead = nullptr;
list* ptrCur = nullptr;

struct list* list_init()
{
    ptrHead = new struct list;
    ptrCur = new struct list;
    ptrHead->next = ptrHead;
    ptrHead->prev = ptrHead;
    ptrCur = ptrHead;
    return ptrCur;
}

struct list* add_to_list()
{
    struct list* ptrNew;
    ptrNew = new struct list;

    ptrNew->next = ptrHead;
    ptrNew->prev = ptrCur->prev;
    ptrCur->prev->next = ptrNew;
    ptrCur->prev = ptrNew;

    return ptrNew;
}

bool readFile(string input)
{
    ifstream file(input);
    if (!file.is_open())
    {
        return false;
    }
    string line;
    getline(file, line);
    int figuresCount = atoi(line.c_str());
    for (int i = 0; i < figuresCount; i++)
    {
        if (i == 0)
        {
            ptrHead = list_init();
            ptrCur = ptrHead;
        }
        else ptrCur = add_to_list();

        getline(file, line);
        switch (atoi(line.c_str()))
        {
        case shape::CIRCLE: ptrCur->shp.tp = shape::CIRCLE; break;
        case shape::RECTANGLE: ptrCur->shp.tp = shape::RECTANGLE; break;
        }

        getline(file, line);
        switch (atoi(line.c_str()))
        {
        case shape::RED: ptrCur->shp.clr = shape::RED; break;
        case shape::ORANGE: ptrCur->shp.clr = shape::ORANGE; break;
        case shape::YELLOW: ptrCur->shp.clr = shape::YELLOW; break;
        case shape::GREEN: ptrCur->shp.clr = shape::GREEN; break;
        case shape::BLUE: ptrCur->shp.clr = shape::BLUE; break;
        case shape::CYAN: ptrCur->shp.clr = shape::CYAN; break;
        case shape::PURPLE: ptrCur->shp.clr = shape::PURPLE; break;
        }
        
        getline(file, line);
        ptrCur->shp.density = atof(line.c_str());

        if (ptrCur->shp.tp == shape::CIRCLE)
        {
            getline(file, line);
            ptrCur->shp.cr.xCenter = atoi(line.c_str());

            getline(file, line);
            ptrCur->shp.cr.yCenter = atoi(line.c_str());

            getline(file, line);
            ptrCur->shp.cr.radius = atoi(line.c_str());

        }
        else if (ptrCur->shp.tp == shape::RECTANGLE) {
            getline(file, line);
            ptrCur->shp.rct.xLeftUpCorner = atoi(line.c_str());

            getline(file, line);
            ptrCur->shp.rct.yLeftUpCorner = atoi(line.c_str());

            getline(file, line);
            ptrCur->shp.rct.xRightDownCorner = atoi(line.c_str());

            getline(file, line);
            ptrCur->shp.rct.yRightDownCorner = atoi(line.c_str());
        }
        ptrCur = ptrCur->next;
    }
    return true;
}
bool out(list* ptrTemp, ofstream& outfile)
{
    string color;
    if (ptrTemp->shp.tp == shape::CIRCLE) {
        outfile << "Type of shape is CIRCLE" << endl;
        outfile << "Center's coordinates are (" << ptrTemp->shp.cr.xCenter << ", " << ptrTemp->shp.cr.yCenter << ")"
            << endl;
        outfile << "Radius is " << ptrTemp->shp.cr.radius << endl;
    }
    else if (ptrTemp->shp.tp == shape::RECTANGLE) {
        outfile << "Type of shape is RECTANGLE" << endl;
        outfile << "Left angle's coordinates are (" << ptrTemp->shp.rct.xLeftUpCorner << ", "
            << ptrTemp->shp.rct.yLeftUpCorner << ')' << endl;
        outfile << "Right angle's coordinates are (" << ptrTemp->shp.rct.xRightDownCorner << ", "
            << ptrTemp->shp.rct.yRightDownCorner << ')' << endl;
    outfile << "Density is " << ptrTemp->shp.density << endl;
    }
    switch (ptrTemp->shp.clr) {
    case shape::RED: color = "red"; break;
    case shape::ORANGE: color = "orange"; break;
    case shape::YELLOW: color = "yellow"; break;
    case shape::GREEN: color = "green"; break;
    case shape::BLUE: color = "blue"; break;
    case shape::CYAN: color = "cyan"; break;
    case shape::PURPLE: color = "purple"; break;
    default: color = "unknown color";
    }
    outfile << "Color is " << color << endl << endl;

    return true;
}
bool writeToFile(string output) {
    ofstream outfile(output);
    if (!outfile.is_open()) {
        return false;
    }
    int figuresCount = 0;
    list* ptrTemp = ptrHead;
    string color;
    do {
        out(ptrTemp, outfile);
        ptrTemp = ptrTemp->next;
        figuresCount++;
    } while (ptrTemp != ptrHead);
    outfile << "Number of shapes is " << figuresCount;
    return true;
}