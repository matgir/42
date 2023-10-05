#ifndef SAMPLECLASS_HPP
# define SAMPLECLASS_HPP

class	Sample
{
	public:

		Sample(void);
		~Sample(void);

		void	bar(char const c) const;
		void	bar(int const n) const;
		void	bar(float const z) const;
		void	bar(Sample const & i) const;
};

#endif