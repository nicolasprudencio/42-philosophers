/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:30 by nprudenc          #+#    #+#             */
/*   Updated: 2024/04/02 16:34:02 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philos.h"

long int	ft_atol(char *nptr)
{
	int			i;
	int			is_neg;
	long int	result;

	i = 0;
	result = 0;
	is_neg = 1;
	if (!nptr)
		return (0);
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			is_neg = -1;
	}
	while (nptr[i] && ft_isdigit(nptr[i]) == 1)
		result = result * 10 + nptr[i++] - 48;
	return (result * is_neg);
}