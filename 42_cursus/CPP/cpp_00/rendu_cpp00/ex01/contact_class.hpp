#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class	Contact
{
	public:

		Contact(void);
		~Contact(void);

		void		displaycontact();
		int			set_fname();
		bool		set_lname();
		int			set_nickname();
		int			set_phnumber();
		int			set_dkst_secret();
		std::string	short_fname();
		std::string	short_lname();
		std::string	short_nickname();

	private:

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkst_secret;

};

#endif