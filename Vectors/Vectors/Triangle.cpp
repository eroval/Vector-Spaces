#include "Triangle.h"
#include "EqualPointsException.h"
#include <math.h>

//Destructor
Triangle::~Triangle() {
	//std::cout << "\nDESTRUCTOR TRIANGLE CALLED\n";
}

//Default Constructor
Triangle::Triangle() {
	this->tA = Point(0, 0, 0);
	this->tB = Point(1, 1, 1);
	this->tC = Point(0, 2, 0);
}

//Constructor with parameters
Triangle::Triangle(const Point& a, const Point& b, const Point& c){
	Vector AB(a,b);
	Vector BC(b,c);
	Vector AC(a,c);

	try {
		if (AB.Parallel(BC)) {
			throw EqualPointsException(b);
		}
		else if (AB.Parallel(AC)) {
			throw EqualPointsException(a);
		}
		else if (BC.Parallel(AC)) {
			throw EqualPointsException(c);
		}
		else {
			this->tA = a;
			this->tB = b;
			this->tC = c;

		}
	}
	catch (EqualPointsException & e) {
		std::cout << e.what() << std::endl;
		this->tA = Point(0, 0, 0);
		this->tB = Point(1, 1, 1);
		this->tC = Point(0, 2, 0);
	}
}

//Copy Constructor
Triangle::Triangle(const Triangle& b) {
	this->tA = b.tA;
	this->tB = b.tB;
	this->tC = b.tC;
}

//Predefined equalization
Triangle& Triangle::operator=(const Triangle& b) {
	this->tA = b.tA;
	this->tB = b.tB;
	this->tC = b.tC;
	return *this;
}

//Check Type of Triangle
const char* Triangle::TypeOfTriangle() const {
	Vector AB(this->getTA(), this->getTB());
	Vector BC(this->getTB(), this->getTC());
	Vector AC(this->getTA(), this->getTC());
	if (
		(AB.Length() < BC.Length() + 0.02 && AB.Length() > BC.Length() - 0.02) ||
		(BC.Length() < AC.Length() + 0.02 && BC.Length() > AC.Length() - 0.02) ||
		(AB.Length() < AC.Length() + 0.02 && AB.Length() > AC.Length() - 0.02)
	   ) 
	{
		return "Triangle is an isosceles triangle.";
	}
	else if (
		(AB.Length() < BC.Length() + 0.02 && AB.Length() > BC.Length() - 0.02) &&
		(BC.Length() < AC.Length() + 0.02 && BC.Length() > AC.Length() - 0.02) &&
		(AB.Length() < AC.Length() + 0.02 && AB.Length() > AC.Length() - 0.02)
		) {

		return "Triangle is an equals triangle.";
	}
	else if (
		(AB * AC<0.01 && AB * AC>-0.01) ||
		(BC * AC<0.01 && BC * AC>-0.01) ||
		(BC * AB<0.01 && BC * AB>-0.01)) {
		return "Triangle is a right triangle.";
	}
	else {
		double ABC = acos(AB * BC);
		double ACB = acos(AC * BC);
		double CAB = acos(AC * AB);

		if (ABC > 1.6||ACB>1.6||CAB>1.6) {
			return "Triangle is a blunt triangle.";
		}
		else {
			return "Triangle is a sharp triangle.";
		}
	}
}

//Finds Perimeter of the Triangle
double Triangle::Perimeter() const {
	Vector AB(this->getTA(), this->getTB());
	Vector BC(this->getTB(), this->getTC());
	Vector AC(this->getTA(), this->getTC());

	return AB.Length() + BC.Length() + AC.Length();
}

//Finds Area of a Triangle
double Triangle::Area() const {
	Vector AB(this->getTA(), this->getTB());
	Vector AC(this->getTA(), this->getTC());

	return ((AB ^ AC).Length() / 2);
}

