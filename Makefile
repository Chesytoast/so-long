# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 17:11:40 by mcourtin          #+#    #+#              #
#    Updated: 2023/01/20 13:51:02 by mcourtin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
DIR = srcs/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iminilibx 
LDFLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

SRCS =  srcs/main.c srcs/map.c srcs/error.c srcs/ft_split.c srcs/utils.c \
		srcs/map_verif.c srcs/window_management.c srcs/player_move.c \
		srcs/win.c srcs/event.c srcs/clean.c srcs/path_finding.c

SRCS_B = bonus/clean_bonus.c bonus/error_bonus.c bonus/event_bonus.c \
		 bonus/ft_split_bonus.c bonus/main_bonus.c bonus/map_bonus.c \
		 bonus/map_verif_bonus.c bonus/path_finding_bonus.c \
		 bonus/player_move_bonus.c bonus/replace_player_bonus.c \
		 bonus/utils_bonus.c bonus/win_bonus.c bonus/window_management_bonus.c \
		bonus/ft_itoa.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C minilibx	
	$(CC) $^ $(LDFLAGS) -o $@

$(NAME_BONUS): $(OBJS_B)
	make -C minilibx
	$(CC) $^ $(LDFLAGS) -o $@

clean:
	rm -f $(OBJS) $(OBJS_B)

better: all clean

bonus : $(NAME_BONUS)

fclean: clean
	make -C minilibx clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re