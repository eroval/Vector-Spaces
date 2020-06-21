//LINE.CPP

#include "Line.h"
#include "VectorLengthException.h"

//Destructor
Line::~Line() {
	//std::cout << "\nDESTRUCTOR LINE CALLED\n"<<*this<<"\n";
}

//Default Constructor
Line::Line() {
	this->setPointX(1);
	this->setPointY(2);
	this->setPointZ(3);
	this->setVectorX(1);
	this->setVectorY(2);
	this->setVectorZ(3);
}

//Line set with Point and a Vector
Line::Line(const Point& a, const Vector& b) {
	this->setPoint(a);
	this->setVector(b);
}

//Line set with two Points
Line::Line(const Point& a, const Point& b) {
	Vector d(a,b);
	this->setPoint(a);
	this->setVector(d);
}

//Line set with another line(copy constructor)
Line::Line(const Line& a) {
	this->setPoint(a.getPoint());
	this->setVector(a.getVector());
};

//predefinition of equalization
Line& Line::operator=(const Line& a) {
	this->setPoint(a.getPoint());
	this->setVector(a.getVector());
	return *this;
}

//finds Greatest Common Divisor
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

//Used to simplify the normal vector
int findGCD(int arr[], int n)
{
	int result = arr[0];
	for (int i = 1; i < n; i++)
	{
		result = gcd(arr[i], result);

		if (result == 1)
		{
			return 1;
		}
	}
	return result;
}

//Finds a normal Vector to the line
Vector Line::Perpendicular() const {
	try {
		if (!this->isItZero()) {
			Vector u = this->getVector()/*.Direction()*/; // with and without direction (.Direction)
			Vector ex(1, 0, 0);
			Vector v = u ^ ex;
			Vector w = v ^ u;
			int arr[] = { w.getVectorX(), w.getVectorY(), w.getVectorZ() };
			int gcd = findGCD(arr, 3);
			w.setVectorX(w.getVectorX() / gcd);
			w.setVectorY(w.getVectorY() / gcd);
			w.setVectorZ(w.getVectorZ() / gcd);
			return w;
		}
		else throw VectorLengthException();
	}
	catch (std::exception & e) {
		std::cout << e.what()<<std::endl;
		return Vector(-1, -1, -1);
	}
	//return d;
}

//Finds the direction of the line
Vector Line::Direction() const {
	return this->getVector().Direction();
}

//Find the shortest distance between two Lines
double Line::ShortestDistance(const Line& b) const {
	Vector AP(b.getPoint(), this->getPoint());
	Vector b1b2 = (this->getVector(), b.getVector());
	double tmp = b1b2.Length();
	double d;
	if (tmp < 0.2) {
		d = (this->getVector() ^ AP).Length();
		return abs(d);
	}
	else {
		d = AP * b1b2;
		d = d / tmp;
		return abs(d);
	}
}

//Finds the shortest distance to a Point
double Line::PointDistance(const Point& a) const {
	Vector AP(this->getPoint(), a);
	Vector b(this->getVector());
	double d = ((AP ^ b).Length() / b.Length());
	return abs(d);
}

//Find the angle created by two lines
double Line::Angle(const Line& b) const {
	try {
		if (!(this->getVector() == b.getVector()) && !this->getVector().isItZero() && !b.getVector().isItZero())
		{
			Vector c = this->getVector().Direction();
			Vector d = b.getVector().Direction();
			return std::acos((c * d) / (c.Length() * d.Length()));
		}
		else throw VectorLengthException();
	}
	catch (std::exception & e) {
		std::cout << e.what()<<std::endl;
		return -1;
	}
}

//Finds if a Point lies on the line
bool Line::operator+(const Point& a) const {
	if (this->PointDistance(a)<0.02) {
		return true;
	}
	else return false;
};

//Checks if two lines are parallel
bool Line::operator||(const Line& c)const {
	Vector a(this->getVector());
	Vector b(c.getVector());	
	if (a.Parallel(b)) {
		if (this->ShortestDistance(c) > 0.2) {
			return true;
		}
		else return false;
	}
	else return false;
};

