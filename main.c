#include "minishell.h"

/*
** funcion echo resive un puntero despues de la palabra echo
** avanza los espacios hasta encontra -n  
** verifica la flag
** avanza hasta encontrar los argumentos
*/
char    *ft_print_echo2(char *str)
{
	while(str[0] != 92 && str[1] != 34 && *str != '\0' && *str != ' ')
	{
		write(1, str, 1);
		str++;
	}
	return (str);
}

void	ft_prit_echo(char *str)
{
	int flag;

	flag = 0;
	while (*str != '\0')
	{
		while (*str == ' ')
			str++;
		while (str[0] == '-' && str[1] == 'n' && flag == 0)
		{
			str++;
			flag = 1;
		}
		if(*str == 92)
		{
			str++;
			str = ft_print_echo2 (str);
		}
		if (str)
			write(1, str, 1);
		else 
			break;
		str++;
	}
	if (flag == 0)
			write(1, "\n", 1);
}

int main ()
{

    ft_prit_echo("\\\"42");
}