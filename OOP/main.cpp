
#include "container.h"

//
int main(int argc, char* argv[]) {
    string inputPath;
    string outputPath;

    if (argc != 3)
    {
        cout << "Type input and output files\n";
        return 1;
    }
    inputPath = argv[1];
    outputPath = argv[2];
    try {
        ifstream infile(inputPath);
        infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        ofstream outfile(outputPath);
        
        List* lst = new List();
        List* ptrCur = nullptr;
        List* ptrHead = nullptr;
        ptrHead = lst->In(infile, ptrCur, ptrHead);

        //lst->Sort(ptrHead);
        lst->Out(outfile, ptrHead);
        //lst->OutRectangle(outfile, ptrHead);
    }
    catch (std::invalid_argument& ia)
    {
        std::cerr << ia.what();
    }
    catch (std::ifstream::failure f)
    {
        std::cerr << "Error reading input file";
    }
   
    return 0;
}
