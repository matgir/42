/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:04:56 by mgirardo          #+#    #+#             */
/*   Updated: 2023/10/03 16:05:02 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		std::string	short_name(int i);
		// std::string	short_lname();
		// std::string	short_nickname();

/*	the short* functions will return either a truncated word or a word
	with the right amount of ' ' at the end of it
*/

	private:

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkst_secret;

};

#endif
