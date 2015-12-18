/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:58:34 by dlouise           #+#    #+#             */
/*   Updated: 2015/12/15 15:12:47 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_grille
{
	int				taille;
	unsigned int	map[32];
	char			reponse[32][32];
}					t_grille;

typedef struct		s_tetrimino
{
	char			lettre;
	int				largeur;
	int				hauteur;
	unsigned int	map[4];
}					t_tetrimino;

int					parametre_invalide(int argc, char **argv);
void				dessiner_grille(t_grille *grille);
void				initialiser_grille(t_grille *grille);
t_list				*charger_pieces(char *fichier);
int					solution(t_grille *grille, t_list *liste_tetriminos);
int					compter_nb_pieces(t_list *pieces);
int					taille_debut(int nb_pieces);

#endif
