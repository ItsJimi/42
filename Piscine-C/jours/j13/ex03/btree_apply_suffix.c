/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 23:14:06 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/25 23:25:59 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root != 0)
	{
		if (root->left != 0)
			btree_apply_suffix(root->left, applyf);
		if (root->right != 0)
			btree_apply_suffix(root->right, applyf);
		applyf(root->item);
	}
}
