#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "contact_class.hpp"

class	Phonebook
{
	public:

		Phonebook(void);
		~Phonebook(void);

		int	setcontact();
		int	displaycontacts();
		int	getcontact(int index);

	private:

		Contact	constacts[8];
		int		nbcontact;
};

#endif