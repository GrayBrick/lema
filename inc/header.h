/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:07:38 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/20 20:24:29 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct		s_gen
{
	int				ants;
	int				sum;
	int				s;
	int				e;
	int				mem;
	int				minway;
	int				x;
}					t_gen;

t_gen				g_gen;

typedef struct		s_cell
{
	int				i;
	short			isant;
	char			*name;
	int				*near;
	int				*block;
	int				wei;
	int				len;
	int				p;
}					t_cell;

typedef struct		s_ant
{
	int				i;
	int				*way;
	int				*iway;
}					t_ant;

typedef	struct		s_a
{
	int				now;
	int				be;
}					t_a;

int					iinarr(int *arr, int a);
t_cell				*delstruct(t_cell *cell, int f);

int					iinarr(int *arr, int a);
int					isnear(t_cell *cells, int a, int b);
void				change_p(t_cell *cells, int m);
void				dij(t_cell *cells, int m);
t_ant				*gant(t_ant *ants, int x, t_cell *cells);

int					getm(t_cell *cells, t_ant *ants, int x, int f);
int					*getcell(t_cell *cells, char *s1, char *s2);
void				copy(t_cell *cells, t_cell *ccell);
t_cell				*addmem(t_cell *cells, char *str);
void				cont(int f);

t_cell				*rem(t_cell *cells, int f, char **str);
t_cell				*rem1(t_cell *cells, int *f, char *str);
t_cell				*rem2(t_cell *cells, int *f, char **str);
int					phelp(char *str);
t_cell				*rem3(t_cell *cells, int s, char *str);

t_cell				*rem4(t_cell *cells, int *s, char *str);
t_cell				*rem5(t_cell *cells, int s, char *str);
t_ant				*cemr(t_ant *ants, int x, int *m, t_cell *cells);
t_cell				*getce(t_cell *cells, int x);
t_cell				*getr(t_cell *cells);

char				*cpytmp(char **str);
void				printant(int x, char *name);
int					isvalidstr(char *str);
void				start(t_cell *cells);

void				alga(t_cell *cells);
int					setcell(char *str, t_cell *cells);
int					*getcell(t_cell *cells, char *s1, char *s2);
char				*getar(char *str, int i, char c);
int					isant(char *str, int i);
int					isroom(char *str);
int					iscon(char *str);
int					dellist(char **str);
t_cell				*getstr(t_cell *cells);

#endif
