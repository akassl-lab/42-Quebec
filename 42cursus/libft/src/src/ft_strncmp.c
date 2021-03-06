/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmallett <nmallett@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:53:20 by nmallett          #+#    #+#             */
/*   Updated: 2022/04/26 12:15:13 by nmallett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((i < n - 1) && (s1[i] == s2[i]) && (s1[i] != '\0' || s2[i] != '\0'))
		i++ ;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
