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

// //Open streams for reading and writing
// void openFiles(ifstream &infile, ofstream &outfile);

// // //Print name and program assignment
// void printHeading(ofstream &outfile);

// //Read shape info, instantiate it and return the pointer to it
// void readShape(ifstream &, Shape *&);

int main()
{

  //Declare a List of pointers to Shape and a pointer to a Shape

  //open streams for input and output
  // ifstream infile;
  // ofstream outfile;
  // openFiles(infile, outfile);

  // printHeading(outfile);

  //read a shape
  //while more data
  //insert the shape and advance cursor to append to the end next time
  //read next shape

  //init cursor and total

  //get each shape, print it's data and accumulate the areas

  //print the cumulative area

  Rect rect("Rectangle", 2, 3);
  Square sqr("Square", 5);
  Oval ova("Oval", 3, 5);
  Circle circ("Circle", 6);

  cout << rect.toString();
  cout << sqr.toString();
  cout << ova.toString();
  cout << circ.toString();

  Rect rect2(rect);
  Circle cir2(circ);
  Square sqr2(sqr);
  Oval ova2(ova);
  cout << "Copy!!!!!!!! " + rect2.toString();
  cout << "Copy!!!!!!!! " + cir2.toString();
  cout << "Copy!!!!!!!! " + sqr2.toString();
  cout << "Copy!!!!!!!! " + ova2.toString();

  List<int> l;
  l.InsertItem(1);
  l.InsertItem(2);
  l.InsertItem(3);
  l.InsertItem(4);
  List<int> l2;
  l2.InsertItem(12);
  l2.InsertItem(23);
  l2.InsertItem(33);
  l2.InsertItem(44);

  l.printListtest();
  cout << "\n";

  l.ClearList();
  l.InsertItem(100);
  cout << "\n";
  l.printListtest();
  // l.SwapLists(l2);
  cout << "\n";
  l.printListtest();
  l.DeleteItem();
  l.DeleteItem();
  l.DeleteItem();
  l.DeleteItem();
  l.printListtest();

  return 0;
}

//Implementations of non-member functions

// //Open streams for reading and writing
// void openFiles(ifstream &infile, ofstream &outfile)
// {
//   string input_file;
//   string output_file;
//   cout << "Please enter the name of the input file. ";
//   cin >> input_file;
//   cout << "Please enter the name of the output file. ";
//   cin >> output_file;
//   infile.open(input_file);
//   outfile.open(output_file);
// }

// //Print name and program assignment
// void printHeading(ofstream &outfile)
// {
//   outfile << "Name: Joachim Isaac \n";
//   outfile << "Program 5 \n";
// }

// void readShape(ifstream &infile, Shape *&s)
// {

//   //declare variables

//   //read the name of the shape

//   //use a switch based on the first character in the shape, instantiate the shape
// }