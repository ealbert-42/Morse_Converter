#include "morse.h"

/* Fichier pour le read de chaque phrase */

/* On doit read du morse */
void	read_morse(char	*str, char **a, char **m)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = ft_strsplit(str, '/');
	while (tab[i])
	{
		j = 0;
		while (m[k] && j != 1)
		{
			if (tab[i][0] == ' ')
			{
					printf(" ");
					j = 1;
			}
			else if (ft_strcmp(tab[i], m[k]) == 0)
			{
				printf("%s", a[k]);
				k = 0;
				j = 1;
			}
			else
				k++;
		}
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
	int		k;

	i = 0;
	k = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] && a[k])
		{
			if (ft_read_compare(a[k][0], tab[i][j]))
			{
				printf("%s", m[k]);
				j++;
				k = 0;
				if (tab[i][j])
					printf("/");
			}
			else
				k++;
		}
		if (!a[k])
			error();
		printf("   ");
		i++;
	}
	printf("\n");
}


/* On cherche quoi read */
void	morse_or_phrase(char *str, char **a, char **m)
{
	if (str[0] == '.' || str[0] == '_')
		read_morse(str, a , m);
	else if (ft_is_alnum(str[0]) == 1)
		read_phrase(to_uppstr(str), a ,m);
	else
		printf("Dafuq did you just send ?\n");
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**base_m;
	char	**base_a;

	j = 0;
	if (!(base_m = (char **)malloc(sizeof(char *) * 36)))
		return (0);
	if (!(base_a = (char **)malloc(sizeof(char *) * 36)))
		return (0);
	while (j < 36)
	{
		if (!(base_m[j] = (char *)malloc(sizeof(char) * 6)))
			return (0);
		if (!(base_a[j] = (char *)malloc(sizeof(char) * 2)))
			return (0);
		j++;
	}
	base_m[0] = "._\0\0\0\0";
	base_m[1] = "_...\0\0";
	base_m[2] = "_._.\0\0";
	base_m[3] = "_..\0\0\0";
	base_m[4] = ".\0\0\0\0\0";
	base_m[5] = ".._.\0\0";
	base_m[6] = "__.\0\0\0";
	base_m[7] = "....\0\0";
	base_m[8] = "..\0\0";
	base_m[9] = ".___\0\0";
	base_m[10] = "_._\0\0\0";
	base_m[11] = "._..\0\0";
	base_m[12] = "__\0\0\0\0";
	base_m[13] = "_.\0\0\0\0";
	base_m[14] = "___\0\0\0";
	base_m[15] = ".__.\0\0";
	base_m[16] = "__._\0\0";
	base_m[17] = "._.\0\0\0";
	base_m[18] = "...\0\0\0";
	base_m[19] = "_\0\0\0\0\0";
	base_m[20] = ".._\0\0\0";
	base_m[21] = "..._\0\0";
	base_m[22] = ".__\0\0\0";
	base_m[23] = "_.._\0\0";
	base_m[24] = "_.__\0\0";
	base_m[25] = "__..\0\0";
	base_m[26] = ".____\0";
	base_m[27] = "..___\0";
	base_m[28] = "...__\0";
	base_m[29] = "...._\0";
	base_m[30] = ".....\0";
	base_m[31] = "_....\0";
	base_m[32] = "__...\0";
	base_m[33] = "___..\0";
	base_m[34] = "____.\0";
	base_m[35] = "_____\0";
	base_a[0] = "A\0";
	base_a[1] = "B\0";
	base_a[2] = "C\0";
	base_a[3] = "D\0";
	base_a[4] = "E\0";
	base_a[5] = "F\0";
	base_a[6] = "G\0";
	base_a[7] = "H\0";
	base_a[8] = "I\0";
	base_a[9] = "J\0";
	base_a[10] = "K\0";
	base_a[11] = "L\0";
	base_a[12] = "M\0";
	base_a[13] = "N\0";
	base_a[14] = "O\0";
	base_a[15] = "P\0";
	base_a[16] = "Q\0";
	base_a[17] = "R\0";
	base_a[18] = "S\0";
	base_a[19] = "T\0";
	base_a[20] = "U\0";
	base_a[21] = "V\0";
	base_a[22] = "W\0";
	base_a[23] = "X\0";
	base_a[24] = "Y\0";
	base_a[25] = "Z\0";
	base_a[26] = "1\0";
	base_a[27] = "2\0";
	base_a[28] = "3\0";
	base_a[29] = "4\0";
	base_a[30] = "5\0";
	base_a[31] = "6\0";
	base_a[32] = "7\0";
	base_a[33] = "8\0";
	base_a[34] = "9\0";
	base_a[35] = "0\0";
	i = 1;
	if (argc < 2)
		printf("Enter a phrase please.\n");
	else
	{
		while (argv[i])
		{
			morse_or_phrase(argv[i], (char **)base_a , (char **)base_m);
			i++;
		}
	}
	return (0);
}
