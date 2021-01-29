/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:13:28 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/29 19:34:17 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *ft_envp(char ** envp)
{
    t_list *envp_l;

    int i ;

    i = 1; 
    envp_l = ft_lstnew (envp [0]);
    while (envp[i])
    {
        ft_lstadd_back(&envp_l, ft_lstnew ((char *)envp [i]));
        i++;
    }
    return(envp_l);
}

void ft_print_envp(char **envp)
{
    int x = 0;
    int y = 1;

    printf("hola");
    printf("%c", envp[x][y]);
    y++;
    printf("%c", envp[x][y]);
    /*while(envp[x])
    {
        while(envp[x][y] != '\0')
        {
            printf("%c", envp[x][y]);
            y++;
        }
        x++;
    }*/
}