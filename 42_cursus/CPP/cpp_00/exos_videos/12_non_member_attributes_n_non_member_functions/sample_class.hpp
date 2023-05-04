#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class	Sample
{

	public:

		Sample(void);
		~Sample(void);

		static int	getnbinst(void);

	private:

		static int	_nbinst;

};

#endif