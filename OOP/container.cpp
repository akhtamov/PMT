#include "container.h"

List* head = nullptr;
List* current = nullptr;

List* List::addElement(List* current, List* head) {

    if (head == nullptr || current == nullptr) {
        throw std::invalid_argument("The list should be initialized first!");
    }

    List* added = new List();

    added->next = head;
    added->prev = current->prev;
    current->prev->next = added;
    current->prev = added;

    return added;
}

List* List::initialization() {
    head = new List();
    current = new List();
    head->next = head;
    head->prev = head;
    current = head;
    return current;
}

List* List::readFromFile(ifstream& in, List* head) {
    if (!in.is_open()) {
        throw std::invalid_argument("Error reading file!");
    }

    string line;
    getline(in, line);

    int shapesCount = atoi(line.c_str());
    for (int i = 0; i < shapesCount; i++) {
        if (i == 0) { 
            head = initialization();
            current = head;
        }
        else 
            current = addElement(current, head);

        getline(in, line);
        int type = atoi(line.c_str());
        switch (type) {
        case 0: {
            current->shape = new Circle();
            current->shape->readFromFile(in);
            break;
        }
        case 1: {
            current->shape = new Rectangle();
            current->shape->readFromFile(in);
            break;
        }
        case 2: {
            current->shape = new Triangle();
            current->shape->readFromFile(in);
            break;
        }
        }
        current = current->next;
    }
    return head;
}

void List::writeToFile(ofstream& out, List *head) {

    if (!out.is_open()) {
        throw std::invalid_argument("Error writing file!");
    }

    if (head == nullptr) {
        throw std::invalid_argument("List is empty!");
    }

    int shapesCount = 0;
    List* temp = head;
 
    do {
        temp->shape->writeToFile(out);
        temp = temp->next;
        shapesCount++;
    } while (temp != head);

    out << "Number of shapes is " << shapesCount;
}

void List::sortByPerimeter(List* head) {
    if (head == nullptr) {
        throw std::invalid_argument("List is empty!");
    }
    int length = getLength(head);
    List* first = head;
    List* second = head->next;
    Shape *shape = second->shape;
    for (int i = 0; i < length - 1; i++) {
        first = head;
        for (int ii = 0; ii != i; ii++) {
            first = first->next;
        }
        second = first->next;
        shape = second->shape;
        for (int j = i + 1; j < length; j++) {
            if (first->shape->isPerimeterLess(shape)) {
                Shape *tmp = first->shape;
                first->shape = shape;
                second->shape = tmp;
            }
            second = second->next;
            shape = second->shape;
        } 
    }
}

int List::getLength(List* head) {
    if (head == nullptr) {
        return 0;
    } 
    else {
        List* temp = head;
        int length = 0;
        do {
            length++;
            temp = temp->next;
        } while (temp != head);
        return length;
    }
}

void List::writeRectanglesToFile(ofstream& out, List * head)
{
    if (!out.is_open()) {
        throw std::invalid_argument("Error writing file!");
    }
    
    if (head == nullptr) {
        throw std::invalid_argument("List is empty!");
    }
    int rectanglesCount = 0;
    List* temp = head;
    out << "Only RECTANGLES: " << endl;
    do {
        temp->shape->writeRectangleToFile(out);
        temp = temp->next;
        rectanglesCount++;
    } while (temp != head);

    out << "Number of shapes is " << rectanglesCount;
}


void List::multimethod(ofstream& out, List* head)
{
    out << endl << endl << "Multimethod!" << endl;
    if (head == nullptr) {
        throw std::invalid_argument("List is empty!");
    }
    int length = getLength(head);

    List* first = head;
    List* second = head;

    for (int i = 0; i < length - 1; i++) {
        second = first->next;
        for (int j = i + 1; j < length; j++) {
            first->shape->multimethod(second->shape, out);
            second = second->next;
        }
        first = first->next;
    }
}