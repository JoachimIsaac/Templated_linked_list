//Catherine Stringfellow  AND Joachim Isaac
//OOP Program 5ListShapesAreas
//ListShapesAreas.cpp - reads a list of shapes and their dimensions from a file and
//outputs their areas and the cumulative area.

//#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "List.h"
#include "Shapes.h"

using namespace std;

//Prototypes for non-member functions

//Open streams for reading and writing
void openFiles(ifstream &infile, ofstream &outfile);

// //Print name and program assignment
void printHeading(ofstream &outfile);

//Read shape info, instantiate it and return the pointer to it
void readShape(ifstream &, Shape *&);

int main()
{

  // //Declare a List of pointers to Shape and a pointer to a Shape
  List<Shape *> shapes;
  Shape *current_shape;

  //open streams for input and output
  ifstream infile;
  ofstream outfile;

  openFiles(infile, outfile);

  printHeading(outfile);

  //read a shape
  readShape(infile, current_shape);

  //while more data
  while (!infile.eof())
  {

    shapes.InsertItem(current_shape);
    shapes.AdvanceCursor();
    readShape(infile, current_shape);
  }

  double total = 0;
  shapes.ResetCursor();
  for (int i = 0; i < shapes.getCount(); i++)
  {
    shapes.GetCurrentItem(current_shape);
    shapes.AdvanceCursor();

    outfile << current_shape->toString();
    total += current_shape->getArea();
  }

  outfile << "\nTotal area of all shapes is  " << total << "\n";

  //insert the shape and advance cursor to append to the end next time
  //read next shape

  //init cursor and total

  //get each shape, print it's data and accumulate the areas

  //print the cumulative area

  return 0;
}

//Implementations of non-member functions

//Open streams for reading and writing
void openFiles(ifstream &infile, ofstream &outfile)
{
  string input_file;
  string output_file;
  cout << "Please enter the name of the input file. ";
  cin >> input_file;
  cout << "Please enter the name of the output file. ";
  cin >> output_file;
  infile.open(input_file);
  outfile.open(output_file);
}

//Print name and program assignment
void printHeading(ofstream &outfile)
{
  outfile << "Name: Joachim Isaac \n";
  outfile << "Program 5 \n\n";
}

void readShape(ifstream &infile, Shape *&s)
{

  //declare variables
  string name;
  char character;
  double value1;
  double value2;

  //read the name of the shape
  infile >> name;

  //use a switch based on the first character in the shape, instantiate the shape
  character = name.at(0);
  //read the name of the shape
  switch (character)
  {
  case 'O':
    infile >> value1;
    infile >> value2;
    s = new Oval("Oval", double(value1), double(value2));
    break;

  case 'S':
    infile >> value1;
    s = new Square("Square", double(value1));
    break;

  case 'C':
    infile >> value1;
    s = new Circle("Circle", double(value1));
    break;

  case 'R':
    infile >> value1;
    infile >> value2;
    s = new Rect("Rectangle", double(value1), double(value2));
    break;

  default:
    cout << "\nThis is not a case!\n";
    break;
  }
}
