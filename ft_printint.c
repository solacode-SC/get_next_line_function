/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:53:24 by soel-mou          #+#    #+#             */
/*   Updated: 2023/12/13 21:53:26 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	int				nb;
	unsigned int	i;

	nb = n;
	i = 1;
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	ft_putnbr(n);
	if (n == -2147483648)
		return (11);
	return (i);
}