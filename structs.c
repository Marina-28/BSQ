#include "bsq.h"

char	*ft_free(char *map, t_prm *p)
{
	free(map);
	if (p != NULL)
		free(p);
	return (NULL);
}

t_prm	*get_prm(char *map, int len, int numb)
{
	t_prm	*p;

	p = (t_prm *)malloc(sizeof(t_prm));
	if (p == NULL)
		return ((t_prm *)ft_free(map, p));
	p->full = map[len - 1];
	p->obst = map[len - 2];
	p->empt = map[len - 3];
	p->bgn = len + 1;
	p->nmb = numb;
	p->len = ft_strlen(map, '\n', (len + 1));
	return (p);
}

t_crd	*create_crd(int	**mat, char	**arr)
{
	t_crd	*k;

	k = (t_crd *)malloc(sizeof(t_crd));
	if (k == NULL)
	{
		mat_del(mat);
		arr_del(arr);
		return (NULL);
	}
	return (k);
}
