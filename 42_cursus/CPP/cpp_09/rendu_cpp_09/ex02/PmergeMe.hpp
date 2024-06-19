#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <utility>
# include <vector>
# include <stdlib.h>
# include <deque>
# include <sys/time.h>

std::vector<int>	algoVect(std::vector<int> myVect);
std::deque<int>		algoDeque(std::deque<int> myDeque);
bool				checkArg(char ** argv, int argc);
time_t				getTimeInMs(void);

#endif
