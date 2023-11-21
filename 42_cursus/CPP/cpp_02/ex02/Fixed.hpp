#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:

		int					_raw_bits; //the raw bits in the int
		static const int	_binary_point = 8;//place of the coma (starting right) in the raw bits to get the decimal

	public:

//********** Constructor **********//
		Fixed(void); //put _raw_bits to 0
		Fixed(Fixed const & copy);
		Fixed(const int i);
		Fixed(const float f);

//********** Destructor **********//
		~Fixed(void);

//********** Comparison **********//
		Fixed	&operator=(Fixed const & copie);
		bool	operator>(Fixed const & compare)const;
		bool	operator<(Fixed const & compare)const;
		bool	operator>=(Fixed const & compare)const;
		bool	operator<=(Fixed const & compare)const;
		bool	operator==(Fixed const & compare)const;
		bool	operator!=(Fixed const & compare)const;

//********** Modifier **********//
		Fixed	operator+(Fixed const & modifier);
		Fixed	operator-(Fixed const & modifier);
		Fixed	operator*(Fixed const & modifier);
		Fixed	operator/(Fixed const & modifier);

//********** Crement **********//
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

//********** Functions **********//
		int						getRawBits(void)const;
		void					setRawBits(int const copie);
		float					toFloat(void)const;
		int						toInt(void)const;

		static Fixed &			min(Fixed & a, Fixed & b);//
		static const Fixed &	min(Fixed const & a, Fixed const & b);//
		static Fixed &			max(Fixed & a, Fixed & b);//
		static Fixed const &	max(Fixed const & a, Fixed const & b);//

};

std::ostream &operator<<(std::ostream & o, Fixed const & i);

#endif