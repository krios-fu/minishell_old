GNL= srcs/gnl/get_next_line_bonus.c

SRCS= $(GNL) ft_envp.c ft_pwd.c minishell.c

OBJS= $(SRCS:.c=.o)

NAME= minishell.a

$(NAME): $(OBJS)
		@make -sC ./srcs/libft/
		@cp ./srcs/libft/libft.a .
		@mv libft.a $(NAME)

		@make -sC ./srcs/printf/
		@cp ./srcs/printf/libftprintf.a .
		@mv libftprintf.a $(NAME)

		@ar -rc $(NAME) $(OBJS)
		@ranlib $(NAME)

.c.o:
	@gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}
	@clear
	@echo "\033[33mCompilando...\033[0m"

all: $(NAME)

clean:
	clear
	@make clean -sC ./srcs/libft/
	@make clean -sC ./srcs/printf/
	@rm -f $(OBJS)
	@echo "\033[32mArchivo ".o" limpiados con éxito\033[0m"

fclean:
	clear
	@make fclean -sC ./srcs/libft/
	@make fclean -sC ./srcs/printf/
	@rm -f $(OBJS) $(NAME)
	@echo "\033[32mArchivo ".o" y ".a" limpiados con éxito\033[0m"

re: fclean all

PHONY: clean all fclean .c.o re