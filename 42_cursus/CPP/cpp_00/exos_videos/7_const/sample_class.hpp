#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class	Sample
{
	public:

		float const	pi;
		int			qd;

		Sample(float const f);
		~Sample(void);

		void	bar(void)const;
};

#endif