//Finds the Centre of the Triangle
Point Triangle::Centre() const {
	return Point(
		(this->getTA().getPointX() + this->getTB().getPointX() + this->getTC().getPointX()) / 3,
		(this->getTA().getPointY() + this->getTB().getPointY() + this->getTC().getPointY()) / 3,
		(this->getTA().getPointZ() + this->getTB().getPointZ() + this->getTC().getPointZ()) / 3);

}

//Finds if a Point is on the plane of the Triangle and inside the triangle
bool Triangle::operator<(const Point& a) const {
	Vector AB(this->getTA(), this->getTB());
	Vector BC(this->getTB(), this->getTC());
	Vector AC(this->getTA(), this->getTC());
	Vector N(AB ^ AC);
	double d = abs((this->getTA().getPointX() * N.getPointX()) + (this->getTA().getPointY() * N.getPointY()) + (this->getTA().getPointZ() * N.getPointZ()));
	double dA = abs(a.getPointX() * N.getPointX()) + (a.getPointY() * N.getPointY()) + (a.getPointZ() * N.getPointZ());
	
	if (dA<d + 0.02 && dA>d - 0.02) {
		double AreaABC = (AB ^ AC).Length() / 2;
		Vector PB(a, this->getTB());
		Vector PC(a, this->getTC());
		Vector PA(a, this->getTA());
		double alpha = (PB ^ PC).Length() / (2 * AreaABC);
		double beta = (PC ^ PA).Length() / (2 * AreaABC);
		double gama = 1 - alpha - beta;

		if (alpha >= 0 && alpha <= 1 &&
			beta >= 0 && beta <= 1 &&
			gama >= 0 && gama <= 1 &&
			(alpha + beta + gama >= 1 - 0.02) &&
			(alpha + beta + gama <= 1 + 0.02)) {
			return true;
		}
		else return false;
		}
	else return false;
}

//Finds if a point lies on the plane of the Triangle and is outside of it
bool Triangle::operator>(const Point& a) const {
	Vector AB(this->getTA(), this->getTB());
	Vector BC(this->getTB(), this->getTC());
	Vector AC(this->getTA(), this->getTC());
	Vector N(AB ^ AC);
	double d = abs((this->getTA().getPointX() * N.getPointX()) + (this->getTA().getPointY() * N.getPointY()) + (this->getTA().getPointZ() * N.getPointZ()));
	double dA = abs(a.getPointX() * N.getPointX()) + (a.getPointY() * N.getPointY()) + (a.getPointZ() * N.getPointZ());

	if (dA<d + 0.02 && dA>d - 0.02) {
		double AreaABC = (AB ^ AC).Length() / 2;
		Vector PB(a, this->getTB());
		Vector PC(a, this->getTC());
		Vector PA(a, this->getTA());
		double alpha = (PB ^ PC).Length() / (2 * AreaABC);
		double beta = (PC ^ PA).Length() / (2 * AreaABC);
		double gama = 1 - alpha - beta;

		if (alpha >= 0 && alpha <= 1 &&
			beta >= 0 && beta <= 1 &&
			gama >= 0 && gama <= 1 &&
			(alpha + beta + gama >= 1 - 0.02) &&
			(alpha + beta + gama <= 1 + 0.02)) {
			return false;
		}
		else return true;
	}
	else return false;
}

