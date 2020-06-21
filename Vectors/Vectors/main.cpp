//MAIN.CPP

#include <fstream>

#include "Point.h";
#include "Vector.h";
#include "Element.h";
#include "VectorLengthException.h";
#include "EqualPointsException.h"
#include "Line.h";
#include "Segment.h"
#include "Triangle.h"
using namespace std;

/*
void Tests() {
	Vector c(1, 1, 1);
	cout << c;
	Vector d = c.Direction();
	cout << d;
	Vector h(1, 1, 1);
	Vector l(-3, -3, -3);
	std::cout << endl;
	std::cout << "Are they Paralel: " << h.Parallel(l) << std::endl;
	std::cout << "Are they Perependicular: " << h.Perpendicular(l);
	std::cout << "\nOPERATION +\n";
	std::cout << h + l << std::endl;
	std::cout << "\nOPERATION -\n";
	std::cout << h - l << std::endl;
	std::cout << "\nOPERATION * with double\n";
	std::cout << h * 7 << std::endl;
	std::cout << "\nOPERATION * with vector\n";
	std::cout << h * l << std::endl;
	std::cout << "\nOPERATION ^ with vector\n";
	std::cout << (h ^ l) << std::endl;
	std::cout << "\nOPERATION () with vector\n";
	std::cout << h(l, d) << std::endl;
	Point p(1, 1, 1);
	Point p3(2, 2, 2);
	Point p2(2, 4, 6);
	Vector vp2(2, 1, -2);
	Line l1(p, c);
	Line l3(p3, c);
	Line l2(p2, vp2);
	Vector l4v(2, 2, 2);
	Line l4(p, l4v);
	Line l5(p, p2);
	std::cout << l1 << std::endl;
	std::cout << l2 << std::endl;
	std::cout << l1.Direction() << std::endl;
	std::cout << l1.Perpendicular() << std::endl;
	std::cout << l1.Angle(l2) << std::endl;
	std::cout << l1.ShortestDistance(l2) << std::endl;
	cout << l1 << endl << l3 << endl;
	std::cout << "L1 || L3 " << l1.ShortestDistance(l3) << std::endl;
	std::cout << (l1 || l3) << std::endl;
	std::cout << "L1==L1 " << std::endl;
	std::cout << (l1 == l1) << std::endl;
	std::cout << "L1==L2 " << std::endl;
	std::cout << (l1 == l2) << std::endl;
	std::cout << "L1==L3 " << std::endl;
	std::cout << (l1 == l3) << std::endl;
	std::cout << "L1==L4 " << std::endl;
	std::cout << (l1 == l4) << std::endl;
	std::cout << "PERPENDICULAR VECTOR TO THE LINE:" << std::endl;
	std::cout << l1.Perpendicular() << std::endl;
	std::cout << l4.Perpendicular() << std::endl;
	std::cout << l5 << endl;
	std::cout << l5.Perpendicular() << std::endl;
	Vector zero(0, -1, 1);
	Line l6(p, zero);
	std::cout << (l6 | l1) << std::endl;

	Point p42d(1, 2, 0);
	Vector v42d(2, 4, 0);
	Line l42d(p42d, v42d);
	std::cout << l42d << std::endl;
	std::cout << l42d.Perpendicular() << std::endl;
	Line superpro;
	superpro = l42d;
	std::cout << superpro << std::endl;
	std::cout << superpro.getX() << std::endl;
	Segment s(p42d,v42d);
	Line lpro2(Point(1, 2, 3), Vector(3,3,3));
	std::cout << lpro2 << std::endl;
	std::cout << lpro2.getX() << std::endl;
	std::cout << s << std::endl;
	std::cout << s.Length() << std::endl;
	std::cout << std::endl;
	std::cout << ( s == p42d ) << std::endl;
	std::cout << std::endl;
	std::cout << (l42d + p42d) << std::endl;
	Point ta(2, 3, 0);
	Point tb(5, 3, 0);
	Point tc(4, 6, 0);
	Triangle tr1(ta, tb, tc);
	std::cout << tr1 << std::endl;
	std::cout << "Medicentre M:"<<tr1.Centre() << std::endl;
	std::cout << "Perimeter = "<<tr1.Perimeter() << std::endl;
	std::cout << tr1.TypeOfTriangle() << std::endl;
	std::cout << "Area = "<<tr1.Area() << std::endl;
	Point tm = tr1.Centre();
	std::cout << " Tr1 + tm: " << (tr1 == tm) << std::endl;
	std::cout << "Tr1 < tm: " << (tr1 < tm) << std::endl; MyString a("Hello");
	ifstream in("Input.txt", ios::binary);
	cout << a << endl;
	MyString b("Del");
	a = "Del";
	cout << a << a.Length() << endl;
	a.setArr("Del");
	cout << a;
	do {
		GetLine(in, a);
		std::cout << a << endl;
	} while (!in.eof());
	in.close();
	int* num = new int[8];
	in.open("intput.txt");
	getStreamInts(in, num);
	in.close();
}
*/

void getStreamInts(ifstream& in, int*& arr, unsigned short& length) {
	unsigned i = 0; 
	do {
		while ((in.peek() < 48 || in.peek() > 57) && !in.eof()){
			in.get();
		}
		if (!in.eof()) {
			in >> arr[i];
			std::cout << arr[i] << " ";
			i++;
		}
	} while (!in.eof() && i < 16);
	length = i;
	std::cout <<std::endl<< length<<std::endl;
	system("pause");
}


