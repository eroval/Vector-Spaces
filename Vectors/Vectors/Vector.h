//VECTOR.H

#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

class Vector : public Point {

private:
	float vx;
	float vy;
	float vz;

public:
	virtual ~Vector();			//Destructor
	Vector();				//Default Constructor
	Vector(float, float, float);		//Constructor with Parameters
	Vector(const Point&, const Point&);	//Vector set with two Points in 3D space
	Vector(const Vector&);			//Copy Constructor
	Vector& operator=(const Vector&);	//predefinition of equalization

	bool isItZero() const;			 //check if it is the Zero Vector
	bool Parallel(const Vector&) const;	 //check if two Vectors are Parallel
	bool Perpendicular(const Vector&) const; //check if two Vectors are Perpendicular
	Vector Projection(const Vector&) const;  //finds projection of one Vector onto another


	double Length() const;		         //finds the Length of a Vector
	Vector Direction() const;	         //finds the Direction of the Vector


	Vector operator+(const Vector&) const;			//Addition of two Vectors
	Vector operator-(const Vector&) const;			//Substraction of two Vectors
	Vector operator*(const double) const;			//Multiplication of a Vector with a number
	double operator*(const Vector&) const;			//Scalar Multiplication of two Vectors
	Vector operator^(const Vector&) const;			//Cross Product
	double operator()(const Vector&, const Vector&) const;  //Combined Multiplication
	bool operator==(const Vector&) const;			 //Checks if two Vectors are the same

	int setVectorX(float);
	int setVectorY(float);
	int setVectorZ(float);

	float getVectorX() const;
	float getVectorY() const;
	float getVectorZ() const; 

	int setVector(Vector);
	Vector getVector() const; //return the whole Vector

	virtual void print(std::ofstream&) const;					//output when manual inputting
	virtual void autoPrint(std::ofstream& out, int* arr, unsigned short b) const;   //output when reading from a file

	virtual std::ostream& ext(std::ostream& out) const;
	virtual std::istream& ins(std::istream& in, bool = 0, int* = nullptr, unsigned short = 0);
};

#endif // !VECTOR_H

//END OF VECTOR.H
