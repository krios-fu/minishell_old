/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:39:06 by krios-fu          #+#    #+#             */
/*   Updated: 2021/01/29 20:09:21 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *list;
    if (!(list = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    list->content = (void*)content;
    list->next = NULL;
    return (list);
}