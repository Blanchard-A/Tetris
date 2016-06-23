/*
** tetris.h for tetris in /home/brunel_d/rendu/sem_2/syst_unix/tetris/include
**
** Made by axel brunel
** Login   <brunel_d@epitech.net>
**
** Started on  Mon Feb 29 12:15:00 2016 axel brunel
** Last update Thu Jun 23 11:57:31 2016 Alexandre
*/

#ifndef TETRIS_H_
# define TETRIS_H_
# define UNUSED __attribute__((__unused__))

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
/* #include <ncurses/curses.h> */
#include <dirent.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <termios.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct		s_parameter
{
  int			level;
  char			*left;
  char			*right;
  char			*turn;
  char			*drop;
  char			*quit;
  char			*pause;
  int			map_x;
  int			map_y;
  int			hide_next;
  int			line_suppr;
  int			color_tempo;
  int			debug_mode;
  int			next;
  int			score;
  int			h_score;
}			t_parameter;

typedef struct		s_tetri
{
  int			in_map;
  int			error;
  int			height;
  int			width;
  int			color;
  char			*form;
  char			**form2d;
  char			*name;
  char			*dos;
  char			*path;
}			t_tetri;

typedef struct		s_tetriminos
{
  int			good;
  int			num;
  t_tetri		*tetri;
}			t_tetriminos;

int	mode_spe(int);
int	mode(int, t_parameter *);
void	param_size_base(t_parameter *);
void	config_param(t_parameter *, char *const envp[]);
char	*my_termname(char *const envp[]);
char	*get_termname_env(char *const envp[]);
int	compare_str(char *, char *);
int	check_column(int **, t_parameter *, int);
int	check_end_fall(int **, t_parameter *);
int	verif_droite(int **, t_parameter *);
int	verif_possible_turn(int **, int, int, t_parameter *);
void	pause_utilisateur(char *, int **, t_parameter *);
void	drop(char *, int **, t_parameter *);
void	right(char *, int **, t_parameter *);
void	turn(char *, int **, t_parameter *);
void	left(char *, int **, t_parameter *);
void	fall_tetri_tab_spe(int **, t_parameter *, int);
void	epur_map(int **, t_parameter *);
int	check_epur(int **, t_parameter *, int);
char	*get_move(char *, int **, t_parameter *);
void	effect_turn(int **, char **, t_parameter *, int);
void	exit_error(char **, int);
int	option_error(char **, char **);
void	get_option(t_parameter *, char **);
int	get_size_l(int **, t_parameter *);
int	get_size_h(int **, t_parameter *);
int	get_pos_start_turn_j(int **, t_parameter *);
int	get_pos_start_turn_i(int **, t_parameter *);
void	boucle_tetris(t_parameter *, t_tetriminos *, int **);
void	adjust_param_user(char *, int, int);
int	get_hscore();
void	all_rest(t_parameter *, t_tetriminos *, int **);
void	my_putstr_fd(int, char *);
void	MaJ_hscore(t_parameter *);
void	else_boucle_tetris(t_parameter *, t_tetriminos *, int **);
void	adjust_struct_user(t_parameter *);
void	press_key();
void	put_in_options(char *, char *);
char	**get_malloc_options(char **);
char	**possible_option();
char	*recup_arg(char *, char *);
int	get_j_to_options(char **, char *);
void	kick_last_form(int **, t_parameter *);
void	get_tempo_color(int **, t_parameter *);
void	my_put_zero(char *, int);
void	put_tempo_form(char **, int **, int, t_parameter *);
char	**get_tempo_form(int **, int, int, t_parameter *);
char	*my_getch();
void	change_val_tab(int **, t_parameter *);
int	move_end(int **, t_parameter *);
int	verif_cores_pt_func(char *, char *);
char	*my_cpy(char *);
int	if_neg(int, char *, int);
int	my_getnbr(char *);
int	count_nbr_inter(int);
void	econom(int, char *, int);
int	my_putnbr_fd(int, int, int);
char	*my_revstr(char *);
void	clear_next(t_parameter *);
void	print_color(int, int, int);
void	show_next(t_tetri *, t_parameter *);
int	get_next_form(t_tetriminos *);
void	put_interface(t_parameter *);
void	put_cadre_score();
void	put_next();
void	verif_dimension(t_parameter *);
void	config_term(t_parameter *);
void	show_tetris_map(int **, t_parameter *, int);
void	fall_tetri_tab(int **, t_parameter *);
void	add_new_tetri_tab(int **, t_tetri *, t_parameter *);
void	end_tetris(t_parameter *);
void	my_putchar_fd(int, char);
void	show_map(int **);
int	**malloc_tab(int **, t_parameter *);
int	**tab_in_frame(int **, t_parameter *);
int	**get_tab(int **, t_parameter *);
int	tab_ch(char **, t_parameter *);
int	tab_func(void (**)(char *, int **, t_parameter *));
void	doble_tiret(t_parameter *, char *, int);
void	simple_tiret(t_parameter *, char *, int);
void	help_mode(char **);
void	tiret_empty(t_parameter *, int, char **);
void	affect_options(char **, t_parameter *, char **);
void	put_T();
void	put_I();
void	put_R();
void	put_T_bis();
void	put_E();
void	put_S();
void	get_truekey(char *, char *);
void	poub_zero(char *, char *);
void	resize_map(t_parameter *, char *, int, int);
void	truekey_ok(char *, char *);
int	check_left_deplacement(int **, t_parameter *, int);
int	check_right_deplacement(int **, t_parameter *, int);
int	check_left_fall(int **, t_parameter *);
int	check_right_fall(int **, t_parameter *);
void	my_putstr(char *);
void	my_putchar(char);
int	my_strlen(char *);
int	setupterm(char *, int, int *);
int	my_printf(const char *, ...);
int	my_strcmp_spe(char *, char *);
int	how_many_files();
int	the_check(char *, t_tetri *, int, int);
int	check_good_dim(t_tetri *);
int	check_all_good(t_tetriminos *);
t_tetri	*create_struct(t_tetriminos *, t_parameter *, int);
void	check_carac(char *);
int	last_star(char *);
int	bigger_name(t_tetriminos *);
char	**rempli_name(char **, t_tetriminos *);
int	my_strcmp_value(char *, char *);
char	**tri_tab(char **, int);
char	**in_order(t_tetriminos *);
char	*my_strcat_spe(char *, char *);
int	my_strlen(char *);
void	print_key(t_parameter *);
void	print_form(t_tetriminos *, int);
void	check_error_print(t_tetriminos *, int);
void	print_tetri(t_tetriminos *, char **);
void	debug_mode(t_tetriminos *, t_parameter *);
int	check_espace(char *, int);
t_tetri	*in_the_form(char *, t_tetri *, int);
int	check_file(char *);
int	check_in_map(t_tetri *, t_parameter *);
char	*my_realloc(char *, int);
char	**my_malloc(char **, int, int);
char	*recup_all(char *);
void	envoi_struct(char *, int, t_tetri *);
void	in_struct(char *, t_tetri *);
char	**my_str_to_word_tab(char *, char **, int, int);
int	check(t_tetri *, t_parameter *);
void	print_name(char *);

#endif /* !TETRIS_H_ */
