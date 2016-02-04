#ifndef MORSE_H
# define MORSE_H
# include <stdlib.h>
# include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2);
char	**ft_strsplit(const char *s, char c);
char	**morse_init(void);
char	**phrase_init(void);
void	error(void);
char	*to_binary(char *str);
char	*to_uppstr(char *str);

#endif
