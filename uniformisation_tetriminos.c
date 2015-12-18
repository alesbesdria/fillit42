/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniformisation_tetriminos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:07:01 by dlouise           #+#    #+#             */
/*   Updated: 2015/12/06 18:08:11 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	mettre_en_haut_a_gauche(t_tetrimino *tetrimino)
{
	while (0 == tetrimino->map[0])
	{
		tetrimino->map[0] = tetrimino->map[1];
		tetrimino->map[1] = tetrimino->map[2];
		tetrimino->map[2] = tetrimino->map[3];
		tetrimino->map[3] = 0;
	}
	while (!(tetrimino->map[0] >> 31 || tetrimino->map[1] >> 31
				|| tetrimino->map[2] >> 31 || tetrimino->map[3] >> 31))
	{
		tetrimino->map[0] <<= 1;
		tetrimino->map[1] <<= 1;
		tetrimino->map[2] <<= 1;
		tetrimino->map[3] <<= 1;
	}
}

int		calculer_largeur(t_tetrimino *tetrimino)
{
	unsigned int ombre;

	ombre = tetrimino->map[0] | tetrimino->map[1]
		| tetrimino->map[2] | tetrimino->map[3];
	if (ombre == 0xf0000000)
		return (4);
	if (ombre == 0xe0000000)
		return (3);
	if (ombre == 0xc0000000)
		return (2);
	return (1);
}

int		calculer_hauteur(t_tetrimino *tetrimino)
{
	if (tetrimino->map[3])
		return (4);
	if (tetrimino->map[2])
		return (3);
	if (tetrimino->map[1])
		return (2);
	return (1);
}
