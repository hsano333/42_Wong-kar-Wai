
#include "stdio.h"

static size_t	get_count(char *p, int n)
{
	long	a;
	size_t	i;	
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (n < 0)
	{
		a = -1 * (long)n;
		cnt++;
	}
	else
		a = n;
	while (a)
	{
		p[i++] = (a % 10) + '0';
		a /= 10;
		cnt++;
	}
	if (n < 0)
		p[i++] = '-';
	return (cnt);
}

void	ft_itoa_no_memory(int n, char *p, char *r)
{
	size_t	i;
	size_t	cnt;

	if (n == 0)
	{
		r[0] = '0';
		r[1] = '\0';
		return ;
	}
	cnt = get_count(p, n);
	r[cnt] = '\0';
	i = 0;
	while (i < cnt)
	{
		r[i] = p[cnt - i - 1];
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while ((*(s++)))
		i++;
	return (i);
}
