#include "minishell.h"

char	*ft_check_flag(int flag, int i, int k)
{
	char	*str;

	if (flag)
		str = malloc(sizeof(*str) * (i + k + 2));
	else
		str = malloc(sizeof(*str) * (i + k + 1));
	return (str);
}

char	*ft_join(char const *s1, char const *s2, int flag)
{
	size_t	i;
	size_t	k;
	size_t	n;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	i = ft_strlen(s1);
	k = ft_strlen(s2);
	n = 0;
	str = ft_check_flag(flag, i, k);
	if (str == 0)
		return (NULL);
	while (*s1)
		str[n++] = *s1++;
	if (flag == 1)
		str[n++] = ' ';
	if (flag == 2)
		str[n++] = '=';
	while (*s2)
		str[n++] = *s2++;
	str[n] = '\0';
	return (str);
}
