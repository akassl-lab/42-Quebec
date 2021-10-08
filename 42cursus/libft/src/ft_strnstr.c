/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmallett <nmallett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:53:26 by nmallett          #+#    #+#             */
/*   Updated: 2021/10/08 14:48:44 by nmallett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (to_find[0] == '\0')
		return ((char *) str);
	if (to_find == NULL || str == NULL)
		return (NULL);
	while (str[i[1]] && i[0] < n)
	{
		while (str[i[1]] && str[i[1]] == to_find[i[2]] && (i[0] + i[1]) < n)
		{
			if (to_find[i[2] + 1] == '\0')
				return ((char *) str + i[1] - i[2]);
			i[1]++;
			i[2]++;
		}
		i[1] = 0;
		i[2] = 0;
		str++;
		i[0]++;
	}
	return (NULL);
}