#include "bsq.h"

void	ft_error(char *map)
{
	free(map);
	ft_putstr("map error\n");
}

int	valid_1(char *map, int len)
{
	int	i;

	i = 0;
	if (len < 4)
		return (1);
	while (i < len)
	{
		while (i < (len - 3))
		{
			if (map[0] == '+')
				i++;
			if (map[i] < 48 || map[i] > 57)
				return (1);
			i++;
		}
		if (map[i] < 32 || map[i] > 126)
			return (1);
		i++;
	}
	if (map[i - 1] == map[i - 2]
		|| map[i - 1] == map[len - 3] || map[i - 2] == map[i - 3])
		return (1);
	return (0);
}

int	valid_3(char *map, int len)
{
	int	i;
	int	a;

	i = len + 1;
	a = 0;
	while (map[i] != '\0')
	{
		while (map[i] != '\n')
		{
			if (map[i] != map[len - 2] && map[i] != map[len - 3])
				return (1);
			a++;
			i++;
		}
		i++;
	}
	if (a == 0)
		return (1);
	return (0);
}

int	valid_2(char *map, int len, int numb)
{
	int	i;
	int	s;
	int	n;
	int	ideal_len;

	i = len + 1;
	ideal_len = ft_strlen(map, '\n', (len + 1));
	n = 0;
	while (map[i] != '\0')
	{
		s = 0;
		while (map[i] != '\n' && map[i] != '\0')
		{
			s++;
			i++;
		}
		n++;
		if (s != ideal_len || map[i] == '\0')
			return (1);
		i++;
	}
	if ((numb == 0) || (n != numb))
		return (1);
	return (valid_3(map, len));
}
