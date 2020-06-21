#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "iostream"
#include "Segment.h"

class Triangle :public Segment {
private:
	Point tA;
	Point tB;
	Point tC;
public:
	virtual ~Triangle();								//Destructor
	Triangle();											//Default Constructor
	Triangle(const Point&, const Point&, const Point&); //Constructor with parameters
	Triangle(const Triangle&);							//Copy Constructor
	Triangle& operator=(const Triangle&);				//Predefined equalization

	const char* TypeOfTriangle() const;					//Check Type of Triangle

	double Perimeter() const;							//Finds Perimeter of the Triangle
	double Area() const;							    //Finds Area of a Triangle
	Point Centre() const;								//Finds the Centre of the Triangle

	Point getTA() const;	  //get Point A
	Point getTB() const;	  //get Point B
	Point getTC() const;	  //get Point C

	int setTA(const Point&);  //set Point A
	int setTB(const Point&);  //set Point B
	int setTC(const Point&);  //set Point C

	virtual void check(const Point&, const Point&, const Point&); //Checks if the sides are properly inputted

	bool operator<(const Point&) const;							  //Finds if a Point is on the plane of the Triangle and inside the triangle
	bool operator>(const Point&) const;							  //Finds if a point lies on the plane of the Triangle and is outside of it
	bool operator==(const Point&) const;						  //Finds if a point lies on a side of the Triangle

	virtual void print(std::ofstream&) const;										//print when manual inputting
	virtual void autoPrint(std::ofstream& out, int* arr, unsigned short b) const;   //print when reading from a file


	virtual std::ostream& ext(std::ostream& out) const;
	virtual std::istream& ins(std::istream& in, bool = 0, int* = nullptr, unsigned short = 0);
};

#endif // !TRIANGLE_H