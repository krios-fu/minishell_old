/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:57:18 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/27 23:14:40 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd_print(t_list *env_l)
{
    while(!ft_strnstr((char *)env_l->content, "PWD=", 4))
        env_l = env_l->next;
    printf("%s",ft_strchr(env_l->content, '/'));
}