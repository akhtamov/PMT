#include <iostream>
#include <string>
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

    readFile(inputPath);
    sortList();
    writeToFile(outputPath);
    return 0;
}
