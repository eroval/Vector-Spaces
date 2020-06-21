#include "Segment.h"

//Destructor
Segment::~Segment() {
	//std::cout << "\nDESTRUCTOR SEGMENT CALLED!" << std::endl;
}

//Default Constructor
Segment::Segment() {
	this->t[0] = 0;
	this->t[1] = 1;
}
void Segment::swap(float& a, float& b) {
	if (a > b) {
		float c = a;
		a = b;
		b = c;
	}
}

//Constructor with Line and an Interval
Segment::Segment(const Point& a, const Vector& b, float c, float d):Line(a,b) {
	if (c < d) {
		t[0] = c;
		t[1] = d;
	}
	else {
		t[0] = d;
		t[1] = c;
	}
}

//Constructor with Default Values
Segment::Segment(const Point& a, const Vector& b):Line(a, b) {
	t[0] = 0;
	t[1] = 1;
}

//Constructor set with a Line and Default Values
Segment::Segment(const Line& a) :Line(a) {
	this->t[0] = 0;
	this->t[1] = 1;
}


//Copy Constructor
Segment::Segment(const Segment& a) {
	this->t[0] = a.getT(0);
	this->t[1] = a.getT(1);
}
//Predefined equalization
Segment& Segment::operator=(const Segment& a) {
	this->t[0] = a.getT(0);
	this->t[1] = a.getT(1);
	return *this;
}

//Return the Length of the Segment
double Segment::Length()  const {
	Point a(this->getVectorX() * this->t[0] + this->getPointX(), this->getVectorY() * this->t[0] + this->getPointY(), this->getVectorZ() * this->t[0] + this->getPointZ());
	Point b(this->getVectorX() * this->t[1] + this->getPointX(), this->getVectorY() * this->t[1] + this->getPointY(), this->getVectorZ() * this->t[1] + this->getPointZ());
	Vector AB(a, b);
	return AB.Length();
}

//Return a Point which is in the middle of the Segment
Point Segment::Middle()  const {
	Point a(this->getVectorX() * this->t[0] + this->getPointX(), this->getVectorY() * this->t[0] + this->getPointY(), this->getVectorZ() * this->t[0] + this->getPointZ());
	Point b(this->getVectorX() * this->t[1] + this->getPointX(), this->getVectorY() * this->t[1] + this->getPointY(), this->getVectorZ() * this->t[1] + this->getPointZ());
	Point AB((a.getPointX() + b.getPointX()) / 2, (a.getPointY() + b.getPointY()) / 2, (a.getPointZ() + b.getPointZ()) / 2);
	return AB;
}


float Segment::getT(int a) const{
	if (a > -1 && a < 2) {
		return this->t[a];
	}
	else return 0;
}

int Segment::setT(int a, float b) {
	if (a > -1 && a < 2) {
		this->t[a] = b;
		swap(this->t[0], this->t[1]);
		return 0;
	}
	else return 0;
}

//Check is a Point lies on the Segment
bool Segment::operator==(const Point& d) const {
	Point a(this->getVectorX() * this->t[0] + this->getPointX(), this->getVectorY() * this->t[0] + this->getPointY(), this->getVectorZ() * this->t[0] + this->getPointZ());
	Point b(this->getVectorX() * this->t[1] + this->getPointX(), this->getVectorY() * this->t[1] + this->getPointY(), this->getVectorZ() * this->t[1] + this->getPointZ());
	Vector AB(a, b);
	Line l2(a, this->getVector());
	if (l2 + d) {
		if (
			((d.getPointX() >= a.getPointX() && d.getPointX() <= b.getPointX()) || (d.getPointX() <= a.getPointX() && d.getPointX() >= b.getPointX())) &&
			((d.getPointY() >= a.getPointY() && d.getPointY() <= b.getPointY()) || (d.getPointY() <= a.getPointY() && d.getPointY() >= b.getPointY())) &&
			((d.getPointZ() >= a.getPointZ() && d.getPointZ() <= b.getPointZ()) || (d.getPointZ() <= a.getPointZ() && d.getPointZ() >= b.getPointZ()))
			)
		{
			return true;
		}
		else return false;
	}
	else return false;
}

