#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <stdlib.h>
// # include <filesystem>

std::map<std::string, float>	mapFromCsv(void);
void							checkStream(std::string inputName);
std::string						lineToUse(std::string extracted);

#endif
