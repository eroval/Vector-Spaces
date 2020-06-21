//VECTOR.CPP

#include "Vector.h"
#include "VectorLengthException.h"

Vector::~Vector() {
	//std::cout << "\nDESTRUCTOR VECTOR CALLED\n"<<*this<<"\n";
}

//Default Constructor
Vector::Vector() {
	this->vx = 1;
	this->vy = 2;
	this->vz = 3;
}

//Constructor with Parameters
Vector::Vector(float a, float b , float c ){
	this->vx = a;
	this->vy = b;
	this->vz = c;
}

//Vector set with two Points in 3D space
Vector::Vector(const Point& a, const Point& b) {
	this->setVectorX(b.getPointX() - a.getPointX());
	this->setVectorY(b.getPointY() - a.getPointY());
	this->setVectorZ(b.getPointZ() - a.getPointZ());
}

//Vector set with another Vector (copy constructor)
Vector::Vector(const Vector& a) {
	this->setVectorX(a.getVectorX());
	this->setVectorY(a.getVectorY());
	this->setVectorZ(a.getVectorZ());
}

//Predefined operator for equalization of two vectors
Vector& Vector::operator=(const Vector& a) {
	this->setVectorX(a.getVectorX());
	this->setVectorY(a.getVectorY());
	this->setVectorZ(a.getVectorZ());
	return *this;
}

//Checks if a Vector is the Zero Vector
bool Vector::isItZero() const {
	if (this->getVectorX() == 0 && this->getVectorY() == 0 && this->getVectorZ() == 0) {
		return true;
	}
	else return false;
}

//Check if two Vectors are Parallel
bool Vector::Parallel(const Vector& a) const {
	try {
		if (this->isItZero() != true && a.isItZero() != true) {
			if ((*this^a).Length()<0.2) {
				return true;
			}
			else return false;
		}
		else throw VectorLengthException();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return false;
	}
}

//Returns the Length of a Vector
double Vector::Length() const {
		return sqrt(pow(getVectorX(), 2) + pow(getVectorY(), 2) + pow(getVectorZ(), 2));
}

//Checks if two Vectors are Perpendicular
bool Vector::Perpendicular(const Vector& a) const {
	try {
		if (!this->isItZero() && !a.isItZero()) {
			if ((*this*a >= -0.1)&&(*this*a<=0.1)){
				return true;
			}
			else return false;
		}
		else throw VectorLengthException();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return false;
	}
}

//Projection of a Vector onto another Vector
Vector Vector::Projection(const Vector& a) const {
	return Vector(a*((*this * a)/a.Length()));
}

//Direction of the Vector
Vector Vector::Direction() const{
	Vector a(*this);
	try {
		if (a.isItZero()) { throw VectorLengthException(); }
		else {
			a.setVectorX(getVectorX() / sqrt(pow(getVectorX(), 2) + pow(getVectorY(), 2) + pow(getVectorZ(), 2)));
			a.setVectorY(getVectorY() / sqrt(pow(getVectorX(), 2) + pow(getVectorY(), 2) + pow(getVectorZ(), 2)));
			a.setVectorZ(getVectorZ() / sqrt(pow(getVectorX(), 2) + pow(getVectorY(), 2) + pow(getVectorZ(), 2)));
			return a;
		}
	}
	catch (VectorLengthException & e) {
		a.~Vector();
		std::cout << std::endl << e.what() << std::endl;
		return Vector(-1,-1,-1);
	}
}

//Predefine addition for Vectors
Vector Vector::operator+(const Vector& a) const {
	Vector b;
	b.setVectorX(this->getVectorX() + a.getVectorX());
	b.setVectorY(this->getVectorY() + a.getVectorY());
	b.setVectorZ(this->getVectorZ() + a.getVectorZ());
	return b;
}

//Predefine substraction for Vectors
Vector Vector::operator-(const Vector& a) const {
	Vector b;
	b.setVectorX(this->getVectorX() - a.getVectorX());
	b.setVectorY(this->getVectorY() - a.getVectorY());
	b.setVectorZ(this->getVectorZ() - a.getVectorZ());
	return b;

}

//Predefine Scalar Multiplication
Vector Vector::operator*(const double a) const {
	Vector b;
	b.setVectorX(this->getVectorX() * a);
	b.setVectorY(this->getVectorY() * a);
	b.setVectorZ(this->getVectorZ() * a);
	return b;
}

//Predefine Multiplication for Vectors
double Vector::operator*(const Vector& a) const {
	return this->getVectorX() * a.getVectorX() + this->getVectorY() * a.getVectorY() + this->getVectorZ() * a.getVectorZ();
}

