/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chargement_pieces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:20:47 by dlouise           #+#    #+#             */
/*   Updated: 2015/12/06 19:43:07 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "uniformisation_tetriminos.h"

static int			lire(int fd, char *buffer, int nb)
{
	int i;

	i = 0;
	while (i < nb && (1 == read(fd, &buffer[i], 1)))
	{
		i++;
	}
	return (i);
}

static t_tetrimino	*creer_tetrimino(char tetri[20])
{
	t_tetrimino	*tetrimino;

	tetrimino = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	tetrimino->map[0] = ((tetri[0] == '#') ? (1 << 31) : 0);
	tetrimino->map[0] |= ((tetri[1] == '#') ? (1 << 30) : 0);
	tetrimino->map[0] |= ((tetri[2] == '#') ? (1 << 29) : 0);
	tetrimino->map[0] |= ((tetri[3] == '#') ? (1 << 28) : 0);
	tetrimino->map[1] = ((tetri[5] == '#') ? (1 << 31) : 0);
	tetrimino->map[1] |= ((tetri[6] == '#') ? (1 << 30) : 0);
	tetrimino->map[1] |= ((tetri[7] == '#') ? (1 << 29) : 0);
	tetrimino->map[1] |= ((tetri[8] == '#') ? (1 << 28) : 0);
	tetrimino->map[2] = ((tetri[10] == '#') ? (1 << 31) : 0);
	tetrimino->map[2] |= ((tetri[11] == '#') ? (1 << 30) : 0);
	tetrimino->map[2] |= ((tetri[12] == '#') ? (1 << 29) : 0);
	tetrimino->map[2] |= ((tetri[13] == '#') ? (1 << 28) : 0);
	tetrimino->map[3] = ((tetri[15] == '#') ? (1 << 31) : 0);
	tetrimino->map[3] |= ((tetri[16] == '#') ? (1 << 30) : 0);
	tetrimino->map[3] |= ((tetri[17] == '#') ? (1 << 29) : 0);
	tetrimino->map[3] |= ((tetri[18] == '#') ? (1 << 28) : 0);
	mettre_en_haut_a_gauche(tetrimino);
	tetrimino->largeur = calculer_largeur(tetrimino);
	tetrimino->hauteur = calculer_hauteur(tetrimino);
	return (tetrimino);
}

static t_list		*inscrire_lettres(t_list *pieces)
{
	char	c;
	t_list	*liste;

	liste = pieces;
	c = 'A';
	while (pieces)
	{
		((t_tetrimino*)pieces->content)->lettre = c;
		c++;
		pieces = pieces->next;
	}
	return (liste);
}

t_list				*charger_pieces(char *fichier)
{
	int			fd;
	char		tetrimino[21];
	t_list		*premier_tetrimino;
	t_list		*dernier_tetrimino;
	t_tetrimino	*new_tetrimino;

	dernier_tetrimino = malloc(sizeof(t_list));
	if (NULL == dernier_tetrimino)
		return (NULL);
	premier_tetrimino = dernier_tetrimino;
	if (-1 == (fd = open(fichier, O_RDONLY)))
		return (NULL);
	while (20 == lire(fd, tetrimino, 20))
	{
		new_tetrimino = creer_tetrimino(tetrimino);
		dernier_tetrimino->next = ft_lstnew(new_tetrimino, sizeof(t_tetrimino));
		free(new_tetrimino);
		dernier_tetrimino = dernier_tetrimino->next;
		if (0 == read(fd, &tetrimino[20], 1))
			return (inscrire_lettres(premier_tetrimino->next));
	}
	return (NULL);
}
