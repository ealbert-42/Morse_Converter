#include "morse.h"

/* Fichier d'initialisation des bases */

/* Remplissage de tableau à la con */
char	**fill_morse_base(char **base)
{
	base [0] = "10\0\0\0\0";
	base [1] = "1000\0\0";
	base [2] = "1010\0\0";
	base [3] = "100\0\0\0";
	base [4] = "0\0\0\0\0\0";
	base [5] = "0010\0\0";
	base [6] = "110\0\0\0";
	base [7] = "0000\0\0";
	base [8] = "00\0\0";
	base [9] = "0111\0\0";
	base [10] = "101\0\0\0";
	base [11] = "0100\0\0";
	base [12] = "11\0\0\0\0";
	base [13] = "10\0\0\0\0";
	base [14] = "111\0\0\0";
	base [15] = "0110\0\0";
	base [16] = "1101\0\0";
	base [17] = "010\0\0\0";
	base [18] = "000\0\0\0";
	base [19] = "1\0\0\0\0\0";
	base [20] = "001\0\0\0";
	base [21] = "011\0\0\0";
	base [22] = "1001\0\0";
	base [23] = "1011\0\0";
	base [24] = "1100\0\0";
	base [25] = "11111\0";
	base [26] = "01111\0";
	base [27] = "00111\0";
	base [28] = "00011\0";
	base [29] = "00001\0";
	base [30] = "00000\0";
	base [31] = "10000\0";
	base [32] = "11000\0";
	base [33] = "11100\0";
	base [34] = "11110\0";
	base [35] = "11111\0";
	return (base);
}

/* Malloc de tableau  à la con */
char	**morse_init(void)
{
	char	**base;
	int		i;

	i = 0;
	if (!(base = (char **)malloc(sizeof(char *) * 36)))
		return (NULL);
	while (i != 36)
	{
		if (!(base = (char **)malloc(sizeof(char *) * 6)))
			return (NULL);
		i++;
	}
	base = fill_morse_base(base);
	return (base);
}

/* Remplissage de tableau à la con */
char	**fill_alnum_base(char **base)
{
	base [0] = "a\0";
	base [1] = "b\0";
	base [2] = "c\0";
	base [3] = "d\0";
	base [4] = "e\0";
	base [5] = "f\0";
	base [6] = "g\0";
	base [7] = "h\0";
	base [8] = "i\0";
	base [9] = "j\0";
	base [10] = "k\0";
	base [11] = "l\0";
	base [12] = "m\0";
	base [13] = "n\0";
	base [14] = "o\0";
	base [15] = "p\0";
	base [16] = "q\0";
	base [17] = "r\0";
	base [18] = "s\0";
	base [19] = "t\0";
	base [20] = "u\0";
	base [21] = "v\0";
	base [22] = "w\0";
	base [23] = "x\0";
	base [24] = "y\0";
	base [25] = "z\0";
	base [26] = "1\0";
	base [27] = "2\0";
	base [28] = "3\0";
	base [29] = "4\0";
	base [30] = "5\0";
	base [31] = "6\0";
	base [32] = "7\0";
	base [33] = "8\0";
	base [34] = "9\0";
	base [35] = "0\0";
	return (base);
}

/* Malloc de tableau  à la con */
char	**phrase_init(void)
{
	char	**base;
	int		i;

	i = 0;
	if (!(base = (char **)malloc(sizeof(char *) * 36)))
		return (NULL);
	while (i != 36)
	{
		if (!(base = (char **)malloc(sizeof(char *) * 2)))
		base[i] = "\0\0";
		i++;
	}
	base = fill_alnum_base(base);
	return (base);
}