//Finds if a point lies on a side of the Triangle
bool Triangle::operator==(const Point& d) const {
	Vector AB(this->getTA(), this->getTB());
	Vector BC(this->getTB(), this->getTC());
	Vector AC(this->getTA(), this->getTC());

	Point a(this->getTA());
	Point b(this->getTB());
	Point c(this->getTC());

	Line lAB(a, AB);
	Line lBC(b, BC);
	Line lAC(a, AC);

	if (lAB+d) {
		if(
			((d.getPointX() >= a.getPointX() && d.getPointX() <= b.getPointX()) || (d.getPointX() <= a.getPointX() && d.getPointX() >= b.getPointX())) &&
			((d.getPointY() >= a.getPointY() && d.getPointY() <= b.getPointY()) || (d.getPointY() <= a.getPointY() && d.getPointY() >= b.getPointY())) &&
			((d.getPointZ() >= a.getPointZ() && d.getPointZ() <= b.getPointZ()) || (d.getPointZ() <= a.getPointZ() && d.getPointZ() >= b.getPointX()))
			) {
		return true;
		}
		else return false;
	}

	else if (lBC+d) {
		if (
			((d.getPointX() >= b.getPointX() && d.getPointX() <= c.getPointX()) || (d.getPointX() <= b.getPointX() && d.getPointX() >= c.getPointX())) &&
			((d.getPointY() >= b.getPointY() && d.getPointY() <= c.getPointY()) || (d.getPointY() <= b.getPointY() && d.getPointY() >= c.getPointY())) &&
			((d.getPointZ() >= b.getPointZ() && d.getPointZ() <= c.getPointZ()) || (d.getPointZ() <= b.getPointZ() && d.getPointZ() >= c.getPointX()))
			) {
			return true;
		}
		else return false;
	
	}
	
	else if (lAC+d) {
		if (
			((d.getPointX() >= a.getPointX() && d.getPointX() <= c.getPointX()) || (d.getPointX() <= a.getPointX() && d.getPointX() >= c.getPointX())) &&
			((d.getPointY() >= a.getPointY() && d.getPointY() <= c.getPointY()) || (d.getPointY() <= a.getPointY() && d.getPointY() >= c.getPointY())) &&
			((d.getPointZ() >= a.getPointZ() && d.getPointZ() <= c.getPointZ()) || (d.getPointZ() <= a.getPointZ() && d.getPointZ() >= c.getPointX()))
			) {
			return true;
		}
		else return false;
	
	}

	else return false;
}

//get Point A
Point Triangle::getTA() const {
	return this->tA;
}

//get Point B
Point Triangle::getTB() const {
	return this->tB;
}

//get Point C
Point Triangle::getTC() const {
	return this->tC;
}

//set Point A
int Triangle::setTA(const Point& a) {
	this->tA.setPoint(a.getPoint());
	this->check(this->getTA(), this->getTB(), this->getTC());
	return 0;
}

//set Point B
int Triangle::setTB(const Point& a) {
	this->tB.setPoint(a.getPoint());
	this->check(this->getTA(), this->getTB(), this->getTC());
	return 0;
}

//set Point C
int Triangle::setTC(const Point& a) {
	this->tC.setPoint(a.getPoint());
	this->check(this->getTA(), this->getTB(), this->getTC());
	return 0;
}

//Checks if the sides are properly inputted
void Triangle::check(const Point& a, const Point& b, const Point& c){
	Vector AB(a,b);
	Vector BC(b,c);
	Vector AC(a,c);
	try {
		if (AB.Parallel(BC)) {
			throw EqualPointsException(b);
		}
		else if (AB.Parallel(AC)) {
			throw EqualPointsException(a);
		}
		else if (BC.Parallel(AC)) {
			throw EqualPointsException(c);
		}
		else {
			this->tA = a;
			this->tB = b;
			this->tC = c;

		}
	}
	catch (EqualPointsException & e) {
		std::cout << e.what() << std::endl;
		std::cout << "\n\n\t\tDefault Values will be set for the points of the Triangle\n\n";
		system("pause");
		this->tA = Point(0, 0, 0);
		this->tB = Point(1, 1, 1);
		this->tC = Point(0, 2, 0);
	}
}

