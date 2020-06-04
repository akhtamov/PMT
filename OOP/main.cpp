
#include "container.h"

//
int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Type input and output files\n";
        return 1;
    }

    string inputPath = argv[1];
    string outputPath = argv[2];

    try {
        ifstream infile(inputPath);
        infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        ofstream outfile(outputPath);
        
        List* list = new List();
        List* head = nullptr;

        head = list->readFromFile(infile, head);

        //list->sortByPerimeter(head);

        list->writeToFile(outfile, head);

        //list->writeRectangleToFile(outfile, head);

        list->multimethod(outfile, head);

    } catch (std::invalid_argument& ia) {
        std::cerr << ia.what();
    } catch (std::ifstream::failure f) {
        std::cerr << "Error reading input file";
    }
   
    return 0;
}
