/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/29 15:00:50 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/27 09:29:06 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_assets
{
	mlx_image_t	*banana;
	mlx_image_t	*home;
	mlx_image_t	*open_home;
	mlx_image_t	*noonoo;
	mlx_image_t	*rice_ball;
	mlx_image_t	*wall;
}t_assets;

typedef struct s_text
{
	mlx_image_t	*move_s;
	mlx_image_t	*move_nb;
	mlx_image_t	*c_nb;
	mlx_image_t	*c_s;
	mlx_image_t	*win_lose;
}t_text;

typedef struct s_game
{
	mlx_t		*mlx;
	char		**s_map;
	t_assets	assets;
	t_assets	old_assets;
	t_text		text;
	t_text		old_text;
	int			rows;
	int			colums;
	int			c_count;
	int			e_count;
	int			p_count;
	int			e_x;
	int			e_y;
	int			move_count;
	int			check_path;
	char		move_d;
	int			loop;
	int			banana;
	int			noonoo;
	int			banana_move;
	int			win_lose;
	int			b_right;
	int			b_left;
	int			b_nb;
}t_game;

char		*read_map(char *map_path);
void		count_rows_colums(char **str, t_game *all);
void		count_c_e_p(char **str, t_game *all);
void		check_count_c_e_p(char c, t_game *all);
mlx_image_t	*xpm_to_image(mlx_t *mlx, char	*img_path);
void		load_assets(t_game *all);
void		delete_old_assets(t_game *all);
void		print_image(t_game *all, int x, int y);
void		print_all_map(t_game *all);
int			open_image(char	*str);
void		move_up(t_game *all);
void		move_down(t_game *all);
void		move_left(t_game *all);
void		move_right(t_game *all);
int			check_flag(t_game *all, char *c1, char *c2);
void		key_hook_move(mlx_key_data_t key, void *tmp);
void		print_error(t_game *all, char *str);
void		check_error(t_game *all, char *map);
void		free_smap(t_game *all);
void		check_wall(t_game *all);
void		check_path_flag(t_game *all, int x, int y);
void		check_path(t_game *all);
void		enemy_animation(t_game *all);
void		animation_banana(t_game *all);
void		animation_noonoo_w(t_game *all);
void		animation_noonoo_d(t_game *all);
void		animation_noonoo_a(t_game *all);
void		animation_noonoo_s(t_game *all);
void		banana_move(t_game *all);
void		put_str_on_window(t_game *all);
void		put_sting(t_game *all);
void		delete_string(t_game *all);
void		swap_x(t_game *all, char *c1, char *c2, int i);
void		check_flag_utils(t_game *all);
void		put_string_utils(t_game *all);
void		banana_move_utils(t_game *all, int x, int y);

#endif