//print when manual inputting
void Triangle::print(std::ofstream& out) const{
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Find the Type of the Triangle." << std::endl;
	std::cout << "2. Find the Area of the Triangle." << std::endl;
	std::cout << "3. Find the Perimeter of the Triangle." << std::endl;
	std::cout << "4. Find the the Medicentre." << std::endl;
	std::cout << "5. Find if a Point lies inside the Triangle." << std::endl;
	std::cout << "6. Find if a Point is on the same Plane but isn't inside the Triangle." << std::endl;
	std::cout << "7. Find if a Point lies on a Side of the Triangle." << std::endl;
	int x;
	std::cin >> x;
	if (x < 1 || x>7) {
		std::cout << "\Invalid Input." << std::endl;
		std::cout << "Enter: ";
		std::cin >> x;
	}
	out << "\n\t" << x;
	Point a;
	switch (x) {
	case 1:
		std::cout << this->TypeOfTriangle() << std::endl;
		out << "\n\t\t"<< this->TypeOfTriangle() << std::endl;
		break;
	case 2:
		std::cout << "\nArea = " << this->Area() << std::endl;
		out << "\n\t\tArea = " << this->Area() << std::endl;
		break;
	case 3:
		std::cout << "\nPerimeter = " << this->Perimeter() << std::endl;
		out << "\n\t\tPerimeter = " << this->Perimeter() << std::endl;
		break;
	case 4:
		std::cout << "\nMedicentre is on the coordinates:" << std::endl;
		out << "\n\t\tMedicenter is on the coordinates:" << std::endl;
		std::cout << this->Centre() << std::endl;
		out << this->Centre() << std::endl;
		break;
	case 5:
		std::cout << "\nEnter values for the Point:" << std::endl;
		std::cin >> a;
		out << "\n\t\tPoint: \n" << a;
		if (*this < a) {
			std::cout << "\nThe Point lies inside the Triangle." << std::endl;
			out << "\n\t\tThe Point lies inside the Triangle." << std::endl;
		}
		else {
			std::cout << "\nThe Point doesn't lie inside the Triangle." << std::endl;
			out << "\n\t\tThe Point doesn't lie inside the Triangle." << std::endl;
		}
		break;
	case 6:
		std::cout << "\nEnter values for the Point:" << std::endl;
		std::cin >> a;
		out << "\n\t\tPoint: \n" << a;
		if (*this > a) {
		std::cout << "\nThe Point lies on the same Plane as the Triangle." << std::endl;
		out << "\n\t\tThe Point lies on the same Plane as the Triangle." << std::endl;
		}
		else {
			std::cout << "\nThe Point doesn't lie on the same Plane as the Triangle." << std::endl;
			out << "\n\t\tThe Point doesn't lie on the same Plane as the Triangle." << std::endl;
		}
		break;
	case 7:
		std::cout << "\nEnter values for the Point:" << std::endl;
		std::cin >> a;
		out << "\n\t\tPoint: \n" << a;
		if (*this == a) {
			std::cout << "\nThe Point lies on a side of the Triangle." << std::endl;
			out << "\n\t\tThe Point lies on a side of the Triangle." << std::endl;
		}
		else {
			std::cout << "\nThe Point doesn't lie on a side of the Triangle." << std::endl;
			out << "\n\t\tThe Point doesn't lie on a side of the Triangle." << std::endl;
		}
		break;
	}
}

