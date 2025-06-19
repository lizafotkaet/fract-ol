/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:04:56 by ebarbash          #+#    #+#             */
/*   Updated: 2025/02/24 14:00:26 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
// #include <stdio.h>
// int	main()
// {
// 	int i = 42;
// 	// void *ptr = &i;
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