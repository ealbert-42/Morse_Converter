#include "morse.h"

/* Fonctions supplémentaires */

int		ft_read_compare(int a, int b)
{
	if	(a == b)
			return (1);
	return (0);
}

int		ft_is_alnum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'&& c <= '9'))
		return (1);
	return (0);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	ft_tabsize(char *s, char c)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			size++;
			i++;
		}
	}
	return (size);
}

static int	ft_len(char *s, char c, int start)
{
	int		len;

	len = 0;
	while (s[start] != c && s[start])
	{
		len++;
		start++;
	}
	return (len);
}

static char	*ft_createstr(char *s, char *s2, char c, int start)
{
	int		i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}

static char	**ft_createtab(char **tab, char *s, char c, int start)
{
	int		len;
	int		i;
	int		j;

	i = start;
	j = 0;
	while (s[i])
	{
		len = ft_len(s, c, start);
		tab[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (tab[j])
		{
			tab[j] = ft_createstr(s, tab[j], c, start);
			j++;
			i += ft_len(s, c, start);
			while (s[i] == c && s[i])
				i++;
			start = i;
		}
		else
			return (NULL);
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;

	i = 0;
	if (s)
	{
		size = ft_tabsize((char *)s, c);
		tab = (char **)malloc(sizeof(char *) * (size + 1));
		i = 0;
		if (tab)
		{
			while (s[i] == c && s[i])
				i++;
			tab = ft_createtab(tab, (char *)s, c, i);
			return (tab);
		}
		return (NULL);
	}
	return (NULL);
}
