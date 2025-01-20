#include "../includes/so_long.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = gnl_strlen(s1) + 1;
	dup = (char *) malloc(len * sizeof(*s1));
	i = 0;
	if (dup == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*gnl_strchr(const char *str, int a)
{
	while ((char)a != *str)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	size_total;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size_total = gnl_strlen(s1) + gnl_strlen(s2);
	dst = malloc(sizeof(char) * (size_total + 1));
	if (!dst)
		return (NULL);
	while (*s1)
		dst[i++] = *s1++;
	while (*s2)
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}
