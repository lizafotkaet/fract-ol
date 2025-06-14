/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:38:35 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/31 03:00:05 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*lst_new;
// 	t_list	*temp_last;

// 	if (!lst)
// 		return (NULL);
// 	lst_new = (t_list *)malloc(sizeof(t_list));
// 	temp_last = NULL;
// 	if (!lst_new)
// 		return (NULL);
// 	lst_new->content = f(lst->content);
// 	if (!lst_new->content)
// 		ft_lstclear(&lst_new, del);
// 	lst = lst->next;
// 	while (lst) // lst->next != NULL
// 	{
// 		lst_new = (t_list *)malloc(sizeof(t_list));
// 		if (lst_new == NULL)
// 			return (NULL);
// 		lst_new->next = temp_last;
// 		lst_new->content = f(lst->content);
// 		if (lst_new->content == NULL)
// 		{
// 			ft_lstclear(&lst_new, del); // & basically means take the address of the address cause the lstclear function takes a double pointer as an argument
// 			return (NULL);
// 		}
// 		lst = lst->next;
// 	}
// 	lst_new->next = NULL;
// 	return (lst_new);
// }

// // #include <stdlib.h>

// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
//     t_list *new_lst = NULL;
// 	t_list	*tail = NULL;
//     t_list *new_node;

//     while (lst)
//     {
//         new_node = (t_list *)malloc(sizeof(t_list));
//         if (!new_node)
//         {
//             ft_lstclear(&new_lst, del); // Clear already created nodes if allocation fails
//             return (NULL);
//         }
//         new_node->content = f(lst->content);
//         if (!new_node->content)
//         {
//             free(new_node); // Free the current node if `f` fails
//             ft_lstclear(&new_lst, del); // Clear already created nodes
//             return (NULL);
//         }
//         new_node->next = NULL;
//         if (!new_lst) // If it's the first node, set as head
//             new_lst = new_node;
//         else
//             tail->next = new_node; // Link to the previous node
//         tail = new_node; // Move the tail to the new node
//         lst = lst->next;
//     }
//     return (new_lst);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current_node;
	
	head = NULL;
	current_node = NULL;
	while (lst)
	{
		current_node = (t_list *)malloc(sizeof(t_list)); // НА ЭТОМ ЭТАПЕ В ПРЕДЫДУЩЕЙ НОДЕ ПОЯВЛЯЕТСЯ УКАЗАТЕЛЬ НА ЭТОТ БЛЯТЬ И ВОТ КСТАТИ ОН И ЕСТЬ НА ЭТОЙ СТРОЧКЕ
		if (!current_node)
			return (NULL);
		current_node->content = f((void *)lst);
		if (!current_node->content)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		current_node->next = NULL;
		lst = lst->next;
		current_node = current_node->next;
	}
	return(head);
}
