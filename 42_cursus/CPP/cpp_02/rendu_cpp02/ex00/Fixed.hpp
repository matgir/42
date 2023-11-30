#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:

		int					_raw_bits; //the raw bits in the int
		static const int	_binary_point;//place of the coma (starting right) in the raw bits to get the decimal

	public:

		Fixed(void); //put _raw_bits to 0
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed	&operator=(Fixed const & rhs);

		int		getRawBits(void)const;
		void	setRawBits(int const raw);

};

#endif