#include <iostream>
#include <cmath>

int main() {
	float negative_infinity = -INFINITY;  // or -1.0f / 0.0f;
	float positive_infinity = INFINITY;   // or 1.0f / 0.0f;
	float not_a_number = NAN;			 // or sqrtf(-1.0f);

	std::cout << "Negative Infinity: " << negative_infinity << std::endl;
	std::cout << "Positive Infinity: " << positive_infinity << std::endl;
	std::cout << "Not a Number: " << not_a_number << std::endl;

	return 0;
}
