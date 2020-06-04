#include "container.h"
#include "stdlib.h"


using namespace std;

List* head = nullptr;
List* current = nullptr;

struct List* initialize()
{
    head = new struct List;
    current = new struct List;
    head->next = head;
    head->prev = head;
    current = head;
    return current;
}

List* addElement(List* current, List* head)
{
    struct List* added;
    added = new struct List;

    added->next = head;
    added->prev = current->prev;
    current->prev->next = added;
    current->prev = added;

    return added;
}

List* readFile(ifstream& file, List* head)
{
    if (!file.is_open()) {
        throw std::invalid_argument("Error reading file!");
    }

    string line;
    getline (file, line);
    int figuresCount = atoi(line.c_str());
    for (int i = 0; i < figuresCount; i++) {
        if (i == 0) {
            head = initialize();
            current = head;
        } else 
            current = addElement(current, head);

        getline(file, line);

        if (atoi(line.c_str()) < 0 || atoi(line.c_str()) > 2) {
            throw std::invalid_argument("Error: unknown shape!");
        }

        switch (atoi (line.c_str())) {
        case Shape::TYPE_CIRCLE    : current->shape.type = Shape::TYPE_CIRCLE;    break;
        case Shape::TYPE_RECTANGLE : current->shape.type = Shape::TYPE_RECTANGLE; break;
        case Shape::TYPE_TRIANGLE  : current->shape.type = Shape::TYPE_TRIANGLE;  break;
        }

        getline(file, line);

        if (atoi (line.c_str()) < 0 || atoi (line.c_str()) > 6) {
            throw std::invalid_argument("Error: unknown color!");
        }

        switch (atoi(line.c_str())) {
        case Shape::COLOR_RED    : current->shape.color = Shape::COLOR_RED;    break;
        case Shape::COLOR_ORANGE : current->shape.color = Shape::COLOR_ORANGE; break;
        case Shape::COLOR_YELLOW : current->shape.color = Shape::COLOR_YELLOW; break;
        case Shape::COLOR_GREEN  : current->shape.color = Shape::COLOR_GREEN;  break;
        case Shape::COLOR_BLUE   : current->shape.color = Shape::COLOR_BLUE;   break;
        case Shape::COLOR_CYAN   : current->shape.color = Shape::COLOR_CYAN;   break;
        case Shape::COLOR_PURPLE : current->shape.color = Shape::COLOR_PURPLE; break;
        }

        getline(file, line);
        if (atof(line.c_str()) <= 0) {
            throw std::invalid_argument("Error: the density should be a positive number!");
        }

        current->shape.density = atof(line.c_str());

        if (current->shape.type == Shape::TYPE_CIRCLE) {
            getline(file, line);
            current->shape.circle.xCenter = atoi(line.c_str());

            getline(file, line);
            current->shape.circle.yCenter = atoi(line.c_str());

            getline(file, line);
            if (atoi(line.c_str()) <= 0) {
                throw std::invalid_argument("Error: the radius should be a positive number!");
            }
            current->shape.circle.radius = atoi(line.c_str());

        } else if (current->shape.type == Shape::TYPE_RECTANGLE) {
            getline(file, line);
            current->shape.rectangle.xLeftUpCorner = atoi(line.c_str());

            getline(file, line);
            current->shape.rectangle.yLeftUpCorner = atoi(line.c_str());

            getline(file, line);
            current->shape.rectangle.xRightDownCorner = atoi(line.c_str());

            getline(file, line);
            current->shape.rectangle.yRightDownCorner = atoi(line.c_str());
        } else if (current->shape.type == Shape::TYPE_TRIANGLE) {
            getline(file, line);
            current->shape.triangle.x1 = atoi(line.c_str());

            getline(file, line);
            current->shape.triangle.y1 = atoi(line.c_str());

            getline(file, line);
            current->shape.triangle.x2 = atoi(line.c_str());

            getline(file, line);
            current->shape.triangle.y2 = atoi(line.c_str());

            getline(file, line);
            current->shape.triangle.x3 = atoi(line.c_str());

            getline(file, line);
            current->shape.triangle.y3 = atoi(line.c_str());
        }
        current = current->next;
    }
   
    return head;
}
    

