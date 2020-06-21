//VECTORLENGTHEXCEPTION.CPP

#include "VectorLengthException.h"

VectorLengthException::VectorLengthException(const char* name) {
	this->name = name;

}

const char* VectorLengthException::what() const{
	return this->name;
}

//END OF VECTORLENGTHEXCEPTION.CPP