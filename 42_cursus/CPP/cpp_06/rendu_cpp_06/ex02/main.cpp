#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <ctime>
#include "Identify.h"

int	main(void)
{
	Base *	testBase1;

	testBase1 = generate();

	Base &	testBase2 = *testBase1;

	identify(testBase1);
	identify(testBase2);

	delete testBase1;

	return 0;
}