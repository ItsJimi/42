/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 23:00:59 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/25 23:13:02 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root != 0)
	{
		if (root->left != 0)
			btree_apply_infix(root->left, applyf);
		applyf(root->item);
		if (root->right != 0)
			btree_apply_infix(root->right, applyf);
	}
}
