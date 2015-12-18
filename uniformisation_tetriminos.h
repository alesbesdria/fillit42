/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniformisation_tetriminos.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:11:06 by dlouise           #+#    #+#             */
/*   Updated: 2015/12/06 18:11:21 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIFORMISATION_TETRIMINOS_H
# define UNIFORMISATION_TETRIMINOS_H

void	mettre_en_haut_a_gauche(t_tetrimino *tetrimino);
int		calculer_largeur(t_tetrimino *tetrimino);
int		calculer_hauteur(t_tetrimino *tetrimino);

#endif
