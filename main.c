/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 20:17:04 by dlouise           #+#    #+#             */
/*   Updated: 2015/12/07 01:16:13 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del(void *mem, size_t n)
{
	mem = (void*)mem;
	n = (size_t)n;
}

int		main(int argc, char **argv)
{
	t_grille	grille;
	t_list		*pieces;
	int			nb_pieces;

	if (parametre_invalide(argc, argv))
	{
		write(1, "error\n", 6);
		return (0);
	}
	initialiser_grille(&grille);
	pieces = charger_pieces(argv[1]);
	nb_pieces = compter_nb_pieces(pieces);
	grille.taille = taille_debut(nb_pieces);
	while (!solution(&grille, pieces))
	{
		grille.taille++;
	}
	dessiner_grille(&grille);
	ft_lstdel(&pieces, del);
	return (0);
}
