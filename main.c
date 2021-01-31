#include "minishell.h"

void	ft_prit_echo(char *str)
{
	int flag;
	int spc;
	int	flag_spc;
	int spc_one;

	spc_one = 0;
	flag_spc = 0;
	spc = 0;
	flag = 0;
	while (*str != '\0')
	{
		while (*str == ' ' && spc == 0)
			str++;
		while (str[0] == '-' && str[1] == 'n' && flag != 2)
		{
			str++;
			flag = 1;
			str++;
		}
		if (*str == 34) // "
		{
			str++;
			spc = 1;
			if(flag_spc > 0)
			{
				spc = 0;
				flag_spc = 0;
			}
			if(spc != 0)
				flag_spc++;
		}
		if(*str == 92) // /
			str++;
		write(1, str, 1);
		if(spc == 0 && str[1] == ' ')
			write(1, " ", 1);
		str++;
	}
	if (flag == 0)
			write(1, "\n", 1);
}

int main ()
{

    ft_prit_echo("");
}