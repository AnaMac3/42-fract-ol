/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:56:52 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/22 16:16:13 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next_temp;

	if (lst == NULL)
		return ;
	temp = *lst;
	while (temp)
	{
		next_temp = temp->next;
		del(temp->content);
		free (temp);
		temp = next_temp;
	}
	*lst = NULL;
}
