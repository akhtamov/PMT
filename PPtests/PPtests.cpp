#include "pch.h"
#include "CppUnitTest.h"
#include "../Procedure/container.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PPtests
{
	TEST_CLASS(ShapeTests)
	{
	public:

		TEST_METHOD(Perimeter)
		{

			List* ptr = new List();

			ptr->shape.type = Shape::TYPE_CIRCLE;
			ptr->shape.circle.xCenter = 0;
			ptr->shape.circle.yCenter = 0;
			ptr->shape.circle.radius = 5;
			float result = round(computePerimeter(ptr) * 10.) / 10.;
			float example = (31.4 * 10.) / 10.;

			Assert::IsTrue(result == example, L"Assert Circle");

		}

		TEST_METHOD(Compare)
		{
			string outputPath = "../../Text_files/output_shape.txt";
			ofstream outfile3(outputPath);


			List* ptr1 = new List();

			ptr1->shape.type = Shape::TYPE_CIRCLE;
			ptr1->shape.circle.xCenter = 0;
			ptr1->shape.circle.yCenter = 0;
			ptr1->shape.circle.radius = 5;

			List* ptr2 = new List();

			ptr2->shape.type = Shape::TYPE_RECTANGLE;
			ptr2->shape.rectangle.xLeftUpCorner = 1;
			ptr2->shape.rectangle.yLeftUpCorner = 5;
			ptr2->shape.rectangle.xRightDownCorner = 6;
			ptr2->shape.rectangle.yRightDownCorner = 2;


			Assert::IsTrue(isPerimeterLess(ptr1, ptr2) == false, L"Assert 1");

			ptr1->shape.circle.radius = 2;

			Assert::IsTrue(isPerimeterLess(ptr1, ptr2) == true, L"Assert 2");

		}
	};

	TEST_CLASS(FileTests)
	{
	public:
		TEST_METHOD(ReadFromFile)
		{
			string inputPath = "../../Text_files/input_list.txt";
			ifstream infile(inputPath);

			List* ptrHead = nullptr;

			ptrHead = readFile(infile, ptrHead);

			Assert::IsTrue(ptrHead->shape.type == 1, L"Assert tp");
			Assert::IsTrue(ptrHead->shape.color == 2, L"Assert clr");
			Assert::IsTrue(ptrHead->shape.rectangle.xRightDownCorner == 6, L"Assert x");
		};


		TEST_METHOD(WriteRectangleToFile)
		{
			string inputPath = "../../Text_files/input_list.txt";
			string outputPath = "../../Text_files/output_rectangles_list.txt";
			ifstream infile(inputPath);
			ofstream file(outputPath);

			List* ptrHead = nullptr;

			ptrHead = readFile(infile, ptrHead);

			writeRectanglesToFile(file, ptrHead);

			ifstream infile1(outputPath);
			stringstream buffer;
			buffer << infile1.rdbuf();
			string fileData = buffer.str();

			string example =
				"Only RECTANGLES: \n"
				"Type of shape is RECTANGLE\n"
				"Left angle's coordinates are (1, 4)\n"
				"Right angle's coordinates are (6, 2)\n"
				"Density is 6\n"
				"Perimeter is 14\n"
				"Color is yellow\n\n";
			//"Number of shapes is 3"; 

			Assert::AreEqual(example, fileData);
		};

		TEST_METHOD(WriteToFile)
		{
			string inputPath = "../../Text_files/input_list.txt";
			string outputPath = "../../Text_files/output_list.txt";
			ifstream infile(inputPath);
			ofstream file(outputPath);

			List* ptrHead = nullptr;

			ptrHead = readFile(infile, ptrHead);

			writeToFile(file, ptrHead);

			ifstream infile1(outputPath);
			stringstream buffer;
			buffer << infile1.rdbuf();
			string fileData = buffer.str();

			string example = "Type of shape is RECTANGLE\n"
				"Left angle's coordinates are (1, 4)\n"
				"Right angle's coordinates are (6, 2)\n"
				"Density is 6\n"
				"Perimeter is 14\n"
				"Color is yellow\n\n"

				"Type of shape is CIRCLE\n"
				"Center's coordinates are (0, 0)\n"
				"Radius is 5\n"
				"Density is 5\n"
				"Perimeter is 31.4\n"
				"Color is orange\n\n"

				"Type of shape is TRIANGLE\n"
				"Its coordinates are (1, 2), (3, 4), (5, 6)\n"
				"Density is 7\n"
				"Perimeter is 11.3137\n"
				"Color is green\n\n";

			//"Number of shapes is 3";

			Assert::AreEqual(example, fileData);

		};
	};


	TEST_CLASS(ContainerTests)
	{
	public:
		TEST_METHOD(ListInitAdd)
		{

			List* ptrHead = nullptr;
			ptrHead = initialize();
			List* ptrCur = ptrHead;

			ptrCur->shape.type = Shape::TYPE_CIRCLE;
			ptrCur->shape.color = Shape::COLOR_RED;
			ptrCur->shape.circle.radius = 5;

			ptrCur = ptrCur->next;
			ptrCur = addElement(ptrCur, ptrHead);

			ptrCur->shape.type = Shape::TYPE_RECTANGLE;
			ptrCur->shape.color = Shape::COLOR_ORANGE;
			ptrCur->shape.rectangle.xLeftUpCorner = 1;

			ptrCur = ptrCur->next;
			ptrCur = addElement(ptrCur, ptrHead);

			ptrCur = ptrCur->prev;

			Assert::IsTrue(ptrCur->shape.type == 1, L"Assert tp");
			Assert::IsTrue(ptrCur->shape.color == 1, L"Assert clr");
			Assert::IsTrue(ptrCur->shape.rectangle.xLeftUpCorner == 1, L"Assert x");

			Assert::IsTrue(ptrHead->shape.type == 0, L"Assert tp");
			Assert::IsTrue(ptrHead->shape.color == 0, L"Assert clr");
			Assert::IsTrue(ptrHead->shape.circle.radius == 5, L"Assert r");


		};

		

		TEST_METHOD(ListSort)
		{
			string inputPath = "../../Text_files/input_list.txt";
			string outputPath = "../../Text_files/output_sorted_list.txt";
			ifstream infile(inputPath);
			ofstream file(outputPath);

			List* ptrHead = nullptr;

			ptrHead = readFile(infile, ptrHead);

			sortByPerimeter(ptrHead);

			writeToFile(file, ptrHead);

			ifstream infile1(outputPath);
			stringstream buffer;
			buffer << infile1.rdbuf();
			string fileData = buffer.str();

			string example =

				"Type of shape is CIRCLE\n"
				"Center's coordinates are (0, 0)\n"
				"Radius is 5\n"
				"Density is 5\n"
				"Perimeter is 31.4\n"
				"Color is orange\n\n"

				"Type of shape is RECTANGLE\n"
				"Left angle's coordinates are (1, 4)\n"
				"Right angle's coordinates are (6, 2)\n"
				"Density is 6\n"
				"Perimeter is 14\n"
				"Color is yellow\n\n"

				"Type of shape is TRIANGLE\n"
				"Its coordinates are (1, 2), (3, 4), (5, 6)\n"
				"Density is 7\n"
				"Perimeter is 11.3137\n"
				"Color is green\n\n";
				//"Number of shapes is 3"; всё должно работать, но нет

			Assert::AreEqual(example, fileData);
		};


		TEST_METHOD(ListLength)
		{
			List* ptrHead;
			ptrHead = initialize();				   // 1
			List* ptrCur = ptrHead;
			ptrCur = ptrCur->next;

			ptrCur = addElement(ptrCur, ptrHead); // 2
			ptrCur = ptrCur->next;

			ptrCur = addElement(ptrCur, ptrHead); // 3
			ptrCur = ptrCur->next;

			ptrCur = addElement(ptrCur, ptrHead); // 4

			Assert::IsTrue(getLength(ptrHead) == 4);

		};

	};
}