//Checks if two lines match
bool Line::operator==(const Line& c) const{
	Vector a(this->getVector());
	Vector b(c.getVector());
	if (a.Parallel(b)) {
		if (this->ShortestDistance(c) < 0.2) {
			return true;
		}
		else return false;
	}
	else return false;
}

//Checks if two lines intersect
bool Line::operator&&(const Line& c) const {
	Vector a(this->getVector());
	Vector b(c.getVector());
	if (!(*this||c)) {
		if (this->ShortestDistance(c) < 0.2) {
			return true;
		}
		else return false;
	}
	else return false;
}

//Checks if two lines never intersect
bool Line::operator!=(const Line& c) const{
	Vector a(this->getVector());
	Vector b(c.getVector());
	
	if ((*this || c)) {
		return true;
	}
	else {
		if (this->ShortestDistance(c) > 0.2) {
			return true;
		}
		else return false;
	}
}

//Checks if two lines are perpendicular(orthogonal more precisely)
bool Line::operator|(const Line& c) const{
	if (this->ShortestDistance(c) < 0.02) {
		Vector a(this->getVector());
		Vector b(c.getVector());
			if (a * b < 0.02 && a * b > -0.02) {
				return true;
			}
			else return false;
		}
	else return false;
}

//output when manual inputting
void Line::print(std::ofstream& out) const {
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Direction of the Line." << std::endl;
	std::cout << "2. Find a Normal Vector to the Line." << std::endl;
	std::cout << "3. Find the Angle between two Lines." << std::endl;
	std::cout << "4. Find if a Point lies on the Line." << std::endl;
	std::cout << "5. Find if a Line is Parallel to another Line." << std::endl;
	std::cout << "6. Find if a Line matches with another Line." << std::endl;
	std::cout << "7. Find if a Line intersects another Line." << std::endl;
	std::cout << "8. Find if a Line never crosses another Line." << std::endl;
	std::cout << "9. Find if a Line is Perpendicular to another Line." << std::endl << std::endl;
	std::cout << "Enter: ";

	int x;
	std::cin >> x;
	while (x < 1 || x>9) {
		std::cout << "\Invalid Input." << std::endl;
		std::cout << "Enter: ";
		std::cin >> x;
	}

	Line l2;
	Point p;

	out << "\n\t" << x;
	switch (x) {
	case 1:
		std::cout << "\nDirection: \n" << this->Direction() << std::endl;
		out << "\n\t\tDirection: \n" << this->Length() << std::endl;
		break;
	case 2:
		std::cout << "\nNormal Vector to the Line is:" << std::endl;
		out << "\n\t\tNormal Vector to the Line is:" << std::endl;
		std::cout << this->Perpendicular() << std::endl;
		out << this->Perpendicular() << std::endl;
		break;
	case 3:
		std::cout << "\nEnter values for the Second Line:" << std::endl;
		std::cin >> l2;
		out << "\n\t\tSecond Line:\n";
		out << l2;
		std::cout <<"\nAngle is: "<< this->Angle(l2) << std::endl;
		out << "\n\t\tAngle is: " << this->Angle(l2) << std::endl;
		break;
	case 4:
		std::cout << "\nEnter a Point: " << std::endl;
		std::cin >> p;
		out << "\n\t\tPoint: \n";
		out << p;
		if (*this + p) { 
			std::cout << "\nThe Point lies on the Line." << std::endl; 
			out << "\n\t\tThe Point lies on the Line." << std::endl;
		}
		else std::cout << "\nThe Point doesn't lie on the Line." << std::endl;
		break;
	case 5:
		std::cout << "\nEnter values for the Second Line:" << std::endl;
		std::cin >> l2;
		out << "\n\t\tSecond Line:\n";
		out << l2;
		if (*this || l2) { 
			std::cout << "\nThe Lines are Parallel." << std::endl;
			out << "\n\t\tThe Lines are Parallel." << std::endl;		
		}
		else {
			std::cout << "\nThe Lines aren't Parallel." << std::endl;
			out << "\n\t\tThe Lines aren't Parallel." << std::endl;
		}
		break;
	case 6:
		std::cout << "\nEnter values for the Second Line:" << std::endl;
		std::cin >> l2;
		out << "\n\t\tSecond Line:\n";
		out << l2;
		if (*this == l2) { 
			std::cout << "\nThe Lines match." << std::endl;
			out << "\n\t\tThe Lines match." << std::endl;
		}
		else { 
			std::cout << "\nThe Lines don't match." << std::endl;
			out << "\n\t\tThe Lines don't match." << std::endl;
		}
		break;
	case 7:
		std::cout << "\nEnter values for the Second Line:" << std::endl;
		std::cin >> l2;
		out << "\n\t\tSecond Line:\n";
		out << l2;
		if (*this && l2) { 
			std::cout << "The Lines intersect." << std::endl;
			out << "\n\t\tThe Lines intersect." << std::endl;
		}
		else {
			std::cout << "\nThe Lines don't intersect." << std::endl;
			out << "\n\t\tThe Lines don't intersect." << std::endl;
		}
		break;
	case 8:
		std::cout << "\nEnter values for the Second Line:" << std::endl;
		std::cin >> l2;
		out << "\n\t\tSecond Line:\n";
		out << l2;
		if (*this != l2) {
			std::cout << "\nThe Lines aren't crossed." << std::endl;
			out << "\n\t\tThe Lines aren't crossed." << std::endl;
		}
		else {
			std::cout << "\nThe Lines are crossed." << std::endl;
			out << "\n\t\tThe Lines are crossed." << std::endl;
		}
		break;
	case 9:
		std::cout << "\nEnter values for the Second Line:" << std::endl;
		std::cin >> l2;
		out << "\n\t\tSecond Line:\n";
		out << l2;
		if (*this | l2) {
			std::cout << "\nThe Lines are Perpendicular." << std::endl;
			out << "\n\t\tThe Lines are Perpendicular." << std::endl;
		}
		else { 
			std::cout << "\nThe Lines aren't Perpendicular." << std::endl;
			out << "\n\t\tThe Lines aren't Perpendicular." << std::endl;
		}
		break;
	}
}

