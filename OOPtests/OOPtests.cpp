#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP/container.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OOPtests
{
	TEST_CLASS(ShapeTests)
	{
	public:

		TEST_METHOD(ReadFromFile)
		{

			string inputPath = "../../Text_files/input_shape.txt";
			ifstream infile(inputPath);

			Shape shape;
			shape.readFromFile(infile);
			infile.close();

			Assert::IsTrue(shape.getColor() == 1, L"Assert GetColor");
			Assert::IsTrue(shape.getDensity() == 100.5, L"Assert GetDensity");
		}

		TEST_METHOD(WriteToFile)
		{
			string outputPath = "../../Text_files/output_shape.txt";
			ofstream outfile(outputPath);

			Shape shape;

			shape.setColor(1);
			shape.setDensity(100.5);

			shape.writeToFile(outfile);
			outfile.close();

			ifstream infile(outputPath);
			stringstream buffer;
			buffer << infile.rdbuf();
			string fileData = buffer.str();


			string example = "Density is 100.5\nColor is orange\n\n";

			Assert::AreEqual(example, fileData);
		}
	};

	TEST_CLASS(RectangleTests)
	{
	public:
		TEST_METHOD(ReadFromFile)
		{
			string inputPath = "../../Text_files/input_rectangle.txt";
			ifstream infile(inputPath);

			Rectangle rectangle;
			rectangle.readFromFile(infile);
			infile.close();

			Assert::IsTrue(rectangle.getXLeftUpCorner() == 1, L"Assert GetXLeftUpCorner");
			Assert::IsTrue(rectangle.getYLeftUpCorner() == 3, L"Assert GetYLeftUpCorner");
			Assert::IsTrue(rectangle.getXRightDownCorner() == 5, L"Assert GetXRightDownCorner");
			Assert::IsTrue(rectangle.getYRightDownCorner() == 1, L"Assert GetYRightDownCorner");
		}

		TEST_METHOD(WriteToFile)
		{
			string outputPath = "../../Text_files/output_rectangle.txt";
			ofstream outfile(outputPath);

			Rectangle rectangle;
			rectangle.setRectangle(1, 4, 6, 2);
			rectangle.setColor(5);
			rectangle.setDensity(1000);

			rectangle.writeToFile(outfile);
			outfile.close();

			ifstream infile(outputPath);
			stringstream buffer;
			buffer << infile.rdbuf();
			string fileData = buffer.str();

			string example = "Type of shape is RECTANGLE\nLeft angle's coordinates are (1, 4)\nRight angle's coordinates are (6, 2)\nPerimeter is 14\nDensity is 1000\nColor is cyan\n\n";

			Assert::AreEqual(example, fileData);
		}

		TEST_METHOD(Perimeter)
		{
			Rectangle rectangle;
			rectangle.setRectangle(1, 3, 5, 1);

			Assert::IsTrue(rectangle.computePerimeter() == 12, L"Assert Rectangle");
		}

		TEST_METHOD(Compare)
		{
			Rectangle rectangle;
			Circle circle;

			rectangle.setRectangle(1, 4, 5, 2);
			circle.setCircle(0, 0, 2);

			Assert::IsTrue(rectangle.isPerimeterLess(&circle) == true, L"Assert Compare");

			circle.setCircle(0, 0, 1);

			Assert::IsTrue(rectangle.isPerimeterLess(&circle) == false, L"Assert Compare2");
		}
	};

	TEST_CLASS(CircleTests)
	{
	public:
		TEST_METHOD(ReadFromFile)
		{
			string inputPath = "../../Text_files/input_circle.txt";
			ifstream infile(inputPath);

			Circle circle;
			circle.readFromFile(infile);
			infile.close();

			Assert::IsTrue(circle.getXCenter() == 3, L"Assert GetXCenter");
			Assert::IsTrue(circle.getYCenter() == 4, L"Assert GetYCenter");
			Assert::IsTrue(circle.getRadius() == 5, L"Assert GetRadius");

		}

		TEST_METHOD(WriteToFile)
		{
			string outputPath = "../../Text_files/output_circle.txt";
			ofstream outfile(outputPath);

			Circle circle;
			circle.setCircle(0, 0, 5);
			circle.setColor(5);
			circle.setDensity(1000);

			circle.writeToFile(outfile);
			outfile.close();

			ifstream infile(outputPath);
			stringstream buffer;
			buffer << infile.rdbuf();
			string fileData = buffer.str();

			string example = "Type of shape is CIRCLE\nCenter's coordinates are (0, 0)\nRadius is 5\nPerimeter is 31.4\nDensity is 1000\nColor is cyan\n\n";

			Assert::AreEqual(example, fileData);
		}

		TEST_METHOD(Perimeter)
		{
			Circle circle;
			circle.setCircle(0, 0, 5);

			float result = floor(circle.computePerimeter() * 10 / 10);

			Assert::IsTrue(result == floor((31.4 * 10) / 10), L"Assert Circle");
		}

		TEST_METHOD(Compare)
		{
			Rectangle rectangle;
			Circle circle;

			rectangle.setRectangle(1, 4, 5, 2);
			circle.setCircle(0, 0, 2);

			Assert::IsTrue(circle.isPerimeterLess(&rectangle) == false, L"Assert Compare");

			circle.setCircle(0, 0, 1);

			Assert::IsTrue(circle.isPerimeterLess(&rectangle) == true, L"Assert Compare2");
		}
	};

	TEST_CLASS(TriangleTests)
	{
	public:
		TEST_METHOD(ReadFromFile)
		{
			string inputPath = "../../Text_files/input_triangle.txt";
			ifstream infile(inputPath);

			Triangle triangle;
			triangle.readFromFile(infile);
			infile.close();

			Assert::IsTrue(triangle.getX1() == 1, L"Assert GetX1");
			Assert::IsTrue(triangle.getY1() == 2, L"Assert GetY1");
			Assert::IsTrue(triangle.getX2() == 3, L"Assert GetX2");
			Assert::IsTrue(triangle.getY2() == 4, L"Assert GetY2");
			Assert::IsTrue(triangle.getX3() == 5, L"Assert GetX3");
			Assert::IsTrue(triangle.getY3() == 6, L"Assert GetY3");
		}

		TEST_METHOD(WriteToFile)
		{
			string outputPath = "../../Text_files/output_triangle.txt";
			ofstream outfile(outputPath);

			Triangle triangle;
			triangle.setTriangle(0, 0, 3, 0, 0, 4);
			triangle.setColor(5);
			triangle.setDensity(1000);

			triangle.writeToFile(outfile);
			outfile.close();

			ifstream infile(outputPath);
			stringstream buffer;
			buffer << infile.rdbuf();
			string fileData = buffer.str();

			string example = "Type of shape is TRIANGLE\nPoint's coordinates are (0, 0), (3, 0), (0, 4)\nPerimeter is 12\nDensity is 1000\nColor is cyan\n\n";

			Assert::AreEqual(example, fileData);
		}

		TEST_METHOD(Perimeter)
		{
			Triangle triangle;
			triangle.setTriangle(0, 0, 3, 0, 0, 4);

			float result = triangle.computePerimeter();

			Assert::IsTrue(triangle.computePerimeter() == 12, L"Assert Circle");
		}

		TEST_METHOD(Compare)
		{
			Rectangle rectangle;
			Triangle triangle;

			rectangle.setRectangle(1, 4, 5, 2);
			triangle.setTriangle(0, 0, 3, 0, 0, 4);

			Assert::IsTrue(triangle.isPerimeterLess(&rectangle) == false, L"Assert Compare");

			rectangle.setRectangle(1, 4, 10, 2);

			Assert::IsTrue(triangle.isPerimeterLess(&rectangle) == true, L"Assert Compare2");
		}
	};

	TEST_CLASS(ContainerTests)
	{

		TEST_METHOD(ListInitAdd)
		{
			List* ptrHead = nullptr;
			List* ptrCur = nullptr;
			ptrCur = List::initialization();
			ptrHead = ptrCur;
			ptrCur->shape = new Shape();
			ptrCur->shape->setColor(1);
			ptrCur->shape->setDensity(1000);

			Assert::IsTrue(ptrCur->shape->getColor() == 1);
			Assert::IsTrue(ptrCur->shape->getDensity() == 1000);

			ptrCur = ptrCur->next;

			ptrCur = List::addElement(ptrCur, ptrHead);
			ptrCur->shape = new Shape();
			ptrCur->shape->setColor(2);
			ptrCur->shape->setDensity(2000);
			Assert::IsTrue(ptrCur->shape->getColor() == 2);
			Assert::IsTrue(ptrCur->shape->getDensity() == 2000);

			ptrCur = ptrCur->next;

			ptrCur = List::addElement(ptrCur, ptrHead);
			ptrCur->shape = new Shape();
			ptrCur->shape->setColor(3);
			ptrCur->shape->setDensity(3000);

			Assert::IsTrue(ptrCur->shape->getColor() == 3);
			Assert::IsTrue(ptrCur->shape->getDensity() == 3000);
	
			ptrCur = ptrCur->prev;

			Assert::IsTrue(ptrCur->shape->getColor() == 2);
			Assert::IsTrue(ptrCur->shape->getDensity() == 2000);


		}

		TEST_METHOD(ListLength)
		{
			List* ptrHead = nullptr;
			List* ptrCur = nullptr;
	
			ptrCur = List::initialization();
			ptrHead = ptrCur;

			ptrCur = ptrCur->next;
			ptrCur = List::addElement(ptrCur, ptrHead);

			ptrCur = ptrCur->next;
			ptrCur = List::addElement(ptrCur, ptrHead);

			ptrCur = ptrCur->next;
			ptrCur = List::addElement(ptrCur, ptrHead);

			int length = List::getLength(ptrHead);
			Assert::IsTrue(length == 4);


		}

		TEST_METHOD(ListIn)
		{
			string inputPath = "../../Text_files/input_list.txt";
			string outputPath = "../../Text_files/output_list.txt";
			ifstream infile(inputPath);
			ofstream outfile(outputPath);
			List* list = new List();
			List* ptrCur = new List();
			List * ptrHead = new List();

			ptrHead = list->readFromFile(infile, ptrHead);
			infile.close();
			
			ptrCur = ptrHead;
			Assert::IsTrue(ptrCur->shape->getColor() == 2, L"Alert 1");

			ptrCur = ptrCur->next;
			Assert::IsTrue(ptrCur->shape->getColor() == 1, L"Alert 2");

			ptrCur = ptrCur->next;
			Assert::IsTrue(ptrCur->shape->getColor() == 3, L"Alert 3");
		}

		TEST_METHOD(ListOut)
		{
			string inputPath = "../../Text_files/input_list.txt";
			string outputPath = "../../Text_files/output_list.txt";
			ifstream infile(inputPath);
			ofstream outfile(outputPath);
			List* list = new List();
			List* ptrCur = new List();
			List* ptrHead = new List();

			ptrHead = list->readFromFile(infile, ptrHead);
			infile.close();

			list->writeToFile(outfile, ptrHead);
			outfile.close();

			ifstream check(outputPath);
			stringstream buffer;
			buffer << check.rdbuf();
			string fileData = buffer.str();

			string example = "Type of shape is RECTANGLE\n"
				"Left angle's coordinates are (1, 4)\n"
				"Right angle's coordinates are (6, 2)\n"
				"Perimeter is 14\n"
				"Density is 6\n"
				"Color is yellow\n\n"

				"Type of shape is CIRCLE\n"
				"Center's coordinates are (0, 0)\n"
				"Radius is 5\n"
				"Perimeter is 31.4\n"
				"Density is 5\n"
				"Color is orange\n\n"

				"Type of shape is TRIANGLE\n"
				"Point's coordinates are (1, 2), (3, 4), (5, 6)\n"
				"Perimeter is 11.3137\n"
				"Density is 7\n"
				"Color is green\n\n"

				"Number of shapes is 3";

			Assert::AreEqual(example, fileData);
		}
		TEST_METHOD(ListOutRectangle)
		{
			string inputPath = "../../Text_files/input_list.txt";
			string outputPath = "../../Text_files/output_rectangles_list.txt";
			ifstream infile(inputPath);
			ofstream outfile(outputPath);
			List* list = new List();
			List* ptrCur = new List();
			List* ptrHead = new List();

			ptrHead = list->readFromFile(infile, ptrHead);
			infile.close();

			list->writeRectanglesToFile(outfile, ptrHead);
			outfile.close();

			ifstream check(outputPath);
			stringstream buffer;
			buffer << check.rdbuf();
			string fileData = buffer.str();

			string example =
					"Only RECTANGLES: \n" 
					"Type of shape is RECTANGLE\n"
					"Left angle's coordinates are (1, 4)\n"
					"Right angle's coordinates are (6, 2)\n"
					"Perimeter is 14\n"
					"Density is 6\n"
					"Color is yellow\n\n"

					"Number of shapes is 3";

			Assert::AreEqual(example, fileData);
		}
		TEST_METHOD(ListSort)
		{
			string inputPath = "../../Text_files/input_list.txt";
			string outputPath = "../../Text_files/output_sorted_list.txt";
			ifstream infile(inputPath);
			ofstream outfile(outputPath);
			List* list = new List();
			List* ptrCur = nullptr;
			List* ptrHead = nullptr;
			ptrHead = list->readFromFile(infile, ptrHead);
			infile.close();

			list->sortByPerimeter(ptrHead);

			list->writeToFile(outfile, ptrHead);
			outfile.close();

			ifstream check(outputPath);
			stringstream buffer;
			buffer << check.rdbuf();
			string fileData = buffer.str();

			string example = 
				"Type of shape is CIRCLE\n"
				"Center's coordinates are (0, 0)\n"
				"Radius is 5\n"
				"Perimeter is 31.4\n"
				"Density is 5\n"
				"Color is orange\n\n"
						
				"Type of shape is RECTANGLE\n"
				"Left angle's coordinates are (1, 4)\n"
				"Right angle's coordinates are (6, 2)\n"
				"Perimeter is 14\n"
				"Density is 6\n"
				"Color is yellow\n\n"

				"Type of shape is TRIANGLE\n"
				"Point's coordinates are (1, 2), (3, 4), (5, 6)\n"
				"Perimeter is 11.3137\n"
				"Density is 7\n"
				"Color is green\n\n"

				"Number of shapes is 3";

			Assert::AreEqual(example, fileData);
		}

	};
}
