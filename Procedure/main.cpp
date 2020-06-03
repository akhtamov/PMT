#include "container.h"


using namespace std;
int main(int argc, char* argv[])
{
    string outputPath;
    string inputPath;
    if (argc != 3) {
        cout << "The output or input files are not entered!\n";
        return true;
    }
    inputPath = argv[1];
    outputPath = argv[2];
   try {
        ifstream file(inputPath);
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        ofstream outfile(outputPath);

        List* head = nullptr;

        head = readFile(file, head);
        //sortByPerimeter(head);
        writeToFile(outfile, head);
        //writeRectanglesToFile(outfile, head);
    } catch (std::invalid_argument& ia) {
        std::cerr << ia.what();
    } catch (std::ifstream::failure f) {
        std::cerr << "Error reading input file";
    }
    return 0;
}
