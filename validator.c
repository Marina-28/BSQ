#include "bsq.h"

char	*ft_error(char	*map)
{
	free(map);
	ft_putstr("map error\n");
	return (NULL);
}

int	valid_1(char	*map, int	len)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (len < 4)
		k++;
	while (i < len)
	{
		while (i < (len - 3))
		{
			if (map[0] == '+')
				i++;
			if (map[i] < 48 || map[i] > 57)
				k++;
			i++;
		}
		if (map[i] < 32 || map[i] > 126)
			k++;
		i++;
	}
	if (map[i - 1] == map[i - 2]
		|| map[i - 1] == map[len - 3] || map[i - 2] == map[i - 3])
		k++;
	return (k);
}

int	valid_2(char	*map, int	len, int	numb)
{
	int	k;
	int	i;
	int	s;
	int	n;

	k = 0;
	i = len + 1;
	n = 0;
	while (map[i] != '\0')
	{
		s = 0;
		while (map[i] != '\n')
		{
			s++;
			i++;
		}
		n++;
		if (s != ft_strlen(map, '\n', (len + 1)))
			k++;
		i++;
	}
	if ((numb == 0) || (n != numb))
		k++;
	return (k);
}

int	valid_3(char	*map, int len)
{
	int	k;
	int	i;
	int	a;

	i = len + 1;
	k = 0;
	a = 0;
	while (map[i] != '\0')
	{
		while (map[i] != '\n')
		{
			if (map[i] != map[len - 2] && map[i] != map[len - 3])
				k++;
			a++;
			i++;
		}
		i++;
	}
	if (a == 0)
		k++;
	return (k);
}
