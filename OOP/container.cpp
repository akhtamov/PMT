#include "container.h"

List* ptrHead = nullptr;
List* ptrCur = nullptr;

List* List::AddToList(List* ptrCur, List* ptrHead) {
    List* ptrNew;
    ptrNew = new List();

    ptrNew->next = ptrHead;
    ptrNew->prev = ptrCur->prev;
    ptrCur->prev->next = ptrNew;
    ptrCur->prev = ptrNew;

    return ptrNew;
}

List* List::InitList(List* ptrCur, List* ptrHead) {
    ptrHead = new List();
    ptrCur = new List();
    ptrHead->next = ptrHead;
    ptrHead->prev = ptrHead;
    ptrCur = ptrHead;
    return ptrCur;
}

List* List::In(ifstream& in, List *ptrCur, List *ptrHead) {
    string line;
    getline(in, line);
    int shapesCount = atoi(line.c_str());
    for (int i = 0; i < shapesCount; i++)
    {
        if (i == 0)
        { 
            ptrHead = InitList(ptrCur, ptrHead);
            ptrCur = ptrHead;
        }
        else ptrCur = AddToList(ptrCur, ptrHead);

        getline(in, line);
        int type = atoi(line.c_str());
        switch (type)
        {
        case 0: {
            ptrCur->shape = new Circle();
            ptrCur->shape->ReadShapeFromFile(in);
            break;
        }
        case 1: {
            ptrCur->shape = new Rectangle();
            ptrCur->shape->ReadShapeFromFile(in);
            break;
        }
        case 2: {
            ptrCur->shape = new Triangle();
            ptrCur->shape->ReadShapeFromFile(in);
            break;
        }

        }
        ptrCur = ptrCur->next;
    }
    return ptrHead;
}

int List::Out(ofstream& out, List *ptrHead) {
    int shapesCount = 0;
    List* ptrTemp = ptrHead;

    do {
        ptrTemp->shape->WriteShapeToFile(out);
        ptrTemp = ptrTemp->next;
        shapesCount++;
    } while (ptrTemp != ptrHead);

    out << "Number of shapes is " << shapesCount;
    return 1;
}



void List::Sort(List* ptrHead) {
    int length = GetListLength(ptrHead);
    List* ptrTemp_i = ptrHead;
    List* ptrTemp_j = ptrHead->next;
    Shape *shape_j = ptrTemp_j->shape;
    for (int i = 0; i < length - 1; i++)
    {
        ptrTemp_i = ptrHead;
        for (int copy_i = 0; copy_i != i; copy_i++)
        {
            ptrTemp_i = ptrTemp_i->next;
        }
        ptrTemp_j = ptrTemp_i->next;
        shape_j = ptrTemp_j->shape;
        for (int j = i + 1; j < length; j++)
        {
            if (ptrTemp_i->shape->Compare(shape_j))
            {
                Shape *tmp = ptrTemp_i->shape;
                ptrTemp_i->shape = shape_j;
                ptrTemp_j->shape = tmp;
            }
            ptrTemp_j = ptrTemp_j->next;
            shape_j = ptrTemp_j->shape;
        } 
    }
}

int List::GetListLength(List* ptrHead) {
    if (ptrHead == nullptr) {
        return 0;
    }
    else {
        List* ptrTemp = ptrHead;
        int length = 0;
        do {
            length++;
            ptrTemp = ptrTemp->next;
        } while (ptrTemp != ptrHead);
        return length;
    }
}

int List::OutRectangle(ofstream& out, List * ptrHead)
{
    int rectangleCount = 0;
    List* ptrTemp = ptrHead;
    out << "Only RECTANGLES: " << endl;
    do {
        ptrTemp->shape->WriteRectangleToFile(out);
        ptrTemp = ptrTemp->next;
        rectangleCount++;
    } while (ptrTemp != ptrHead);

    out << "Number of shapes is " << rectangleCount;
    return 1;

}