void Start() {
	bool quit = false;
	ofstream file("Data.txt");
	std::ifstream input("Input.txt");
	while (quit == false) {
		system("cls");
		char enterAutomatically = '0';
		std::cout << "Would you like to read from a file automatically?\nEnter '0' to input manually and '1' to read from a file: ";
		std::cin >> enterAutomatically;

		system("cls");
		Element* a;

		//MANUAL INPUT

		if (enterAutomatically == '0') {
			char c;
			do {
				system("cls");
				std::cout << "Enter 1 for Point." << std::endl;
				std::cout << "Enter 2 for Vector." << std::endl;
				std::cout << "Enter 3 for Line." << std::endl;
				std::cout << "Enter 4 for Segment." << std::endl;
				std::cout << "Enter 5 for Triangle." << std::endl;
				std::cout << "Enter 0 to Quit." << std::endl;
				std::cin >> c;
			} while ((c < '1' || c>'5') && c != '0');

			switch (c) {
			case '1':
				file << "1\n";
				system("cls");
				a = new Point();
				std::cin >> *a;
				std::cout << *a << std::endl;
				file << *a << std::endl;
				system("pause");
				break;
			case '2':
				file << "2\n";
				system("cls");
				a = new Vector;
				std::cin >> *a;
				file << *a << std::endl;
				c = 'y';
				while (c == 'y' || c == 'Y') {
					system("cls");
					std::cout << *a << std::endl;
					a->print(file);
					std::cout << std::endl << "Would you like to continue? (enter y/n) ";
					std::cin >> c;
				}
				break;
			case '3':
				file << "3\n";
				system("cls");
				a = new Line;
				std::cin >> *a;
				file << *a << std::endl;
				c = 'y';
				while (c == 'y' || c == 'Y') {
					system("cls");
					std::cout << *a << std::endl;
					a->print(file);
					std::cout << std::endl << "Would you like to continue? (enter y/n) ";
					std::cin >> c;
				}
				break;
			case '4':
				file << "4\n";
				system("cls");
				a = new Segment;
				std::cin >> *a;
				file << *a << std::endl;
				c = 'y';
				while (c == 'y' || c == 'Y') {
					system("cls");
					std::cout << *a << std::endl;
					a->print(file);
					std::cout << std::endl << "Would you like to continue? (enter y/n) ";
					std::cin >> c;
				}
				break;
			case '5':
				file << "5\n";
				system("cls");
				a = new Triangle;
				std::cin >> *a;
				file << *a << std::endl;
				c = 'y';
				while (c == 'y' || c == 'Y') {
					system("cls");
					std::cout << *a << std::endl;
					a->print(file);
					std::cout << std::endl << "Would you like to continue? (enter y/n) ";
					std::cin >> c;
				}
				break;
			case'0':
				a = new Point();
				quit = true;
				break;
			}
		}

		//AUTOMATIC INPUT

		else {
			try {
				//std::ifstream input("Input.txt");
				if (input.is_open()) {
					if (input.peek() == std::ifstream::traits_type::eof()) {
						throw std::logic_error("File is Empty or there isn't anything else to read.");
					}
					unsigned short sz = 16;
					unsigned short length = sz;
					int* arr = new int[sz];
					getStreamInts(input, arr, length);
					if (length == 0) { throw std::logic_error("File doesn't have any integer information in it."); }
					if (arr[0] != NULL) {
						switch (arr[0]) {
						case 1:
							file << "1\n";
							a = new Point;
							a->ins(std::cin, true, arr, length);
							std::cout << *a << std::endl;
							file << *a << std::endl;
							break;
						case 2:
							file << "2\n";
							system("cls");
							a = new Vector;
							a->ins(std::cin, true, arr, length);
							file << *a << std::endl;
							std::cout << *a << std::endl;
							a->autoPrint(file, arr, length);
							break;
						case 3:
							file << "3\n";
							system("cls");
							a = new Line;
							a->ins(std::cin, true, arr, length);
							file << *a << std::endl;
							std::cout << *a << std::endl;
							a->autoPrint(file, arr, length);
							break;
						case 4:
							file << "4\n";
							system("cls");
							a = new Segment;
							a->ins(std::cin, true, arr, length);
							file << *a << std::endl;
							std::cout << *a << std::endl;
							a->autoPrint(file, arr, length);
							break;
						case 5:
							file << "5\n";
							system("cls");
							a = new Triangle;
							a->ins(std::cin, true, arr, length);
							file << *a << std::endl;
							std::cout << *a << std::endl;
							a->autoPrint(file, arr, length);
						default:break;
						}

					}
					if (arr != nullptr) {
						delete[] arr;
					}
					std::cout << "\nWould you like to quit? (0/1)\n";
					std::cin >> quit;
					//input.close();
				}
				else {
					throw std::logic_error("\nCouldn't open File\n");
				}

			}
			catch (std::logic_error & e) {
				std::cout << e.what();
				std::cout << "\nWould you like to quit? (0/1)\n";
				std::cin >> quit;
			}
		}
	}
	file.close();
	input.close();
}



int main() {
	//Tests();
	Start();
	return 0;
}

//END OF MAIN.CPP