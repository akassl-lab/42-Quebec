/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmallett <nmallett@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:52:17 by nmallett          #+#    #+#             */
/*   Updated: 2022/04/26 12:13:29 by nmallett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalnum(int c)
{
	unsigned int	i;

	i = c;
	if ((i < 65 || i > 90) && (i < 97 || i > 122) && (i < 48 || i > 57))
		return (0);
	return (1);
}