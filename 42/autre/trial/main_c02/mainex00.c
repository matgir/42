/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:34:16 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/11 21:25:31 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char	*dest, 	char	*src);

int main(void)
{
    char    str1[] = "je suis la source et je vais aller dans la destination si elle est plus grande aue moi sinon je crois aue ca ne fonctionnera pas trop trop";
    char    str2[] = "je suis la destination et je dois etre plus grand aue la source sinon ce programme ne fonctionne pas !!";

    printf("%s\n", str1);
    printf("%s\n", str2);
    ft_strcpy(str2, str1);
    printf("%s\n", str1);
    printf("%s\n", str2);
    /*strcpy(str2, str1);
    printf("%s\n", str1);
    printf("%s\n", str2);*/
    return (0);
}
