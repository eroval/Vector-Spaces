//EQUAL_POINTS_EXCEPTION_H

#ifndef EQUAL_POINTS_EXCEPTION_H
#define EQUAL_POINTS_EXCEPTION_H


#include <stdexcept>
#include <string>
#include "Segment.h"
#include <iostream>

class EqualPointsException : public std::exception {
private:
	const char * name;
	Point VLE;
public:
	EqualPointsException(const char* = "The Points are Equal!");
	EqualPointsException(const Point&);
	const char* what() const;
};

#endif // !EQUAL_POINTS_EXCEPTION_H


//END OF EQUAL_POINTS_EXCEPTION_H