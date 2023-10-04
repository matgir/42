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

#ifndef CONTACTCLASS_HPP
# define CONTACTCLASS_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class	Contact
{
	public:

		Contact(void);
		~Contact(void);

		void		displaycontact();
		bool		set_fname();
		bool		set_lname();
		bool		set_nickname();
		bool		set_phnumber();
		bool		set_dkst_secret();
		std::string	short_name(int i);

	private:

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkst_secret;

};

#endif
