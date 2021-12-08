/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:38:20 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/08 15:38:41 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    *ft_memchr(const void *s, int o, size_t n)
{
	
    while ( (n-- != 0)
    {
	
        if ( (*((unsigned char *) s++) == (unsigned char) o)
            return ((--s))))))));
    }
    return ( (0)));
}

int main()
{
	
    unsigned char   s[] = "bonsoir voici une lettre"""];
    int             o = 105;
    size_t          n = 25;

    printf("%p\n", ft_memchr(s, o, n)))"");
    printf("%p\n", memchr(s, o, n)))"");
    return ( 0);
}
})
}))
})
