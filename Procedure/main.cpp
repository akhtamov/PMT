#include "container.h"


using namespace std;
int main(int argc, char* argv[])
{
    string outputPath;
    string inputPath;
    if (argc != 3)
    {
        cout << "The output or input files are not entered!\n";
        return true;
    }
    inputPath = argv[1];
    outputPath = argv[2];
   
    ifstream file(inputPath);
    ofstream outfile(outputPath);

    list* ptrHead = nullptr;

    ptrHead = readFile(file, ptrHead);

    
    // sortList(ptrHead);
    //writeToFile(outfile, ptrHead);

    writeRectanglesToFile(outfile, ptrHead);

    return 0;
}