//Predefine Cross Product for Vectors
Vector Vector::operator^(const Vector& a) const {
	Vector b;
	b.setVectorX(this->getVectorY() * a.getVectorZ() - this->getVectorZ() * a.getVectorY());
	b.setVectorY(this->getVectorZ() * a.getVectorX() - this->getVectorX() * a.getVectorZ());
	b.setVectorZ(this->getVectorX() * a.getVectorY() - this->getVectorY() * a.getVectorX());
	return b;
}

//Predefine Combined Multiplication for three Vectors
double Vector::operator()(const Vector& a, const Vector& b) const {
	Vector d = *this ^ a;
	return (d * b);
}

//Checks if two Vectors are the same
bool Vector::operator==(const Vector& a) const {
	if (this->getVectorX() == a.getVectorX() && this->getVectorY() == a.getVectorY() && this->getVectorZ() == a.getVectorZ()) {
		return true;
	}
	else return false;
}


int Vector::setVectorX(float a) {
	vx = a;
	return 0;
}

int Vector::setVectorY(float a) {
	vy = a;
	return 0;
}

int Vector::setVectorZ(float a) {
	vz = a;
	return 0;
}

int Vector::setVector(Vector a) {
	this->vx = a.vx;
	this->vy = a.vy;
	this->vz = a.vz;
	return 0;
};

float Vector::getVectorX() const {
	return vx;
}

float Vector::getVectorY() const {
	return vy;
}

float Vector::getVectorZ() const {
	return vz;
}

Vector Vector::getVector() const {
	return *this;
}

//output when manual inputting
void Vector::print(std::ofstream& out) const {
	Vector a = *this;
	std::cout << "What would you like to do? " << std::endl;
	std::cout << "1: Length of Vector." << std::endl;
	std::cout << "2: Direction of Vector." << std::endl;
	std::cout << "3: Vector projection of Vector onto Vector." << std::endl;
	std::cout << "4: Check if it is the Zero Vector." << std::endl;
	std::cout << "5: Check if Vector is Parallel with another Vector." << std::endl;
	std::cout << "6: Check if Vector is Perpendicular with another Vector." << std::endl;
	std::cout << "7: Vector Addition." << std::endl;
	std::cout << "8: Scalar Product of Vector and a real number." << std::endl;
	std::cout << "9: Scalar Product of two Vectors." << std::endl;
	std::cout << "10: Vector Multiplication of two Vectors." << std::endl;
	std::cout << "11: Combined Multiplication of three Vectors." << std::endl<<std::endl;
	std::cout << "Enter: ";
	int e;
	std::cin >> e;
	while (e < 1 || e>11) {
		std::cout << "\nInvalid Input."<<std::endl;
		std::cout << "Enter: ";
		std::cin >> e;
	}
	Vector b;
	Vector c;
	float x;
	out << "\n\t" << e;
	switch (e) {
	case 1:
		std::cout << "\nLength = " << this->Length() << std::endl;
		out << "\n\t\tLength = " << this->Length() << std::endl;
		break;
	case 2:
		std::cout << "\nDirection: \n" << this->Direction() << std::endl;
		out << "\n\t\tDirection: \n" << this->Direction() << std::endl;
		break;
	case 3:
		std::cout << "Enter elements of Vector b:" << std::endl; 
		std::cin >> b;
		std::cout << "Vector projection of current Vector onto b is:" << std::endl;
		out << "\n\t\tVector b: \n" << b;
		out << "\n\t\tVector projection of current Vector onto b is:" << std::endl;
		std::cout << this->Projection(b) << std::endl;
		out << "\t\t" << this->Projection(b) << std::endl;
		break;
	case 4:
		if (this->isItZero()) {
			std::cout << "\nIt is the Zero Vector!" << std::endl;
			out << "\n\t\tIt is the Zero Vector!" << std::endl;
			break;
		}
		else { std::cout << "\nIt isn't the Zero Vector!" << std::endl; 
		out << "\n\t\tIt isn't the Zero Vector!" << std::endl;
		}
		break;
	case 5:
		std::cout << "\nEnter elements of Vector b:" << std::endl; 
		std::cin >> b;
		out << "\n\t\tVector b: \n" << b;
		if (this->Parallel(b)) {
			std::cout << "\nThey are Parallel." << std::endl;
			out << "\n\t\tThey are Parallel." << std::endl;
			break; }
		else std::cout << "\nThey aren't Parallel." << std::endl;
		out << "\n\t\tThey aren't Parallel." << std::endl;
		break;
	case 6:
		std::cout << "\nEnter elements of Vector b:" << std::endl;
		std::cin >> b;
		out << "\n\t\tVector b: \n" << b;
		if (this->Perpendicular(b)) {
			std::cout << "\nThe Vectors are Perpendicular." << std::endl;
			out << "\n\t\tThe Vectors are Perpendicular." << std::endl;
			break;
		}
		else {
			std::cout << "The Vectors aren't Perpendicular." << std::endl;
			out << "\n\t\tThe Vectors aren't Perpendicular." << std::endl;
			break;
		}
	case 7:
		std::cout << "\nEnter elements of Vector b:" << std::endl;
		std::cin >> b;
		out << "\n\t\tVector b: \n" << b;
		std::cout << "The new Vector is:" << std::endl;
		std::cout << (*this + b) << std::endl;
		out << "\n\t\tThe new Vector is:\n" << *this + b << std::endl;
		break;
	case 8:
		std::cout << "\nEnter number for Multiplication: ";
		std::cin >> x;
		std::cout << *this * x << std::endl;
		out << "\n\t\tMultiplication Number: " << x << "\n";
		out << *this * x << std::endl;
		break;
	case 9:
		std::cout << "\nEnter elements of Vector b:" << std::endl;
		std::cin >> b;
		out << "\n\t\tVector b: \n" << b;
		std::cout << "\nThe Scalar Product of the two Vectors is:" << std::endl;
		out << "\n\t\tThe Scalar Product of the two Vectors is:" << std::endl;
		std::cout << *this * b << std::endl;
		out << "\t\t"<<*this * b << std::endl;
		break;
	case 10:
		std::cout << "\nEnter elements of Vector b:" << std::endl;
		std::cin >> b;
		out << "\n\t\tVector b: \n" << b;
		std::cout << "The Vector Multiplication of the two Vectors is:" << std::endl;
		out << "\n\t\tThe Vector Multiplication of the two Vectors is:" << std::endl;
		std::cout << (*this ^ b) << std::endl;
		out << (*this ^ b) << std::endl;
		break;
	case 11:
		std::cout << "\nEnter elements of Vector b:" << std::endl;
		std::cin >> b;
		out << "\n\t\tVector b: \n" << b;
		std::cout << "\nEnter elements of Vector c:" << std::endl;
		std::cin >> c;
		out << "\n\t\tVector c: \n" << c;
		std::cout << "\nMixed multiplication = ";
		std::cout << (*this)(b, c) << std::endl;
		out << "\n\t\t(a^b)*c"<<std::endl;
		out << (*this)(b, c) << std::endl;
		break;
	}
}

