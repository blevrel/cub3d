/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:45:27 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/23 15:04:07 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	ft_get_base(int b)
{
	char	*base;

	base = "0123456789ABCDEF";
	return (base[b]);
}

static int	ft_get_size(int n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static void	ft_fill_res(int offset, int n, char *res, int base)
{
	int	size;

	size = ft_get_size(n, base);
	while (size > offset)
	{
		res[size - 1] = ft_get_base(n % base);
		n = n / base;
		size--;
	}
}

char	*ft_is_zero()
{
	char	*str;

	str = malloc(3 * sizeof(char));
	str[0] = '0';
	str[1] = '0';
	str[2] = '\0';
	return (str);
}

char	*ft_itoa_base(int n, int base)
{
	int		offset;
	int		size;
	char	*res;

	if (base < 2 || base > 16)
		return (NULL);
	if (n == -2147483648 && base == 10)
		return ("-2147483648");
	if (n == 0)
		return (ft_is_zero());
	size = ft_get_size(n, base);
	res = malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	offset = 0;
	if (n < 0)
	{
		res[0] = '-';
		offset = 1;
		n = -n;
	}
	ft_fill_res(offset, n, res, base);
	res[size] = '\0';
	return (res);
}
