#include "morse.h"

/* Fichier pour le read de chaque phrase */

/* On doit read du morse */
void	read_morse(char	*str, char **a, char **m)
{
	char	**tab;
	int		i;
	int		j;
	int		good;

	i = 0;
	tab = ft_strsplit(str, '/');
	while (tab[i])
	{
		j = 0;
		while (j != 36 && good != 1)
		{
			if (ft_strcmp(tab[i], m[j]) == 1)
			{
				printf("%s",a[j]);
				good = 1;
			}
			j++;
		}
		if (j == 36)
			error();
		good = 0;
		i++;
	}
	printf("\n");
}

/* On doit read une phrase */
void	read_phrase(char *str, char **a, char **m)
{
	char	**tab;
	int		i;
	int		j;
	int		good;

	i = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i])
	{
		j = 0;		
		while (j != 36 && good != 1)
		{
			if (ft_strcmp(tab[i], a[j]) == 1)
			{
				printf("%s",m[j]);
				good = 1;
			}
			j++;
		}
		if (j == 36)
			error();
		good = 0;
		i++;
	}
	printf("\n");
}


/* On cherche quoi read */
void	morse_or_phrase(char *str, char **a, char **b)
{
	if (str[0] == '.' || str[0] == '_')
		read_morse(to_binary(str), a ,b);
	else if (ft_is_alnum(str[0]) == 1)
		read_phrase(to_uppstr(str), a ,b);
	else
		printf("Dafuq did you just send ?\n");
}

int		main(int argc, char **argv)
{
	int		i;
	char	**base_m;
	char	**base_a;

	base_m = morse_init();
	base_a = phrase_init();
	i = 1;
	if (argc < 2)
		printf("Enter a phrase please.\n");
	else
	{
			while (argv[i])
			{
				morse_or_phrase(argv[i], base_a , base_m);
				i++;
			}
	}	
	return (0);
}
