
#include "container.h"

//
int main(int argc, char* argv[]) {

    string inputPath;
    string outputPath;

    if (argc != 3) {
        cout << "Type input and output files\n";
        return 1;
    }
    inputPath = argv[1];
    outputPath = argv[2];
    try {
        ifstream infile(inputPath);
        infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        ofstream outfile(outputPath);
        
        List* list = new List();
        List* current = nullptr;
        List* head = nullptr;

        head = list->readFromFile(infile, current, head);

        //list->sortByPerimeter(ptrHead);

        list->writeToFile(outfile, head);

        //list->writeRectangleToFile(outfile, head);

    } catch (std::invalid_argument& ia) {
        std::cerr << ia.what();
    } catch (std::ifstream::failure f) {
        std::cerr << "Error reading input file";
    }
   
    return 0;
}
