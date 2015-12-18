/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture_fichier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:47:31 by dlouise           #+#    #+#             */
/*   Updated: 2015/12/15 14:44:47 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		nb_carres_adjacents(char tetriminos[4][4], int i, int j)
{
	if (i < 0 || i >= 4 || j < 0 || j >= 4)
		return (0);
	if ('#' == tetriminos[i][j])
	{
		tetriminos[i][j] = '*';
		return (1
				+ nb_carres_adjacents(tetriminos, i - 1, j)
				+ nb_carres_adjacents(tetriminos, i + 1, j)
				+ nb_carres_adjacents(tetriminos, i, j - 1)
				+ nb_carres_adjacents(tetriminos, i, j + 1));
	}
	return (0);
}

static int		sans_residu(char tetriminos[4][4])
{
	int		i;
	int		j;
	int		nb_etoiles;

	i = 0;
	j = 0;
	nb_etoiles = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if ('*' == tetriminos[i][j])
				nb_etoiles++;
			else if ('.' != tetriminos[i][j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (4 == nb_etoiles);
}

static int		tetriminos_verifie(char tetriminos[4][4])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if ('#' == tetriminos[i][j])
			{
				if (4 == nb_carres_adjacents(tetriminos, i, j))
					return (sans_residu(tetriminos));
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int		tetriminos_valide(int fd)
{
	int		i;
	char	c;
	char	tetriminos[4][4];

	i = 0;
	while (i < 4 && 4 == read(fd, tetriminos[i], 4))
	{
		if (1 != read(fd, &c, 1) || '\n' != c)
		{
			close(fd);
			return (0);
		}
		i++;
	}
	if (4 != i)
	{
		close(fd);
		return (0);
	}
	return (tetriminos_verifie(tetriminos));
}

int				parametre_invalide(int argc, char **argv)
{
	int		fd;
	char	c;
	int		compteur;

	if (2 != argc)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (-1 == fd)
		return (1);
	compteur = 0;
	while (tetriminos_valide(fd) && ++compteur <= 26)
	{
		if (0 == read(fd, &c, 1))
		{
			close(fd);
			return (0);
		}
		if ('\n' != c)
		{
			close(fd);
			return (1);
		}
	}
	close(fd);
	return (1);
}
