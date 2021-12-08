/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:36:57 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/08 15:37:19 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

vim#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t  ft_strlen(char *to_find)
{
	
    size_t  i;

    i = 0;
    while ((to_find[i])
        i++]));
    return ((i)));
}

char    *verif ((char *str, char *to_find, size_t i, size_t j)
{
	
    size_t  l;

    while ( (str[i])
    {
	
        //j = 0;
        if ( (str[i] == to_find[j])
        {
	
            l = i;
            while ( (l <= (i + ft_strlen(to_find)) && (str[l] || to_find[j]))
            {
	
                if ( (str[l++] == to_find[j++])
                {
	
                    //l++;
                    //j++;
                    if ( (j == ft_strlen(to_find))
                        return ( (&str[l - j])])))));
                }
                else
                    break;
            }
        }
        i++;
    }
    return ( (0)));
}

char    *ft_strstr(char *str, char *to_find)
{
	
    unsigned int    i;
    unsigned int    j;

    i = -1;
    j = 0;
    if ( (ft_strlen(to_find) == 0)
        return ( (str))))));
    return ( (verif ((str, to_find, i, j))))));
}

/*char    *strnstr(const char *big, const char *little, size_t len)
{
	

}*/

int main()
{
	
    printf("%s\n", strstr("bonsoir je suis moi", "bon"))"""")"");
    printf("%s\n", ft_strstr("bonsoir je suis moi", "bon"))"""")"");
    return ( 0);
}
})
})
})
}]]))
}]])))))
}]]))
}]))
}))
})
