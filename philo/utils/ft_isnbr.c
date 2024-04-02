/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:22 by nprudenc          #+#    #+#             */
/*   Updated: 2024/04/02 16:34:10 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philos.h"

int	ft_isnbr(char	*nptr)
{
	int	i;

	i = 0;
	if (ft_atol(nptr) > 2147483647 || ft_atol(nptr) < -2147483648)
		return (0);
	if ((nptr[0] == '-' && nptr[1]) || (nptr[0] == '+' && nptr[1]))
		i++;
	while (nptr[i])
		if (nptr[i] == '-' || nptr[i] == '+' || !ft_isdigit(nptr[i++]))
			return (0);
	return (1);
}