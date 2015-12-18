/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_grille.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:04:26 by dlouise           #+#    #+#             */
/*   Updated: 2015/12/06 18:04:30 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		compter_nb_pieces(t_list *pieces)
{
	int n;

	n = 0;
	while (pieces)
	{
		pieces = pieces->next;
		n++;
	}
	return (n);
}

int		taille_debut(int nb_pieces)
{
	if (nb_pieces >= 26)
		return (11);
	if (nb_pieces >= 21)
		return (10);
	if (nb_pieces >= 17)
		return (9);
	if (nb_pieces >= 13)
		return (8);
	if (nb_pieces >= 10)
		return (7);
	if (nb_pieces >= 7)
		return (6);
	if (nb_pieces >= 5)
		return (5);
	if (nb_pieces >= 3)
		return (4);
	if (nb_pieces >= 2)
		return (3);
	if (nb_pieces >= 1)
		return (2);
	return (0);
}

void	initialiser_grille(t_grille *grille)
{
	int		i;
	int		j;

	grille->taille = 1;
	i = 0;
	while (i < 32)
	{
		grille->map[i] = 0;
		i++;
	}
	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < 32)
		{
			grille->reponse[j][i] = '.';
			i++;
		}
		j++;
	}
}
