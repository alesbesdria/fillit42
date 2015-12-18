/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:25:44 by dlouise           #+#    #+#             */
/*   Updated: 2015/12/06 18:27:23 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		dessiner_grille(t_grille *grille)
{
	int		i;
	int		j;

	j = 0;
	while (j < grille->taille)
	{
		i = 0;
		while (i < grille->taille)
		{
			write(1, &grille->reponse[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

static void	ecrire_reponse(t_grille *grille, t_tetrimino *piece, int x, int y)
{
	int		ix;
	int		iy;

	iy = 0;
	while (iy < 4)
	{
		ix = 0;
		while (ix < 4)
		{
			if ((piece->map[iy] & (1 << (31 - ix))))
				grille->reponse[y + iy][x + ix] = piece->lettre;
			ix++;
		}
		iy++;
	}
}

static int	reserver(t_grille *grille, t_tetrimino *piece, int x, int y)
{
	t_tetrimino	piece_place;

	piece_place.map[0] = piece->map[0] >> x;
	piece_place.map[1] = piece->map[1] >> x;
	piece_place.map[2] = piece->map[2] >> x;
	piece_place.map[3] = piece->map[3] >> x;
	if (!(grille->map[y + 0] & piece_place.map[0]
				|| grille->map[y + 1] & piece_place.map[1]
				|| grille->map[y + 2] & piece_place.map[2]
				|| grille->map[y + 3] & piece_place.map[3]))
	{
		grille->map[y + 0] |= piece_place.map[0];
		grille->map[y + 1] |= piece_place.map[1];
		grille->map[y + 2] |= piece_place.map[2];
		grille->map[y + 3] |= piece_place.map[3];
		return (1);
	}
	return (0);
}

static void	liberer(t_grille *grille, t_tetrimino *piece, int x, int y)
{
	t_tetrimino	piece_place;

	piece_place.map[0] = piece->map[0] >> x;
	piece_place.map[1] = piece->map[1] >> x;
	piece_place.map[2] = piece->map[2] >> x;
	piece_place.map[3] = piece->map[3] >> x;
	grille->map[y + 0] &= ~piece_place.map[0];
	grille->map[y + 1] &= ~piece_place.map[1];
	grille->map[y + 2] &= ~piece_place.map[2];
	grille->map[y + 3] &= ~piece_place.map[3];
}

int			solution(t_grille *grille, t_list *pieces)
{
	int		x;
	int		y;

	if (NULL == pieces)
		return (1);
	y = 0;
	while (y <= grille->taille - ((t_tetrimino*)pieces->content)->hauteur)
	{
		x = 0;
		while (x <= grille->taille - ((t_tetrimino*)pieces->content)->largeur)
		{
			if (reserver(grille, (t_tetrimino*)pieces->content, x, y))
			{
				if (solution(grille, pieces->next))
				{
					ecrire_reponse(grille, (t_tetrimino*)pieces->content, x, y);
					return (1);
				}
				liberer(grille, (t_tetrimino*)pieces->content, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
