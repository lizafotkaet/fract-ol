/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:15:42 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/30 16:35:33 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
// #include <stdio.h>
// int	main()
// {
// 	int i = 42;
// 	t_list *lst = ft_lstnew((void *)i);
// 	printf("%d\n", (int)lst->content);
// 	printf("%p", lst->next);
// }
//
//
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;