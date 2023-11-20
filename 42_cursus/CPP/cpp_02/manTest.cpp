#include <iostream>
#include <limits>

int main() {
    // Determine the number of bits in an integer type
    int numBits = std::numeric_limits<int>::digits;

	if (std::numeric_limits<int>::is_signed)
		numBits++;

    std::cout << "Number of bits in an int: " << numBits << std::endl;

    return 0;
}
