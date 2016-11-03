# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smassand <marvin@42.fr>                   +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 13:44:49 by smassand          #+#    #+#              #
#    Updated: 2016/05/09 18:45:09 by smassand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		wolf3d	

CC =		gcc

EXT =		.c

FLAGS =		-g -Wall -Werror -Wextra
# -fsanitize=address 

FILE =		wolf		wolf_hook		wolf_ray		wolf_draw		\
			wolf_speed	wolf_init		wolf_map		wolf_set_map	\
			wolf_hook_plus

SOURCE = 	srcs/

INCLUDE =	includes/

HEADER = 	wolf.h

FRAM 	=	-F$(HOME)/Library/Frameworks/	-framework SDL2 -framework SDL2_image

FRAMINC		=	-I$(HOME)/Library/Frameworks/SDL2.framework/Headers \
				-I$(HOME)/Library/Frameworks/SDL2_image.framework/Headers

FILES =		$(addprefix $(SOURCE), $(addsuffix $(EXT), $(FILE)))

OBJ = 		$(FILES:$(EXT)=.o)

LIB_DIR =	libft

EXEC=		$(LIB_DIR)/$(LIB_DIR).a

C_W=		\033[0m
C_R=		\033[38;5;124m
C_Y=		\033[38;5;214m
C_B=		\033[38;5;97m
C_N=		\033[38;5;200m
C_G=		\033[38;5;190m

all: 	$(EXEC) $(NAME) #norme

$(EXEC):
		@make -C $(LIB_DIR)
		@echo "$(C_Y)$(LIB_DIR) $(C_R)			is done !$(C_W)"

$(NAME): $(OBJ)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(EXEC) $(FRAM)
		@echo "\n$(C_Y)$(NAME) $(C_R)		is done !$(C_W)"

%.o:	%$(EXT) $(INCLUDE)
		@$(CC) $(FLAGS) -c $< -o $@ -I libft $(FRAMINC)
		@printf "\033[32m.$(C_W)"

clean:
		@rm -rf $(OBJ)
		@echo "$(C_B)$(NAME)$(C_R)		All obj are cleaned$(C_W)"
		@(cd $(LIB_DIR) && $(MAKE) $@)
		@echo "$(C_B)$(LIB_DIR)$(C_R)		All obj are cleaned$(C_W)"

fclean: clean
		@rm -rf $(NAME)
		@echo "\n$(C_G)$(NAME)$(C_R)		is clean$(C_W)"
		@(cd $(LIB_DIR) && $(MAKE) $@)
		@echo "$(C_G)$(EXEC)$(C_R)	is clean$(C_W)\n"

norme:
	@echo "\nSource:$(C_N)"
	@norminette $(FILES)
	@echo "\n$(C_W)Header:$(C_N)"
	@norminette $(INCLUDE)$(HEADER)
	@echo "$(C_W)"

re: fclean all
