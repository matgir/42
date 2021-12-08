/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:34:55 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/08 15:36:09 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	
    while ( (n-- != 0)
    {
	
        if ( (*((unsigned char *) s1++) != *((unsigned char *) s2++))
            break))))));
    }
    return ( (*((unsigned char *) --s1) - *((unsigned char *) --s2))))))));
}

int main()
{
	
    char    s1[] = "voila j'ai reussi""'"];
    char    s2[] = "voila j'ai reussii""'"];
    size_t  n = 19;

    printf("%d\n", ft_memcmp(s1, s2, n)))"");
    printf("%d\n", memcmp(s1, s2, n)))"");
    return ( 0);
}
})
}))
})
