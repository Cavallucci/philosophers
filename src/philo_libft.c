#include "philo.h"

int	ft_atoi(const char *str)
{
	size_t				i;
	int					m;
	unsigned long long	var;

	m = 1;
	i = 0;
	var = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			m = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		var = var * 10 + (str[i] - 48);
		i++;
	}
	if (var > 9223372036854775807 && m == 1)
		return (-1);
	else if (var > 9223372036854775807 && m == -1)
		return (0);
	return (var * m);
}

int	ft_isnumeric(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + i++) = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	array = (void *)malloc(size * count);
	if (!array)
		return (NULL);
	ft_bzero(array, size * count);
	return (array);
}
