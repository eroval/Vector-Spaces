//POINT.CPP

#include "Point.h"

//Destructor
Point::~Point() {
	//std::cout << "\nDESTROCTOR POINT CALLED\n"<<*this<<"\n";
}

//Default Constructor
Point::Point() {
	px = 1;
	py = 2;
	pz = 3;
}

//Constructor with Parameters
Point::Point(float a, float b, float c) {
	px = a;
	py = b;
	pz = c;
}

//Copy Constructor
Point::Point(const Point& a) {
	this->px = a.px;
	this->py = a.py;
	this->pz = a.pz;
}

//predefinition of equalization
Point& Point::operator=(const Point& a) {
	this->px = a.px;
	this->py = a.py;
	this->pz = a.pz;
	return *this;
}

//Checks if two Points are the same
bool Point::operator==(const Point& a) const {
	if (px == a.px && py == a.py && pz == a.pz) {
		return true;
	}
	else return false;
}

int Point::setPointX(float a) {
	px = a;
	return 0;
}

int Point::setPointY(float a) {
	py = a;
	return 0;
}

int Point::setPointZ(float a) {
	pz = a;
	return 0;
}

int Point::setPoint(Point a) {
	px = a.px;
	py = a.py;
	pz = a.pz;
	return 0;
}

float Point::getPointX() const {
	return px;
}

float Point::getPointY() const {
	return py;
}

float Point::getPointZ() const {
	return pz;
}

Point Point::getPoint() const {
	return *this;
}

//output when manual inputting
void Point::print() const {
	std::cout << "\nx=" << px << std::endl;
	std::cout << "y=" << py << std::endl;
	std::cout << "z=" << pz << std::endl;
	std::cout << std::endl;
}

//output when reading from a file
void Point::autoPrint(std::ofstream& out, int* arr, unsigned short b) const {
	std::cout << "\nx=" << px << std::endl;
	std::cout << "y=" << py << std::endl;
	std::cout << "z=" << pz << std::endl;
	std::cout << std::endl;
};

std::istream& Point::ins(std::istream& in, bool a, int*arr, unsigned short b) {
	if (a == 0) {
		std::cout << "Enter x: ";
		in >> px;
		std::cout << "Enter y: ";
		in >> py;
		std::cout << "Enter z: ";
		in >> pz;
	}
	else {
		if (b < 4) {
			std::cout << "Not enough information for the Point. Enter Manually: "<<std::endl;
			this->ins(in, 0, arr, b);
		}
		else
		{
			px = arr[1];
			py = arr[2];
			pz = arr[3];
		}
	}
	return in;
}

std::ostream& Point::ext(std::ostream& out) const{
	out << std::endl<< "x=" << this->getPointX()<<std::endl;
	out << "y=" << this->getPointY() << std::endl;
	out << "z=" << this->getPointZ() << std::endl;
	return out;
}

//END OF POINT.CPP