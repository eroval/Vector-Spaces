//POINT.H

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Element.h"

class Point : public Element {

private:
	float px;
	float py;
	float pz;

public:
	virtual ~Point();				//Destructor
	Point();						//Default Constructor
	Point(float , float , float );  //Constructor with Parameters
	Point(const Point&);			//Copy Constructor
	Point& operator=(const Point&); //predefinition of equalization

	bool operator ==(const Point&) const; //Checks if two Points are the same

	int setPointX(float);
	int setPointY(float);
	int setPointZ(float);
	int setPoint(Point);

	float getPointX() const;
	float getPointY() const;
	float getPointZ() const;
	Point getPoint() const; //return the whole Point


	virtual void print() const;														 //output when manual inputting
	virtual void autoPrint(std::ofstream& out, int* arr, unsigned short b) const;	 //output when reading from a file

	virtual std::istream& ins(std::istream&, bool = 0, int* = nullptr, unsigned short = 0);
	virtual std::ostream& ext(std::ostream&) const;
};


#endif 

//END OF POINT.H