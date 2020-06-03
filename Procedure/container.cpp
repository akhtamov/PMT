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

bool readFile(ifstream& in)
{
    if (!in.is_open())
    {
        return false;
    }
    string line;
    getline(in, line);
    int figuresCount = atoi(line.c_str());
    for (int i = 0; i < figuresCount; i++)
    {
        if (i == 0)
        {
            ptrHead = list_init();
            ptrCur = ptrHead;
        }
        else ptrCur = add_to_list();

        getline(in, line);
        switch (atoi(line.c_str()))
        {
        case shape::CIRCLE: ptrCur->shp.tp = shape::CIRCLE; break;
        case shape::RECTANGLE: ptrCur->shp.tp = shape::RECTANGLE; break;
        }

        getline(in, line);
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

        if (ptrCur->shp.tp == shape::CIRCLE)
        {
            getline(in, line);
            ptrCur->shp.cr.xCenter = atoi(line.c_str());

            getline(in, line);
            ptrCur->shp.cr.yCenter = atoi(line.c_str());

            getline(in, line);
            ptrCur->shp.cr.radius = atoi(line.c_str());

        }
        else if (ptrCur->shp.tp == shape::RECTANGLE) {
            getline(in, line);
            ptrCur->shp.rct.xLeftUpCorner = atoi(line.c_str());

            getline(in, line);
            ptrCur->shp.rct.yLeftUpCorner = atoi(line.c_str());

            getline(in, line);
            ptrCur->shp.rct.xRightDownCorner = atoi(line.c_str());

            getline(in, line);
            ptrCur->shp.rct.yRightDownCorner = atoi(line.c_str());
        }
        ptrCur = ptrCur->next;
    }
    return true;
}

bool writeToFile(ofstream& out) {
    if (!out.is_open()) {
        return false;
    }
    int figuresCount = 0;
    list* ptrTemp = ptrHead;
    string color;
    do {
        if (ptrTemp->shp.tp == shape::CIRCLE) {
            out << "Type of shape is CIRCLE" << endl;
            out << "Center's coordinates are (" << ptrTemp->shp.cr.xCenter << ", " << ptrTemp->shp.cr.yCenter << ")"
                << endl;
            out << "Radius is " << ptrTemp->shp.cr.radius << endl;
        }
        else if (ptrTemp->shp.tp == shape::RECTANGLE) {
            out << "Type of shape is RECTANGLE" << endl;
            out << "Left angle's coordinates are (" << ptrTemp->shp.rct.xLeftUpCorner << ", "
                << ptrTemp->shp.rct.yLeftUpCorner << ')' << endl;
            out << "Right angle's coordinates are (" << ptrTemp->shp.rct.xRightDownCorner << ", "
                << ptrTemp->shp.rct.yRightDownCorner << ')' << endl;
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
        out << "Color is " << color << endl << endl;
        ptrTemp = ptrTemp->next;
        figuresCount++;
    } while (ptrTemp != ptrHead);
    out << "Number of shapes is " << figuresCount;
    return true;
}

bool multiMethod(ofstream& out)
{
    out << endl <<  endl <<"Multimethod!" << endl;
    if (ptrHead == nullptr) {
        return 0;
    }
    list* ptrTemp = ptrHead;
    int length = 0;

    do {
        ptrTemp = ptrTemp->next;
        length++;
    } while (ptrTemp != ptrHead);

    list* ptrTemp_i = ptrHead;
    list* ptrTemp_j = ptrHead;

    for (int i = 0; i < length - 1; i++) {
        ptrTemp_j = ptrTemp_i->next;
        for (int j = i + 1; j < length; j++) {
            switch (ptrTemp_i->shp.tp)
            {
            case shape::CIRCLE:
                switch (ptrTemp_j->shp.tp) {
                case shape::CIRCLE:
                    out << "CIRCLE and CIRCLE" << endl;
                    break;
                case shape::RECTANGLE:
                    out << "CIRCLE and RECTANGLE" << endl;
                    break;
                default:
                    out << "CIRCLE and unknown type of shape" << endl;
                    break;
                }
                break;

            case shape::RECTANGLE:
                switch (ptrTemp_j->shp.tp) {
                case shape::CIRCLE:
                    out << "RECTANGLE and CIRCLE" << endl;
                    break;
                case shape::RECTANGLE:
                    out << "RECTANGLE and RECTANGLE" << endl;
                    break;
                default:
                    out << "RECTANGLE and unknown type of shape" << endl;
                    break;
                }
                break;
            default:
                out << "Unknown type of shape" << endl;
                break;
            }
            ptrTemp_j = ptrTemp_j->next;
        }
        ptrTemp_i = ptrTemp_i->next;
    }
}