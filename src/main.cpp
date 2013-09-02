#include <iostream>

#include "Point.h"

using namespace RescueHim;
using namespace RescueHim::Geom;

int main(int argc, char* argv[]) {
	Point a;
	Point b(1, 2);
	Point c(3, 4);

	Point d = a - b + c;

	std::cout << "d = " << d << '\n';

	if (d == Point(-2, 2)) {
		std::cout << "d ist ";
	} else {
		std::cout << "d ist nicht ";
	}

	std::cout << Point(-2, 2) << std::endl;

	return 0;
}

