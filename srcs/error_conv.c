#include "morse.h"

/* Fichier de conversions et gestion d'erreur */

/* On a trouvé une erreur */
void	error(void)
{
	printf("Error encountered. Please try again.\n");
}

/* '.' = 0, '_' = 1 */
char	*to_binary(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			str[i] = '0';
		else if (str[i] == '_')
			str[i] = '1';
		i++;
	}
	return (str);
}


/* On met toutes les lettres en majuscules */
char	*to_uppstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
