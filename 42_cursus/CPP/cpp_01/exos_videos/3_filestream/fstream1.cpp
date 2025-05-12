#include <iostream>
#include <fstream>

int	main()
{
	std::ifstream	ifs("numbers");
	unsigned int	dst = 2;
	unsigned int	dst2 = 8;
	// std::cout << dst << " " << dst2 << std::endl;
	ifs >> dst >> dst2;

	// std::cout << dst << " " << dst2 << std::endl;
	// std::cout << ifs << std::endl;
	ifs.close();

	//------------------

	std::ofstream	ofs("test.out");

	ofs << "i like ponies a whole damn lot" << std::endl;
	ofs << "i like whales a whole damn lot" << std::endl;
	ofs.close();
}