void out(List* temp, ofstream& outfile)
{

    if (!outfile.is_open()) {
        throw std::invalid_argument("Error writing file!");
    }

    string color;
    if (temp->shape.type == Shape::TYPE_CIRCLE) {
        if (temp->shape.circle.radius <= 0) {
            throw std::invalid_argument("Error: the radius should be a positive number!");
        }
        outfile << "Type of shape is CIRCLE"                                          << endl
            << "Center's coordinates are (" << temp->shape.circle.xCenter << ", " 
                                            << temp->shape.circle.yCenter << ")"  << endl
            << "Radius is "                 << temp->shape.circle.radius          << endl;
    } else if (temp->shape.type == Shape::TYPE_RECTANGLE) {
        outfile << "Type of shape is RECTANGLE"      << endl
            << "Left angle's coordinates are ("  << temp->shape.rectangle.xLeftUpCorner    << ", "
                                                 << temp->shape.rectangle.yLeftUpCorner    << ')'  << endl
            << "Right angle's coordinates are (" << temp->shape.rectangle.xRightDownCorner << ", "
            <<                                      temp->shape.rectangle.yRightDownCorner << ')'  << endl;
    } else if (temp->shape.type == Shape::TYPE_TRIANGLE) {
        outfile << "Type of shape is TRIANGLE" << endl
            << "Its coordinates are ("     << temp->shape.triangle.x1 << ", " << temp->shape.triangle.y1 << "), (" 
                                           << temp->shape.triangle.x2 << ", " << temp->shape.triangle.y2 << "), ("
                                           << temp->shape.triangle.x3 << ", " << temp->shape.triangle.y3 << ")" << endl;
    }

    if (temp->shape.density <= 0) {
        throw std::invalid_argument("Error: the density should be a positive number!");
    }

    if (computePerimeter(temp) < 0) {
        throw std::invalid_argument("Error computing perimeter");
    }

   

    switch (temp->shape.color) {
    case Shape::COLOR_RED    : color = "red";    break;
    case Shape::COLOR_ORANGE : color = "orange"; break;
    case Shape::COLOR_YELLOW : color = "yellow"; break;
    case Shape::COLOR_GREEN  : color = "green";  break;
    case Shape::COLOR_BLUE   : color = "blue";   break;
    case Shape::COLOR_CYAN   : color = "cyan";   break;
    case Shape::COLOR_PURPLE : color = "purple"; break;
    default                  : color = "unknown color";
    }

    if (color == "unknown color") {
        throw std::invalid_argument("Error: unknown color");
    }

    outfile << "Density is "   << temp->shape.density    << endl
            << "Perimeter is " << computePerimeter(temp) << endl
            << "Color is "     << color                  << endl << endl;
}

void writeToFile(ofstream& outfile, List* head) 
{
    if (!outfile.is_open()) {
        throw std::invalid_argument("Error writing file!");
    }

    List* temp = head;
    if (temp == nullptr) {
        throw std::invalid_argument("Error: list is empty!");
    }

    int shapesCount = 0;
    do {
        out(temp, outfile);
        temp = temp->next;
        shapesCount++;
    } while (temp != head);

    outfile << "Number of shapes is " << shapesCount;
}

float computePerimeter(List* temp)
{
    switch (temp->shape.type) {

    case Shape::TYPE_RECTANGLE: {
        int x1 = temp->shape.rectangle.xRightDownCorner,
            x2 = temp->shape.rectangle.xLeftUpCorner,
            y1 = temp->shape.rectangle.yRightDownCorner,
            y2 = temp->shape.rectangle.yLeftUpCorner;
        return 2 * (abs(x2 - x1) + abs(y2 - y1));
    }

    case Shape::TYPE_CIRCLE :
        return 2 * 3.14 * temp->shape.circle.radius;

    case Shape::TYPE_TRIANGLE : {
        float first = sqrt(pow((temp->shape.triangle.x2 - temp->shape.triangle.x1), 2) 
                        + pow((temp->shape.triangle.y2 - temp->shape.triangle.y1), 2));

        float second = sqrt(pow((temp->shape.triangle.x2 - temp->shape.triangle.x3), 2)
                        + pow((temp->shape.triangle.y2 - temp->shape.triangle.y3), 2));

        float third = sqrt(pow((temp->shape.triangle.x3 - temp->shape.triangle.x1), 2) 
                       + pow((temp->shape.triangle.y3 - temp->shape.triangle.y1), 2));

        return first + second + third;
    }
    }
}

