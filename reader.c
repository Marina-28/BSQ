#include "bsq.h"

char	*reader(char	*file)
{
	int		fd;
	int		i;
	int		n;
	char	buf[4096];
	char	*map;

	i = 1;
	n = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (i)
	{
		i = read(fd, buf, 4096);
		n = n + i;
	}
	close (fd);
	map = (char *)malloc((n + 1) * sizeof(char));
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = read(fd, map, n);
	close (fd);
	map[n + 1] = '\0';
	return (map);
}

char	*get_file(void)
{
	char	buf;
	char	*filename;
	int		fd;

	filename = "newfile";
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
		return (NULL);
	while (read(0, &buf, 1))
		write(fd, &buf, 1);
	close (fd);
	return (filename);
}

char	**arr_crt(char	*map, t_prm	*p)
{
	int		i;
	char	**arr;

	i = 0;
	arr = (char **)malloc((p->nmb + 2) * sizeof(char *));
	if (arr == NULL)
	{
		free(map);
		return (NULL);
	}
	while (i < p->nmb)
	{
		arr[i] = malloc((p->len + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			arr_del_ind(arr, i);
			free(p);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

void	arr_fill(char	**arr, char	*map, t_prm	*p)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = p->bgn;
	while (i < p->nmb)
	{
		j = 0;
		while (map[k] != '\n')
		{
			arr[i][j] = map[k];
			j++;
			k++;
		}
		arr[i][j] = '\n';
		arr[i][j + 1] = '\0';
		k = k + 1;
		i++;
	}
}
