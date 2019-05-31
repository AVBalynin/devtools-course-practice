// Copyright 2019 Balynin Alexey

#include <iostream>

#include "include/length_calculator.h"

int main(int argc, const char** argv) {
	LengthCalculator app;
	std::cout << app(argc, argv);
	return 0;
}