int getLength(List* head)
{
    if (head == nullptr) {
        return 0;
    }
    List *temp = head;    
    int length = 0;

    do {
        temp = temp->next;
        length++;
    } while (temp != head);

    return length;
}

bool isPerimeterLess(List* first, List* second) 
{ 
    return computePerimeter(first) < computePerimeter(second);
}

void sortByPerimeter(List* head)
{
    if (head == nullptr) {
        throw std::invalid_argument("Error: list is empty!");
    }

    int length = getLength(head);

    List* first;
    List* second;
    for (int i = 0; i < length - 1; i++) {
        first = head;
        for (int copy_i = 0; copy_i != i; copy_i++) {
            first = first->next;
        }
        second = first->next;

        for (int j = i + 1; j < length; j++) {
            if (isPerimeterLess(first, second)) {
                Shape temp = first->shape;
                first->shape = second->shape;
                second->shape = temp;
            }
            second = second->next;
        }   
    }
}

void writeRectanglesToFile(ofstream& outfile, List* head)
{
    if (!outfile.is_open()) {
        throw std::invalid_argument("Error writing file!");
    }

    List* temp = head;
    if (temp == nullptr) {
        throw std::invalid_argument("Error: list is empty!");
    }

    outfile << "Only RECTANGLES: " << endl;
    int figuresCount = 0;
    do {
        if (temp->shape.type == Shape::TYPE_RECTANGLE)
            out(temp, outfile);
        temp = temp->next;
        figuresCount++;
    } while (temp != head);
    outfile << "Number of shapes is " << figuresCount;

}


void multimethod(ofstream& out, List* head)
{
    out << endl << endl << "Multimethod!" << endl;
    if (head == nullptr) {
        throw std::invalid_argument("Error: list is empty!");
    }
    
    int length = getLength(head);

    List* first = head;
    List* second = head;

    for (int i = 0; i < length - 1; i++) {
        second = first->next;
        for (int j = i + 1; j < length; j++) {
            switch (first->shape.type)
            {
            case Shape::TYPE_CIRCLE:
                switch (second->shape.type) {
                case Shape::TYPE_CIRCLE    : out << "CIRCLE and CIRCLE"                 << endl; break;
                case Shape::TYPE_RECTANGLE : out << "CIRCLE and RECTANGLE"              << endl; break;
                case Shape::TYPE_TRIANGLE:   out << "CIRCLE and TRIANGLE"               << endl; break;
                default                    : out << "CIRCLE and unknown type of shape"  << endl; break;
                } break;

            case Shape::TYPE_RECTANGLE:
                switch (second->shape.type) {
                case Shape::TYPE_CIRCLE    : out << "RECTANGLE and CIRCLE"                << endl; break;
                case Shape::TYPE_RECTANGLE : out << "RECTANGLE and RECTANGLE"             << endl; break;
                case Shape::TYPE_TRIANGLE: out <<   "RECTANGLE and TRIANGLE"              << endl; break;
                default                    : out << "RECTANGLE and unknown type of shape" << endl; break;
                } break;

            case Shape::TYPE_TRIANGLE:
                switch (second->shape.type) {
                case Shape::TYPE_CIRCLE    : out << "TRIANGLE and CIRCLE"                << endl; break;
                case Shape::TYPE_RECTANGLE : out << "TRIANGLE and RECTANGLE"             << endl; break;
                case Shape::TYPE_TRIANGLE:   out << "TRIANGLE and TRIANGLE"              << endl; break;
                default                    : out << "TRIANGLE and unknown type of shape" << endl; break;
                } break;

            default : out << "Unknown type of shape" << endl; break;
            }
            second = second->next;
        }
        first = first->next;
    }
}
