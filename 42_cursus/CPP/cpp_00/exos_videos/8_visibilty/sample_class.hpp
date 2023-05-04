/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:55:09 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:55:09 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
