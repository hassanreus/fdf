/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 00:12:18 by hseffian          #+#    #+#             */
/*   Updated: 2019/10/25 15:59:51 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_init_var(t_mlx *mlx)
{
	mlx->bonus.projection = 1;
	mlx->bonus.left = 0;
	mlx->bonus.right = 0;
	mlx->bonus.up = 0;
	mlx->bonus.down = 0;
	mlx->bonus.zoom = 0.5;
	mlx->bonus.h = 1;
}

void	open_wind(t_mlx *mlx)
{
	if (mlx->first_nbc >= 200)
	{
		mlx->bonus.windowx = 3500;
		mlx->bonus.windowy = 3700;
	}
	else
	{
		mlx->bonus.windowx = mlx->first_nbc * 28;
		mlx->bonus.windowy = mlx->nbl * 30;
	}
	mlx->win = mlx_new_window(mlx->ptr, mlx->bonus.windowx
			, mlx->bonus.windowy, "fdf");
}

int		main(int ac, char **av)
{
	t_mlx mlx;
	t_fdf fdf;

	if (ac != 2)
		ft_putstr("usage: ./fdf file\n");
	else
	{
		mlx.ptr = mlx_init();
		mlx_init_var(&mlx);
		get_pos_z(&mlx, &fdf, av[1]);
		open_wind(&mlx);
		draw(&mlx);
		mlx_key_hook(mlx.win, keyhooks, &mlx);
		close(fdf.fd);
		mlx_loop(mlx.ptr);
	}
	return (0);
}