//output when reading from a file
void Vector::autoPrint(std::ofstream& out, int* arr, unsigned short arrsz) const {
	Vector a = *this;
	try {
	int e;
	if (arrsz < 5) { throw std::logic_error("File too short!"); }
	e = arr[4];
	while (e < 1 || e>11) {
		std::cout << "\nInvalid Input." << std::endl;
		std::cout << "Enter: ";
		std::cin >> e;
	}
		Vector b;
		Vector c;
		float x;
		out << "\n\t" << e;
		switch (e) {
		case 1:
			std::cout << "\nLength = " << this->Length() << std::endl;
			out << "\n\t\tLength = " << this->Length() << std::endl;
			break;
		case 2:
			std::cout << "\nDirection: \n" << this->Direction() << std::endl;
			out << "\n\t\tDirection: \n" << this->Direction() << std::endl;
			break;
		case 3:
			if (arrsz < 8) { throw std::logic_error("Not enough information! All vectors/necessary points must be written in order!"); }
			b = Vector(arr[5], arr[6], arr[7]);
			std::cout << "\nVector b: \n" << b<<"\n";
			std::cout << "Vector projection of current Vector onto b is:" << std::endl;
			out << "\n\t\tVector b: \n" << b;
			out << "\n\t\tVector projection of current Vector onto b is:" << std::endl;
			std::cout << this->Projection(b) << std::endl;
			out << "\t\t" << this->Projection(b) << std::endl;
			break;
		case 4:
			if (this->isItZero()) {
				std::cout << "\nIt is the Zero Vector!" << std::endl;
				out << "\n\t\tIt is the Zero Vector!" << std::endl;
				break;
			}
			else {
				std::cout << "\nIt isn't the Zero Vector!" << std::endl;
				out << "\n\t\tIt isn't the Zero Vector!" << std::endl;
			}
			break;
		case 5:
			if (arrsz < 8) { throw std::logic_error("Not enough information! All vectors/necessary points must be written in order!"); }
			b = Vector(arr[5], arr[6], arr[7]);
			std::cout << "\nVector b: \n" << b << "\n";
			out << "\n\t\tVector b: \n" << b;
			if (this->Parallel(b)) {
				std::cout << "\nThey are Parallel." << std::endl;
				out << "\n\t\tThey are Parallel." << std::endl;
				break;
			}
			else std::cout << "\nThey aren't Parallel." << std::endl;
			out << "\n\t\tThey aren't Parallel." << std::endl;
			break;
		case 6:
			if (arrsz < 8) { throw std::logic_error("Not enough information! All vectors/necessary points must be written in order!"); }
			b = Vector(arr[5], arr[6], arr[7]);
			std::cout << "\nVector b: \n" << b << "\n";
			out << "\n\t\tVector b: \n" << b;
			if (this->Perpendicular(b)) {
				std::cout << "\nThe Vectors are Perpendicular." << std::endl;
				out << "\n\t\tThe Vectors are Perpendicular." << std::endl;
				break;
			}
			else {
				std::cout << "The Vectors aren't Perpendicular." << std::endl;
				out << "\n\t\tThe Vectors aren't Perpendicular." << std::endl;
				break;
			}
		case 7:
			if (arrsz < 8) { throw std::logic_error("Not enough information! All vectors/necessary points must be written in order!"); }
			b = Vector(arr[5], arr[6], arr[7]);
			std::cout << "\nVector b: \n" << b << "\n";
			out << "\n\t\tVector b: \n" << b;
			std::cout << "The new Vector is:" << std::endl;
			std::cout << *this + b << std::endl;
			out << "\n\t\tThe new Vector is:\n" << *this + b << std::endl;
			break;
		case 8:
			if (arrsz < 6) { throw std::logic_error("Not enough information! All vectors/necessary points must be written in order!"); }
			x = arr[5];
			std::cout << "\nx = " << x << "\n";
			std::cout << *this * x << std::endl;
			out << "\n\t\tMultiplication Number: " << x << "\n";
			out << *this * x << std::endl;
			break;
		case 9:
			if (arrsz < 8) { throw std::logic_error("Not enough information! All vectors/necessary points must be written in order!"); }
			b = Vector(arr[5], arr[6], arr[7]);
			std::cout << "\nVector b: \n" << b << "\n";
			out << "\n\t\tVector b: \n" << b;
			std::cout << "\nThe Scalar Product of the two Vectors is:" << std::endl;
			out << "\n\t\tThe Scalar Product of the two Vectors is:" << std::endl;
			std::cout << *this * b << std::endl;
			out << "\t\t" << *this * b << std::endl;
			break;
		case 10:
			if (arrsz < 8) { throw std::logic_error("Not enough information! All vectors/necessary points must be written in order!"); }
			b = Vector(arr[5], arr[6], arr[7]);
			std::cout << "\nVector b: \n" << b << "\n";
			out << "\n\t\tVector b: \n" << b;
			std::cout << "The Vector Multiplication of the two Vectors is:" << std::endl;
			out << "\n\t\tThe Vector Multiplication of the two Vectors is:" << std::endl;
			std::cout << (*this ^ b) << std::endl;
			out << (*this ^ b) << std::endl;
			break;
		case 11:
			if (arrsz < 11) { throw std::logic_error("Not enough information! All vectors/necessary points must be written in order!"); }
			b = Vector(arr[5], arr[6], arr[7]);
			std::cout << "\nVector b: \n" << b << "\n";
			c = Vector(arr[8], arr[9], arr[10]);
			std::cout << "\nVector c: \n" << c << "\n";
			out << "\n\t\tVector b: \n" << b;
			out << "\n\t\tVector c: \n" << c;
			std::cout << "\nMixed multiplication = ";
			std::cout << (*this)(b, c) << std::endl;
			out << "\n\t\t(a^b)*c" << std::endl;
			out << (*this)(b, c) << std::endl;
			break;
		}
	}
	catch (std::logic_error & e) {
		std::cout << e.what() << std::endl;
		system("pause");
		system("cls");
		this->print(out);
	}
}


std::ostream& Vector::ext(std::ostream& out) const {
	out << "x = " << this->getVectorX();
	out << "\ny = " << this->getVectorY();
	out << "\nz = " << this->getVectorZ()<<std::endl;
	return out;
}

std::istream& Vector::ins(std::istream& in, bool a, int* arr, unsigned short b) {
	if (a == 0) {
		std::cout << "Enter x: ";
		in >> vx;
		std::cout << "Enter y: ";
		in >> vy;
		std::cout << "Enter z: ";
		in >> vz;
	}
	else {
		if (b < 4) {
			std::cout << "Not enough information for the Vector. Enter Manually: " << std::endl;
			this->ins(in, 0, arr, b);
		}
		else
		{
			vx = arr[1];
			vy = arr[2];
			vz = arr[3];
		}
	}
	return in;
}

//END OF VECTOR.CPP
