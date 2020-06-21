//ELEMENT.CPP

#include "Element.h"

Element::Element() {}

Element::~Element() {}

std::istream& Element::ins(std::istream& in, bool a, int* arr, unsigned short b) {
	return in;
}

std::ostream& Element::ext(std::ostream& out) const{
	return out;
}

std::ostream& operator<<(std::ostream& out, const Element& r) {
	return r.ext(out);
}

std::istream& operator>>(std::istream& in, Element& r) {
	return r.ins(in);
}

void Element::print(std::ofstream& a) const{}

void Element::autoPrint(std::ofstream&, int*, unsigned short) const {};

//END OF ELEMENT.CPP