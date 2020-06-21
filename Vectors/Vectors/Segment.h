#ifndef SEGMENT_H
#define SEGMENT_H

#include "Line.h"

class Segment : public Line {
private:
	//interval of the segment
	float t[2];
public:
	virtual ~Segment();						 //Destructor
	Segment();							 //Default Constructor
	Segment(const Point&, const Vector&, float, float); 		 //Constructor with Line and an Interval
	Segment(const Point&, const Vector&);				 //Constructor with Default Values
	Segment(const Line&);						 //Constructor set with a Line and Default Values
	Segment(const Segment&);					 //Copy Constructor
	Segment& operator=(const Segment&);				 //Predefined equalization

	double Length() const;					 	 //Return the Length of the Segment
	Point Middle() const;						 //Return a Point which is in the middle of the Segment

	bool operator==(const Point&) const;			   	 //Check is a Point lies on the Segment

	float getT(int) const; //interval get
	int setT(int, float);  //interval set

	void swap(float&, float&);

	virtual void print(std::ofstream&) const;				   	    //output when manual inputting
	virtual void autoPrint(std::ofstream& out, int* arr, unsigned short b) const;       //output when reading from a file

	virtual std::ostream& ext(std::ostream& out) const;
	virtual std::istream& ins(std::istream& in, bool = 0, int* = nullptr, unsigned short = 0);
};


#endif
