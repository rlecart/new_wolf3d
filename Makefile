# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 00:43:30 by rlecart           #+#    #+#              #
#    Updated: 2017/10/28 19:46:48 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT		=	WOLF3D
NAME		=	wolf3d
OBJSDIR		=	objs/
SRCSDIR		=	srcs/
SRCS		=	main.c \
				init.c \
				raycasting.c \
				hook.c \
				reset.c
MINILIBX	=	minilibx_macos/libmlx.a
LIBFT		=	libft/libft.a
GRAPHICS	=	graphics/graphics.a
OBJS		=	$(addprefix $(OBJSDIR),$(SRCS:.c=.o))
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I includes/ -I libft/includes/ -I graphics/includes/ $(OPTI) $(DEBUG)
OPTI		=	-Ofast
DEBUG		=	
MLXF		=	-framework OpenGL -framework AppKit

WHITE		=	\033[7;49;39m
BLUE		=	\033[7;49;34m
RED			=	\x1B[31m
YELLOW		=	\x1B[33m
GREEN		=	\033[0;49;32m
GREEN_BG	=	\033[1;49;32m
GRAY		=	\033[7;49;90m
NO_COLOR	=	\033[m

all: mlx lib gra $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(GRAPHICS) $(OBJSDIR) $(OBJS)
	@printf "\r$(GREEN)[$(PROJECT)] Objs compilation done.                                                        \n"
	@printf "$(YELLOW)[$(PROJECT)] Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(MLXF) -o $(NAME) $(OBJS) $(MINILIBX) $(LIBFT) $(GRAPHICS)
	@printf "\r$(GREEN)[$(PROJECT)] Compilation done.                          \n$(NO_COLOR)"

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	@printf "$(YELLOW)\r[$(PROJECT)] Compiling $< to $@ -g                                                          \r"
	@$(CC) $(CFLAGS) -o $@ -c $<

mlx:
	@printf "$(YELLOW)[MINILIBX] Compiling objs...                                                     \r$(NO_COLOR)"
	@make -s -C minilibx_macos 2> /dev/null > /dev/null

lib:
	@make -s -C libft 2> /dev/null > /dev/null

gra:
	@make -s -C graphics 2> /dev/null > /dev/null

$(OBJSDIR):
	@mkdir $(OBJSDIR)

clean:
	@make -s -C libft clean
	@make -s -C graphics clean
	@printf "$(YELLOW)[$(PROJECT)] Removing objs..."
	@rm -rf $(OBJS)
	@rm -rf $(OBJSDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Objs removed.                                                   \n$(NO_COLOR)"

fclean:
	@make -s -C minilibx_macos clean
	@make -s -C libft fclean
	@make -s -C graphics fclean
	@printf "$(YELLOW)[$(PROJECT)] Removing objs..."
	@rm -rf $(OBJS)
	@rm -rf $(OBJSDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Objs removed.                                                   \n$(NO_COLOR)"
	@printf "$(YELLOW)[$(PROJECT)] Removing $(NAME)..."
	@rm -rf $(NAME)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) removed.                                               \n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
