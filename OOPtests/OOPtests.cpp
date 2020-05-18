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
			shape.ReadShapeFromFile(infile);
			infile.close();

			Assert::IsTrue(shape.GetColor() == 1, L"Assert GetColor");
			Assert::IsTrue(shape.GetDensity() == 100.5, L"Assert GetDensity");
		}

		TEST_METHOD(WriteToFile)
		{
			string outputPath = "../../Text_files/output_shape.txt";
			ofstream outfile(outputPath);

			Shape shape;

			shape.SetColor(1);
			shape.SetDensity(100.5);

			shape.WriteShapeToFile(outfile);
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
			rectangle.ReadShapeFromFile(infile);
			infile.close();

			Assert::IsTrue(rectangle.GetXLeftUpCorner() == 1, L"Assert GetXLeftUpCorner");
			Assert::IsTrue(rectangle.GetYLeftUpCorner() == 3, L"Assert GetYLeftUpCorner");
			Assert::IsTrue(rectangle.GetXRightDownCorner() == 5, L"Assert GetXRightDownCorner");
			Assert::IsTrue(rectangle.GetYRightDownCorner() == 1, L"Assert GetYRightDownCorner");
		}

		TEST_METHOD(WriteToFile)
		{
			string outputPath = "../../Text_files/output_rectangle.txt";
			ofstream outfile(outputPath);

			Rectangle rectangle;
			rectangle.SetRectangle(1, 4, 6, 2);
			rectangle.SetColor(5);
			rectangle.SetDensity(1000);

			rectangle.WriteShapeToFile(outfile);
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
			rectangle.SetRectangle(1, 3, 5, 1);

			Assert::IsTrue(rectangle.CalculateThePerimeter() == 12, L"Assert Rectangle");
		}

		TEST_METHOD(Compare)
		{
			Rectangle rectangle;
			Circle circle;

			rectangle.SetRectangle(1, 4, 5, 2);
			circle.SetCircle(0, 0, 2);

			Assert::IsTrue(rectangle.Compare(&circle) == true, L"Assert Compare");

			circle.SetCircle(0, 0, 1);

			Assert::IsTrue(rectangle.Compare(&circle) == false, L"Assert Compare2");
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
			circle.ReadShapeFromFile(infile);
			infile.close();

			Assert::IsTrue(circle.GetXCenter() == 3, L"Assert GetXCenter");
			Assert::IsTrue(circle.GetYCenter() == 4, L"Assert GetYCenter");
			Assert::IsTrue(circle.GetRadius() == 5, L"Assert GetRadius");

		}

		TEST_METHOD(WriteToFile)
		{
			string outputPath = "../../Text_files/output_circle.txt";
			ofstream outfile(outputPath);

			Circle circle;
			circle.SetCircle(0, 0, 5);
			circle.SetColor(5);
			circle.SetDensity(1000);

			circle.WriteShapeToFile(outfile);
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
			circle.SetCircle(0, 0, 5);

			float result = floor(circle.CalculateThePerimeter() * 10 / 10);

			Assert::IsTrue(result == floor((31.4 * 10) / 10), L"Assert Circle");
		}

		TEST_METHOD(Compare)
		{
			Rectangle rectangle;
			Circle circle;

			rectangle.SetRectangle(1, 4, 5, 2);
			circle.SetCircle(0, 0, 2);

			Assert::IsTrue(circle.Compare(&rectangle) == false, L"Assert Compare");

			circle.SetCircle(0, 0, 1);

			Assert::IsTrue(circle.Compare(&rectangle) == true, L"Assert Compare2");
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
			triangle.ReadShapeFromFile(infile);
			infile.close();

			Assert::IsTrue(triangle.GetX1() == 1, L"Assert GetX1");
			Assert::IsTrue(triangle.GetY1() == 2, L"Assert GetY1");
			Assert::IsTrue(triangle.GetX2() == 3, L"Assert GetX2");
			Assert::IsTrue(triangle.GetY2() == 4, L"Assert GetY2");
			Assert::IsTrue(triangle.GetX3() == 5, L"Assert GetX3");
			Assert::IsTrue(triangle.GetY3() == 6, L"Assert GetY3");
		}

		TEST_METHOD(WriteToFile)
		{
			string outputPath = "../../Text_files/output_triangle.txt";
			ofstream outfile(outputPath);

			Triangle triangle;
			triangle.SetTriangle(0, 0, 3, 0, 0, 4);
			triangle.SetColor(5);
			triangle.SetDensity(1000);

			triangle.WriteShapeToFile(outfile);
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
			triangle.SetTriangle(0, 0, 3, 0, 0, 4);

			float result = triangle.CalculateThePerimeter();

			Assert::IsTrue(triangle.CalculateThePerimeter() == 12, L"Assert Circle");
		}

		TEST_METHOD(Compare)
		{
			Rectangle rectangle;
			Triangle triangle;

			rectangle.SetRectangle(1, 4, 5, 2);
			triangle.SetTriangle(0, 0, 3, 0, 0, 4);

			Assert::IsTrue(triangle.Compare(&rectangle) == false, L"Assert Compare");

			rectangle.SetRectangle(1, 4, 10, 2);

			Assert::IsTrue(triangle.Compare(&rectangle) == true, L"Assert Compare2");
		}
	};

	TEST_CLASS(ContainerTests)
	{

		TEST_METHOD(ListInitAdd)
		{
			List* ptrHead = nullptr;
			List* ptrCur = nullptr;
			ptrCur = List::InitList(ptrCur, ptrHead);
			ptrHead = ptrCur;
			ptrCur->shape = new Shape();
			ptrCur->shape->SetColor(1);
			ptrCur->shape->SetDensity(1000);

			Assert::IsTrue(ptrCur->shape->GetColor() == 1);
			Assert::IsTrue(ptrCur->shape->GetDensity() == 1000);

			ptrCur = ptrCur->next;

			ptrCur = List::AddToList(ptrCur, ptrHead);
			ptrCur->shape = new Shape();
			ptrCur->shape->SetColor(2);
			ptrCur->shape->SetDensity(2000);
			Assert::IsTrue(ptrCur->shape->GetColor() == 2);
			Assert::IsTrue(ptrCur->shape->GetDensity() == 2000);

			ptrCur = ptrCur->next;

			ptrCur = List::AddToList(ptrCur, ptrHead);
			ptrCur->shape = new Shape();
			ptrCur->shape->SetColor(3);
			ptrCur->shape->SetDensity(3000);

			Assert::IsTrue(ptrCur->shape->GetColor() == 3);
			Assert::IsTrue(ptrCur->shape->GetDensity() == 3000);
	
			ptrCur = ptrCur->prev;

			Assert::IsTrue(ptrCur->shape->GetColor() == 2);
			Assert::IsTrue(ptrCur->shape->GetDensity() == 2000);


		}

		TEST_METHOD(ListLength)
		{
			List* ptrHead = nullptr;
			List* ptrCur = nullptr;
	
			ptrCur = List::InitList(ptrCur, ptrHead);
			ptrHead = ptrCur;

			ptrCur = ptrCur->next;
			ptrCur = List::AddToList(ptrCur, ptrHead);

			ptrCur = ptrCur->next;
			ptrCur = List::AddToList(ptrCur, ptrHead);

			ptrCur = ptrCur->next;
			ptrCur = List::AddToList(ptrCur, ptrHead);

			int length = List::GetListLength(ptrHead);
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

			ptrHead = list->In(infile, ptrCur, ptrHead);
			infile.close();
			
			ptrCur = ptrHead;
			Assert::IsTrue(ptrCur->shape->GetColor() == 2, L"Alert 1");

			ptrCur = ptrCur->next;
			Assert::IsTrue(ptrCur->shape->GetColor() == 1, L"Alert 2");

			ptrCur = ptrCur->next;
			Assert::IsTrue(ptrCur->shape->GetColor() == 3, L"Alert 3");
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

			ptrHead = list->In(infile, ptrCur, ptrHead);
			infile.close();

			list->Out(outfile, ptrHead);
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

			ptrHead = list->In(infile, ptrCur, ptrHead);
			infile.close();

			list->OutRectangle(outfile, ptrHead);
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
			ptrHead = list->In(infile, ptrCur, ptrHead);
			infile.close();

			list->Sort(ptrHead);

			list->Out(outfile, ptrHead);
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
