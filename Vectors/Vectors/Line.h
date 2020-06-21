//LINE.H

#ifndef LINE_H
#define LINE_H

#include "Vector.h"

class Line : public Vector {
public:
	virtual ~Line(); //Destructor
	Line(); //Default Constructor
	Line(const Point& , const Vector&);          //Set with a Point and a Vector
	Line(const Point&, const Point&);            //Set with two Points
	Line(const Line&);                           //Copy Constructor
	Line& operator=(const Line&);                //predefinition of equalization

	Vector Perpendicular() const;                //Finds a normal Vector to the line
	Vector Direction() const;                    //Finds the direction of the line

	double ShortestDistance(const Line&) const;  //Find the shortest distance between two Lines
	double PointDistance(const Point& a) const;  //Finds the shortest distance to a Point
	double Angle(const Line&) const;             //Find the angle created by two lines

	bool operator+(const Point&) const;          //Finds if a Point lies on the line
	bool operator||(const Line&) const;	     //Checks if two lines are parallel
	bool operator==(const Line&) const;	     //Checks if two lines match
	bool operator&&(const Line&) const;	     //Checks if two lines intersect
	bool operator!=(const Line&) const;	     //Checks if two lines never intersect
	bool operator|(const Line&) const;	     //Checks if two lines are perpendicular(orthogonal more precisely)


	virtual void print(std::ofstream&) const;						//output when manual inputting
	virtual void autoPrint(std::ofstream& out, int* arr, unsigned short b) const;		//output when reading from a file

	virtual std::ostream& ext(std::ostream& out) const;
	virtual std::istream& ins(std::istream& in, bool = 0, int* = nullptr, unsigned short = 0);
};


#endif // !LINE_H

//END OF LINE.H
