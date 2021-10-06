/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmallett <nmallett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:52:22 by nmallett          #+#    #+#             */
/*   Updated: 2021/10/06 16:13:17 by nmallett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_isascii(int c)
{
    unsigned int i;

    i = c;
    if (i >= 0 && i <= 127)
        return (1);
    return (0);
}