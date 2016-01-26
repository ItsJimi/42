/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 22:00:44 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/25 22:45:33 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root != 0)
	{
		applyf(root->item);
		if (root->left != 0)
			btree_apply_prefix(root->left, applyf);
		else if (root->right != 0)
			btree_apply_prefix(root->right, applyf);
	}
}
