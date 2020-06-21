//ELEMENT.H

#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <fstream>

//abstract class
class Element {
public:	
	virtual ~Element(); //Destructor
	Element();			//Default Constructor

	virtual void print(std::ofstream&) const;											//print when manual inputting
	virtual void autoPrint(std::ofstream&, int* = nullptr, unsigned short = 0) const;   //print when reading from a file

	virtual std::istream& ins(std::istream&, bool = 0, int* = nullptr, unsigned short = 0);			 //for operator >>
	virtual std::ostream& ext(std::ostream&) const;													 //for operator <<
};

std::ostream& operator<<(std::ostream&, const Element&);	//predefinition of operator <<
std::istream& operator>>(std::istream&, Element&);			//predefinition of operator >>

#endif

//END OF ELEMENT.H