#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:

		int					_raw_bits; //the raw bits in the int
		static const int	_binary_point;//place of the coma (starting right) in the raw bits to get the decimal

	public:

		Fixed(void); //put _raw_bits to 0
		Fixed(Fixed const & copy);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed(void);

		Fixed	&operator=(Fixed const & copie);

		int		getRawBits(void)const;
		void	setRawBits(int const copie);
		float	toFloat(void)const;
		int		toInt(void)const;

};

std::ostream &operator<<(std::ostream & o, Fixed const & i);

#endif