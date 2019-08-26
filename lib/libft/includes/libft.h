/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:07:39 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:25:47 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>

# define BUFF_SIZE 100
# define ABS(x) ((x) < 0 ? -(x) : (x))

int							g_new_line;
typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

union						u_mytype
{
	char					c;
	double					d;
	unsigned char			uc;
	long long int			lli;
	unsigned long long int	ulli;
};

typedef struct				s_allstr
{
	int						fd;
	int						count;
	char					*color;
	char					*allstr;
}							t_allstr;

typedef struct				s_fl
{
	int						hesh;
	int						zero;
	int						space;
	int						plus;
	int						minus;
	int						precis;
}							t_fl;

typedef enum				e_mod
{
	NOT, hh, h, ll, l, j, z, t, L
}							t_mod;

typedef struct				s_mcon
{
	t_fl					*fl;
	t_mod					mod;
	int						width;
	int						num_prec;
	int						zerocheck;
	int						zerofload;
	int						precfload;
	int						zerocheckminus;
	int						zeroinxo;
	char					con;
	char					dsign;
	char					*sign;
	char					*head;
	char					*point;
	char					*strtmp;
}							t_mcon;

void						ft_putchar(char c);
void						ft_putstr(char const *s);
void						ft_putendl(char const *s);
void						ft_putnbr(int n);
size_t						ft_strlen(const char *str);
char						*ft_strdup(const char *s1);
char						*ft_strcpy(char *dst, const char *src);
int							ft_atoi(const char *str);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_toupper(int c);
int							ft_tolower(int c);
void						*ft_memset(void *b, int c, size_t len);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *dst, const void *src,
																size_t n);
void						*ft_memccpy(void *dst, const void *src,
															int c, size_t n);
void						*ft_memmove(void *dst, const void *src,
																size_t len);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2,
																size_t n);
char						*ft_strncpy(char *dst, const char *src,
																size_t len);
int							ft_strncmp(const char *s1, const char *s2,
																size_t n);
void						ft_strclr(char *s);
void						*ft_memalloc(size_t size);
void						ft_memdel(void **ap);
char						*ft_strnew(size_t size);
void						ft_strdel(char **as);
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char const *s, int fd);
void						ft_putendl_fd(char const *s, int fd);
void						ft_putnbr_fd(int n, int fd);
char						*ft_strcat(char *s1, const char *s2);
char						*ft_strncat(char *s1, const char *s2, size_t n);
size_t						ft_strlcat(char *dst, const char *src,
															size_t dstsize);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
char						*ft_strstr(const char *haystack, const char
																	*needle);
char						*ft_strnstr(const char *haystack,
												const char *needle, size_t len);
void						ft_striter(char *s, void (*f)(char *));
void						ft_striteri(char *s,
											void (*f)(unsigned int, char *));
char						*ft_strmap(char const *s, char (*f)(char));
char						*ft_strmapi(char const *s,
												char (*f)(unsigned int, char));
int							ft_strequ(char const *s1, char const *s2);
int							ft_strnequ(char const *s1, char const *s2,
																	size_t n);
char						*ft_strsub(char const *s, unsigned int start,
																size_t len);
char						*ft_strjoin(char *s1, char *s2);
char						*ft_strtrim(char const *s);
char						**ft_strsplit(char const *s, char c);
char						*ft_itoa(int n);
t_list						*ft_lstnew(void const *content,
														size_t content_size);
void						ft_lstdelone(t_list **alst,
												void (*del)(void*, size_t));
void						ft_lstdel(t_list **alst,
												void (*del)(void*, size_t));
void						ft_lstadd(t_list **alst, t_list *new);
void						ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list						*ft_lstmap(t_list *lst,
												t_list *(*f)(t_list *elem));
int							ft_countword(char const *s, char c);
void						ft_swap(int *a, int *b);
int							ft_sqrt(int nb);
int							ft_isspace(int ch);
char						*ft_itoa_base(int n, int base);
int							get_next_line(const int ft, char **line);
void						ft_lstadd_end(t_list **alst, t_list *new);
char						*ft_strnjoin(char *s1, char *s2, int n);
char						*ft_strndup(const char *s1, int n);

int							ft_printf(const char *format, ...);
char						*ft_collor(char *str, t_allstr *allstr);
char						*ft_print_con(char *str, t_allstr *all,
																va_list argc);
char						*ft_check_mod(char *str, t_mcon *mcon,
																va_list argc);
long double					ft_change_type_f(t_mcon *mcon, va_list argc);
long long int				ft_change_type_d(t_mcon *mcon, va_list argc);
unsigned long long int		ft_change_type_du(t_mcon *mcon, va_list argc);
void						ft_write_f(t_mcon *mcon, long double n);
void						print_prec_width(t_mcon *mcon);
char						*ft_ftoa(long double n, t_mcon *mcon);
char						*ft_str_prec(char *s1, int dot, int end, int hash);
long double					ft_len_f(long double n, int prec, t_mcon *mcon);
void						ft_f_inf(t_mcon *mcon);
void						ft_write_di(t_mcon *mcon, long long n);
void						ft_write_u(t_mcon *mcon, unsigned long long n);
void						ft_write_o(t_mcon *mcon, unsigned long long n);
void						ft_write_x(t_mcon *mcon, unsigned long long n);
void						ft_write_p(t_mcon *mcon, unsigned long long n);
void						ft_write_str(t_mcon *mcon, char *str);
void						ft_write_char(t_mcon *mcon, char c, t_allstr *all);
void						ft_write_date(void);
void						ft_write_r(t_mcon *mcon, int c);
int							ft_strlen_for_print(char *s);
t_list						*ft_lstlinks(void *content, size_t content_size);
void						ft_arreydel(char **str);
int							ft_lstcount(t_list *list);
int							ft_atoi_base(char *str, int base);
int							ft_allsumbl(char *str);
int							ft_allalpha(char *str);
int							ft_allnum(char *str);

#endif
