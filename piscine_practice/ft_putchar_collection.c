/* https://github.com/efichot/Libft/blob/master/ft_putchar.c */
// This is how its actually implemented in libft (42's official stdlib you'll 
// re-create throught the piscine).
// #include "libft.h" ==> https://github.com/R4meau/libft

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* https://github.com/jplot/Piscine_C-42/blob/master/colle00/ex00/ft_putchar.c */
#include <unistd.h>

int		jp_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

/* https://github.com/Eywek/42-piscine/blob/master/others/ft_putchar.c */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* https://github.com/kigiri/userpref/blob/master/ft_42/ft_putstr.c */
void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
