# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yserhii <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 11:51:56 by yserhii           #+#    #+#              #
#    Updated: 2018/12/11 14:13:14 by yserhii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_head.c ft_lstdel.c\
		ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c\
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c\
		ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c\
		ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
		ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
		ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
		ft_tolower.c ft_toupper.c ft_countword.c ft_swap.c ft_sqrt.c ft_isspace.c\
		get_next_line.c ft_lstadd_end.c ft_itoa_base.c ft_strnjoin.c ft_strndup.c\
		ft_printf.c ft_collor.c ft_print_con.c ft_check_mod.c ft_change_type.c\
		ft_write_f.c ft_ftoa.c ft_write_di.c ft_write_u.c ft_write_o.c\
		ft_write_x.c ft_write_p.c ft_write_str.c ft_write_char.c ft_floadadd.c\
		ft_f_nan_ifn.c ft_write_date.c ft_write_r.c ft_lstlink.c ft_arreydel.c\
		ft_lstcount.c ft_atoi_base.c ft_allalpha.c ft_allnum.c ft_allsumbl.c

INCL = includes

SRCO = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCO)

	@ar rc $(NAME) $(SRCO)

%.o: %.c
	@clang -I$(INCL) $(FLAG) -o $@ -c $<

clean:
		@rm -f $(SRCO)

fclean: clean
		@rm -f $(NAME)

re: fclean all
