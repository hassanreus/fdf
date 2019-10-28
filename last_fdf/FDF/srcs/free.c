/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:49:42 by hseffian          #+#    #+#             */
/*   Updated: 2019/10/25 23:55:25 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_tab(void **tab, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		free(tab[i]);
	free(tab);
}

void	suit_free(int **tbl)
{
	free(tbl);
	exit(0);
}