//output when reading from a file
void Line::autoPrint(std::ofstream& out, int* arr, unsigned short arrsz) const {
	try {
		if (arrsz < 9) { throw std::logic_error("File too short!"); }
		int x;
		x = arr[8];

		while (x < 1 || x>9) {
			std::cout << "\Invalid Input." << std::endl;
			std::cout << "Enter: ";
			std::cin >> x;
		}

		Line l2;
		Point p;

		out << "\n\t" << x;
		switch (x) {
		case 1:
			std::cout << "\nDirection: \n" << this->Direction() << std::endl;
			out << "\n\t\tDirection: \n" << this->Length() << std::endl;
			break;
		case 2:
			std::cout << "\nNormal Vector to the Line is:" << std::endl;
			out << "\n\t\tNormal Vector to the Line is:" << std::endl;
			std::cout << this->Perpendicular() << std::endl;
			out << this->Perpendicular() << std::endl;
			break;
		case 3:
			if (arrsz < 16) { throw std::logic_error("Not enough information! All lines/necessary points must be written in order!"); }
			while (arr[9] != 1 && arr[9] != 2) {
				std::cout << "Invalid Input. Choose set for line manually.\n1.Point & Point\n2.Point & Vector\n";
				std::cin >> arr[9];
			}
			if (arr[9] == 1) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Point(arr[13], arr[14], arr[15]));
			}
			else if (arr[9] == 2) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Vector(arr[13], arr[14], arr[15]));
			}
			std::cout << "\nSecond Line:\n";
			std::cout << l2<<"\n";
			out << "\n\t\tSecond Line:\n";
			out << l2;
			std::cout << "\nAngle is: " << this->Angle(l2) << std::endl;
			out << "\n\t\tAngle is: " << this->Angle(l2) << std::endl;
			break;
		case 4:
			if (arrsz < 13) { throw std::logic_error("Not enough information! All lines/necessary points must be written in order!"); }
			p = Point(arr[10], arr[11], arr[12]);
			std::cout << "\nPoint:\n" << p << "\n";
			out << "\n\t\tPoint: \n";
			out << p;
			if (*this + p) {
				std::cout << "\nThe Point lies on the Line." << std::endl;
				out << "\n\t\tThe Point lies on the Line." << std::endl;
			}
			else std::cout << "\nThe Point doesn't lie on the Line." << std::endl;
			break;
		case 5:
			if (arrsz < 16) { throw std::logic_error("Not enough information! All lines/necessary points must be written in order!"); }
			while (arr[9] != 1 && arr[9] != 2) {
				std::cout << "Invalid Input. Choose set for line manually.\n1.Point & Point\n2.Point & Vector\n";
				std::cin >> arr[9];
			}
			if (arr[9] == 1) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Point(arr[13], arr[14], arr[15]));
			}
			else if (arr[9] == 2) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Vector(arr[13], arr[14], arr[15]));
			}
			std::cout << "\nSecond Line:\n";
			std::cout << l2 << "\n";
			out << "\n\t\tSecond Line:\n";
			out << l2;
			if (*this || l2) {
				std::cout << "\nThe Lines are Parallel." << std::endl;
				out << "\n\t\tThe Lines are Parallel." << std::endl;
			}
			else {
				std::cout << "\nThe Lines aren't Parallel." << std::endl;
				out << "\n\t\tThe Lines aren't Parallel." << std::endl;
			}
			break;
		case 6:
			if (arrsz < 16) { throw std::logic_error("Not enough information! All lines/necessary points must be written in order!"); }
			while (arr[9] != 1 && arr[9] != 2) {
				std::cout << "Invalid Input. Choose set for line manually.\n1.Point & Point\n2.Point & Vector\n";
				std::cin >> arr[9];
			}
			if (arr[9] == 1) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Point(arr[13], arr[14], arr[15]));
			}
			else if (arr[9] == 2) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Vector(arr[13], arr[14], arr[15]));
			}
			std::cout << "\nSecond Line:\n";
			std::cout << l2 << "\n";
			out << "\n\t\tSecond Line:\n";
			out << l2;
			if (*this == l2) {
				std::cout << "\nThe Lines match." << std::endl;
				out << "\n\t\tThe Lines match." << std::endl;
			}
			else {
				std::cout << "\nThe Lines don't match." << std::endl;
				out << "\n\t\tThe Lines don't match." << std::endl;
			}
			break;
		case 7:
			if (arrsz < 16) { throw std::logic_error("Not enough information! All lines/necessary points must be written in order!"); }
			while (arr[9] != 1 && arr[9] != 2) {
				std::cout << "Invalid Input. Choose set for line manually.\n1.Point & Point\n2.Point & Vector\n";
				std::cin >> arr[9];
			}
			if (arr[9] == 1) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Point(arr[13], arr[14], arr[15]));
			}
			else if (arr[9] == 2) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Vector(arr[13], arr[14], arr[15]));
			}
			std::cout << "\nSecond Line:\n";
			std::cout << l2 << "\n";
			out << "\n\t\tSecond Line:\n";
			out << l2;
			if (*this && l2) {
				std::cout << "The Lines intersect." << std::endl;
				out << "\n\t\tThe Lines intersect." << std::endl;
			}
			else {
				std::cout << "\nThe Lines don't intersect." << std::endl;
				out << "\n\t\tThe Lines don't intersect." << std::endl;
			}
			break;
		case 8:
			if (arrsz < 16) { throw std::logic_error("Not enough information! All lines/necessary points must be written in order!"); }
			while (arr[9] != 1 && arr[9] != 2) {
				std::cout << "Invalid Input. Choose set for line manually.\n1.Point & Point\n2.Point & Vector\n";
				std::cin >> arr[9];
			}
			if (arr[9] == 1) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Point(arr[13], arr[14], arr[15]));
			}
			else if (arr[9] == 2) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Vector(arr[13], arr[14], arr[15]));
			}
			std::cout << "\nSecond Line:\n";
			std::cout << l2 << "\n";
			out << "\n\t\tSecond Line:\n";
			out << l2;
			if (*this != l2) {
				std::cout << "\nThe Lines are crossed." << std::endl;
				out << "\n\t\tThe Lines are crossed." << std::endl;
			}
			else {
				std::cout << "\nThe Lines aren't crossed." << std::endl;
				out << "\n\t\tThe Lines aren't crossed." << std::endl;
			}
			break;
		case 9:
			if (arrsz < 16) { throw std::logic_error("Not enough information! All lines/necessary points must be written in order!"); }
			while (arr[9] != 1 && arr[9] != 2) {
				std::cout << "Invalid Input. Choose set for line manually.\n1.Point & Point\n2.Point & Vector\n";
				std::cin >> arr[9];
			}
			if (arr[9] == 1) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Point(arr[13], arr[14], arr[15]));
			}
			else if (arr[9] == 2) {
				l2 = Line(Point(arr[10], arr[11], arr[12]), Vector(arr[13], arr[14], arr[15]));
			}
			std::cout << "\nSecond Line:\n";
			std::cout << l2 << "\n";
			out << "\n\t\tSecond Line:\n";
			out << l2;
			if (*this | l2) {
				std::cout << "\nThe Lines are Perpendicular." << std::endl;
				out << "\n\t\tThe Lines are Perpendicular." << std::endl;
			}
			else {
				std::cout << "\nThe Lines aren't Perpendicular." << std::endl;
				out << "\n\t\tThe Lines aren't Perpendicular." << std::endl;
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


std::ostream& Line::ext(std::ostream& out) const {
	out << "Line:" << std::endl;
	out << "x = " << this->getPointX() << " + " << this->getVectorX() << "*" << "t" << std::endl;
	out << "y = " << this->getPointY() << " + " << this->getVectorY() << "*" << "t" << std::endl;
	out << "z = " << this->getPointZ() << " + " << this->getVectorZ() << "*" << "t" << std::endl;
	return out;
}

std::istream& Line::ins(std::istream& in, bool a, int* arr, unsigned short arrsz) {
	if (a == 0) {
		char y;
		std::cout << "1. Enter Line with two Points." << std::endl;
		std::cout << "2. Enter Line with a Point and a Vector." << std::endl;
		std::cout << "Enter: ";
		std::cin >> y;
		while (y != '1' && y != '2') {
			std::cin >> y;
		}
		if (y == '1') {
			Point a;
			Point b;
			std::cout << "Enter values for Point a." << std::endl;
			std::cin >> a;
			std::cout << "Enter values for Point b." << std::endl;
			std::cin >> b;

			Vector d(a,b);
			this->setPoint(a);
			this->setVector(d);
		}
		else if (y == '2') {
			Point a;
			Vector b;
			std::cout << "Enter values for Point a." << std::endl;
			std::cin >> a;
			std::cout << "Enter values for Vector b." << std::endl;
			std::cin >> b;
			this->setPoint(a);
			this->setVector(b);
		}
	}
	else {
		try {
			if (arr[1] == 1) {
				if (arrsz < 8) { throw std::logic_error("Not enough information for the Line.\nEnter Line Manually!\n\n"); }
				Point a(arr[2], arr[3], arr[4]);
				Point b(arr[5], arr[6], arr[7]);


				Vector d(a,b);
				this->setPoint(a);
				this->setVector(d);
			}
			else if (arr[1] == 2) {
				if (arrsz < 8) { throw std::logic_error("Not enough information for the Line.\nEnter Line Manually!\n\n");}
				Point a(arr[2], arr[3], arr[4]);
				Vector b(arr[5], arr[6], arr[7]);
				this->setPoint(a);
				this->setVector(b);
			}
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


//END OF LINE.CPP