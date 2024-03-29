/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:55:52 by nprudenc          #+#    #+#             */
/*   Updated: 2024/03/29 17:19:49 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	ft_putstr(char *s, int fd)
{
	int i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}

int	ft_atoi(const char *nptr)
{	
	int	i;
	int	is_neg;
	int	result;

	i = 0;
	is_neg = 0;
	result = 0;
	if (!nptr)
		return (0);
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg++;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]) == 1)
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	if (is_neg == 1)
		return (result * -1);
	return (result);
}

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}