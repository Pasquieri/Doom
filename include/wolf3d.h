/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:13:49 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/20 15:34:48 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define FLOOR 0
# define W_GRAY 1
# define W_WHITE 2
# define W_BLUE 3
# define W_G_TAB 4
# define W_W_TAB 5
# define W_B_TAB 6
# define WIN 7
# define BEGIN 8
# define DOOR 9
# define GRID 10
# define END 11
# define COLUMN 12
# define BANANA 13
# define MONKEY 14

typedef struct	s_coord
{
	double	x;
	double	y;
	int		nb;
}				t_coord;

typedef struct	s_cercle
{
	int		rayon;
	int		color;
	t_coord	coord;
}				t_cercle;

typedef struct	s_coef
{
	int		x;
	int		y;
}				t_coef;

typedef struct	s_fill
{
	char	*line;
	char	**tmp;
	int		nb_char;
	int		verif;
	int		i;
	int		j;
	int		nb_sol;
	int		k;
}				t_fill;

typedef struct	s_rgb
{
	int		b;
	int		g;
	int		r;
	int		a;
}				t_rgb;

typedef struct	s_color_menu
{
	int		black_color;
	int		red_color;
	int		play_color;
	int		exit_color;
	int		map1_color;
	int		map2_color;
	int		map3_color;
	int		map4_color;
}				t_color_menu;

typedef struct	s_mlx
{
	void	*img;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		end;
	int		width;
	int		height;
}				t_mlx;

typedef struct	s_inv
{
	int		lim_gun[5];
	_Bool	gun;
}				t_inv;

typedef struct	s_spr t_spr;
struct	s_spr
{
	t_coord	coord;
	int		nb;
	t_spr	*next;
};

typedef struct	s_lst
{
	t_spr	*first;
}				t_lst;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_mlx	m[2];

	int		coef;
	int		x;
	int		y;
	int		**tab;
	int		d_regard;
	double	angle;
	double	perso_x;
	double	perso_y;
	int		perso_r;
	int		x_init; // a supp
	int		y_init; // a supp 
	double	vitesse;
	int		musique;

	int		detail;
	int		menu;
	int		menu_select;
	int		map_entree;

	int		nb_colonne;
	float	d_ecran;
	int		h_mur;
	t_coord	coord_mur;
	int		wall_nb;
	int		img_x;
	int		h_regard;
	float	lim;
	int		orientation; // cardinaux texture a supp
	int		lum;
	int		lum_int;

	float	lim_sol; // test
	double	h_ref; // test

	t_rgb	rgb[10];
	t_mlx	text[25];
	t_mlx	sp[7];
	t_spr	*spr;
	t_lst	first;
	int		sprite_on;

	t_inv	inv;
	_Bool	key[604];
}				t_env;

int				recup_music(char *str);
void			exec_calcul(t_env *env, int d_regard, int init);
void			arrow_menu(t_env *env);
void			key_invalid_menu(t_env *env);
void			key_valid_menu(t_env *env);
int				trig_press(t_env *env);
int				key_press(int key, t_env *env);
int				key_release(int key, t_env *env);
int				key_apply(t_env *env);
void			rotation_regard(t_env *env);
int				win_init(t_env *env);
int				motion_notify(int x, int y, t_env *env);
int				re_pars(char *str, t_env *env);
int				check_open_map(char *map, int fd, t_env *env);
int				check_file(int	fd, t_env *env);
int				recup_info_player(char *str, char c);
int				verif_valeur(char *str, t_env *env);
int				malloc_tab(t_env *env);
int				fill_tab(int fd, t_env *env);
int				tablen(char **str);
int				verif_char(char *str, t_env *env);
int				error_message(int num, t_env *env);
void			open_menu(t_env *env);
int				pars_init(int argc, char **argv, t_env *var_check);
void			init_env(t_env *env);
void			init_rgb(t_env *env);
int				ft_trace_seg(t_env *env, t_coord coord1, t_coord coord2);
void			quadrillage(t_env *env);
void			put_pxl_img(t_env *env, int x, int y, int color);
void			clean_img(t_env *env);
void			color_case(t_env *env);
void			print_cercle(t_env *env);
double			detection_mur(t_env *env);
int				init_var_hor(t_env *env, double *ya, double *xa, t_coord *c1);
int				coef_hor(t_env *env, int *coef_x, int *coef_y);
int				verif_hor(t_env *env, t_coord *coord);
int				init_var_ver(t_env *env, double *ya, double *xa, t_coord *c2);
int				coef_ver(t_env *env, int *coef_x, int *coef_y);
int				verif_ver(t_env *env, t_coord *coord);
int				intersection_horizontal(t_env *env, t_coord *cd);
int				intersection_vertical(t_env *env, t_coord *cd);
void			affichage_mur(t_env *env);
char			luminosite(int text, int coef);
void			deplacements(t_env *env);
void			depla_horizontal(t_env *env, int key);
void			depla_vertical(t_env *env, int key);
void			put_texture_img(t_env *env, double h_per, int y, t_mlx *text);
void			init_texture(t_env *env);
void			init_sprite(t_env *env);
void			print_sprite(t_env *env);
void			print_gun(t_env *env, int k);
//void			lstadd(t_spr **first, t_spr *nw);

int				wall_line(char *str, t_env *env);
int				wall_row(char *str, int nb_char, t_env *env);
int				compte_char(char *str, char c);

#endif
