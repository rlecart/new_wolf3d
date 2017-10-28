# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 15:16:35 by rlecart           #+#    #+#              #
#    Updated: 2017/10/26 05:43:54 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT		=	GRAPHICS
NAME		=	graphics.a
OBJSDIR		=	objs/
SRCSDIR		=	srcs/
SRCS		=	color.c \
				pixel.c \
				vectors.c \
				img.c
OBJS		=	$(addprefix $(OBJSDIR),$(SRCS:.c=.o))
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I includes/ -Ofast

WHITE		=	\033[7;49;39m
BLUE		=	\033[7;49;34m
RED			=	\x1B[31m
YELLOW		=	\x1B[33m
GREEN		=	\033[0;49;32m
GREEN_BG	=	\033[1;49;32m
GRAY		=	\033[7;49;90m
NO_COLOR	=	\033[m

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	@printf "\r$(GREEN)[$(PROJECT)] Bin compilation done.                                                  \n"
	@printf "$(YELLOW)[$(PROJECT)] Compiling $(NAME)..."
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) compiled.                                           \n$(NO_COLOR)"

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	@printf "$(YELLOW)\r[$(PROJECT)] Compiling $< to $@                                                       \r"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJSDIR):
	@mkdir $(OBJSDIR)

clean:
	@printf "$(YELLOW)[$(PROJECT)] Removing bin..."
	@rm -rf $(OBJS)
	@rm -rf $(OBJSDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Obj removed.                                                \n$(NO_COLOR)"

fclean: clean
	@printf "$(YELLOW)[$(PROJECT)] Removing $(NAME)..."
	@rm -rf $(NAME)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) removed.                                            \n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
