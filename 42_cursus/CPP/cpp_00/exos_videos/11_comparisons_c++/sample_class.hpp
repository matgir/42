#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class	Sample
{
	public:

		Sample(int v);
		~Sample(void);

		int	getfoo(void)const;
		int	compare(Sample *other)const;

	private:

		int	_foo;
};

#endif