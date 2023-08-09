# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 17:17:14 by lzi-xian          #+#    #+#              #
#    Updated: 2023/08/09 17:23:46 by lzi-xian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
SRC_DIR     =   srcs/
OBJS_DIR    =   objs/
MAN_FILES	=	main					\
				get_next_line			\
				get_next_line_utils		\
				ft_draw_minimap			\
				ft_draw_player			\
				ft_draw_line			\
				ft_draw_view			\
				ft_get_texture_path		\
				ft_get_line 			\
				ft_get_map 				\
				ft_intersect			\
				ft_door 				\
				ft_hook 				\
				ft_node 				\
				ft_atoi					
OBJS 		=	$(SRCS:.c=.o)
SRCS        =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(MAN_FILES)))
OBJS        =	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(MAN_FILES)))
ARCR		= 	ar cr 
RMRF		=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3
GCC			=	gcc


all:
	@mkdir -p $(OBJS_DIR)
	@make $(NAME)

$(OBJS_DIR)%.o:	$(SRC_DIR)%.c
	@$(GCC) ${RLINC} -c $< -o $@

$(NAME):	${OBJS}
	${GCC} ${CFLAGS} ${OBJS} -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean:
	${RMRF} ${OBJS} ${OBJS_DIR}

fclean:	clean
	${RMRF}	$(NAME)

re:	fclean all