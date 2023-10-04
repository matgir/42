/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:47 by mgirardo          #+#    #+#             */
/*   Updated: 2023/10/03 16:05:53 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "ContactClass.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>

class	Phonebook
{
	public:

		Phonebook(void);
		~Phonebook(void);

		void	setcontact(Phonebook phonebook);
		void	displaycontacts();
		void	updatephonebook(Contact newcontact);

	private:

		Contact	contacts[8];
		int		nbcontact;
};

#endif
