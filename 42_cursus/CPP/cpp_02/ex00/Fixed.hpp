#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:

		int					_fixedpointnumber;
		static const int	_fractbits;

	public:

		Fixed(void); //put _fixedpointnumber to 0
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed	&operator=(Fixed const & rhs);

		int		getRawBits(void)const;
		void	setRawBits(int const raw);

};

#endif