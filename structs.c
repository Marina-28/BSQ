#include "bsq.h"

t_prm	*get_prm(char	*map, int	len, int	numb)
{
	t_prm	*p;

	p = (t_prm *)malloc(sizeof(t_prm));
	if (p == NULL)
	{
		free(map);
		return (NULL);
	}
	p->full = map[len - 1];
	p->obst = map[len - 2];
	p->empt = map[len - 3];
	p->bgn = len + 1;
	p->nmb = numb;
	p->len = ft_strlen(map, '\n', (len + 1));
	return (p);
}

t_crd	*create_crd(int	**mat, char	**arr, t_prm	*p)
{
	t_crd	*k;

	k = (t_crd *)malloc(sizeof(t_crd));
	if (k == NULL)
	{
		mat_del(mat, p);
		arr_del(arr, p);
		return (NULL);
	}
	return (k);
}
