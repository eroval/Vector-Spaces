//EQUALPOINTSEXCEPTION.CPP

#include "EqualPointsException.h"

EqualPointsException::EqualPointsException(const char* a) {
	this->VLE = Point(0, 0, 0);
}

EqualPointsException::EqualPointsException(const Point& VLE) {
	this->VLE = VLE;
	std::string tmp = "The Points Are Equal! The Point (";
	tmp.append(std::to_string(VLE.getPointX()));
	tmp.append(",");
	tmp.append(std::to_string(VLE.getPointY()));
	tmp.append(",");
	tmp.append(std::to_string(VLE.getPointZ()));
	tmp.append(") intersects.");
	this->name = tmp.c_str();
}

const char* EqualPointsException::what() const {
	return this->name;
}

//END OF EQUALPOINTSEXCEPTION.CPP