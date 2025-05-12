/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_struct.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:55:54 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:55:55 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_STRUCT_HPP
# define SAMPLE_STRUCT_HPP

struct	Sample1
{
	// private:
		int	foo1;

		Sample1(void);
		~Sample1(void);

		void	bar1(void)const;
};

#endif
