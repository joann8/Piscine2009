/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:39:22 by jacher            #+#    #+#             */
/*   Updated: 2020/09/28 15:08:55 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <libgen.h>
# include <sys/errno.h>
# include <strings.h>
# include <stdlib.h>

void	print_name(char *name);
int		check_n(char *str);
int		find_n(char **av, int *ptr);
void	print_error(int errnum, char *name);
int		check_slash_points(char *av, int start, int ac, int pos);
void	print_error_arg(void);
void	print_error_option(int ac, char *av);
void	print_error(int errnum, char *name);
int		check_arg(int ac, char **av);
int		check_arg_three(int ac, char **av);
int		check_arg_two(int ac, char **av);
int		check_arg_one(void);
void	run_tail(int ac, char **av, int i, int n);
void	cat(int fd, char *av, int n, int diff);

#endif
