/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmallett <nmallett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:52:31 by nmallett          #+#    #+#             */
/*   Updated: 2021/10/08 11:41:41 by nmallett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *str, int n, size_t n2)
{
    size_t      i;
    char    *newStr;

    i = 0;
    newStr = (char *) str;
	if (n2 == 0)
		return (NULL);
		
    while (i <= n2)
    {
        if (newStr[i] == (char) n)
            return (&newStr[i]);
        i++;
    }
    return (NULL);
}