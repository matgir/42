/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:56:31 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:56:35 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class	Sample
{
	public:

		Sample(void);
		~Sample(void);

		int		getfoo(void)const;
		void	setfoo(int v);

	private:

		int		_foo;

};

#endif
