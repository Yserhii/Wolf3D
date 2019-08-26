/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:49:35 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/09 16:49:37 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF_H
# define FT_WOLF_H

# define X_MASK 0
# define WIN_WIDTH 1080
# define WIN_HEIGHT 1080

# define ESC 53
# define MOVE_FORWARD 126
# define MOVE_BACKWARD 125
# define MOVE_RIGHT 124
# define MOVE_LEFT 123
# define BEER 14
# define WALKING_LEFT 0
# define WALKING_RIGTH 2
# define MOVE_SLOW 257
# define MENU_UP 126
# define MENU_DOWN 125
# define MENU_SELECT 36

# define POS_X wolf->vect->pos_x
# define POS_Y wolf->vect->pos_y
# define DIR_X wolf->vect->dir_x
# define DIR_Y wolf->vect->dir_y
# define MOVE_SPEED wolf->vect->move_speed
# define TURN_SPEED wolf->vect->turn_speed
# define PLANE_X wolf->vect->plane_x
# define PLANE_Y wolf->vect->plane_y

# include <mlx.h>
# include <math.h>
# include <libft.h>

typedef	struct		s_coor
{
	int				x;
	int				y;
}					t_coor;

typedef	struct		s_img
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*ptr;
	char			*addr;
	int				w;
	int				h;
	int				w_cel;
	int				h_cel;
	int				w_menu;
	int				h_menu;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_color;

typedef struct		s_vect
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			turn_speed;
}					t_vect;

typedef struct		s_vis
{
	int				floor_tex_x;
	int				floor_tex_y;
	int				tex_num;
	int				tex_x;
	int				tex_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			turn;
	double			old_dir_x;
	double			old_plane_x;
	double			weight;
	double			dist_wall;
	double			dist_player;
	double			current_dist;
	double			floor_x_wall;
	double			floor_y_wall;
	double			current_floor_x;
	double			current_floor_y;
	double			wall_x;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
}					t_vis;

typedef	struct		s_wolf
{
	t_img			*img;
	t_vect			*vect;
	t_vis			vis;
	void			*texturs[11];
	char			*texturs_addr[11];
	void			*menu[7];
	char			*menu_addr[7];
	int				fd;
	int				menu_flag;
	int				menu_index;
	int				map_flag;
	int				x_map;
	int				y_map;
	int				**map;
	int				color;
	int				mouse_x;
	int				beer;
}					t_wolf;

void				ft_error(int n);
void				menu();
void				open_tex_for_menu(t_wolf *wolf);
void				select_read_map(t_wolf *wolf);
void				key_init(t_wolf *wolf);
void				read_map(int fd, t_wolf *wolf);
void				visual(t_wolf *wolf);
void				draw(t_wolf *wolf);
void				print_with_text(t_wolf *wolf, int x);
void				print_floor_ceiling(t_wolf *wolf, int x);
void				print_one_pixel(double x, double y, t_wolf *wolf);
void				choose_wall_color(t_wolf *wolf);
int					key(int keycode, t_wolf *wolf);

#endif
