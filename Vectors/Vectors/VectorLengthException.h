//VECTORLENGTHEXCEPTION.H

#ifndef VECTOR_LENGTH_EXCEPTION_H
#define VECTOR_LENGTH_EXCEPTION_H

#include <stdexcept>
#include "Vector.h"
#include <iostream>

class VectorLengthException : public std::exception{
private:
	const char* name; //Stores Error
public:
	VectorLengthException(const char* = "It is the Zero Vector!"); //Default Error Value
	const char* what() const;									   //Returns Error Value
};

#endif // !VECTOR_LENGTH_EXCEPTION_H


//END OF VECTORLENGTHEXCEPTION.h