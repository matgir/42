/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:13:46 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 19:13:48 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class	Sample
{
	public:

		Sample(int v);
		~Sample(void);

		int	getfoo(void)const;
		int	compare(Sample *other)const;

	private:

		int	_foo;
};

#endif
