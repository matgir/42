#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
private:

	std::string	_name;
//	static int	_nbinst;//

public:

	Zombie();
	~Zombie();

	void		announce();
	void		setname(std::string name);
//	static void	getnbinst();//

};

#endif
