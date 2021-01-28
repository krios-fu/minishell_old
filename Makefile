SRCS= ft_envp.c ft_pwd.c minishell.c

OBJS= $(SRCS:.c=.o)
NAME= minishell.a

$(NAME): $(OBJS)
		@make -sC ./libft/
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		@ar -rc $(NAME) $(OBJS)
		@ranlib $(NAME)

.c.o:
	@gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}
	@clear
	@echo "\033[32mCompilación exitosa\033[0m"

all: $(NAME)

clean:
	@rm *.o *.a
	@clear
	@echo "\033[32m\033[0m

PHONY: clean all fclean .c.o 