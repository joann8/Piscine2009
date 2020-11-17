/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:53:47 by jacher            #+#    #+#             */
/*   Updated: 2020/09/20 17:54:37 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>

void	board_init_0(int board[6][6]);
int		board_init_argv_lines(char *argv, int board[6][6]);
void	board_init_argv_col(char *argv, int board[6][6], int k);
void	init_big_tab(int big_tab[24][4]);
int		solve(int board[6][6], int big_tab[24][4], int row);
int		check_inputs(char *argv);
int		line_is_valid_left(int row, int board[6][6]);
int		line_is_valid_right(int row, int board[6][6]);
int		columns_are_valid(int row, int board[6][6]);
int		column_is_valid_up(int row, int board[6][6]);
int		column_is_valid_down(int row, int board[6][6]);
void	print(int board[6][6]);
void	assign(int board[6][6], int big_tab[24][4], int row, int cmb);
void	placement(int tab[4], int col, int *count, int big_tab[24][4]);
int		check(int tab[4], int col, int k);
void	print_rec(int tab[4], int *count, int big_tab[24][4]);

#endif
