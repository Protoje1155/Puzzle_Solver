SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, main.c solver.c utils.c random.c print.c matrixes.c)
OBJS = $(SRCS:.c=.o)
CC = cc
YELLOW := "\033[0;33m"
GREEN := "\033[0;32m"
BLUE := "\033[0;34m"
RED := "\033[0;31m"
NC := "\033[0m"
CFLAGS = -I./lib/ #-Werror -Wall -Wextra 
NAME = solver

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(GREEN)"Compiling $(NAME)..."$(NC)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@echo $(YELLOW)"Compiling $<"$(NC)
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@echo $(RED)"Cleaning objects..."$(NC)
	@rm -rf $(OBJS)

fclean: clean
	@echo $(BLUE)"Cleaning $(NAME)..."$(NC)
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all solver clean fclean re