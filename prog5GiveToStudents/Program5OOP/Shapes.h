//Catherine Stringfellow  AND
//Shapes.h declares AND DEFINES an inheritance hierarchy of shapes: Shape, Oval, Circle, Rectangle, Square

#pragma once
#include <iostream>
#include <string>
using namespace std;

//Abstract class Shape - has a name only
class Shape
{
public:
	//Constructors & Destructor
	Shape() { name = "Shape"; }

	Shape(string s) { name = s; }

	Shape(const Shape &other) { name = other.name; }

	~Shape() {}

	//getters and setters
	string getName() const { return this->name; }

	void setName(string s) { this->name = s; }

	//methods to override
	virtual double getArea() = 0;

	virtual string toString() { return "Shape is " + name + ".\t Area is undeterminable.\n"; }

private:
	string name;
};

class Rect : public Shape
{

public:
	// make set name and get name and make set value set values....
	Rect() { setName("Rectangle"); }

	Rect(string s, double l, double w) : Shape(s)
	{
		this->length = l;
		this->width = w;
	}

	Rect(const Rect &other) : Shape(other.getName())
	{
		this->length = other.length;
		this->width = other.width;
	}

	double get_length() { return this->length; }

	double get_width() { return this->width; }

	void set_length(double l) { this->length = l; }

	void set_width(double w) { this->width = w; }

	double getArea() { return length * width; }

	string toString()
	{
		return "Shape is " + getName() + ".\t Area is " + to_string(getArea()) + ".\n";
	}

private:
	double length, width;
};

class Square : public Rect
{
public:
	Square() { setName("Square"); }

	Square(string s, double side) : Rect("Square", side, side) {}
};

class Oval : public Shape
{
public:
	// make set name and get name and make set value set values....
	Oval() { setName("Oval"); }

	Oval(string s, double min, double major) : Shape(s)
	{
		minorR = min;
		majorR = major;
	}

	Oval(const Oval &other) : Shape(other.getName())
	{
		minorR = other.minorR;
		majorR = other.majorR;
	}

	double getArea() { return majorR * minorR * 3.14; }

	string toString()
	{
		return "Shape is " + getName() + ".\t Area is " + to_string(getArea()) + ".\n";
	}

	double get_minor_radius() { return this->minorR; }

	double get_major_radius() { return this->majorR; }

	void set_minor_radius(double min) { this->minorR = min; }

	void set_major_radius(double major) { this->majorR = major; }

private:
	double minorR, majorR;
};

class Circle : public Shape
{

public:
	//make set name and get name and make set value set values....
	Circle() { setName("Circle"); }

	Circle(string s, double r)
	{
		setName(s);
		this->radius = r;
	}

	Circle(const Circle &other) : Shape(other.getName()) { this->radius = other.radius; }

	double getArea() { return 3.14 * (radius * radius); }

	double get_radius() { return this->radius; }

	void set_radius(double r) { this->radius = r; }

	string toString()
	{
		return "Shape is " + getName() + ".\t Area is " + to_string(getArea()) + ".\n";
	}

private:
	double radius;
};