//print when reading from a file
void Triangle::autoPrint(std::ofstream& out, int* arr, unsigned short arrsz) const {
	try {
		if (arrsz < 11) { throw std::logic_error("File too short!"); }
		int x;
		x = arr[10];

		while (x < 1 || x>7) {
			std::cout << "\Invalid Input." << std::endl;
			std::cout << "Enter: ";
			std::cin >> x;
		}

		Point a;

		out << "\n\t" << x;
		switch (x) {
		case 1:
			std::cout << this->TypeOfTriangle() << std::endl;
			out << "\n\t\t" << this->TypeOfTriangle() << std::endl;
			break;
		case 2:
			std::cout << "\nArea = " << this->Area() << std::endl;
			out << "\n\t\tArea = " << this->Area() << std::endl;
			break;
		case 3:
			std::cout << "\nPerimeter = " << this->Perimeter() << std::endl;
			out << "\n\t\tPerimeter = " << this->Perimeter() << std::endl;
			break;
		case 4:
			std::cout << "\nMedicentre is on the coordinates:" << std::endl;
			out << "\n\t\tMedicenter is on the coordinates:" << std::endl;
			std::cout << this->Centre() << std::endl;
			out << this->Centre() << std::endl;
			break;
		case 5:
			if (arrsz < 14) { throw std::logic_error("Not enough information! The Point must be written in order!"); }
			std::cout << "\nPoint:" << std::endl;
			a = Point(arr[11],arr[12],arr[13]);
			out << "\n\t\tPoint: \n" << a;
			if (*this < a) {
				std::cout << "\nThe Point lies inside the Triangle." << std::endl;
				out << "\n\t\tThe Point lies inside the Triangle." << std::endl;
			}
			else {
				std::cout << "\nThe Point doesn't lie inside the Triangle." << std::endl;
				out << "\n\t\tThe Point doesn't lie inside the Triangle." << std::endl;
			}
			break;
		case 6:
			if (arrsz < 14) { throw std::logic_error("Not enough information! The Point must be written in order!"); }
			std::cout << "\nPoint:" << std::endl;
			a = Point(arr[11], arr[12], arr[13]);
			out << "\n\t\tPoint: \n" << a;
			if (*this > a) {
				std::cout << "\nThe Point lies on the same Plane as the Triangle." << std::endl;
				out << "\n\t\tThe Point lies on the same Plane as the Triangle." << std::endl;
			}
			else {
				std::cout << "\nThe Point doesn't lie on the same Plane as the Triangle." << std::endl;
				out << "\n\t\tThe Point doesn't lie on the same Plane as the Triangle." << std::endl;
			}
			break;
		case 7:
			if (arrsz < 14) { throw std::logic_error("Not enough information! The Point must be written in order!"); }
			std::cout << "\nPoint:" << std::endl;
			a = Point(arr[11], arr[12], arr[13]);
			out << "\n\t\tPoint: \n" << a;
			if (*this == a) {
				std::cout << "\nThe Point lies on a side of the Triangle." << std::endl;
				out << "\n\t\tThe Point lies on a side of the Triangle." << std::endl;
			}
			else {
				std::cout << "\nThe Point doesn't lie on a side of the Triangle." << std::endl;
				out << "\n\t\tThe Point doesn't lie on a side of the Triangle." << std::endl;
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


std::ostream& Triangle::ext(std::ostream& out) const{
	Point a = this->getTA();
	Point b = this->getTB();
	Point c = this->getTC();
	Vector AB(a,b);
	Vector BC(b,c);
	Vector AC(a,c);
	out << "\nTriangle: \n" << std::endl;
	out << "Point A: " << this->getTA() << std::endl;
	out << "Point B: " << this->getTB() << std::endl;
	out << "Point C: " << this->getTC() << std::endl;
	out << "Vector AB: \n" << AB << std::endl;
	out << "Vector BC: \n" << BC << std::endl;
	out << "Vector AC: \n" << AC << std::endl;
	out << "AB = " << AB.Length() << std::endl;
	out << "BC = " << BC.Length() << std::endl;
	out << "AC = " << AC.Length() << std::endl;
	return out;
}

std::istream& Triangle::ins(std::istream& in, bool a, int* arr, unsigned short arrsz) {
	if (a == 0) {
		Point a;
		Point b;
		Point c;
		std::cout << "Enter values for Point A:" << std::endl;
		std::cin >> a;
		std::cout << "Enter values for Point B:" << std::endl;
		std::cin >> b;
		std::cout << "Enter values for Point C:" << std::endl;
		std::cin >> c;
		check(a, b, c);
	}
	else {
		try {
			if (arrsz < 11) { throw std::logic_error("Not enough information to set the Triangle."); }
			Point a(arr[1], arr[2], arr[3]);
			Point b(arr[4], arr[5], arr[6]);
			Point c(arr[7], arr[8], arr[9]);
			check(a, b, c);
		}
		catch (std::logic_error & e) {
			std::cout << e.what() << std::endl;
			this->ins(in, 0, arr, arrsz);
		}
	}
	return in;
}