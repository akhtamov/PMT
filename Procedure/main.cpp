#include <iostream>
#include <string>
#include "container.h"
#include <fstream>
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
    ifstream in(inputPath);
    ofstream out(outputPath);

    readFile(in);
    writeToFile(out);
    multiMethod(out);

    in.close();
    out.close();

    return 0;
}