//output when manual inputting
void Segment::print(std::ofstream& out) const {
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Find Length of the Segment." << std::endl;
	std::cout << "2. Find the Middle of the Segment." << std::endl;
	std::cout << "3. Find if a Point lies on the Segment." << std::endl << std::endl;
	std::cout << "Enter: ";
	int x;
	std::cin >> x;
	while (x < 1 || x>3) {
		std::cout << "\Invalid Input." << std::endl;
		std::cout << "Enter: ";
		std::cin >> x;
	}
	Point a;
	out << "\n\t" << x;
	switch (x) {
	case 1:
		std::cout << "\nLength = " << this->Length() << std::endl;
		out << "\n\t\tLength = " << this->Length() << std::endl;
		break;
	case 2:
		std::cout << "\nMiddle Point: " << std::endl;
		out << "\n\t\tMiddle Point: \n" << this->Middle() << std::endl;
		std::cout << this->Middle() << std::endl;
		break;
	case 3:
		std::cout << "\nEnter values for the Point." << std::endl;
		std::cin >> a;
		out << "\n\t\tPoint:\n"<<a;
		if (*this == a) {
			std::cout << "\nThe Point lies on the Segment." << std::endl;
			out << "\n\t\tThe Point lies on the Segment." << std::endl;
		}
		else {
			std::cout << "\nThe Point doesn't lie on the Segment." << std::endl; 
			out << "\n\t\tThe Point doesn't lie on the Segment." << std::endl;
		}
		break;
	}

}

//output when reading from a file
void Segment::autoPrint(std::ofstream& out, int* arr, unsigned short arrsz) const {
	try {
		if (arrsz < 11) { throw std::logic_error("File too short!"); }
		int x;
		x = arr[10];

		while (x < 1 || x>3) {
			std::cout << "\Invalid Input." << std::endl;
			std::cout << "Enter: ";
			std::cin >> x;
		}

		Point a;

		out << "\n\t" << x;
		switch (x) {
		case 1:
			std::cout << "\nLength = " << this->Length() << std::endl;
			out << "\n\t\tLength = " << this->Length() << std::endl;
			break;
		case 2:
			std::cout << "\nMiddle Point: " << std::endl;
			out << "\n\t\tMiddle Point: \n" << this->Middle() << std::endl;
			std::cout << this->Middle() << std::endl;
			break;
		case 3:
			if (arrsz < 14) { throw std::logic_error("Not enough information! Necessary point must be written in order!"); }
			a = Point(arr[11], arr[12], arr[13]);
			out << "\n\t\tPoint:\n" << a;
			if (*this == a) {
				std::cout << "\nThe Point lies on the Segment." << std::endl;
				out << "\n\t\tThe Point lies on the Segment." << std::endl;
			}
			else {
				std::cout << "\nThe Point doesn't lie on the Segment." << std::endl;
				out << "\n\t\tThe Point doesn't lie on the Segment." << std::endl;
			}
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



std::ostream& Segment::ext(std::ostream& out) const {
	out << "Segment:\n";
	out << "Parametric equation: \n";
	out << "x = " << this->getPointX() << " + " << this->getVectorX() << "*" << "t" << std::endl;
	out << "y = " << this->getPointY() << " + " << this->getVectorY() << "*" << "t" << std::endl;
	out << "z = " << this->getPointZ() << " + " << this->getVectorZ() << "*" << "t" << std::endl;
	out << "Beginning: " << std::endl;
	out << "x = " << this->getPointX() + this->getVectorX() * t[0] << std::endl;
	out << "y = " << this->getPointY() + this->getVectorY() * t[0] << std::endl;
	out << "z = " << this->getPointZ() + this->getVectorZ() * t[0] << std::endl << std::endl;
	out << "End: " << std::endl;
	out << "x = " << this->getPointX() + this->getVectorX() * t[1] << std::endl;
	out << "y = " << this->getPointY() + this->getVectorY() * t[1] << std::endl;
	out << "z = " << this->getPointZ() + this->getVectorZ() * t[1] << std::endl << std::endl;
	return out;
}

std::istream& Segment::ins(std::istream& in, bool a, int* arr, unsigned short arrsz) {
	if (a == 0) {
		Line::ins(in);
		std::cout << "\nEnter beginning of interval: ";
		std::cin >> this->t[0];
		std::cout << "\nEnter end of interval: ";
		std::cin >> this->t[1];
	}
	else {
		try {
			if (arrsz < 10) { throw std::logic_error("Not enough information for the Segment.\nEnter Segment Manually!\n\n"); }
			Line::ins(in, 1, arr, arrsz);
			this->t[0] = arr[8];
			this->t[1] = arr[9];
		}
		catch (std::logic_error & e) {
			std::cout << e.what();
			system("pause");
			system("cls");
			this->ins(in, 0, arr, arrsz);
		}
	}
	return in;
}