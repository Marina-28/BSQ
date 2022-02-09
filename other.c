#include "bsq.h"

void	ft_putstr(char	*str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char	*str, char	c, int	i)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

int	ft_atoi(char *map, int len)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < (len - 3))
	{
		if (map[0] == '+')
			i++;
		n = n * 10 + map[i] - 48;
		i++;
	}
	return (n);
}

int	find_min(int	a, int	b, int	c)
{
	int	min_numb;

	min_numb = 0;
	if (a < b)
	{
		if (a < c)
			min_numb = a;
		else
			min_numb = c;
	}
	else
	{
		if (b < c)
			min_numb = b;
		else
			min_numb = c;
	}
	return (min_numb);
}
