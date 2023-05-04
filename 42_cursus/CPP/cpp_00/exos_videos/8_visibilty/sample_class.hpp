#ifndef SAMPLE_CLASS_HPP
# define SMAPLE_CLASS_HPP

class Sample
{
	public:

		int		publicfoo;

		Sample(void);
		~Sample(void);

		void	publicbar(void)const;

	private:

		int		_privatefoo;

		void	_privatebar(void)const;

};

#endif
