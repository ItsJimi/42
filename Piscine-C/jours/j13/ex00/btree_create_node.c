/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 13:19:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/25 23:28:50 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree		*tree;

	tree = malloc(sizeof(t_btree));
	tree->item = item;
	tree->left = 0;
	tree->right = 0;
	return (tree);
}
