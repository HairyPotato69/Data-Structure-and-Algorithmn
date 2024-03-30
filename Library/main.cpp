#include "data_structure.hpp"
#include "node.hpp"

#include <iostream>

int factorial(int n) {
	if (n > 0)
		return n * factorial(n - 1);
	return 1;
}

int main() {
	std::cout << factorial(5);
	return 0;
}