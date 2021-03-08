/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_places.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:48:17 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/14 15:06:25 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_PLACES_H
# define CHECK_PLACES_H

int		check_norm_col(int tab[6][6]);

int		check_rev_col(int tab[6][6]);

int		check_norm_row(int tab[6][6]);

int		check_rev_row(int tab[6][6]);

int		is_possible(int tab[6][6], int col, int row, int place);

#endif
