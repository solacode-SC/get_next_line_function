#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char	*ft_strjoin(char *s1, char *s2, int v1, int v2)
{
	char			*dest;
	unsigned int	i;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		dest[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	dest[ft_strlen(s1) + i] = 0;
	if (v1)
		free(s1);
	if (v2)
		free(s2);
	return (dest);
}

char	*until_nl(char *s)
{
	int		i;
	char	*unl;

	i = 0;
	unl = ft_strjoin(s, NULL, 0, 0);
	while (s[i] != '\n')
		i++;
	unl[i + 1] = '\0';
	free(s);
	return (unl);
}

char	*after_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	if (i < (int)ft_strlen(s))
		return (ft_strjoin((s + i + 1), NULL, 0, 0));
	return (NULL);
}
