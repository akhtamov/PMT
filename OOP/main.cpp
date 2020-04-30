
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

    ifstream infile(inputPath);
    if (!infile.is_open())
    {
        return 1;
    }
    ofstream outfile(outputPath);
    if (!outfile.is_open())
    {
        return 1;
    }

    List* lst = new List();
    lst->In(infile);
    lst->Sort();
    lst->Out(outfile);

    return 0;
}
