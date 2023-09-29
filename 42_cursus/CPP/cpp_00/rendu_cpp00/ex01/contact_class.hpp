#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class	Contact
{
	public:

		Contact(void);
		~Contact(void);

		void	displaycontact();
		int		set_fname(std::string fname);
		int		set_lname(std::string lname);
		int		set_nickname(std::string nickname);
		int		set_phnumber(std::string phnumber);
		int		set_dkst_secret(std::string dkst_secret);
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