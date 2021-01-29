/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:13:28 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/29 20:48:57 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list  *ft_set_envp(char **envp)
{
    t_list *envp_l;

    char **matriz;
    int x = 0;

    while(envp[x])
    {
        matriz = ft_split(envp[x], '=');
        if (matriz[0] == '\0')
        {
            ft_lstadd_back(&envp_l, ft_lstnew((char *)matriz[0]));
        }
        else
            ft_lstadd_back(&envp_l, ft_lstnew2((char *)matriz[0], (char *)matriz[1]));
        x++;
    }
    return(envp_l);
}

void    ft_printf_env(t_list *envp_l)
{
    while (envp_l)
    {
        if (envp_l->var)
            ft_printf("---> [%s]", envp_l->var);
        if (envp_l->content)
            ft_printf("=%s", envp_l->content);
        ft_printf("\n");
        envp_l = envp_l->next;
    }
}

//Hacer export
//Hacer unset