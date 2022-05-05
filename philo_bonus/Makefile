NAME		=	philosophers_bonus

HEADER		=	philo_bonus.h

SRC			=	main.c	 init_struct.c	utils.c		philo_create.c		life_cycle.c	ft_time.c

OBJ			=	$(SRC:.c=.o)

FLAGS		=	-Wall -Wextra -Werror

%.o: %.c	$(HEADER)
			@echo 'Some magic...'`gcc $(FLAGS) -o $@ -c $< -I $(HEADER) -o $(<:.c=.o)`''

all:		$(NAME)

bonus:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			@echo 'Done'`gcc $(FLAGS) $(OBJ) -o $(NAME)`''

clean:
		@echo 'Cleaned'`rm -rf $(OBJ)`''


fclean:	clean
		@echo 'Cleaned all'`rm -rf $(NAME)`''

re:		fclean all

.PHONY:	all clean fclean re bonus